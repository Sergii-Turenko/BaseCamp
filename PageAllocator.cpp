#include "stdafx.h"
#include "PageAllocator.h"

#include <stdlib.h>

#define NULL 0
#define PAGE_SIZE 4096

char* errorBuf = "";
void* heapAdrs = NULL;

struct memBlock{
	memBlock* next;
	memBlock* prev;
	size_t size;
	void* adrs;
} *freeList, *reservList;

void memAlloc(unsigned num)
{
	if (!heapAdrs) 
	{
		heapAdrs = malloc(PAGE_SIZE * num);
		freeList = (memBlock*)malloc(sizeof(struct memBlock));
		freeList->adrs = heapAdrs;
		freeList->size = PAGE_SIZE * num;
		freeList->next = NULL;
		freeList->prev = NULL;

		reservList = NULL;
	}
}

void deleteBlock(memBlock* block, int list)
{

		if (!block->next && !block->prev)
		{
			switch (list)
			{
			case 0: 
				reservList = NULL; 
				break;
			case 1:
				freeList = NULL; 
				break;
			}
		}
		else
		{
			if (block->next)
			{
				block->next->prev = block->prev;
			}
			if (block->prev)
			{
				block->prev->next = block->next;
			}
			else
			{
				switch (list)
				{
				case 0: 
					reservList = block->next; 
					break;
				case 1: 
					freeList = block->next; 
					break;
				}
			}
		}
}

void* mReserv(size_t size)
{
	memBlock* tempList = freeList;

	if (!heapAdrs)
	{
		errorBuf = "Memory pool wasn't preallocated!";
		return NULL;
	}

	while (tempList->size < (size) )
	{
		if (!tempList->next)
		{
			errorBuf = "Haven't appropriate contiguous memory block!";
			return NULL;
		}
		tempList = tempList->next;
	}

	if (!reservList)
	{
		reservList = (memBlock*)malloc(sizeof(struct memBlock) );
		reservList->next = NULL;
	}
	else
	{
		reservList->prev = (memBlock*)malloc(sizeof(struct memBlock) );
		reservList->prev->next = reservList;
		reservList = reservList->prev;
	}

	reservList->prev = NULL;
	reservList->size = size;
	reservList->adrs = tempList->adrs;

	if (!(tempList->size -= size) ) 
	{
		if (tempList->prev)
		{
			tempList->prev->next = tempList->next;
		}
		else if (!tempList->next)
		{
			freeList = NULL;
		}
	}
	else
	{
		tempList->adrs = (char*)(tempList->adrs) + size;
	}

	return reservList->adrs;
}

unsigned mFree(void *p)
{
	memBlock* tempResList = reservList;
	memBlock* tempFreeList = freeList;
	char* pBackAdr;
	char* pFrontAdr;
	char merged = 0;

	while (tempResList)
	{
		if (tempResList->adrs == p)
		{
			deleteBlock(tempResList, 0);

			pFrontAdr = (char*)tempResList->adrs + tempResList->size;
			while (tempFreeList)
			{

				if (tempFreeList->adrs == pFrontAdr)
				{
					tempResList->size += tempFreeList->size;
					deleteBlock(tempFreeList, 1);
					pFrontAdr = (char*)tempResList->adrs + tempResList->size;
					merged++;
					continue;
				}

				pBackAdr = (char*)tempFreeList->adrs + tempFreeList->size;
				if (tempResList->adrs == pBackAdr)
				{
					tempResList->size += tempFreeList->size;
					tempResList->adrs = tempFreeList->adrs;
					deleteBlock(tempFreeList, 1);
					merged++;
				}

				if (merged == 2)
				{
					break;
				}

				tempFreeList = tempFreeList->next;
			}

			//if (merged) return 0;

			tempResList->next = freeList;
			tempResList->prev = NULL;
			if (freeList)
			{
				freeList->prev = tempResList;
			}
			freeList = tempResList;

			return 0;
		}
		tempResList = tempResList->next;
	}

	errorBuf = "Pointer doesn't point to start of previously allocated memory block!";
	return 1;
}

void freeAllMem()
{
	free(heapAdrs);
	heapAdrs = NULL;
	while (freeList)
	{
		if (!freeList->next)
		{
			free(freeList);  
			break;
		}
		freeList = freeList->next;
		free(freeList->prev);
	}

	while (reservList)
	{
		if (!reservList->next)
		{
			free(reservList);
			break;
		}
		reservList = reservList->next;
		free(reservList->prev);
	}
}

void map()
{
	if (!heapAdrs) 
	{
		return;
	}

	printf("|virtual address | actual address |  state   | size\n");
	memBlock* tempList = reservList;
	while (tempList)
	{
		printf("|    %p    |    %p    |  Reserved|  %u\n", 
			(char*)tempList->adrs - (char*)heapAdrs, tempList->adrs, tempList->size);
		tempList = tempList->next;
	}

	tempList = freeList;
	while (tempList)
	{
		printf("|    %p    |    %p    |  Free    |  %u\n", 
			(char*)tempList->adrs - (char*)heapAdrs ,tempList->adrs, tempList->size);
		tempList = tempList->next;
	}
}

void printLastError()
{
	printf("%s",errorBuf);
}
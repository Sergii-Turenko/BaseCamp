/**
  *@file PageAllocator.h
  *@brief This library provide heap allocator, and containt functions for allocation heap memory
  *heap memory allocates in virtual pages, minimum size is 4096k
*/
#ifndef _PAGE_ALLOCATOR_H_
#define _PAGE_ALLOCATOR_H_

typedef unsigned size_t;

/**
  *@brief function allocates num pages of memory, if memory already been allocated do nothing
  *@remark reallocation memory of another size available only after freeing previous block
*/
void memAlloc(unsigned num);

/**
  *@brief get defined portion of memory of size from allocator memory pool if no memory available returns null pointer
  *@return void* pointer
  *@remark if memory wasn't allocated use printLastError for reason
*/
void* mReserv(size_t size);

/**
  *@brief returns block of memory pointed by p to memory pool, returns number that defines whether memory freed successful or not
  *@return unsigned number 0 if freeing successful, >0 if not
  *@remark if call unsuccessful use printLastError for a reason
*/
unsigned mFree(void *p);

/**
  *@brief prints all current content of memory pool, it includes pool virtual addresses, actual addresses, 
  *memory state(free or not) and size
*/
void map();

/**
  *@brief frees all memory used by PageAllocator
  *@warning all memory completely deallocated, using any of them will lead to program crash
*/
void freeAllMem();

/**
  *@brief prints last error that occurred in current memory pool if no error, nothing happens
*/
void printLastError();

#endif
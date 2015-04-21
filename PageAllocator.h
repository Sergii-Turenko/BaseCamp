#ifndef _PAGE_ALLOCATOR_H_
#define _PAGE_ALLOCATOR_H_

typedef unsigned size_t;

void memAlloc(unsigned num);
void* mReserv(size_t size);
unsigned mFree(void *p);
void map();
void freeAllMem();
void printLastError();

#endif
// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void *pointer = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	mem_list_add(pointer, size);
	return pointer;
}

void *calloc(size_t nmemb, size_t size)
{
	void *pointer = mmap(NULL, size * nmemb, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	memset(pointer, 0, size);
	mem_list_add(pointer, size * nmemb);
	return pointer;
}

void free(void *ptr)
{
	munmap(ptr, mem_list_find(ptr)->len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	void *pointer = mremap(ptr, mem_list_find(ptr)->len, size, MREMAP_MAYMOVE);
	mem_list_find(ptr)->len = size;
	mem_list_find(ptr)->start = pointer;
	return pointer;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	void *pointer = mremap(ptr, mem_list_find(ptr)->len, size * nmemb, MREMAP_MAYMOVE);
	mem_list_find(ptr)->len = size * nmemb;
	mem_list_find(ptr)->start = pointer;
	return pointer;
}

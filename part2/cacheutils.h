#ifndef CACHEUTILS_H
#define CACHEUTILS_H

unsigned long long rdtsc();
void maccess(void* p);
void flush(void* p);

int init();
void create_shared_memory();
void victim();

extern unsigned long shared_array[2048];
extern void *addr;
extern int *shmem_ptr;

//cache access: >50 cycles
//memory access: 100+ cycles
unsigned long long rdtsc() { //read time step counter
	unsigned long long a, d;
	asm volatile ("mfence");
	asm volatile ("rdtsc" : "=a" (a), "=d" (d));
	a = (d<<32) | a;
	asm volatile ("mfence");
	return a;
}

void maccess(void* p)
{
  asm volatile ("movq (%0), %%rax\n"
    :
    : "c" (p)
    : "rax");
}

void flush(void* p) {
    asm volatile ( "clflush (%0)" :: "r"( p ) );
}

#endif



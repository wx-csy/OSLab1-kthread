#include <stdint.h>
#include <os.h>

static void pmm_init();
static void *pmm_alloc(size_t size);
static void pmm_free(void *ptr);

MOD_DEF(pmm) {
  .init = pmm_init,
  .alloc = pmm_alloc,
  .free = pmm_free  
};

#define CHUNK_SIZE    512

static inline void *align_up(void *ptr) {
  uintptr_t addr = (uintptr_t)ptr;
  while (addr & CHUNK_SIZE) addr += addr & -addr;
  return (void*)addr;
}

static inline void *align_down(void *ptr) {
  uintptr_t addr = (uintptr_t)ptr;
  while (addr & CHUNK_SIZE) addr -= addr & -addr;
  return (void*)addr;
}

static void *start, *end;
static void *mem_table;

static void pmm_init() {
  start = _heap.start;
  end = _heap.end();
  
}

static void *pmm_alloc(size_t size) {
  
}

static void pmm_free(void *ptr) {
   
}


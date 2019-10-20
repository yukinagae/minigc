#include "stdio.h"

/* ========================================================================== */
/*  mini_gc_malloc                                                                      */
/* ========================================================================== */

#define TINY_HEAP_SIZE 0x4000 // 16384 (2 ** 14)
// size_t: unsigned long
#define PTRSIZE ((size_t)sizeof(void *)) // unsigned long: 8 bytes (64 bits)
#define HEAP_LIMIT 10000

// TODO: why?
// x = 10
// a = 8
// (((10) + (8 - 1)) & ~(8 - 1))
// ((10) + (7)) & ~(7)
// (1010 + 111) & ~(111)
// (10001) & ~(111)
// (10001) & 11000
// 10000 => 16
//
// x = 16
// a = 8
// (((16) + (8 - 1)) & ~(8 - 1))
// ((16) + (7)) & ~(7)
// (10000 + 111) & ~(111)
// (10111) & ~(111)
// (10111) & 11000
// 10000 => 16
//
// x = 17
// a = 8
// (((17) + (8 - 1)) & ~(8 - 1))
// ((17) + (7)) & ~(7)
// (10001 + 111) & ~(111)
// (11000) & ~(111)
// (11000) & 11000
// 11000 => 24
#define ALIGN(x, a) (((x) + (a - 1)) & ~(a - 1))

typedef struct header
{
    size_t flags;
    size_t size;
    struct header *next_free;
} Header;

static Header *free_list;
static size_t gc_heaps_used = 0;

// TODO: not yet
static Header *add_heap(size_t req_size)
{
    //
    void *p;
    Header *aligh_p;
}

// TODO: not yet
void *mini_gc_malloc(size_t req_size)
{
    Header *p, *prevp;
    size_t do_gc = 0;

    req_size = ALIGN(req_size, PTRSIZE);

    if (req_size <= 0)
    {
        return NULL;
    }

    if ((prevp = free_list) == NULL)
    {
        if (!(p = add_heap(TINY_HEAP_SIZE)))
        {
            return NULL;
        }
        prevp = free_list = p;
    }

    // TODO: not yet implemented

    return NULL;
}

/* ========================================================================== */
/*  mini_gc                                                                   */
/* ========================================================================== */

static void *stack_start = NULL; // void pointer

// TODO: not yet
// Initialize GC stack start
void gc_init(void)
{
    long dummy = 42;
    stack_start = (void *)&dummy;
    printf("%p\n", stack_start); // TODO: debug
}

/* ========================================================================== */
/*  test                                                                      */
/* ========================================================================== */

// TODO: not yet
static void test_mini_gc_malloc_free(void)
{
    void *p1, *p2, *p3;

    /* malloc check */
    p1 = (void *)mini_gc_malloc(10);
    // p2 = (void *)mini_gc_malloc(16);
    // p3 = (void *)mini_gc_malloc(17);
}

static void test_garbage_collect(void)
{
}

static void test_garbage_collect_load_test(void)
{
}

// Run all the setup
static void run(void)
{
    gc_init();
    test_mini_gc_malloc_free();
    test_garbage_collect();
    test_garbage_collect_load_test();
}

int main(int argc, char **argv)
{
    run();
    return 0;
}

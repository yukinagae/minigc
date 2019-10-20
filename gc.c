#include "stdio.h"

/* ========================================================================== */
/*  mini_gc_malloc                                                                      */
/* ========================================================================== */

#define PTRSIZE ((size_t)sizeof(void *))

#define ALIGN(x, a) (((x) + (a - 1)) & ~(a - 1))

typedef struct header
{
    size_t flags;
    size_t size;
    struct header *next_free;
} Header;

void *mini_gc_malloc(size_t req_size)
{
    Header *p, *prevp;
    size_t do_gc = 0;

    printf("%zu\n", PTRSIZE);

    req_size = ALIGN(req_size, PTRSIZE);

    printf("%zu\n", req_size);

    return NULL;
}

/* ========================================================================== */
/*  mini_gc                                                                   */
/* ========================================================================== */

static void *stack_start = NULL; // void pointer

// Initialize GC stack start
void gc_init(void)
{
    long dummy;

    dummy = 42;

    stack_start = ((void *)&dummy);

    printf("%p\n", stack_start);
}

/* ========================================================================== */
/*  test                                                                      */
/* ========================================================================== */

static void test_mini_gc_malloc_free(void)
{
    void *p1, *p2, *p3;

    /* malloc check */
    p1 = (void *)mini_gc_malloc(10);
    p2 = (void *)mini_gc_malloc(16);
    p3 = (void *)mini_gc_malloc(17);
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

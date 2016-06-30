/*++

Copyright (c) 2016  Radial Technologies

Module Name:

    malloc.c


Abstract:

    Allocates a block of memory of n bytes on the heap (which is a doubly
    linked list of memory blocks).


Author:

    Quaker762


Environment:


Notes:

    The MK20DX256 has no MMU, so this is all physical allocations. This makes our life
    somewhat easier, as we don't have to worry about mapping any pages in if we run out room.
    However, a serious downside is we only have 64KiB of Physical RAM to map, so once we're
    out of memory, we're in a bit of a pickle.

    This allocator works on the principal of two-block coalescing. That is, every time
    we free a block, we also check to the left and right of the block to see if they are
    free. If they are, we merge the three blocks by modifying the size variable of the
    leftmost block and setting it to free. The other blocks will then get trampled next allocation.

    I just realised, statically allocated variables could get trampled here.. Perhaps the heap
    should be 32KiB large instead? That works much better with our 15-bit allocation size as
    well


Revision History:

    30/6/2016: Initial Revision.

--*/
//#include <stdlib.h>
//#include <stdint.h>

#define HEAP_START  0x20000000 // 32KiB into SRAM
#define HEAP_END    0x20008000 // END OF SRAM

#define ENOMEM -1

/**
    Memory block data structure.
    Maximum 15-bit (32KiB - 1byte) allocation per block
**/
typedef struct MEMBLOCK
{
    MEMBLOCK*   prev;
    MEMBLOCK*   next;
    uint16_t    in_use : 1;
    uint16_t    size : 15;
} memblock_t;

static void split_block(memblock_t* block, uint16_t size)
{
    if(block->size - size > sizeof(memblock_t))
    {
        memblock_t* next = (memblock_t*)(next + next->size); // Get the next header
        next->prev = block;
        next->size = size - block->size - sizeof(memblock_t);
        next->in_use = 0;

        block->next = next;
    }
}


void* malloc(uint16_t size)
{
    memblock_t* current     = HEAP_START;
    memblock_t* prev        = 0; // REPLACE ME WITH NULL!

    // Increment the current block pointer
    while(current < HEAP_END)
    {
        // We've found a free block that's large enough
        if(curent->in_use == 0 && current->size >= size)
        {
            current->in_use = 1; // This block is taken, ladies!
            current->size   = size - sizeof(memblock_t);

            // If the current block is larger than the allocation request, split it.
            // Also make sure the next block isn't actually in use so we don't trample it.
            if(current->size > size && current->next->in_use == 0)
                split_block(current, size);

            return (void*)((uint32_t)current + sizeof(memblock_t)); // Return pointer address to data start
        }

        prev = current;
        current += current->size;
    }

    return ENOMEN; // If we return this we're in a bit of trouble.. We should probably try and recover...
}

int free(void* block)
{
    memblock_t* block = (memblock_t*)(block - sizeof(memblock_t)); // Get the address of the actual block
    block->in_use = 0;

    // Right block coalesce. Make sure we don't go over usable RAM
    if(block->next->in_use == 0 && block->next < HEAP_END)
        block->size += block->next->size;

    // Left block coalesce
    if(block->prev->in_use ==0 && block->prev > HEAP_START)
        block->prev->size += block->size; // Add on the size of both blocks

}






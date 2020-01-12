#include "organism.h"
#include <stdbool.h>
#include <stdlib.h>


typedef struct __OrganismData
{
    Organism pub;
    bool     isIntelligent;
    char     padding[90];
} OrganismData;

Organism * Organism_Ctor()
{
    /*
     * LESSON: Without language support we must allocate space for objects on
     *         the heap. We can't return structs by value in C and the struct
     *         created goes out of scope as soon as we leave the function so
     *         we couldn't return the address of the data.
     */
    OrganismData * var = calloc(1, sizeof(OrganismData));

    var->pub.isBreathing = true;
    var->isIntelligent = true;

    return (Organism *)var;
}

void Organism_Dtor(Organism * const _ptr)
{
    OrganismData * const ptr = (OrganismData * const)_ptr;
    free(ptr);
}

bool Organism_IsBreathing(Organism * const _ptr)
{
    return _ptr->isBreathing;
}

bool Organism_IsAlive(Organism * const _ptr)
{
    OrganismData * const ptr = (OrganismData *)_ptr;

    return ptr->pub.isBreathing && ptr->isIntelligent;
}

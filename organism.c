#include "organism.h"
#include <stdbool.h>
#include <stdlib.h>


typedef struct __OrganismData
{
    Organism pub;
    bool     isIntelligent;
} OrganismData;

Organism * Organism_Ctor()
{
    OrganismData * var = malloc(sizeof(OrganismData));

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

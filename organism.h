//
//- Organism class
//
#include <stdbool.h>

typedef struct __Organism
{
    bool isBreathing;
} Organism;

Organism * Organism_Ctor();
void Organism_Dtor(Organism * _ptr);

bool Organism_IsBreathing(Organism * const _ptr);
bool Organism_IsAlive(Organism * const _ptr);

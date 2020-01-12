#ifndef ORGANISM_H
#define ORGANISM_H

#include <stdbool.h>

/*
 * LESSON: This idea falls apart as soon as there's no public data exposed for
 *         the user. You don't want them carrying around a void pointer because
 *         type safety goes out the window, but what do they have to carry that
 *         says "I own this object" if they don't have access to it? We could
 *         put the private data definition here but then you've just made your
 *         private data public (whoops).
 */
typedef struct __Organism
{
    bool isBreathing;
} Organism;

Organism * Organism_Ctor();
void Organism_Dtor(Organism * _ptr);

bool Organism_IsBreathing(Organism * const _ptr);
bool Organism_IsAlive(Organism * const _ptr);

#endif

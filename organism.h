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
/*
 * Follow up: C allows you to do `typedef struct <useless name> <public name>;`
 *            which blows me away. But, that means the previous lesson is just
 *            lack of experience.
 */
typedef char OrganismPrivateSize[1];

typedef struct __Organism
{
    OrganismPrivateSize private;
    bool isBreathing;
} Organism;

/*
 * LESSON: C++ gives you constructors and destructors for free if your memory
 *         is statically allocated. We need to discriminate in C.
 */
Organism *Organism_Ctor();
void Organism_CtorStatic(Organism *_ptr);
void Organism_Dtor(Organism *_ptr);
void Organism_DtorStatic(Organism *_ptr);

bool Organism_IsBreathing(Organism *const _ptr);
bool Organism_IsAlive(Organism *const _ptr);

#endif

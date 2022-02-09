#ifndef ANIMAL_H
#define ANIMAL_H

#include "organism.h"

typedef struct __Animal
{
    Organism parent;
    unsigned appendages;
} Animal;

Animal *Animal_Ctor();
void Animal_CtorStatic(Animal *_ptr);
void Animal_Dtor(Animal *_ptr);
void Animal_DtorStatic(Animal *_ptr);

char *Animal_TalkVirtual(Animal *_ptr, bool forceThis);

#endif

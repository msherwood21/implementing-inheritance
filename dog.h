#ifndef DOG_H
#define DOG_H

#include "animal.h"

typedef struct __Dog
{
    Animal parent;
} Dog;

Dog *Dog_Ctor();
void Dog_CtorStatic(Dog *_ptr);
void Dog_Dtor(Dog *_ptr);
void Dog_DtorStatic(Dog *_ptr);

char *Dog_TalkVirtual(Dog *_ptr, bool forceThis);

#endif

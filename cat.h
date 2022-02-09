#ifndef CAT_H
#define CAT_H

#include "animal.h"

typedef struct __Cat
{
    Animal parent;
} Cat;

Cat *Cat_Ctor();
void Cat_CtorStatic(Cat *_ptr);
void Cat_Dtor(Cat *_ptr);
void Cat_DtorStatic(Cat *_ptr);

char *Cat_TalkVirtual(Cat *_ptr, bool forceThis);

#endif

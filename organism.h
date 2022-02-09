#ifndef ORGANISM_H
#define ORGANISM_H

#include "virtual.h"
#include <stdbool.h>

//- LESSON: For private data C is incredibly forgiving for types. However,
//  it insists on knowing the data size. This still works for our purposes
//  because the user doesn't know how to interpret the private data, but it is
//  aware of how much the object costs for their memory budget. This is an
//  additional win because now we can statically add parent classes to child
//  classes with the correct data layout and padding. The only thing we must do
//  is statically assert the public size matches the actual private size. We do
//  that in the constructor function for every object.
typedef char OrganismPrivateSize[1];

//- If we had an object with no data and no virtual functions we could put
//  `typedef struct <useless name> <public name>;` here. If that doesn't work
//  we could follow C++ and have one useless byte to represent a class.
typedef struct __Organism
{
    Virtual virtual;
    OrganismPrivateSize private;
    bool isBreathing;
} Organism;

//- LESSON: C++ gives you constructors and destructors for free if your memory
//  is statically allocated. We need to discriminate in C.
Organism *Organism_Ctor();
void Organism_CtorStatic(Organism *_ptr);
void Organism_Dtor(Organism *_ptr);
void Organism_DtorStatic(Organism *_ptr);

bool Organism_IsBreathing(Organism *const _ptr);
bool Organism_IsAlive(Organism *const _ptr);

//- forceThis is equivalent to specifying a particular version of a virtual
//  function (as in <class>::function).
char *Organism_TalkVirtual(Organism *_ptr, bool forceThis);

#endif

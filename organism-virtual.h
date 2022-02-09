#ifndef ORGANISM_VIRTUAL_H
#define ORGANISM_VIRTUAL_H

//- NOTE: This header should only be included by the Organism class, its
//  children and the main module. This header should only be included in the
//  *.c files.
//- To make a virtual table work we need to be able to route any call to a
//  virtual function to the correct specification. The C++ compiler is able to
//  build this table at compile time without exposing any class details; it
//  just needs to see who the class inherits from. We have to mimic this
//  functionality at runtime.
//
//  We make this happen by declaring a function signature for each virtual
//  function. Next, we declare, through an extern, that we need function
//  implementations from every class listed for that function. Class modules
//  that implement a function will assign their implementation to their
//  associated signature. Finally, an array of function pointers will be
//  declared to hold all the function pointers. At runtime, the
//  InitializeStatic function will add all the function pointers to the array.
//  Now our virtual table is built.

#include "virtual.h"
#include "organism.h"

typedef char *(*Organism_TalkVirtualSig)(Organism *);
extern Organism_TalkVirtualSig Organism_TalkSigVirtual;
extern Organism_TalkVirtualSig Animal_TalkSigVirtual;
extern Organism_TalkVirtualSig Dog_TalkSigVirtual;
extern Organism_TalkVirtualSig Cat_TalkSigVirtual;
extern Organism_TalkVirtualSig organismTalkVirtuals[ClassTypeId_EnumSize];

//- Creates the virtual table used for dynamic function dispatch
void Organism_InitializeStaticVirtual();

//- Creates the virtual header in every Organism derived class
void Organism_CtorVirtual(Organism *_ptr, ClassTypeIdEnum childId);

#endif

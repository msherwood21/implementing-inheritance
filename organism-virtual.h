#ifndef ORGANISM_VIRTUAL_H
#define ORGANISM_VIRTUAL_H

//- To make a virtual table work we need to be able to route any call to a
//  virtual function to the correct specification. The C++ compiler is able to
//  build this table at compile time without exposing any class details; it
//  just needs to see who the class inherits from. We can mimic this
//  functionality at link time, but we have to be clever about it.
//
//  We make this happen by declaring a function signature for each virtual
//  function. Next, we declare, through an extern, that we need function
//  implementations from every class listed for that function. Class modules
//  that implement a function will assign their implementation to their
//  associated signature. If they don't have an implementation, they still need
//  to assign their signature to NULL so they linker has something to pick up.
//  Finally, an array of pointers to function pointers will be declared to hold
//  all the virtual implementations. We must store the addresses of the
//  function pointers because the C compiler does not think externally declared
//  function pointers are defined by compile time. Now our virtual table is built.

//- NOTE: This header should only be included by the Organism class and its
//  children. To make this method work without conflict, the header should only
//  be included in the *.c files.

#include "virtual.h"
#include "organism.h"

typedef char *(*Organism_TalkVirtualSig)(Organism *);
extern Organism_TalkVirtualSig Organism_TalkSigVirtual;
extern Organism_TalkVirtualSig Animal_TalkSigVirtual;
extern Organism_TalkVirtualSig Dog_TalkSigVirtual;
extern Organism_TalkVirtualSig Cat_TalkSigVirtual;
extern Organism_TalkVirtualSig * organismTalkVirtuals[ClassTypeId_EnumSize];

//- Creates the virtual header in every Organism derived class. Must be
//  implemented by the Organism base class.
void Organism_CtorVirtual(Organism *_ptr, ClassTypeIdEnum childId);

#endif

#include "organism.h"
#include "organism-virtual.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

//-
//- Virtual Functions
//-

char *Organism_TalkImplVirtual(__attribute__((unused)) Organism *_ptr)
{
    return "Do organisms talk?";
}

//- Link our implementation of the Talk function to its exposed signature so we
//  can get called.
Organism_TalkVirtualSig Organism_TalkSigVirtual = &Organism_TalkImplVirtual;

//- This function matches the signature in virtual.h. Look there for a writeup
//  of what's going on.
VirtualImpl Organism_VirtualLookup(TypeId typeId)
{
    //- This would be significantly optimized in a production setting, but this
    //  is just proof of concept stuff
    if (typeId < ClassTypeId_EnumSize)
    {
        if (organismTalkVirtuals[typeId] != NULL)
        {
            return (VirtualImpl)organismTalkVirtuals[typeId];
        }
        else
        {
            //- Also, in a production setting I believe you walk the parent
            //  classes until you arrive at the base implementation. We cut out
            //  that logic here for simplicity.
            return (VirtualImpl)organismTalkVirtuals[ClassTypeId_Organism];
        }
    }
    else
    {
        return NULL;
    }
}

//-
//- Private Data
//-

typedef struct __OrganismPrivate
{
    bool isIntelligent;
} OrganismPrivate;

//-
//- Private functions
//-

void Organism_InitializeMembers(Organism *_ptr)
{
    if (_ptr != NULL)
    {
        OrganismPrivate *varPrivate = (OrganismPrivate *)_ptr->private;

        _ptr->isBreathing = true;
        varPrivate->isIntelligent = true;
    }
}

//-
//- Public functions
//-

Organism *Organism_Ctor()
{
    static_assert(sizeof(OrganismPrivateSize) == sizeof(OrganismPrivate),
                  "OrganismPrivate has a size mismatch");

    //- LESSON: Without language support we must allocate space for objects on
    //  the heap. We can't return structs by value in C and the struct created
    //  goes out of scope as soon as we leave the function so we couldn't
    //  return the address of the data.
    Organism *var = calloc(1, sizeof(Organism));

    Organism_CtorStatic(var);

    return var;
}

void Organism_CtorStatic(Organism *_ptr)
{
    if (_ptr != NULL)
    {
        Organism_CtorVirtual(_ptr, ClassTypeId_Organism);
        Organism_InitializeMembers(_ptr);
    }
}

void Organism_CtorVirtual(Organism *_ptr, ClassTypeIdEnum childId)
{
    if (_ptr != NULL)
    {
        _ptr->virtual.lookup = &Organism_VirtualLookup;

        if (childId <= ClassTypeId_EnumSize)
        {
            _ptr->virtual.id = childId;
        }
        else
        {
            _ptr->virtual.id = ClassTypeId_EnumSize;
        }
    }
}

void Organism_Dtor(Organism *const _ptr)
{
    free(_ptr);
}

void Organism_DtorStatic(__attribute__((unused)) Organism *_ptr)
{
    //- No resources to cleanup so nothing to do!
}

bool Organism_IsBreathing(Organism *const _ptr)
{
    bool result = false;

    if (_ptr != NULL)
    {
        result = _ptr->isBreathing;
    }

    return result;
}

bool Organism_IsAlive(Organism *const _ptr)
{
    bool result = false;

    if (_ptr != NULL)
    {
        OrganismPrivate *const varPrivate = (OrganismPrivate *)_ptr->private;

        result = _ptr->isBreathing && varPrivate->isIntelligent;
    }

    return result;
}

//- Our public entry point into the class' virtual function. If the user really
//  wants this implementation we'll call it immediately. Otherwise, we perform
//  a lookup and call the right function.
char *Organism_TalkVirtual(Organism *_ptr, bool forceThis)
{
    if (forceThis)
    {
        return Organism_TalkImplVirtual(_ptr);
    }
    else if (_ptr != NULL)
    {
        Organism_TalkVirtualSig talkImpl = (Organism_TalkVirtualSig)_ptr->virtual.lookup(_ptr->virtual.id);

        return talkImpl(_ptr);
    }
    else
    {
        return "";
    }
}

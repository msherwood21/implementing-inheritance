#include "animal.h"
#include "organism-virtual.h"
#include <assert.h>
#include <stdlib.h>

//-
//- Virtual Functions
//-

char *Animal_TalkImplVirtual(__attribute__((unused)) Organism *_ptr)
{
    //- We don't have any logic here that requires it, but we could safely
    //  recast the pointer to an Animal if we'd like.
    return "Animals definitely talk!";
}

Organism_TalkVirtualSig Animal_TalkSigVirtual = &Animal_TalkImplVirtual;

//-
//- Private functions
//-

void Animal_InitializeMembers(Animal *_ptr)
{
    _ptr->appendages = 0;
}

//-
//- Public functions
//-

Animal *Animal_Ctor()
{
    Animal *var = calloc(1, sizeof(Animal));

    Animal_CtorStatic(var);

    return var;
}

void Animal_CtorStatic(Animal *_ptr)
{
    if (_ptr != NULL)
    {
        Organism_CtorStatic(&(_ptr->parent));
        Organism_CtorVirtual(&(_ptr->parent), ClassTypeId_Animal);
        Animal_InitializeMembers(_ptr);
    }
}

void Animal_Dtor(Animal *_ptr)
{
    if (_ptr != NULL)
    {
        Animal_DtorStatic(_ptr);
        free(_ptr);
    }
}

void Animal_DtorStatic(Animal *_ptr)
{
    if (_ptr != NULL)
    {
        Organism_DtorStatic(&(_ptr->parent));
    }
}

char *Animal_TalkVirtual(Animal *_ptr, bool forceThis)
{
    if (forceThis)
    {
        return Animal_TalkImplVirtual(&(_ptr->parent));
    }
    else if (_ptr != NULL)
    {
        Organism_TalkVirtualSig talkImpl = (Organism_TalkVirtualSig)_ptr->parent.virtual.lookup(_ptr->parent.virtual.id);

        //- We can safely cast the parent to the child object later only
        //  because the parent object is the first member in the data
        //  structure. If it was anywhere else we would not be able to safely
        //  access a child class' full data.
        return talkImpl(&(_ptr->parent));
    }
    else
    {
        return "";
    }
}

#include "cat.h"
#include "organism-virtual.h"
#include <assert.h>
#include <stdlib.h>

//-
//- Virtual Functions
//-

char *Cat_TalkImplVirtual(__attribute__((unused)) Organism *_ptr)
{
    //- We don't have any logic here that requires it, but we could safely
    //  recast the pointer to an Cat if we'd like.
    return "Meow...";
}

Organism_TalkVirtualSig Cat_TalkSigVirtual = &Cat_TalkImplVirtual;

//-
//- Private functions
//-

void Cat_InitializeMembers(__attribute__((unused)) Cat *_ptr)
{
    //- Nothing to do
}

//-
//- Public functions
//-

Cat *Cat_Ctor()
{
    Cat *var = calloc(1, sizeof(Cat));

    Cat_CtorStatic(var);

    return var;
}

void Cat_CtorStatic(Cat *_ptr)
{
    if (_ptr != NULL)
    {
        Animal_CtorStatic(&(_ptr->parent));
        Organism_CtorVirtual(&(_ptr->parent.parent), ClassTypeId_Cat);
        Cat_InitializeMembers(_ptr);
    }
}

void Cat_Dtor(Cat *_ptr)
{
    if (_ptr != NULL)
    {
        Cat_DtorStatic(_ptr);
        free(_ptr);
    }
}

void Cat_DtorStatic(Cat *_ptr)
{
    if (_ptr != NULL)
    {
        Animal_DtorStatic(&(_ptr->parent));
    }
}

//- By this point you'll see that we have to keep jumping into the parent of
//  the parent to pass in the data we need to pass in. This is really tedious,
//  so deep object trees are not recommended.
char *Cat_TalkVirtual(Cat *_ptr, bool forceThis)
{
    if (forceThis)
    {
        return Cat_TalkImplVirtual(&(_ptr->parent.parent));
    }
    else if (_ptr != NULL)
    {
        Organism_TalkVirtualSig talkImpl = (Organism_TalkVirtualSig)_ptr->parent.parent.virtual.lookup(_ptr->parent.parent.virtual.id);

        //- We can safely cast and inflate later only because the parent object
        //  is the first member in the data structure. If it was anywhere else
        //  this would break.
        return talkImpl(&(_ptr->parent.parent));
    }
    else
    {
        return "";
    }
}

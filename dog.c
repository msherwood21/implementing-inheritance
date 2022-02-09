#include "dog.h"
#include "organism-virtual.h"
#include <assert.h>
#include <stdlib.h>

//-
//- Virtual Functions
//-

char *Dog_TalkImplVirtual(__attribute__((unused)) Organism *_ptr)
{
    //- We don't have any logic here that requires it, but we could safely
    //  recast the pointer to a Dog if we'd like.
    return "Woof Woof!";
}

Organism_TalkVirtualSig Dog_TalkSigVirtual = &Dog_TalkImplVirtual;

//-
//- Private functions
//-

void Dog_InitializeMembers(__attribute__((unused)) Dog *_ptr)
{
    //- Nothing to do
}

//-
//- Public functions
//-

Dog *Dog_Ctor()
{
    Dog *var = calloc(1, sizeof(Dog));

    Dog_CtorStatic(var);

    return var;
}

void Dog_CtorStatic(Dog *_ptr)
{
    if (_ptr != NULL)
    {
        Animal_CtorStatic(&(_ptr->parent));
        Organism_CtorVirtual(&(_ptr->parent.parent), ClassTypeId_Dog);
        Dog_InitializeMembers(_ptr);
    }
}

void Dog_Dtor(Dog *_ptr)
{
    if (_ptr != NULL)
    {
        Dog_DtorStatic(_ptr);
        free(_ptr);
    }
}

void Dog_DtorStatic(Dog *_ptr)
{
    if (_ptr != NULL)
    {
        Animal_DtorStatic(&(_ptr->parent));
    }
}

//- By this point you'll see that we have to keep jumping into the parent of
//  the parent to pass in the data we need to pass in. This is really tedious,
//  so deep object trees are not recommended.
char *Dog_TalkVirtual(Dog *_ptr, bool forceThis)
{
    if (forceThis)
    {
        return Dog_TalkImplVirtual(&(_ptr->parent.parent));
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

#include "animal.h"
#include <assert.h>
#include <stdlib.h>

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

    if (var != NULL)
    {
        Organism_CtorStatic(&(var->parent));
        Animal_InitializeMembers(var);
    }

    return var;
}

void Animal_CtorStatic(Animal *_ptr)
{
    if (_ptr != NULL)
    {
        Organism_CtorStatic(&(_ptr->parent));
        Animal_InitializeMembers(_ptr);
    }
}

void Animal_Dtor(Animal *_ptr)
{
    if (_ptr != NULL)
    {
        Organism_DtorStatic(&(_ptr->parent));
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

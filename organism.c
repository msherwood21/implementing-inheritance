#include "organism.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

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
    /*
     * LESSON: For private data C is incredibly forgiving for types. However,
     *         it insists on knowing the data size. This still works for our
     *         purposes because the user doesn't know how to interpret the
     *         private data, but it is aware of how much the object costs for
     *         their memory budget. This is an additional win because now we
     *         can statically add parent classes to child classes with the
     *         correct data layout and padding. The only thing we must do is
     *         statically assert the public size matches the actual private
     *         size.
     */
    static_assert(sizeof(OrganismPrivateSize) == sizeof(OrganismPrivate),
                  "OrganismPrivate has a size mismatch");

    /*
     * LESSON: Without language support we must allocate space for objects on
     *         the heap. We can't return structs by value in C and the struct
     *         created goes out of scope as soon as we leave the function so
     *         we couldn't return the address of the data.
     */
    Organism *var = calloc(1, sizeof(Organism));

    Organism_InitializeMembers(var);

    return var;
}

void Organism_CtorStatic(Organism *_ptr)
{
    if (_ptr != NULL)
    {
        Organism_InitializeMembers(_ptr);
    }
}

void Organism_Dtor(Organism *const _ptr)
{
    free(_ptr);
}

//- GCC specific unused parameter attribute
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

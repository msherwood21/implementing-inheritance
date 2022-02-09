#include "organism-virtual.h"
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include <stdio.h>

int main(void)
{
    //- C++ has the ability to see all symbols in a binary and create virtual
    //  tables statically. We don't have that ability with C. The following method
    //  of adding symbols at an initialization point is not great, but it keeps us
    //  from having to worry about a host of virtual table related issues.
    Organism_InitializeStaticVirtual();

    //- Class creation with public, private and virtual data
    Organism organism;
    Organism_CtorStatic(&organism);
    Organism *const organismHeap = Organism_Ctor();

    //- Class creation of a child class with virtual data
    Animal animal;
    Animal_CtorStatic(&animal);
    Animal *const animalHeap = Animal_Ctor();

    //- Class functions with specific and child classes
    printf("organismHeap is breathing (%u)\n", Organism_IsBreathing(organismHeap));
    printf("organismHeap is alive (%u)\n", Organism_IsAlive(organismHeap));
    printf("animalHeap has %u legs and is breathing (%u)\n", animalHeap->appendages, Organism_IsBreathing(&(animalHeap->parent)));

    //- Class creation of child classes on the same inheritance level
    Dog *const dog = Dog_Ctor();
    Cat cat;
    Cat_CtorStatic(&cat);

    //- Virtual class functions at class levels
    printf("%s\n", Organism_TalkVirtual(organismHeap, false));
    printf("%s\n", Organism_TalkVirtual(&(animalHeap->parent), false));
    printf("%s\n", Organism_TalkVirtual(&(animalHeap->parent), true));
    printf("%s\n", Dog_TalkVirtual(dog, false));
    printf("%s\n", Cat_TalkVirtual(&cat, false));

    //- Object cleanup
    Cat_DtorStatic(&cat);
    Dog_Dtor(dog);
    Animal_Dtor(animalHeap);
    Animal_DtorStatic(&animal);
    Organism_Dtor(organismHeap);
    Organism_DtorStatic(&organism);

    return 0;
}

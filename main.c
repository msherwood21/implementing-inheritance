#include "animal.h"
#include "organism.h"
#include <stdio.h>

int main(void)
{
    Organism *const v = Organism_Ctor();
    Animal *const a = Animal_Ctor();

    Organism org;
    Organism_CtorStatic(&org);

    Animal an;
    Animal_CtorStatic(&an);

    printf("v is breathing (%u)\n", Organism_IsBreathing(v));
    printf("v is alive (%u)\n", Organism_IsAlive(v));

    printf("a has %u legs and is breathing (%u)\n",
           a->appendages,
           Organism_IsBreathing(&(a->parent)));

    printf("org is breathing (%u)\n", Organism_IsBreathing(&org));
    printf("an is alive (%u)\n", Organism_IsAlive(&(an.parent)));

    Organism_Dtor(v);
    Animal_Dtor(a);
    Organism_DtorStatic(&org);
    Animal_DtorStatic(&an);

    return 0;
}

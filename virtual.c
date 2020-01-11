#include "organism.h"
#include <stdbool.h>
#include <stdio.h>


int main(void)
{
    Organism * const v = Organism_Ctor();

    printf("v is breathing (%u)\n", Organism_IsBreathing(v));
    printf("v is alive (%u)\n", Organism_IsAlive(v));

    Organism_Dtor(v);

    return 0;
}

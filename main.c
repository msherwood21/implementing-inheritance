#include "animal.h"
#include "organism.h"
#include <stdio.h>


int main(void)
{
    Organism * const v = Organism_Ctor();
    Animal * const a = Animal_Ctor();

    printf("v is breathing (%u)\n", Organism_IsBreathing(v));
    printf("v is alive (%u)\n", Organism_IsAlive(v));

    /*
     * LESSON: Unless the child class (and any potential intermediary
     *         classes) is able to allocate all memory in the correct layout,
     *         it must expose a pointer to its parent data for the user to call
     *         any parent functions. Because the class only knows about its
     *         parent (or parents in multi-inheritance) we must chain functions
     *         that expose parent data if the class is several layers deep in
     *         a heirarchy.
     *
     *         Note that you've now brought your class implementation into user
     *         code. The function is Organism_IsBreathing and your user must
     *         now find a way to make the Animal class work.
     */
    printf("a has %u legs and is breathing (%u)\n",
            a->appendages,
            Organism_IsBreathing(Animal_ReturnParent(a)));

    Organism_Dtor(v);
    Animal_Dtor(a);

    return 0;
}

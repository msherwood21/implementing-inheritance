#include "animal.h"
#include <stdlib.h>


typedef struct __AnimalData
{
    Animal     pub;
    Organism * parent;
} AnimalData;

Animal * Animal_Ctor()
{
    /*
     * LESSON: Without language support for object creation and destruction you
     *         are required to use the parent class' ctor / dtor functions. Only
     *         they know how to initialize the private data for their class!
     *         This means the data allocations could be in entirely different
     *         ends of the memory map. That is, if you don't run out of memory
     *         after creating (one of) the parent object(s)! Potentially
     *         increased cache misses if you're calling different functions /
     *         data up the heirarchy as well!
     */
    /*
     * OPTIMIZATION: Export the size of an object's public + private data. This
     *               leaks implementation details + recompilation issues at the
     *               expense of allowing the children classes to allocate all
     *               the memory they need in one go. This would require
     *               rearchitecting how classes are created though as each
     *               class still needs to be able to setup its own data.
     */
    AnimalData * ptr = calloc(1, sizeof(AnimalData));
    ptr->parent = Organism_Ctor();

    return (Animal *)ptr;
}

void Animal_Dtor(Animal * _ptr)
{
    Organism_Dtor(((AnimalData *)_ptr)->parent);
    free(_ptr);
}

Organism * Animal_ReturnParent(Animal * _ptr)
{
    return ((AnimalData *)_ptr)->parent;
}

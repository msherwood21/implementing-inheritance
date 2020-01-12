#ifndef ANIMAL_H
#define ANIMAL_H

#include "organism.h"

/*
 * LESSON: Were it not for the organism include and the ReturnParent function
 *         there would be no way to indicate this class is inheriting from the
 *         Organism class outside of a comment or a drawing.
 */
typedef struct __Animal
{
    unsigned appendages;
} Animal;

Animal * Animal_Ctor();
void Animal_Dtor(Animal * _ptr);

Organism * Animal_ReturnParent(Animal * _ptr);

#endif

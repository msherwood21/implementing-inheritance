#ifndef VIRTUAL_H
#define VIRTUAL_H

//- Unlike C++ we don't have a facility to specify complex types ahead of
//  time (templates). We have to type erase here in order to accept any virtual
//  function specification.
typedef void (*VirtualImpl)(void);

//- To perform dynamic dispatch we need a way to know what object type we
//  actually are. Every virtual class has a type ID to make this happen.
typedef unsigned TypeId;

//- Our function signature for looking up what virtual function to call based
//  on who we are. I've limited the proof of concept to just one function;
//  otherwise we'd need to have another argument expressing what function we're
//  wanting to call.
typedef VirtualImpl (*VirtualLookup)(TypeId);

typedef struct __Virtual
{
    VirtualLookup lookup;
    TypeId id;
} Virtual;

typedef enum __Class_TypeIdEnum
{
    ClassTypeId_Organism = 0,
    ClassTypeId_Animal,
    ClassTypeId_Dog,
    ClassTypeId_Cat,
    ClassTypeId_EnumSize
} ClassTypeIdEnum;

#endif

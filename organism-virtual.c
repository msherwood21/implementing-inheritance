#include "organism-virtual.h"

Organism_TalkVirtualSig organismTalkVirtuals[ClassTypeId_EnumSize];

void Organism_InitializeStaticVirtual()
{
    organismTalkVirtuals[ClassTypeId_Organism] = Organism_TalkSigVirtual;
    organismTalkVirtuals[ClassTypeId_Animal] = Animal_TalkSigVirtual;
    organismTalkVirtuals[ClassTypeId_Dog] = Dog_TalkSigVirtual;
    organismTalkVirtuals[ClassTypeId_Cat] = Cat_TalkSigVirtual;
}

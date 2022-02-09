#include "organism-virtual.h"

Organism_TalkVirtualSig * organismTalkVirtuals[ClassTypeId_EnumSize] = {
    &Organism_TalkSigVirtual, &Animal_TalkSigVirtual, &Dog_TalkSigVirtual,
    &Cat_TalkSigVirtual};

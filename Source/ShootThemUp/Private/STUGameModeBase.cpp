// Shoot Them Up game. All Rights Resived.

#include "STUGameModeBase.h"

void ASTUGameModeBase::BeginPlay()
{
    int32 Variable = 0;
    if (Variable < 10)
    {
        for (int32 i = 0; i < 10; ++i)
        {
            UE_LOG(LogTemp, Display, TEXT("index: %i"), i);
        }
    }
}
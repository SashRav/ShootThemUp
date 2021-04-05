#pragma once

class STUUtils
{
public:
    template <typename T> static T* GetSTUPlayerController(AActor* PlayerPawn)
    {
        if (!PlayerPawn)
            return nullptr;

        const auto Component = PlayerPawn->GetComponentByClass(T::StaticClass());
        return Cast<T>(Component);
    }
};
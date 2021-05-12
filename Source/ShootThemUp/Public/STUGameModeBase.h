// Shoot Them Up game. All Rights Resived.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "STUCoreTypes.h"
#include "STUGameModeBase.generated.h"


class AAIController;

UCLASS()
class SHOOTTHEMUP_API ASTUGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    ASTUGameModeBase();

    FOnMatchStateChangedSignature OnMatchStateChanged;

    virtual void StartPlay() override;
    virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;

    void Killed(AController* KillerController, AController* VictimController);

    FGameData GetGameData() const { return GameData; }
//    void SetGameData(FGameData NewGameData) { GameData = NewGameData; }
    int32 GetCurrentRoundNum() const { return CurrentRound; }
    int32 GetRoundSecondsRemaining() const { return RoundCoundDown; }

    void RespawnRequest(AController* Controller);

    virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;
    virtual bool ClearPause() override;

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Game")
    TSubclassOf<AAIController> AIControllerClass;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    FGameData GameData;

    UPROPERTY(EditDefaultsOnly, Category = "Game")
    TSubclassOf<APawn> AIPawnClass;

private:
    ESTUMatchState MatchState = ESTUMatchState::WaitingToStart;
    int32 CurrentRound = 1;
    int32 RoundCoundDown = 0;
    FTimerHandle GameRoundTimerHandle;

    void SpawnBots();
    void StartRound();
    void GameTimerUpdate();

    void ResetPlayers();
    void ResetOnePlayer(AController* Controller);

    void CreateTeamsInfo();
    FLinearColor DetermineColorByTeamID(int32 TeamID) const;
    void SetPlayerColor(AController* Controller);

    void LogPlayerInfo();

    void StartRespawn(AController* Controller);

    void GameOver();

    void SetMatchState(ESTUMatchState State);

    void StopAllFire();
};

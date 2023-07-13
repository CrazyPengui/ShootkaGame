
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "STUCoreTypes.h"
#include "SKAGameModeBase.generated.h"


class AAIController;

UCLASS()
class SHOOTKA_API ASKAGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ASKAGameModeBase();

	FOnMatchStateChangedSignature OnMatchStateChanged;

	virtual void StartPlay();

	virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;


	void Killed(AController* Killer, AController* Victim);

	FGameData GetGameData() const { return GameData;  }
	int32 GetCurrentRoundNum() const { return CurrentRound;  }
	int32 GetRoundSecondsRemaining() const { return RoundTimeDown;  }

	void RespawnRequest(AController* Controller);

	virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;

	virtual bool ClearPause() override;


protected:
	UPROPERTY(EditDefaultsOnly, Category = "Game")
		TSubclassOf <AAIController> AIControllerClass;

	UPROPERTY(EditDefaultsOnly, Category = "Game")
		TSubclassOf <APawn> AIPawnClass;

	UPROPERTY(EditDefaultsOnly, Category = "Game")
		FGameData GameData;

private:


	ESTUmatchState MatchState = ESTUmatchState::WaitingToStart;
	int32 CurrentRound = 1;
	int32 RoundTimeDown = 0;

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
	void SetMatchState(ESTUmatchState State);
};

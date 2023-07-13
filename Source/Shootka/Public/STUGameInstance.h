
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "STUCoreTypes.h"
#include "STUGameInstance.generated.h"

class USoundClass;

UCLASS()
class SHOOTKA_API USTUGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	FLevelData GetStartupLevel() const { return StartupLevel; }
	void  SetStartupLevel(const FLevelData& Data) { StartupLevel = Data; }

	TArray<FLevelData> GetLevelsData() const { return LevelsData; }

	FName GetMMLevelName() const { return MMLevelName; }

	void ToggleVolume();


protected:

	UPROPERTY(EditDefaultsOnly, Category = "Game")
		TArray<FLevelData> LevelsData;


	UPROPERTY(EditDefaultsOnly, Category = "Game")
		FName StartupLevelName = NAME_None;
		
	UPROPERTY(EditDefaultsOnly, Category = "Game")
		FName MMLevelName = NAME_None;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundClass* MasterSoundClass;


private:
	FLevelData StartupLevel;
};

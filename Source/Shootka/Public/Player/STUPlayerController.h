// Shootka Game. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "STUCoreTypes.h"
#include "STUPlayerController.generated.h"


class USTURespawnComponent;

UCLASS()
class SHOOTKA_API ASTUPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ASTUPlayerController();

protected:
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		USTURespawnComponent* RespawnComponent;


		virtual void BeginPlay() override;
		virtual void SetupInputComponent() override;

private:
	void OnPauseGame();
	void OnMatchStateChanged(ESTUmatchState State)	;
	void OnMuteSound();
};

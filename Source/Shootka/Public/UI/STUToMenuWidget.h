// Shootka Game. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUToMenuWidget.generated.h"

class UButton;

UCLASS()
class SHOOTKA_API USTUToMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
		UButton* ToMainMenuButton;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
		void OnPauseGame();
};

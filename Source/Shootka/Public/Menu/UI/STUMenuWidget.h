// Shootka Game. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "UI/STUBaseWidget.h"
#include "STUCoreTypes.h"
#include "STUMenuWidget.generated.h"


class UButton;
class UHorizontalBox;
class USTUGameInstance;
class USTULevelItemWidget;
class USoundCue;

UCLASS()
class SHOOTKA_API USTUMenuWidget : public USTUBaseWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
		UButton* StartGameButton;

	UPROPERTY(meta = (BindWidget))
		UButton* ExitGameButton;

	UPROPERTY(meta = (BindWidget))
		UHorizontalBox* LevelItemsBox;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> LevelItemWidgetClass;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
		UWidgetAnimation* HideAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
		USoundCue* StartGameSound;



	virtual void NativeOnInitialized() override;
	virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

private:
	UPROPERTY()
		TArray<USTULevelItemWidget*> LevelItemWidgets;

	UFUNCTION()
		void OnStartGame();

	UFUNCTION()
		void OnExitGame();

	void InitLevelItems();
	void OnLevelSelected(const FLevelData& Data);

	USTUGameInstance* GetSTUGameInstance() const;
};

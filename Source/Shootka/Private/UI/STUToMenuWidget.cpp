// Shootka Game. All rights reserved!


#include "UI/STUToMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "STUGameInstance.h"


void USTUToMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (ToMainMenuButton)
	{
		ToMainMenuButton->OnClicked.AddDynamic(this, &USTUToMenuWidget::OnPauseGame);
	}
}

void USTUToMenuWidget::OnPauseGame()
{
	if (!GetWorld()) return;

	const auto STUGameInstance = GetWorld()->GetGameInstance<USTUGameInstance>();

	if (!STUGameInstance) return;

	if (STUGameInstance->GetMMLevelName().IsNone())
	{
		return;
	}

	UGameplayStatics::OpenLevel(this, STUGameInstance->GetMMLevelName());
}

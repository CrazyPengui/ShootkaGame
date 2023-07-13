// Shootka Game. All rights reserved!


#include "UI/STUGameDataWidget.h"
#include "SKAGameModeBase.h"
#include "Player/STUPlayerState.h"



int32 USTUGameDataWidget::GetKillsNum() const
{
	const auto PlayerState = GetSTUPlayerState();
	return PlayerState ? PlayerState->GetKillsNum() : 0;
}

int USTUGameDataWidget::GetCurrentRoundNum() const
{
	const auto GameMode = GetSKAGameModeBase();
	return GameMode ? GameMode->GetCurrentRoundNum() : 0;
}

int32 USTUGameDataWidget::GetTotalRoundsNum() const
{
	const auto GameMode = GetSKAGameModeBase();
	return GameMode ? GameMode->GetGameData().RoundsNum : 0;
}

int32 USTUGameDataWidget::GetRoundSecondsRemaining() const
{
	const auto GameMode = GetSKAGameModeBase();
	return GameMode ? GameMode->GetRoundSecondsRemaining() : 0;
}

ASKAGameModeBase* USTUGameDataWidget::GetSKAGameModeBase() const
{
	return GetWorld() ? Cast<ASKAGameModeBase>(GetWorld()->GetAuthGameMode()) : nullptr;
}

ASTUPlayerState* USTUGameDataWidget::GetSTUPlayerState() const 
{
	return GetOwningPlayer() ? Cast<ASTUPlayerState>(GetOwningPlayer()->PlayerState) : nullptr;
}

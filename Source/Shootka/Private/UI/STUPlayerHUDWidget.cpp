// Shootka Game. All rights reserved!


#include "UI/STUPlayerHUDWidget.h"
#include "Components/STUHealthActorComponent.h"
#include "Components/STUWeaponComponent.h"
#include "STUUtils.h"
#include "Components/ProgressBar.h"






float USTUPlayerHUDWidget::GetHealthPercent() const
{
	const auto HealthComponent = STUUtils::GetSTUPlayercomponent<USTUHealthActorComponent>(GetOwningPlayerPawn());
	if (!HealthComponent) return 0.0f;

	return HealthComponent->GetHealthPercent();
}




bool USTUPlayerHUDWidget::GetCurrentWeaponUIData(FWeaponUIData& UIData) const
{

	const auto WeaponComponent = STUUtils::GetSTUPlayercomponent<USTUWeaponComponent>(GetOwningPlayerPawn());
	if (!WeaponComponent) return false;

	return WeaponComponent->GetCurrentWeaponUIData(UIData);
}




bool USTUPlayerHUDWidget::GetCurrentWeaponAmmoData(FAmmoData& AmmoData) const
{
	const auto WeaponComponent = STUUtils::GetSTUPlayercomponent<USTUWeaponComponent>(GetOwningPlayerPawn());
	if (!WeaponComponent) return false;

	return WeaponComponent->GetCurrentWeaponAmmoData(AmmoData);
}

bool USTUPlayerHUDWidget::IsPlayerAlive() const
{
	const auto HealthComponent = STUUtils::GetSTUPlayercomponent<USTUHealthActorComponent>(GetOwningPlayerPawn());
	return HealthComponent && !HealthComponent->IsDead();
}

bool USTUPlayerHUDWidget::IsPlayerSpectating() const
{
	const auto Controller = GetOwningPlayer();
	return Controller && Controller->GetStateName() == NAME_Spectating;
}

FString USTUPlayerHUDWidget::FormatBullets(int32 BulletsNum) const
{
	const int32 MaxLen = 2;
	const TCHAR PrefixSymbol = '0';

	auto BulletStr = FString::FromInt(BulletsNum);
	const auto SymbolsNumToAdd = MaxLen - BulletStr.Len();

	if (SymbolsNumToAdd > 0)
	{
		BulletStr = FString::ChrN(SymbolsNumToAdd, PrefixSymbol).Append(BulletStr);
	}
	return BulletStr;
}


void USTUPlayerHUDWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if (GetOwningPlayer())
	{
		GetOwningPlayer()->GetOnNewPawnNotifier().AddUObject(this, &USTUPlayerHUDWidget::OnNewPawn);
		OnNewPawn(GetOwningPlayerPawn());
	}

}

void USTUPlayerHUDWidget::OnHealthChanged(float Health, float HealthDelta)
{
	if (HealthDelta < 0.0f)
	{
		OnTakeDamage();

		if (!IsAnimationPlaying(DamageAnimation))
		{
			PlayAnimation(DamageAnimation);
		}
	}
	
	UpdateHealthBar();
}

void USTUPlayerHUDWidget::OnNewPawn(APawn* NewPawn)
{
	const auto HealthComponent = STUUtils::GetSTUPlayercomponent<USTUHealthActorComponent>(NewPawn);
	if (HealthComponent)
	{
		HealthComponent->OnHealthChanged.AddUObject(this, &USTUPlayerHUDWidget::OnHealthChanged);
	}

	UpdateHealthBar();
}

void USTUPlayerHUDWidget::UpdateHealthBar()
{
	if (HealthProgressBar)
	{
		HealthProgressBar->SetFillColorAndOpacity(GetHealthPercent() > PercentColorThreshold ? GoodColor : BadColor);
	}
}




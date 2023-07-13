// Shootka Game. All rights reserved!


#include "Components/STUHealthActorComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Camera/CameraShakeBase.h"
#include "SKAGameModeBase.h"
#include "Perception/AISense_Damage.h"



DEFINE_LOG_CATEGORY_STATIC(LogHealthActorComponent, All, All);

USTUHealthActorComponent::USTUHealthActorComponent()
{

	PrimaryComponentTick.bCanEverTick = false;

}



void USTUHealthActorComponent::BeginPlay()
{
	Super::BeginPlay();

	check(MaxHealth > 0);

	SetHealth(MaxHealth);

	
	AActor* ComponentOwner = GetOwner();
	if (ComponentOwner)
	{
		ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &USTUHealthActorComponent::OnTakeAnyDamage);
	}


}

bool USTUHealthActorComponent::TryToAddHP(float HPAmount)
{
	if (IsDead() || IsHPFull()) return false;

	SetHealth(Health + HPAmount);
	return true;
}

bool USTUHealthActorComponent::IsHPFull() const
{
	return FMath::IsNearlyEqual(Health, MaxHealth);
}

void USTUHealthActorComponent::OnTakeAnyDamage(
	AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0.0f || IsDead() || !GetWorld()) return;

	SetHealth(Health - Damage);


	GetWorld()->GetTimerManager().ClearTimer(HealTimerHandle);

	if (IsDead())
	{
		Killed(InstigatedBy);
		OnDeath.Broadcast();
	}
	else if(AutoHeal )
	{
		GetWorld()->GetTimerManager().SetTimer(HealTimerHandle, this, &USTUHealthActorComponent::HealUpdate, HealUpdateTime, true, HealDelay);
	}
	PlayCameraShake();
	ReportDamageEvent(Damage, InstigatedBy);
	
}

void USTUHealthActorComponent::HealUpdate()
{
	SetHealth(Health + HealModifier);

	if (IsHPFull() && GetWorld())
	{	
		GetWorld()->GetTimerManager().ClearTimer(HealTimerHandle);
	}

}

void USTUHealthActorComponent::SetHealth(float NewHealth)
{
	const auto NextHealth = FMath::Clamp(NewHealth, 0.0f, MaxHealth);
	const auto HealthDelta = NextHealth - Health;

	Health = NextHealth;
	OnHealthChanged.Broadcast(Health, HealthDelta);
}

void USTUHealthActorComponent::PlayCameraShake()
{
	if (IsDead()) return;

	const auto Player = Cast<APawn>(GetOwner());
	if (!Player) return;

	const auto Controller = Player->GetController<APlayerController>();
	if (!Controller || !Controller->PlayerCameraManager) return;

	Controller->PlayerCameraManager->StartCameraShake(CameraShake);

}

void USTUHealthActorComponent::Killed(AController* Killer)
{
	if (!GetWorld()) return;
	const auto GameMode = Cast<ASKAGameModeBase>(GetWorld()->GetAuthGameMode());
	if (!GameMode) return;

	const auto Player = Cast<APawn>(GetOwner());
	const auto VictimController = Player ? Player->Controller : nullptr;

	GameMode->Killed(Killer, VictimController);
}

void USTUHealthActorComponent::ReportDamageEvent(float Damage, AController* InstigatedBy)
{
	if (!InstigatedBy || !InstigatedBy->GetPawn() || !GetOwner()) return;

	UAISense_Damage::ReportDamageEvent(GetWorld(),
		GetOwner(),
		InstigatedBy->GetPawn(),
		Damage,
		InstigatedBy->GetPawn()->GetActorLocation(),
		GetOwner()->GetActorLocation());
}

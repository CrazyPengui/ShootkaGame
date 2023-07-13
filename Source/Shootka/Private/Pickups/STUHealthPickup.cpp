// Shootka Game. All rights reserved!


#include "Pickups/STUHealthPickup.h"
#include "Components/STUHealthActorComponent.h"
#include "STUUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthPickup, All, All);



bool ASTUHealthPickup::GivePickupTo(APawn* PlayerPawn)
{
	const auto HealthComponent = STUUtils::GetSTUPlayercomponent<USTUHealthActorComponent>(PlayerPawn);
	if (!HealthComponent || HealthComponent->IsDead()) return false;


	return HealthComponent->TryToAddHP(HPAmount);
}

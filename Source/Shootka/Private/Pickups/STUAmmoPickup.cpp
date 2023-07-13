// Shootka Game. All rights reserved!


#include "Pickups/STUAmmoPickup.h"
#include "Components/STUHealthActorComponent.h"
#include "Components/STUWeaponComponent.h"
#include "STUUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogAmmoPickup, All, All);


bool ASTUAmmoPickup::GivePickupTo(APawn* PlayerPawn)
{
	const auto HealthComponent = STUUtils::GetSTUPlayercomponent<USTUHealthActorComponent>(PlayerPawn);
	if (!HealthComponent || HealthComponent->IsDead()) return false;



	const auto WeaponComponent = STUUtils::GetSTUPlayercomponent<USTUWeaponComponent>(PlayerPawn);	
	if (!WeaponComponent) return false;

	return WeaponComponent->TryToAddAmmo(WeaponType, ClipsAmount);
}

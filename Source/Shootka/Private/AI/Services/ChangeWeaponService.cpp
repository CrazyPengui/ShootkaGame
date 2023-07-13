// Shootka Game. All rights reserved!

#include "AIController.h"
#include "Components/STUWeaponComponent.h"
#include "AI/Services/ChangeWeaponService.h"
#include "STUUtils.h"

UChangeWeaponService::UChangeWeaponService()
{
	NodeName = "Change Weapon";
}

void UChangeWeaponService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	const auto Controller = OwnerComp.GetAIOwner();
	if (Controller)
	{
		const auto WeaponComponent = STUUtils::GetSTUPlayercomponent<USTUWeaponComponent>(Controller->GetPawn());
		if (WeaponComponent && Probability >= FMath::FRand() )
		{
			WeaponComponent->NextWeapon();
		}
	}

	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

}





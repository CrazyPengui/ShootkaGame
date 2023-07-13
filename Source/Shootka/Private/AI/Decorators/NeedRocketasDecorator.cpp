// Shootka Game. All rights reserved!


#include "AI/Decorators/NeedRocketasDecorator.h"
#include "AIController.h"
#include "Components/STUWeaponComponent.h"
#include "STUUtils.h"
#include "STUCoreTypes.h"


UNeedRocketasDecorator::UNeedRocketasDecorator()
{
	NodeName = "Need Rocketas";
}

bool UNeedRocketasDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	const auto Controller = OwnerComp.GetAIOwner();
	if (!Controller) return false;



	const auto WeaponComponent = STUUtils::GetSTUPlayercomponent<USTUWeaponComponent>(Controller->GetPawn());
	if (!WeaponComponent) return false;

	return WeaponComponent->NeedRocketas(WeaponType);
}




#include "AI/Decorators/NeedAmmosDecorator.h"
#include "AIController.h"
#include "Components/STUWeaponComponent.h"
#include "STUUtils.h"
#include "STUCoreTypes.h"

UNeedAmmosDecorator::UNeedAmmosDecorator()
{
	NodeName = "Need Ammos";
}

bool UNeedAmmosDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	const auto Controller = OwnerComp.GetAIOwner();
	if (!Controller) return false;



	const auto WeaponComponent = STUUtils::GetSTUPlayercomponent<USTUWeaponComponent>(Controller->GetPawn());
	if (!WeaponComponent) return false;

	return WeaponComponent->NeedAmmos(WeaponType);
}

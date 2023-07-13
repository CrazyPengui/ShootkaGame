// Shootka Game. All rights reserved!


#include "AI/Decorators/STUHPDecorator.h"
#include "AIController.h"
#include "Components/STUHealthActorComponent.h"
#include "STUUtils.h"

USTUHPDecorator::USTUHPDecorator()
{
	NodeName = "Health Percent";
}

bool USTUHPDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	const auto Controller = OwnerComp.GetAIOwner();
	if (!Controller) return false;

	const auto HealthComponent = STUUtils::GetSTUPlayercomponent<USTUHealthActorComponent>(Controller->GetPawn());
	if(!HealthComponent || HealthComponent->IsDead()) return false;

	return HealthComponent->GetHealthPercent() <= HP;
}


#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "STUHPDecorator.generated.h"

UCLASS()
class SHOOTKA_API USTUHPDecorator : public UBTDecorator
{
	GENERATED_BODY()

		USTUHPDecorator();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		float HP = 0.6f;

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

};

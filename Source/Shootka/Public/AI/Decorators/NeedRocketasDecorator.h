
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "NeedRocketasDecorator.generated.h"


class ASTUBaseWeapon;

UCLASS()
class SHOOTKA_API UNeedRocketasDecorator : public UBTDecorator
{
	GENERATED_BODY()


public:
		UNeedRocketasDecorator();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		TSubclassOf<ASTUBaseWeapon>WeaponType;

		

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	
};

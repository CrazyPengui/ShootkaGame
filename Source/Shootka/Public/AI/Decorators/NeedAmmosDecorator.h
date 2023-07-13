// Shootka Game. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "NeedAmmosDecorator.generated.h"

class ASTUBaseWeapon;

UCLASS()
class SHOOTKA_API UNeedAmmosDecorator : public UBTDecorator
{
	GENERATED_BODY()
	


public:
	UNeedAmmosDecorator();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		TSubclassOf<ASTUBaseWeapon>WeaponType;



	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;


};

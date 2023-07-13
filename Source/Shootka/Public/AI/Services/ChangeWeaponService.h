
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "ChangeWeaponService.generated.h"

UCLASS()
class SHOOTKA_API UChangeWeaponService : public UBTService
{
	GENERATED_BODY()

public:
	UChangeWeaponService();


	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (ClampMin = "0.01", ClampMax = "1"))
		float Probability = 0.7f;
};

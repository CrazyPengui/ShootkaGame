
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "STUFEService.generated.h"


UCLASS()
class SHOOTKA_API USTUFEService : public UBTService
{
	GENERATED_BODY()
	

public:
	USTUFEService();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		FBlackboardKeySelector EnemyActorKey;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

};

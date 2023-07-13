// Shootka Game. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "Pickups/STUBasePickup.h"
#include "STUHealthPickup.generated.h"



UCLASS()
class SHOOTKA_API ASTUHealthPickup : public ASTUBasePickup
{
	GENERATED_BODY()
	

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (ClampMin = "1.0", ClampMax = "1000.0"))
		int32 HPAmount = 100.0f;



private:
	virtual bool GivePickupTo(APawn* PlayerPawn) override;


};

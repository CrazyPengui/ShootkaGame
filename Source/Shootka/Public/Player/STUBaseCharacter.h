// Shootka Game. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "STUBaseCharacter.generated.h"


class USTUHealthActorComponent;
class USTUWeaponComponent;
class USoundCue;


UCLASS()
class SHOOTKA_API ASTUBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASTUBaseCharacter(const FObjectInitializer& ObjInit);

protected:




	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		USTUHealthActorComponent* HealthComponent;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		USTUWeaponComponent* WeaponComponent;


	UPROPERTY(EditDefaultsOnly, Category = "Animation")
		UAnimMontage* DeathAnimMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
		FVector2D LandedDamageVelocity = FVector2D(1000.0f, 2000.0f);

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
		FVector2D LandedDamage = FVector2D(10.0f, 228.0f);

	UPROPERTY(EditDefaultsOnly, Category = "Material")
		FName MaterialColorName = "Paint Color";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
		USoundCue* DeathSound;



	virtual void OnDeath();



	virtual void BeginPlay() override;

	virtual void OnHealthChanged(float Health, float HealthDelta);

public:	
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintCallable, Category = "Movement")
	virtual bool IsRunning() const;

	UFUNCTION(BlueprintCallable, Category = "Movement")
		float GetMovementDirection() const;

	void SetPlayerColor(const FLinearColor& Color);


private:

	UFUNCTION()
	void OnGroundLanded(const FHitResult& Hit);
	

};


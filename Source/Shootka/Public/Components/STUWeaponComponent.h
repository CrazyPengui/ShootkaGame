// Shootka Game. All rights reserved!

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STUCoreTypes.h"
#include "STUWeaponComponent.generated.h"


class ASTUBaseWeapon;



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTKA_API USTUWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USTUWeaponComponent();

	virtual void StartFire();
	void StopFire();
	virtual void NextWeapon();
	void Reload();

	bool GetCurrentWeaponUIData(FWeaponUIData& UIData) const;
	bool GetCurrentWeaponAmmoData(FAmmoData& AmmoData) const;

	bool TryToAddAmmo(TSubclassOf<ASTUBaseWeapon>WeaponType, int32 ClipsAmount);
	bool NeedRocketas(TSubclassOf<ASTUBaseWeapon>WeaponType);
	bool NeedAmmos(TSubclassOf<ASTUBaseWeapon>WeaponType);

	void Zoom(bool Enabled);

protected:


	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		TArray<FWeaponData> WeaponData;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		FName WeaponEquipSocketName = "WeaponSocket";

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		FName WeaponArmorySocketName = "ArmorySocket";

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
		UAnimMontage* EquipAnimMontage;

	UPROPERTY()
		ASTUBaseWeapon* CurrentWeapon = nullptr;

	UPROPERTY()
		TArray<ASTUBaseWeapon*> Weapons;


	int32 CurrentWeaponIndex = 0;


	bool CanFire() const;
	bool CanEquip() const;
	void EquipWeapon(int32 WeaponIndex);
		
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;




public:	

private:


	UPROPERTY()
		UAnimMontage* CurrentReloadAnimMontage = nullptr;

	bool EquipAnimInProgress = false;
	bool ReloadAnimInProgress = false;

	void SpawnWeapons();
	void AttachWeaponToSocket(ASTUBaseWeapon* Weapon, USceneComponent* SceneComponent, const FName& SocketName);
	

	void PlayAnimMontage(UAnimMontage* Animation);
	void InitAnimations();
	void OnEquipFinished(USkeletalMeshComponent* MeshComponent);
	void OnReloadFinished(USkeletalMeshComponent* MeshComponent);



	bool CanReload() const;

	void OnEmptyClip(ASTUBaseWeapon* AmmoEmptyWeapon);
	void ChangeClip();


};

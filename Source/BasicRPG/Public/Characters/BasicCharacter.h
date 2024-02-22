// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterTypes.h"
#include "BasicCharacter.generated.h"



UCLASS()
class BASICRPG_API ABasicCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABasicCharacter();
protected:
	virtual void BeginPlay() override;
public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void EKeyPressed();
	void Attack();

	bool CanAttack();
	bool CanDisarm();
	bool CanArm();

	void PlayAttackMontage();
	UFUNCTION(BlueprintCallable)
	void AttackEnd();

	void PlayEquipMontage(FName SectionName);
	UFUNCTION(BlueprintCallable)
	void Disarm();
	UFUNCTION(BlueprintCallable)
	void Arm();
	UFUNCTION(BlueprintCallable)
	void FinishEquipping();

private:
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* ViewCamera;
	UPROPERTY(VisibleAnywhere, Category = Hair)
	class UGroomComponent* Hair;
	UPROPERTY(VisibleAnywhere, Category = Hair)
	class UGroomComponent* Eyebrows;
	UPROPERTY(VisibleInstanceOnly)
	class AItem* OverlappingItem;
	UPROPERTY(VisibleAnywhere, Category = Weapon)
	class AWeapon* EquipedWeapon;
	
	UPROPERTY(EditDefaultsOnly, Category = Montages)
	class UAnimMontage* AttackMontage;
	UPROPERTY(EditDefaultsOnly, Category = Montages)
	class UAnimMontage* EquipMontage;
public:
	FORCEINLINE void SetOverlappingItem(AItem* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BasicAnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

#include "Characters/BasicCharacter.h"

void UBasicAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	BasicCharacter = Cast<ABasicCharacter>(TryGetPawnOwner());
	if (BasicCharacter)
	{
		BasicCharacterMovement = BasicCharacter->GetCharacterMovement();
	}
}

void UBasicAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (BasicCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(BasicCharacterMovement->Velocity);
		IsFalling = BasicCharacterMovement->IsFalling();
	}
}

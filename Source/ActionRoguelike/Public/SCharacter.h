// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

// ���ٱ���ʱ��ķ�ʽ,����ʹ��include
class UCameraComponent;
class USpringArmComponent;
class USInteractionComponent;
class UAnimMontage;
class USAttributeComponent;

UCLASS()
class ACTIONROGUELIKE_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void MoveForward(float Value);

	void MoveRight(float Value);

	void PrimaryAttack();

	void PrimaryAttack_TimeElapsed();

	void PrimaryInteract();

	void BlackHoleAttack();

	void BlackholeAttack_TimeElapsed();

	void Dash();

	void Dash_TimeElapsed();

	// Re-use spawn logic between attacks
	void SpawnProjectile(TSubclassOf<AActor> ClassToSpawn);

protected:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
	USInteractionComponent* InteractionComp;

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
		TSubclassOf<AActor> BlackHoleProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
		TSubclassOf<AActor> DashProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
		UAnimMontage* AttackAnim;

	UPROPERTY(EditDefaultsOnly, Category = "Attack")
		float AttackAnimDelay;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USAttributeComponent* AttributeComp;

	FTimerHandle TimerHandle_PrimaryAttack;		// ����ɫ���ˣ��ǵ����ٶ�ʱ��
	FTimerHandle TimerHandle_BlackholeAttack;
	FTimerHandle TimerHandle_Dash;


};

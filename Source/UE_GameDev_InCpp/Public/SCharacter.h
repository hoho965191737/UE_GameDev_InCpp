// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

// 减少编译时间的方式,而不使用include
class USpringArmComponent;
class UCameraComponent;
class USInteractionComponent;
class UAnimMontage;


UCLASS()
class UE_GAMEDEV_INCPP_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);
	void MoveRight(float value);

protected:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* springArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* cameraComp;

	UPROPERTY(VisibleAnywhere)
	USInteractionComponent* interactionComp;

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> projectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
	UAnimMontage* attackAnim;

	FTimerHandle TimerHandle_PrimaryAttack;	// 当角色死了，记得销毁定时器

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void PrimaryAttack();
	void PrimaryAttack_TimeElapsed();
	void PrimaryInteract();

};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SMagicProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;

UCLASS()
class UE_GAMEDEV_INCPP_API ASMagicProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASMagicProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere)
	USphereComponent* sphereComp;

	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* movementComp;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* effectComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

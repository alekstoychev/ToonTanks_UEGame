// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void UpdateDamage(float NewDamage) { Damage = NewDamage; }

	UPROPERTY(VisibleAnywhere, Category = "Combat")
	uint8 OwnerType = 0;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	class UProjectileMovementComponent* ProjectileMovementComponent;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float Damage = 50.f;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	class UParticleSystem* HitParticles;
	
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	class UParticleSystemComponent* SmokeTrail;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	class USoundBase* FireSound;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	USoundBase* HitSound;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TSubclassOf<class UCameraShakeBase> HeavyHitCameraShakeClass;
};

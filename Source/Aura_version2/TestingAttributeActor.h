// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


UENUM(BlueprintType)
enum class EEffectApplicationPolicy :uint8
{
	ApplyOnOverlap,
	ApplyOnEndOverlap,
	DoNotApply
};

UENUM(BlueprintType)
enum class EEffectRemovePolicy :uint8
{
	RemoveOnOverlap,	
	DoNotRemove
};


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "TestingAttributeActor.generated.h"

class UGameplayEffect;
class USphereComponent;
class UAbilitySystemComponent;


UCLASS()
class AURA_VERSION2_API ATestingAttributeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestingAttributeActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Applied Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Applied Effects")
	TSubclassOf<UGameplayEffect> PeriodGameplayEffectClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Applied Effects")
	TSubclassOf<UGameplayEffect>InfiniteGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Applied Effects")
	EEffectApplicationPolicy InfiniteEffectApplicationPolicy=EEffectApplicationPolicy::DoNotApply;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Applied Effects")
	EEffectRemovePolicy InfiniteEffectRemovePolicy=EEffectRemovePolicy::DoNotRemove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Applied Effects")
	bool bDestroyOnEffectRemoval = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ActorLevel = 1.f;

	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveEffectHandles;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* ToTarget, TSubclassOf<UGameplayEffect> GameplayEffectClass);
	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* Target);
	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* Target);
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "TestingAttributeActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemInterface.h"
#include "AuraAttributeSet.h"
#include "Components/SphereComponent.h"

// Sets default values
ATestingAttributeActor::ATestingAttributeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("Scene")));
}

// Called when the game starts or when spawned
void ATestingAttributeActor::BeginPlay()
{
	Super::BeginPlay();
}

void ATestingAttributeActor::ApplyEffectToTarget(AActor* ToTarget, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent*  TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(ToTarget);
	if(TargetASC==nullptr)return;

	check(GameplayEffectClass);
	FGameplayEffectContextHandle GameplayEffectContextHandle = TargetASC->MakeEffectContext();
	GameplayEffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, ActorLevel, GameplayEffectContextHandle);
	FActiveGameplayEffectHandle ActiveGameplayEffectHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

	const bool bIsInfinity = EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy==EGameplayEffectDurationType::Infinite;
	if(bIsInfinity && InfiniteEffectRemovePolicy==EEffectRemovePolicy::RemoveOnOverlap)
	{
		ActiveEffectHandles.Add(ActiveGameplayEffectHandle, TargetASC);
	}
}

void ATestingAttributeActor::OnOverlap(AActor* Target)
{
	if(InfiniteEffectApplicationPolicy ==EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(Target, InfiniteGameplayEffectClass);
	}
}

void ATestingAttributeActor::OnEndOverlap(AActor* Target)
{
	if(InfiniteEffectApplicationPolicy ==EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(Target, InfiniteGameplayEffectClass);
	}
	if(InfiniteEffectRemovePolicy == EEffectRemovePolicy::RemoveOnOverlap)
	{
		UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
		if(!IsValid(TargetASC))return;

		TArray<FActiveGameplayEffectHandle> HandleToRemove;
		for(TPair<FActiveGameplayEffectHandle, UAbilitySystemComponent*> HandlePair : ActiveEffectHandles )
		{
			if(TargetASC==HandlePair.Value)
			{
				TargetASC->RemoveActiveGameplayEffect(HandlePair.Key);
				HandleToRemove.Add(HandlePair.Key);
			}
		}
		for(FActiveGameplayEffectHandle& Handle : HandleToRemove)
		{
			ActiveEffectHandles.FindAndRemoveChecked(Handle);
		}
	}
}




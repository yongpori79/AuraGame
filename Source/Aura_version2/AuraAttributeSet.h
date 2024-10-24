// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "AuraAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


USTRUCT(Blueprintable)
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties(){}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayEffectContextHandle EffectContextHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAbilitySystemComponent* SourceASC = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* SourceAvatarActor =nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AController* SourceController = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAbilitySystemComponent* TargetASC = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* TargetAvatarActor =nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AController* TargetController = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ACharacter*TargetCharacter = nullptr;
	
};



UCLASS()
class AURA_VERSION2_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UAuraAttributeSet();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing= OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing= OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing= OnRep_Mana)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing= OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana)


	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth);
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana);
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana);

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties Props);
};

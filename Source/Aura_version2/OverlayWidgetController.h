// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

/**
 * 
 */

struct FOnAttributeChangeData;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);

UCLASS(BlueprintType, Blueprintable)
class AURA_VERSION2_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()
public:
	virtual void BroadcastInitialValue() override;
	virtual void BindCallbackDependencies() override;

	UPROPERTY(EditAnywhere, BlueprintAssignable)
	FOnHealthChangedSignature OnHealthChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable)
	FOnMaxHealthChangedSignature OnMaxHealthChanged;

	void HealthChange(const FOnAttributeChangeData& data) ;
	void MaxHealthChange(const FOnAttributeChangeData& data) ;
};

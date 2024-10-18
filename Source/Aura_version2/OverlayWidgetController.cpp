// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlayWidgetController.h"

#include "AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValue()
{
	const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(AttributeSet);
	if(AuraAttributeSet)
	{
		OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
		OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
	}
	
}

void UOverlayWidgetController::BindCallbackDependencies()
{
	const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(AttributeSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthAttribute()).AddUObject(this,
		&UOverlayWidgetController::HealthChange);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxHealthAttribute()).AddUObject(this,
		&UOverlayWidgetController::MaxHealthChange);
}

void UOverlayWidgetController::HealthChange(const FOnAttributeChangeData& data)
{
	OnHealthChanged.Broadcast(data.NewValue);
}

void UOverlayWidgetController::MaxHealthChange(const FOnAttributeChangeData& data)
{
	OnMaxHealthChanged.Broadcast(data.NewValue);
}

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
		OnManaChanged.Broadcast((AuraAttributeSet->GetMana()));
		OnMaxManaChanged.Broadcast(AuraAttributeSet->GetMaxMana());
	}
	
}

void UOverlayWidgetController::BindCallbackDependencies()
{
	const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(AttributeSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthAttribute()).AddUObject(this,
		&UOverlayWidgetController::HealthChange);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxHealthAttribute()).AddUObject(this,
		&UOverlayWidgetController::MaxHealthChange);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetManaAttribute()).AddUObject(this,
        &UOverlayWidgetController::ManaChange);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxManaAttribute()).AddUObject(this,
        &UOverlayWidgetController::MaxManaChange);
}

void UOverlayWidgetController::HealthChange(const FOnAttributeChangeData& data)
{
	OnHealthChanged.Broadcast(data.NewValue);
}

void UOverlayWidgetController::MaxHealthChange(const FOnAttributeChangeData& data)
{
	OnMaxHealthChanged.Broadcast(data.NewValue);
}

void UOverlayWidgetController::ManaChange(const FOnAttributeChangeData& data)
{
	OnManaChanged.Broadcast(data.NewValue);
}

void UOverlayWidgetController::MaxManaChange(const FOnAttributeChangeData& data)
{
	OnMaxManaChanged.Broadcast(data.NewValue);
}

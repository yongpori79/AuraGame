// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraWidgetController.h"

UAuraWidgetController::UAuraWidgetController()
{
}

void UAuraWidgetController::SetAuraWidgetControllerParameters(const FAuraWidgetControllerParam& params)
{
	PlayerController = params.PlayerController;
	PlayerState = params.PlayerState;
	AbilitySystemComponent = params.AbilitySystemComponent;
	AttributeSet = params.AttributeSet;
}

void UAuraWidgetController::BroadcastInitialValue()
{
}

void UAuraWidgetController::BindCallbackDependencies()
{
	
}

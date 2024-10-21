// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraWidgetController.h"

UAuraWidgetController::UAuraWidgetController()
{
}

void UAuraWidgetController::SetAuraWidgetControllerParameters(const FAuraWidgetControllerParam& Params)
{
	PlayerController = Params.PlayerController;
	PlayerState = Params.PlayerState;
	AbilitySystemComponent = Params.AbilitySystemComponent;
	AttributeSet = Params.AttributeSet;
}

void UAuraWidgetController::BroadcastInitialValue()
{
}

void UAuraWidgetController::BindCallbackDependencies()
{
	
}

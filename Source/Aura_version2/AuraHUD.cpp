// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraHUD.h"

#include "AuraUserWidget.h"
#include "OverlayWidgetController.h"
#include "Blueprint/UserWidget.h"

AAuraHUD::AAuraHUD()
{
}



UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FAuraWidgetControllerParam& Param)
{
	if(!AuraOverlayWidgetController)
	{
		AuraOverlayWidgetController = NewObject<UOverlayWidgetController>(this, AuraOverlayWidgetControllerClass);
		AuraOverlayWidgetController->SetAuraWidgetControllerParameters(Param);
		AuraOverlayWidgetController->BindCallbackDependencies();

		return AuraOverlayWidgetController;
	}

	return AuraOverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* InPlayerController, APlayerState* InPlayerState,
	UAbilitySystemComponent* InAbilitySystemComponent, UAttributeSet* InAttributeSet)
{
	checkf(AuraOverlayWidgetClass, TEXT("AuraOverlayWidgetClass uninitialised, please fill out BP_AuraHud"));
	checkf(AuraOverlayWidgetControllerClass, TEXT("Widget Controller class uninitialised, please fill out BP_AuraHud"));

	
	UAuraUserWidget* Widget = CreateWidget<UAuraUserWidget>(GetWorld(), AuraOverlayWidgetClass);
	if(Widget)
	{
		AuraOverlayWidget = Widget;
		const FAuraWidgetControllerParam Parameters(InPlayerController, InPlayerState, InAbilitySystemComponent, InAttributeSet);
		UOverlayWidgetController* WidgetController = GetOverlayWidgetController(Parameters);
		AuraOverlayWidget->SetWidgetController(WidgetController);
		WidgetController->BroadcastInitialValue();
		Widget->AddToViewport();
	}
		
}

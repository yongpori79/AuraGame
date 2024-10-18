// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
struct FAuraWidgetControllerParam;
class UOverlayWidgetController;
class UAuraUserWidget;
/**
 * 
 */
UCLASS()
class AURA_VERSION2_API AAuraHUD : public AHUD
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAuraUserWidget> AuraOverlayWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UAuraUserWidget> AuraOverlayWidgetClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UOverlayWidgetController> AuraOverlayWidgetController;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UOverlayWidgetController> AuraOverlayWidgetControllerClass;
	AAuraHUD();
	

	UOverlayWidgetController* GetOverlayWidgetController(const FAuraWidgetControllerParam& Param);

	void InitOverlay(APlayerController* InPlayerController, APlayerState* InPlayerState,
		UAbilitySystemComponent* InAbilitySystemComponent, UAttributeSet* InAttributeSet);
};

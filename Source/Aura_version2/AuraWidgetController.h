// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AuraWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */

USTRUCT(BlueprintType)
struct FAuraWidgetControllerParam
{
	GENERATED_BODY()
	FAuraWidgetControllerParam(){}
	FAuraWidgetControllerParam(APlayerController* InPlayerController, APlayerState* InPlayerState, UAbilitySystemComponent* InAbilitySystemComponent, UAttributeSet* InAttributeSet):
	    PlayerController(InPlayerController), PlayerState(InPlayerState), AbilitySystemComponent(InAbilitySystemComponent), AttributeSet(InAttributeSet) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerController> PlayerController;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerState> PlayerState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAttributeSet> AttributeSet;
};


UCLASS()
class AURA_VERSION2_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerController> PlayerController;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerState> PlayerState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAttributeSet> AttributeSet;

	UAuraWidgetController();
	UFUNCTION(BlueprintCallable)
	void SetAuraWidgetControllerParameters(const FAuraWidgetControllerParam& Params);
	virtual void BroadcastInitialValue();
	virtual void BindCallbackDependencies();
};

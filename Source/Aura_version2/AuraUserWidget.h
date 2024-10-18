// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class AURA_VERSION2_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UObject> WAuraController;

	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UFUNCTION(BlueprintImplementableEvent)
	void AuraWidgetBeginPlay();
};

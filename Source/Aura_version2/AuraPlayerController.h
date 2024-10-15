// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class IEnemyInterface;
struct FInputActionValue;
class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class AURA_VERSION2_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AAuraPlayerController();
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void PlayerTick(float DeltaTime) override;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UInputMappingContext> AuraContext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TScriptInterface<IEnemyInterface> LastActor= nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TScriptInterface<IEnemyInterface> ThisActor = nullptr;
	
	void Move(const FInputActionValue& InputAction);
	void TraceCursor();
};

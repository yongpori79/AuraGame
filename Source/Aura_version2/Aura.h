// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Aura.generated.h"

class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class AURA_VERSION2_API AAura : public ABaseCharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCameraComponent> Camera;

	AAura();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	void InitGas();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
};

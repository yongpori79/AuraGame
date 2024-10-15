// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "EnemyInterface.h"
#include "Goblin.generated.h"

/**
 * 
 */
UCLASS()
class AURA_VERSION2_API AGoblin : public ABaseCharacter, public IEnemyInterface
{
	GENERATED_BODY()
public:
	AGoblin();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void HighLightActor() override;
	virtual void UnHighLightActor() override;
};

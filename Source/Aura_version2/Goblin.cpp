// Fill out your copyright notice in the Description page of Project Settings.


#include "Goblin.h"

AGoblin::AGoblin()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGoblin::BeginPlay()
{
	Super::BeginPlay();
}

void AGoblin::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AGoblin::HighLightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(250.f);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(250.f);
}

void AGoblin::UnHighLightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

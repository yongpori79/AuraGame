// Fill out your copyright notice in the Description page of Project Settings.


#include "Aura.h"

#include "AbilitySystemComponent.h"
#include "AuraAbilitySystemComponent.h"
#include "AuraAttributeSet.h"
#include "AuraHUD.h"
#include "AuraPlayerController.h"
#include "AuraPlayerState.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AAura::AAura()
{
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArmComponent);
	SpringArmComponent->TargetArmLength = 600.0f;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
}

void AAura::BeginPlay()
{
	Super::BeginPlay();
}

void AAura::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AAura::InitGas()
{
	AAuraPlayerState* AuraPlayerState = Cast<AAuraPlayerState>(GetPlayerState());
	check(AuraPlayerState)
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
	AbilitySystemComponent = Cast<UAuraAbilitySystemComponent>(AuraPlayerState->GetAbilitySystemComponent());
	AttributeSet = Cast<UAuraAttributeSet>(AuraPlayerState->GetAttributeSet());
	if(AAuraPlayerController* MyPlayerController = Cast<AAuraPlayerController>(GetController()))
	{
		if(AAuraHUD* MyHUD = Cast<AAuraHUD>(MyPlayerController->GetHUD()))
		{
			MyHUD->InitOverlay(MyPlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
}

void AAura::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitGas();
}

void AAura::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitGas();
}

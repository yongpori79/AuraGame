// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraPlayerController.h"

#include "EnemyInterface.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Goblin.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem)
	Subsystem->AddMappingContext(AuraContext, 0);
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Hand;

	FInputModeGameAndUI GameAndUI;
	GameAndUI.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	GameAndUI.SetHideCursorDuringCapture(false);
	SetInputMode(GameAndUI);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if(UEnhancedInputComponent* EnhancedPlayerInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedPlayerInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
	}
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	TraceCursor();
}

void AAuraPlayerController::TraceCursor()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if(!CursorHit.bBlockingHit)return;
	
	LastActor = ThisActor;
	
	ThisActor = CursorHit.GetActor();
	
	
	
	if(LastActor==nullptr)
	{
		if(ThisActor)
		{
			ThisActor->HighLightActor();
		}			
	}
	else
	{
		if(!ThisActor)
		{
			LastActor->UnHighLightActor();
		}
		else
		{
			if(ThisActor!=LastActor)
			{
				ThisActor->HighLightActor();
				LastActor->UnHighLightActor();               
			}
		}
		
	}
	
}


void AAuraPlayerController::Move(const FInputActionValue& InputAction)
{
	const FVector2D Position = InputAction.Get<FVector2D>();
	FRotator Rotation = GetControlRotation();
	FRotator YawRotation = FRotator(0.f, Rotation.Yaw, 0.f);
	FVector Forward = YawRotation.RotateVector(FVector::ForwardVector);
	FVector Right = YawRotation.RotateVector(FVector::RightVector);

	if(APawn* PlayerPawn = GetPawn<APawn>())
	{
		PlayerPawn->AddMovementInput(Forward, Position.Y);
		PlayerPawn->AddMovementInput(Right, Position.X);
	}
}


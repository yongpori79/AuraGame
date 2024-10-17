// Fill out your copyright notice in the Description page of Project Settings.


#include "TestingAttributeActor.h"

#include "AbilitySystemInterface.h"
#include "AuraAttributeSet.h"
#include "Components/SphereComponent.h"

// Sets default values
ATestingAttributeActor::ATestingAttributeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	TestSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	TestSphere->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ATestingAttributeActor::BeginPlay()
{
	Super::BeginPlay();
	TestSphere->OnComponentBeginOverlap.AddDynamic(this, &ATestingAttributeActor::OnTestOverlap);
}

void ATestingAttributeActor::OnTestOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(IAbilitySystemInterface* Interface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UAuraAttributeSet* Aura = Cast<UAuraAttributeSet>(Interface->GetAbilitySystemComponent()->GetAttributeSet(UAuraAttributeSet::StaticClass()));
		UAuraAttributeSet* MutableAura = const_cast<UAuraAttributeSet*>(Aura);
		MutableAura->SetHealth(MutableAura->GetHealth() + 10.f);
		Destroy();
	}
}

// Called every frame



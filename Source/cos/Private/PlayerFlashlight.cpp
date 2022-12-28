#include "PlayerFlashlight.h"
#include "Components/SpotLightComponent.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
APlayerFlashlight::APlayerFlashlight()
{
	PrimaryActorTick.bCanEverTick = false;
	
	flashlightMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FlashlightMesh"));
	RootComponent = flashlightMesh;
	
	spotLightComponent = CreateDefaultSubobject<USpotLightComponent>(TEXT("FlashlightLightSource"));
	spotLightComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APlayerFlashlight::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerFlashlight::ToogleFlashlight()
{
	if (spotLightComponent) 
	{
		bool bLight = spotLightComponent->bHiddenInGame;
		spotLightComponent->SetHiddenInGame(!bLight);
		
		//play sound
		UE_LOG(LogTemp, Warning, TEXT("Flashlight turn %s"), bLight ? TEXT("on") : TEXT("off"));
	}
}
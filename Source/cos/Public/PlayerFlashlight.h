//Source:
//https://www.youtube.com/watch?v=4xH-mMw6Rmc&list=PLnHeglBaPYu_nXuj2AmYoz6Sg9R37y8Pp&index=1
//
//DAX.PL

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerFlashlight.generated.h"

UCLASS()
class COS_API APlayerFlashlight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerFlashlight();
	void ToogleFlashlight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	
	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* flashlightMesh;
	UPROPERTY(EditDefaultsOnly)
	class USpotLightComponent* spotLightComponent;
	UPROPERTY(VisibleAnywhere)
	bool bLightOn = true;
	
};

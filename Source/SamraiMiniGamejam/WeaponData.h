// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeaponData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class SAMRAIMINIGAMEJAM_API UWeaponData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UAnimSequenceBase* IdleAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UAnimMontage* AttackAnimation;
};

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SamraiMiniGamejamHUD.generated.h"

UCLASS()
class ASamraiMiniGamejamHUD : public AHUD
{
	GENERATED_BODY()

public:
	ASamraiMiniGamejamHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

protected:
	UPROPERTY(EditDefaultsOnly)
	class UTexture2D* CrosshairTex;

};


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MazeGenerator.generated.h"

UCLASS()
class SAMRAIMINIGAMEJAM_API AMazeGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MazeGeneration")
		int mazeWidth = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MazeGeneration")
		int mazeHeight = 100;

	struct Box {
		int width;
		int height;
		int x;
		int y;
	};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	char* maze = nullptr;

public:	
	// Sets default values for this actor's properties
	AMazeGenerator();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void generateMaze();

	static bool isOverlapping(const Box& b1, const Box& b2);
	bool isOverlappingInMaze(const Box& b) const;

	~AMazeGenerator();

};

// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeGenerator.h"

// Sets default values
AMazeGenerator::AMazeGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMazeGenerator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMazeGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMazeGenerator::generateMaze()
{
	// make sure the maze is empty
	if (maze != nullptr)
		delete maze;

	// Create array
	maze = new unsigned int[mazeWidth * mazeHeight]{};
	for (unsigned int i{ 0 }; i < mazeWidth * mazeHeight; ++i) {
		// Set to 1 to indicate walls
		maze[i] = 1;
	}


}

AMazeGenerator::~AMazeGenerator()
{
	if (maze != nullptr) {
		delete maze;
		maze = nullptr;
	}
}


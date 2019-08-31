// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGenerator.h"
#include "Kismet/KismetMathLibrary.h"

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

	if (mazeWidth < 0)
		mazeWidth = FMath::Abs(mazeWidth);
	if (mazeHeight < 0)
		mazeHeight = FMath::Abs(mazeHeight);


	// Create array
	maze = new char[mazeWidth * mazeHeight]{};
	for (int i{ 0 }; i < mazeWidth * mazeHeight; ++i) {
		// Set to 1 to indicate walls
		maze[i] = 0b0001;
	}

	// 1. First, sprinkle in some random rooms.
	// Make sure they don't overlap
	int rooms = 10;
	for (int room{ 0 }; room < rooms; ++room) {
		int width = UKismetMathLibrary::RandomIntegerInRange(1, 7);
		int height = UKismetMathLibrary::RandomIntegerInRange(1, 7);

		int maxAttempts = 10;
		for (int attempt = 0; attempt < maxAttempts; ++attempt) {
			Box box{
				width,
				height,
				UKismetMathLibrary::RandomInteger(mazeWidth - width),
				UKismetMathLibrary::RandomInteger(mazeHeight - height)
			};

			// Check if ranndom box collides with any other boxes
			if (!isOverlappingInMaze(box)) {
				// Map out room.
				for (int x = box.x; x < box.x + box.width; ++x) {
					for (int y = box.y; y < box.y + box.height; ++y) {
						maze[x * y] = 0b0000;
					}
				}
				break;
			}
		}
	}

	/*for (int x = 0; x < mazeWidth; ++x) {
		for (int y = 0; y < mazeHeight; ++y) {
			
		}
	}*/
}

bool AMazeGenerator::isOverlapping(const Box& b1, const Box& b2)
{
	return
		b1.x + b1.width / 2.f > b2.x - b2.width / 2.f &&
		b1.x - b1.width / 2.f < b2.x + b2.width / 2.f &&
		b1.y + b1.height / 2.f > b2.y - b2.height / 2.f &&
		b1.y - b1.height / 2.f < b2.y + b2.height / 2.f;
}

bool AMazeGenerator::isOverlappingInMaze(const Box& b) const
{
	if (maze == nullptr)
		return false;

	for (int x = b.x; x < b.x + b.width; ++x) {
		for (int y = b.y; y < b.y + b.height; ++y) {
			if (!maze[x * y]) {
				return true;
			}
		}
	}

	return false;
}

AMazeGenerator::~AMazeGenerator()
{
	if (maze != nullptr) {
		delete maze;
		maze = nullptr;
	}
}


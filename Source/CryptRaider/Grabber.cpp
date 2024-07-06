// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"

#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.
	// You can turn these features off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UPhysicsHandleComponent *PhysicsHandle = GetPhysicsHandle();
	// If the PhysicsHandleComponent is not found, log a warning and return
	if (PhysicsHandle && PhysicsHandle->GetGrabbedComponent())
	{
		// Get the starting and ending points of the grab action
		FVector TargetLocation = GetComponentLocation() + GetForwardVector() * HoldDistance;
		// Optionally, draw a sphere in the world to visualize the grab action
		PhysicsHandle->SetTargetLocationAndRotation(TargetLocation, GetComponentRotation());
	}
}

// Handles the grab action of the grabber
void UGrabber::Grab()
{
	// Get the PhysicsHandleComponent of the owner of this component
	UPhysicsHandleComponent *PhysicsHandle = GetPhysicsHandle();
	if (PhysicsHandle == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("No PhysicsHandleComponent found!"));
		return;
	}

	// Get the first grabbable object in reach
	FHitResult HitResult;
	// If the grabbable object is found, log a message
	bool HasHit = GetGrabbableInReach(HitResult);

	// Log the result of the grab attempt
	if (HasHit)
	{
		// Log the name of the grabbed object
		UPrimitiveComponent *HitComponent = HitResult.GetComponent();
		HitComponent->SetSimulatePhysics(true);
		HitComponent->WakeAllRigidBodies();
		AActor *HitActor = HitResult.GetActor();
		HitActor->Tags.Add("Grabbed");
		HitActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		PhysicsHandle->GrabComponentAtLocationWithRotation(
			HitComponent,
			NAME_None,
			HitResult.ImpactPoint,
			GetComponentRotation());
	}
}

// Handles the release action of the grabber
void UGrabber::Release()
{
	// Get the PhysicsHandleComponent of the owner of this component
	UPhysicsHandleComponent *PhysicsHandle = GetPhysicsHandle();

	// Release the grabbed object
	if (PhysicsHandle && PhysicsHandle->GetGrabbedComponent())
	{
		AActor *GrabbedActor = PhysicsHandle->GetGrabbedComponent()->GetOwner();
		GrabbedActor->Tags.Remove("Grabbed");
		// Release the grabbed object
		PhysicsHandle->ReleaseComponent();
	}
}

// Returns the PhysicsHandleComponent of the owner of this component
UPhysicsHandleComponent *UGrabber::GetPhysicsHandle() const
{
	// Get the PhysicsHandleComponent of the owner of this component
	UPhysicsHandleComponent *Result = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (Result == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No PhysicsHandleComponent found!"));
	}
	return Result;
}

// Returns the forward vector of the owner of this component
bool UGrabber::GetGrabbableInReach(FHitResult &OutHitResult) const
{
	// Get the starting and ending points of the grab action
	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrabDistance;

	// Optionally, draw a line in the world to visualize the grab action
	// DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	// Optionally, draw a sphere in the world to visualize the grab action
	// DrawDebugSphere(GetWorld(), End, 10, 10, FColor::Blue, false, 5);

	// Define the collision shape and parameters for the sweep
	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);

	// If the sweep hits something, grab it
	return GetWorld()->SweepSingleByChannel(
		OutHitResult,
		Start, End,
		FQuat::Identity,
		ECC_GameTraceChannel2,
		Sphere);
}
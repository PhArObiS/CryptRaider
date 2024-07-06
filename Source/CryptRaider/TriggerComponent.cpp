// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerComponent.h"

// Sets default values for this component's properties
UTriggerComponent::UTriggerComponent()
{
    // Enable ticking for this component
    PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UTriggerComponent::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // Check if a mover is set
    if (Mover == nullptr)
    {
        // If no mover is set, do nothing
        return;
    }

    // Get the actor to check for tags
    AActor *Actor = GetTagToCheck();
    if (Actor != nullptr)
    {
        // If actor is found with the specified tag, attach and enable movement
        UPrimitiveComponent *Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
        if (Component != nullptr)
        {
            // Disable physics simulation on the actor's root component
            Component->SetSimulatePhysics(false);
        }

        // Attach the actor to this trigger component and enable movement in the mover
        Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
        Mover->SetShouldMove(true);
    }
    else
    {
        // If no actor with the specified tag is found, disable movement in the mover
        Mover->SetShouldMove(false);
    }
}

// Set the mover associated with this trigger component
void UTriggerComponent::SetMover(UMover *NewMover)
{
    Mover = NewMover;
}

// Get the actor within the trigger zone that has the specified tag
AActor *UTriggerComponent::GetTagToCheck() const
{
    // Array to store overlapping actors
    TArray<AActor *> Actors;
    GetOverlappingActors(Actors);

    // Iterate through overlapping actors
    for (AActor *Actor : Actors)
    {
        // Check if the actor has the specified tag and is not already grabbed
        bool HasTagToCheck = Actor->ActorHasTag(TagToCheck);
        bool IsGrabbed = Actor->ActorHasTag("Grabbed");
        if (HasTagToCheck && !IsGrabbed)
        {
            // Return the first actor that satisfies the conditions
            return Actor;
        }
    }

    // Return nullptr if no matching actor is found
    return nullptr;
}

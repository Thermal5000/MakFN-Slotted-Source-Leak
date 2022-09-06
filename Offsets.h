#pragma once
#include <Windows.h>

#define OFFSET_UWORLD 0xcca9dc8 

namespace Offsets {

    uintptr_t GameInstance = 0x1A8;
    uintptr_t LocalPlayers = 0x38;
    uintptr_t PlayerController = 0x30;
    uintptr_t LocalPawn = 0x310; //AcknowledgedPawn 
    uintptr_t PlayerState = 0x290;
    uintptr_t RootComponent = 0x188;
    uintptr_t Persistentlevel = 0x30;
    uintptr_t TeamIndex = 0x1048;
    uintptr_t AcotrCount = 0xA0;
    uintptr_t AAcotrs = 0x98; //actor array
    uintptr_t Mesh = 0x2F0;
    uintptr_t RelativeLocation = 0x128;
    uintptr_t CurrentActor = 0x8;
    uintptr_t Velocity = 0x140;
    uintptr_t ComponentToWorld = 0x240;
    uintptr_t BoneArray = 0x590;
    uintptr_t bIsDying = 0x6d8;
    uintptr_t bIsDBNO = 0x752;
    uintptr_t CameraManager = 0x328;
    uintptr_t ActorCount = 0xA0;
    uintptr_t ReviveFromDBNOTime = 0x40a0;
    uintptr_t ControlRotation = 0x2e8;
    uintptr_t LastFrameCameraCachePrivate = 0x28d0;
    uintptr_t Tier = 0x6C;
    uintptr_t bIsReloading = 0x2B9;
    uintptr_t bIsEquippingWeapon = 0x2B8;
    uintptr_t CurrentWeapon = 0x7f8;
    uintptr_t WeaponData = 0x3d8;
    uintptr_t DisplayName = 0xD80;
    uintptr_t AmmoCount = 0xb3c;
    uintptr_t default_fov = 0x284 + 0x4;
    uintptr_t player_camera_manager = 0x328;
    uintptr_t local_player_controller = 0x30;
    uintptr_t local_player_array = 0x38;
    constexpr uintptr_t current_vehicle = 0x21b8;
    constexpr uintptr_t acknowledged_pawn = 0x310;
    uintptr_t actor_array = 0x98;
    uintptr_t ItemDefinition = 0x18;
    uintptr_t PrimaryPickupItemEntry = 0x2f8;
}
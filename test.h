//#pragma once
//#include <utils.h>
//#include <driver.h>
//#include "Offsets.h"
//kernel::driver driver;
//struct FRecoilData {
//	float recoilRiseTime;
//	float recoilTotalTime;
//	float verticalRecoilAmount;
//	float horizontalRecoilAmount;
//	float recoilKick;
//	float visualRecoil;
//};
//
//struct FMinimalViewInfo
//{
//	Vector3 Location;
//	Vector3 Rotation;
//	float FOV;
//};
//
//struct FCameraCacheEntry
//{
//	FMinimalViewInfo POV;
//};
//
//
//
//class APlayerState {
//public:
//	BYTE Team_Num() {
//		if (!this)
//			return {};
//		return driver.read<BYTE>(uintptr_t(this) + Offsets::TeamIndex);
//	}
//};
//
//class USkeletalMeshComponent {
//public:
//	FTransform ComponentToWorld() {
//		if (!this)
//			return {};
//		return driver.read<FTransform>(uintptr_t(this) + Offsets::ComponentToWorld);
//	}
//
//	uintptr_t BoneArray() {
//		if (!this)
//			return {};
//		return driver.read<uintptr_t>(uintptr_t(this) + Offsets::BoneArray);
//	}
//};
//
//class ARootComponent {
//public:
//	Vector3 RelativeLocation() {
//		if (!this)
//			return {};
//		return driver.read<Vector3>(uintptr_t(this) + Offsets::RelativeLocation);
//	}
//};
//
//class AFortItemDefinition {
//public:
//
//	char* DisplayName() {
//		if (!this)
//			return {};
//		return driver.read<char*>(uintptr_t(this) + Offsets::DisplayName);
//	}
//};
//
//class AFortWeapon {
//public:
//	AFortItemDefinition* WeaponData() {
//		if (!this)
//			return {};
//		return driver.read<AFortItemDefinition*>(uintptr_t(this) + Offsets::WeaponData);
//	}
//
//	int32_t AmmoCount() {
//		if (!this)
//			return {};
//		return driver.read<int32_t>(uintptr_t(this) + Offsets::AmmoCount);
//	}
//
//	int32_t bIsReloadingWeapon() {
//		if (!this)
//			return {};
//		return driver.read<int32_t>(uintptr_t(this) + Offsets::bIsReloading);
//	}
//
//	void CustomTimeDilation(float value) {
//		if (!this)
//			return;
//		driver.write(uintptr_t(this) + 0x64, value);
//	}
//};
//
//class AFortPawn {
//public:
//	USkeletalMeshComponent* Mesh() {
//		if (!this)
//			return {};
//		return driver.read<USkeletalMeshComponent*>(uintptr_t(this) + Offsets::Mesh);
//	}
//
//	ARootComponent* RootComponent() {
//		if (!this)
//			return {};
//		return driver.read<ARootComponent*>(uintptr_t(this) + Offsets::RootComponent);
//	}
//
//	APlayerState* PlayerState() {
//		if (!this)
//			return {};
//		return driver.read<APlayerState*>(uintptr_t(this) + Offsets::PlayerState);
//	}
//
//	AFortWeapon* CurrentWeapon() {
//		if (!this)
//			return {};
//		return driver.read<AFortWeapon*>(uintptr_t(this) + Offsets::CurrentWeapon);
//	}
//
//
//
//
//
//	Vector3 GetBone(int index) {
//		auto Mesh = this->Mesh();
//		if (!Mesh)
//			return {};
//
//		auto BoneArray = Mesh->BoneArray();
//		if (!BoneArray)
//			return {};
//
//		FTransform ComponentToWorld = Mesh->ComponentToWorld();
//
//		FTransform FirstBone = driver.read<FTransform>(BoneArray + (sizeof(FTransform) * index));
//		D3DMATRIX matrix = MatrixMultiplication(FirstBone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());
//		return Vector3(matrix._41, matrix._42, matrix._43);
//	}
//};
//
//class APlayerCameraManager {
//public:
//	void FOV(float Value) {
//		if (!this)
//			return;
//		driver.write<float>(uintptr_t(this) + Offsets::default_fov, Value);
//	}
//};
//
//class APlayerController {
//public:
//	APlayerCameraManager* PlayerCameraManager() {
//		if (!this)
//			return {};
//		return driver.read<APlayerCameraManager*>(uintptr_t(this) + Offsets::player_camera_manager);
//	}
//
//	AFortPawn* AcknowledgedPawn() {
//		if (!this)
//			return {};
//		return driver.read<AFortPawn*>(uintptr_t(this) + Offsets::LocalPawn);
//	}
//};
//
//class ULocalPlayer {
//public:
//	APlayerController* PlayerController() {
//		if (!this)
//			return {};
//		return driver.read<APlayerController*>(uintptr_t(this) + Offsets::local_player_controller);
//	}
//};
//
//class ULocalPlayers {
//public:
//	ULocalPlayer* LocalPlayer() {
//		if (!this)
//			return {};
//		return driver.read<ULocalPlayer*>(uintptr_t(this));
//	}
//};
//
//class ULevel {
//public:
//	int ActorCount() {
//		if (!this)
//			return {};
//		return driver.read<int>(uintptr_t(this) + Offsets::ActorCount);
//	}
//
//	uintptr_t Actors() {
//		if (!this)
//			return {};
//		return driver.read<uintptr_t>(uintptr_t(this) + Offsets::actor_array);
//	}
//};
//
//class UGameInstance {
//public:
//	ULocalPlayers* LocalPlayers() {
//		if (!this)
//			return {};
//		return driver.read<ULocalPlayers*>(uintptr_t(this) + Offsets::local_player_array);
//	}
//};
//
//class UWorld {
//public:
//	UGameInstance* GameInstance() {
//		if (!this)
//			return {};
//		return driver.read<UGameInstance*>(uintptr_t(this) + Offsets::GameInstance);
//	}
//
//	ULevel* PersistentLevel() {
//		if (!this)
//			return {};
//		return driver.read<ULevel*>(uintptr_t(this) + Offsets::Persistentlevel);
//	}
//};
//
//namespace Addresses {
//	APlayerCameraManager* PlayerCameraManager{};
//	AFortPawn* LocalPawn{};
//	APlayerController* PlayerController{};
//	ULocalPlayer* LocalPlayer{};
//
//	Vector3 CameraLocation;
//	Vector3 CameraRotation;
//	float FOVAngle;
//
//	FCameraCacheEntry LastFrameCameraCachePrivate{};
//}
//
//std::vector<AFortPawn*> PlayerPawns{};
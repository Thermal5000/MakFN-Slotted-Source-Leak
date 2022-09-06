//#pragma once
//#include "utils.h"
//#include "driver.h"
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
//
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
//
//
//	AFortPawn* GetVehicle() {
//		if (!this)
//			return {};
//		return driver.read<AFortPawn*>(uintptr_t(this) + Offsets::current_vehicle);
//	}
//
//#pragma region WriteMemory
//
//
//	BOOL K2_TeleportTo(const Vector3& DestRotation) {
//		if (!this)
//			return {};
//
//		uintptr_t DestLocationRoot = driver.read<uintptr_t>(uintptr_t(this) + Offsets::RootComponent);
//		driver.write<char>(DestLocationRoot + Offsets::RootComponent, 0);
//		driver.write<Vector3>(DestLocationRoot + Offsets::RootComponent, DestRotation);
//	}
//#pragma endregion
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
//	VOID FOV(float Value) {
//		if (!this)
//			return;
//		driver.write<float>(uintptr_t(this) + Offsets::default_fov, Value);
//	}
//};
//
//class APlayerController {
//public:
//	//APlayerCameraManager* PlayerCameraManager() {
//	//	if (!this)
//	//		return {};
//	//	return driver.read<APlayerCameraManager*>(uintptr_t(this) + Offsets::player_camera_manager);
//	//}
//
//	AFortPawn* AcknowledgedPawn() {
//		if (!this)
//			return {};
//		return driver.read<AFortPawn*>(uintptr_t(this) + Offsets::acknowledged_pawn);
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
//
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
//
//
//namespace Addresses {
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
//
//
////class AFortPawn {
////public:
////	BOOL K2_TeleportTo(const Vector3& DestRotation) {
////		if (!this)
////			return {};
////
////		uintptr_t DestLocationRoot = driver.read<uintptr_t>(uintptr_t(this) + Offsets::RootComponent);
////		driver.write<char>(DestLocationRoot + Offsets::RootComponent, 0);
////		driver.write<Vector3>(DestLocationRoot + Offsets::RelativeLocation, DestRotation);
////	}
////};
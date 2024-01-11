// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Grabber.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CRYPTRAIDER_Grabber_generated_h
#error "Grabber.generated.h already included, missing '#pragma once' in Grabber.h"
#endif
#define CRYPTRAIDER_Grabber_generated_h

#define FID_CryptRaider_Source_CryptRaider_Grabber_h_12_SPARSE_DATA
#define FID_CryptRaider_Source_CryptRaider_Grabber_h_12_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_CryptRaider_Source_CryptRaider_Grabber_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_CryptRaider_Source_CryptRaider_Grabber_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGrab); \
	DECLARE_FUNCTION(execRelease);


#define FID_CryptRaider_Source_CryptRaider_Grabber_h_12_ACCESSORS
#define FID_CryptRaider_Source_CryptRaider_Grabber_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGrabber(); \
	friend struct Z_Construct_UClass_UGrabber_Statics; \
public: \
	DECLARE_CLASS(UGrabber, USceneComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CryptRaider"), NO_API) \
	DECLARE_SERIALIZER(UGrabber)


#define FID_CryptRaider_Source_CryptRaider_Grabber_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGrabber(UGrabber&&); \
	NO_API UGrabber(const UGrabber&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGrabber); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGrabber); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGrabber) \
	NO_API virtual ~UGrabber();


#define FID_CryptRaider_Source_CryptRaider_Grabber_h_9_PROLOG
#define FID_CryptRaider_Source_CryptRaider_Grabber_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_CryptRaider_Source_CryptRaider_Grabber_h_12_SPARSE_DATA \
	FID_CryptRaider_Source_CryptRaider_Grabber_h_12_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_CryptRaider_Source_CryptRaider_Grabber_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_CryptRaider_Source_CryptRaider_Grabber_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_CryptRaider_Source_CryptRaider_Grabber_h_12_ACCESSORS \
	FID_CryptRaider_Source_CryptRaider_Grabber_h_12_INCLASS_NO_PURE_DECLS \
	FID_CryptRaider_Source_CryptRaider_Grabber_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CRYPTRAIDER_API UClass* StaticClass<class UGrabber>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_CryptRaider_Source_CryptRaider_Grabber_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NavLinkGenerator/Public/CustomNavLinkProxy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomNavLinkProxy() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_ANavLinkProxy();
	NAVLINKGENERATOR_API UClass* Z_Construct_UClass_ACustomNavLinkProxy();
	NAVLINKGENERATOR_API UClass* Z_Construct_UClass_ACustomNavLinkProxy_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NavLinkGenerator();
// End Cross Module References
	void ACustomNavLinkProxy::StaticRegisterNativesACustomNavLinkProxy()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACustomNavLinkProxy);
	UClass* Z_Construct_UClass_ACustomNavLinkProxy_NoRegister()
	{
		return ACustomNavLinkProxy::StaticClass();
	}
	struct Z_Construct_UClass_ACustomNavLinkProxy_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACustomNavLinkProxy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ANavLinkProxy,
		(UObject* (*)())Z_Construct_UPackage__Script_NavLinkGenerator,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACustomNavLinkProxy_Statics::Class_MetaDataParams[] = {
		{ "AutoCollapseCategories", "SmartLink Actor" },
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Input" },
		{ "IncludePath", "CustomNavLinkProxy.h" },
		{ "ModuleRelativePath", "Public/CustomNavLinkProxy.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACustomNavLinkProxy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACustomNavLinkProxy>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACustomNavLinkProxy_Statics::ClassParams = {
		&ACustomNavLinkProxy::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACustomNavLinkProxy_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACustomNavLinkProxy_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACustomNavLinkProxy()
	{
		if (!Z_Registration_Info_UClass_ACustomNavLinkProxy.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACustomNavLinkProxy.OuterSingleton, Z_Construct_UClass_ACustomNavLinkProxy_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACustomNavLinkProxy.OuterSingleton;
	}
	template<> NAVLINKGENERATOR_API UClass* StaticClass<ACustomNavLinkProxy>()
	{
		return ACustomNavLinkProxy::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACustomNavLinkProxy);
	ACustomNavLinkProxy::~ACustomNavLinkProxy() {}
	struct Z_CompiledInDeferFile_FID_Link_Plugins_NavLinkGenerator_Source_NavLinkGenerator_Public_CustomNavLinkProxy_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Link_Plugins_NavLinkGenerator_Source_NavLinkGenerator_Public_CustomNavLinkProxy_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACustomNavLinkProxy, ACustomNavLinkProxy::StaticClass, TEXT("ACustomNavLinkProxy"), &Z_Registration_Info_UClass_ACustomNavLinkProxy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACustomNavLinkProxy), 2023532256U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Link_Plugins_NavLinkGenerator_Source_NavLinkGenerator_Public_CustomNavLinkProxy_h_3046748781(TEXT("/Script/NavLinkGenerator"),
		Z_CompiledInDeferFile_FID_Link_Plugins_NavLinkGenerator_Source_NavLinkGenerator_Public_CustomNavLinkProxy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Link_Plugins_NavLinkGenerator_Source_NavLinkGenerator_Public_CustomNavLinkProxy_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NavLinkGenerator/Public/GenSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGenSettings() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
	NAVLINKGENERATOR_API UClass* Z_Construct_UClass_ACustomNavLinkProxy_NoRegister();
	NAVLINKGENERATOR_API UClass* Z_Construct_UClass_UGenSettings();
	NAVLINKGENERATOR_API UClass* Z_Construct_UClass_UGenSettings_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NavLinkGenerator();
// End Cross Module References
	void UGenSettings::StaticRegisterNativesUGenSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGenSettings);
	UClass* Z_Construct_UClass_UGenSettings_NoRegister()
	{
		return UGenSettings::StaticClass();
	}
	struct Z_Construct_UClass_UGenSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LinkClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_LinkClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGenSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_NavLinkGenerator,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGenSettings_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "DisplayName", "Nav Link Generator" },
		{ "IncludePath", "GenSettings.h" },
		{ "ModuleRelativePath", "Public/GenSettings.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGenSettings_Statics::NewProp_LinkClass_MetaData[] = {
		{ "Category", "NavLink" },
		{ "Comment", "// Enables experimental *incomplete and unsupported* texture atlas groups that sprites can be assigned to\n" },
		{ "ModuleRelativePath", "Public/GenSettings.h" },
		{ "ToolTip", "Enables experimental *incomplete and unsupported* texture atlas groups that sprites can be assigned to" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UGenSettings_Statics::NewProp_LinkClass = { "LinkClass", nullptr, (EPropertyFlags)0x0014040000004015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UGenSettings, LinkClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ACustomNavLinkProxy_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGenSettings_Statics::NewProp_LinkClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGenSettings_Statics::NewProp_LinkClass_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGenSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenSettings_Statics::NewProp_LinkClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGenSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenSettings_Statics::ClassParams = {
		&UGenSettings::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGenSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGenSettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_UGenSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGenSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGenSettings()
	{
		if (!Z_Registration_Info_UClass_UGenSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenSettings.OuterSingleton, Z_Construct_UClass_UGenSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UGenSettings.OuterSingleton;
	}
	template<> NAVLINKGENERATOR_API UClass* StaticClass<UGenSettings>()
	{
		return UGenSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGenSettings);
	UGenSettings::~UGenSettings() {}
	struct Z_CompiledInDeferFile_FID_Link_Plugins_NavLinkGenerator_Source_NavLinkGenerator_Public_GenSettings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Link_Plugins_NavLinkGenerator_Source_NavLinkGenerator_Public_GenSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UGenSettings, UGenSettings::StaticClass, TEXT("UGenSettings"), &Z_Registration_Info_UClass_UGenSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenSettings), 1471303535U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Link_Plugins_NavLinkGenerator_Source_NavLinkGenerator_Public_GenSettings_h_1910052118(TEXT("/Script/NavLinkGenerator"),
		Z_CompiledInDeferFile_FID_Link_Plugins_NavLinkGenerator_Source_NavLinkGenerator_Public_GenSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Link_Plugins_NavLinkGenerator_Source_NavLinkGenerator_Public_GenSettings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

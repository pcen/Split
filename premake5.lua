workspace "Split"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

startproject "TestApp"

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
testAppDir = "../TestApp"

include "Split/dependencies"

project "Split"
	location "Split"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	pchheader "pch.h"
	pchsource "%{prj.name}/src/pch.cpp"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin_int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/{prj.name}"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/dependencies/SPDLOG/include",
		"%{prj.name}/dependencies/GLFW/include",
		"%{prj.name}/dependencies/GLAD/include",
		"%{prj.name}/dependencies/GLM"
	}

	links
	{
		"GLFW",
		"GLAD",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PLATFORM_WINDOWS",
			"BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "SPLIT_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SPLIT_RELEASE"
		runtime "Release"
		optimize "on"

project "TestApp"
	location "../TestApp"
	kind "ConsoleApp"
	staticruntime "on"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin_int/" .. outputDir .. "/%{prj.name}")

	files
	{
		(testAppDir .. "/**.h"),
		(testAppDir .. "/**.hpp"),
		(testAppDir .. "/**.cpp")
	}

	includedirs
	{
		"Split/dependencies/SPDLOG/include",
		"Split/src",
		"Split/dependencies/GLM"
	}

	links
	{
		"Split"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SPLIT_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "SPLIT_RELEASE"
		optimize "on"

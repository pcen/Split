workspace "Split"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

startproject "civ3"

civ3dir = "../civ3"

include "Split/dependencies"

project "Split"
	location "Split"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	systemversion "latest"
	staticruntime "on"

	pchheader "pch.h"
	pchsource "%{prj.name}/src/pch.cpp"

	targetdir ("bin/")
	objdir ("obj/")

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
		"%{prj.name}/dependencies/imgui",
		"%{prj.name}/dependencies/GLM",
		"%{prj.name}/dependencies/STB"
	}

	links
	{
		"GLFW",
		"GLAD",
		"IMGUI",
		"opengl32.lib"
	}

	defines
	{
		"GLFW_INCLUDE_NONE",
		"STB_IMAGE_IMPLEMENTATION"
	}

	filter "configurations:Debug"
		defines "SPLIT_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SPLIT_RELEASE"
		runtime "Release"
		optimize "on"

project "civ3"
	location "../civ3"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	systemversion "latest"
	staticruntime "on"

	targetdir (civ3dir .. "/bin/")
	objdir (civ3dir .. "/obj/")

	files
	{
		(civ3dir .. "/src/**.h"),
		(civ3dir .. "/src/**.hpp"),
		(civ3dir .. "/src/**.cpp")
	}

	includedirs
	{
		civ3dir .. "/src/",
		"Split/dependencies/SPDLOG/include",
		"Split/src",
		"Split/dependencies/GLM",
		"Split/dependencies/STB"
	}

	links
	{
		"Split"
	}

	filter "configurations:Debug"
		defines "SPLIT_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "SPLIT_RELEASE"
		optimize "on"

workspace "Split"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

project "Split"
	-- kind "StaticLib"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	systemversion "latest"
	staticruntime "on"

	pchheader "pch.h"
	pchsource "./src/pch.cpp"

	targetdir ("bin/")
	objdir ("bin/obj/")

	files
	{
		"./src/**.h",
		"./src/**.cpp",
		"./third_party/glad/src/glad.c"
	}

	includedirs
	{
		"./src",
		"./third_party/glad/include",
		"./third_party/glad/include", -- glad.h includes "KHR/khrplatform.h"
		"./third_party/spdlog/include",
		"./third_party/imgui",
		"./third_party/stb"
	}

	defines
	{
		"STB_IMAGE_IMPLEMENTATION",
		"_CRT_SECURE_NO_WARNINGS"
	}

	filter "files:**.c"
		flags {"noPCH" }

	filter "system:windows"
		systemversion "latest"

		includedirs
		{
			"C:/Libs/SDL2/include",
			"C:/Libs/glm"
		}
		libdirs
		{
			"C:/Libs/SDL2/lib/x64"
		}
		links
		{
			"SDL2.lib",
			"SDL2main.lib",
			"opengl32.lib"
		}

	filter "configurations:Debug"
		defines "SPLIT_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SPLIT_RELEASE"
		runtime "Release"
		optimize "on"

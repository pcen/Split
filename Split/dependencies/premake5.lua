project "GLFW"
	kind "StaticLib"
	language "C"
	staticruntime "on"

	targetdir ("bin/")
	objdir ("obj/")

	files
	{
		"GLFW/include/GLFW/glfw3.h",
		"GLFWinclude/GLFW/glfw3native.h",
		"GLFW/src/glfw_config.h",
		"GLFW/src/context.c",
		"GLFW/src/init.c",
		"GLFW/src/input.c",
		"GLFW/src/monitor.c",
		"GLFW/src/vulkan.c",
		"GLFW/src/window.c"
	}

	filter "system:windows"
		systemversion "latest"

		files
		{
			"GLFW/src/win32_init.c",
			"GLFW/src/win32_joystick.c",
			"GLFW/src/win32_monitor.c",
			"GLFW/src/win32_time.c",
			"GLFW/src/win32_thread.c",
			"GLFW/src/win32_window.c",
			"GLFW/src/wgl_context.c",
			"GLFW/src/egl_context.c",
			"GLFW/src/osmesa_context.c"
		}

		defines
		{
			"_GLFW_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

project "GLAD"
	kind "StaticLib"
	language "C"
	staticruntime "on"

	targetdir ("bin/")
	objdir ("obj/")

	files
	{
		"GLAD/include/glad/glad.h",
		"GLAD/include/KHR/khrplatform.h",
		"GLAD/src/glad.c"
	}

	includedirs
	{
		"GLAD/include"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

project "IMGUI"
	kind "StaticLib"
	language "C++"
	staticruntime "on"
	systemversion "latest"
	cppdialect "C++17"

	targetdir ("bin/")
	objdir ("obj/")

	files
	{
		"imgui/imconfig.h",
		"imgui/imgui.h",
		"imgui/imgui.cpp",
		"imgui/imgui_draw.cpp",
		"imgui/imgui_internal.h",
		"imgui/imgui_widgets.cpp",
		"imgui/imstb_rectpack.h",
		"imgui/imstb_textedit.h",
		"imgui/imstb_truetype.h",
		"imgui/imgui_demo.cpp"
	}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

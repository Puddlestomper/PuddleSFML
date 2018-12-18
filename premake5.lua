outputdir = "%{cfg.buildcfg}-%{cfg.platform}"

workspace "PuddleSFML"
	configurations {"Debug", "Release"}
	platforms {"x64", "Win32"}
	
	filter "platforms:Win32"
      architecture "x86"
	  system "Windows"

    filter "platforms:x64"
      architecture "x64"
	  system "Windows"
	
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/res/**"
	}
	
	includedirs
	{
		"PuddleSFML/src",
		"PuddleSFML/vendor/SFML/%{cfg.platform}/SFML-2.5.1/include"
	}
	
	libdirs
	{
		"PuddleSFML/vendor/SFML/%{cfg.platform}/SFML-2.5.1/lib"
	}
	
	links "PuddleSFML"
	
	cppdialect "C++17"
	
	filter "system:Windows"
		systemversion "latest"
		staticruntime "On"
		
		postbuildcommands
		{
			"{COPY} ../bin/" .. outputdir .. "/PuddleSFML/PuddleSFML.dll" .. " ../bin/" .. outputdir .. "/Sandbox"
		}
		
	filter "configurations:Debug"
		symbols "On"
		
		links
		{
			"sfml-system-d",
			"sfml-window-d",
			"sfml-graphics-d"
		}
		
		postbuildcommands
		{
			"{COPY} ../PuddleSFML/vendor/SFML/%{cfg.platform}/SFML-2.5.1/bin/sfml-graphics-d-2.dll" .. " ../bin/" .. outputdir .. "/Sandbox",
			"{COPY} ../PuddleSFML/vendor/SFML/%{cfg.platform}/SFML-2.5.1/bin/sfml-window-d-2.dll" .. " ../bin/" .. outputdir .. "/Sandbox",
			"{COPY} ../PuddleSFML/vendor/SFML/%{cfg.platform}/SFML-2.5.1/bin/sfml-system-d-2.dll" .. " ../bin/" .. outputdir .. "/Sandbox"
		}
		
	filter "configurations:Release"
		symbols "Off"
		optimize "On"
		
		links
		{
			"sfml-system",
			"sfml-window",
			"sfml-graphics"
		}
		
		postbuildcommands
		{
			"{COPY} ../PuddleSFML/vendor/SFML/%{cfg.platform}/SFML-2.5.1/bin/sfml-graphics-2.dll" .. " ../bin/" .. outputdir .. "/Sandbox",
			"{COPY} ../PuddleSFML/vendor/SFML/%{cfg.platform}/SFML-2.5.1/bin/sfml-window-2.dll" .. " ../bin/" .. outputdir .. "/Sandbox",
			"{COPY} ../PuddleSFML/vendor/SFML/%{cfg.platform}/SFML-2.5.1/bin/sfml-system-2.dll" .. " ../bin/" .. outputdir .. "/Sandbox"
		}
	
project "PuddleSFML"
	location "PuddleSFML"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/vendor/SFML/%{cfg.platform}/SFML-2.5.1/include"
	}
	
	libdirs
	{
		"%{prj.name}/vendor/SFML/%{cfg.platform}/SFML-2.5.1/lib"
	}
	
	defines {"PUDL_BUILD_DLL"}
	
	cppdialect "C++17"
	
	filter "system:Windows"
		systemversion "latest"
		staticruntime "On"
		
	filter "configurations:Debug"
		symbols "On"
		
		links
		{
			"sfml-system-d",
			"sfml-window-d",
			"sfml-graphics-d"
		}
		
	filter "configurations:Release"
		symbols "Off"
		optimize "On"
		
		links
		{
			"sfml-system",
			"sfml-window",
			"sfml-graphics"
		}
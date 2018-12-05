workspace "PuddleSFML"
	configurations {"Debug", "Release"}
	platforms {"x64", "Win32"}
	
	filter "platforms:Win32"
      architecture "x86"
	  system "Windows"

    filter "platforms:x64"
      architecture "x64"
	  system "Windows"
	
outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"	

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
	
	defines {"PUDL_BUILD_DLL"}
	
	cppdialect "C++17"
	
	filter "system:Windows"
		systemversion "latest"
		staticruntime "On"
		
		postbuildcommands
		{
			"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
		}
		
	filter "configurations:Debug"
		symbols "On"
		
	filter "configurations:Release"
		symbols "Off"
		optimize "On"
	
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
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
		"PuddleSFML/src"
	}
	
	links "PuddleSFML"
	
	cppdialect "C++17"
	
	filter "system:Windows"
		systemversion "latest"
		staticruntime "On"
		
	filter "configurations:Debug"
		symbols "On"
		
	filter "configurations:Release"
		symbols "Off"
		optimize "On"
	
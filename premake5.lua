-- premake5.lua
-- https://git-scm.com/book/en/v2/Git-Tools-Submodules
workspace "PressF"
   architecture "x64"
   startproject "PressF"
   configurations { "Debug", "Release", "Dist"}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["glm"] = "dependencies/glm"
IncludeDir["spdlog"] = "dependencies/spdlog/include"
IncludeDir["Glad"] = "dependencies/Glad/include"
IncludeDir["nuklear"] = "dependencies/nuklear/"
IncludeDir["SDL"] = "dependencies/SDL/include"


group "Dependencies"
	include "dependencies/Glad"
	-- include "dependencies/SDL2"
group ""

project "PressF"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17" --StaticLib

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
   
   files { 
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp",
      "dependencies/glm/glm/**.hpp",
      "dependencies/glm/glm/**.inl"
   }

   includedirs {
      -- internal 
      "%{prj.name}/src",

      -- dependencies
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.nuklear}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.SDL}"
   }

   libdirs
   {
      "SDL2" ,"dependencies/SDL/lib/**"
   }

   links {
      "Glad",
      "SDL2",
   }

   -- prebuildcommands { "MyTool --dosomething" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

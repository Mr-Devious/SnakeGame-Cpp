-- premake5.lua

workspace "SnakeGame"
    configurations { "Debug", "Release" }
    startproject "SnakeGame"

    filter "system:linux"
        language "C++"
        buildoptions { "-std=c++17" }
        --DEFAULT_SOURCE is required for clock_gettime/CLOCK_MONOTONIC
        defines { "_DEFAULT_SOURCE" } 
    
    project "SnakeGame"
        kind "ConsoleApp"
        targetdir "bin/%{cfg.buildcfg}"
        objdir "bin-int/%{cfg.buildcfg}"
       
        files { "**cpp", "**h", "**hpp", "**c" } 

        includedirs { 
            
            "Core/Source/Core/Raylib/include/",
            "App/Source/",
            "App/Source/Game",
            "Core/Source/Core/"
            
        }

        libdirs { 
            "Core/Source/Core/Raylib/" 
        }

        links { 
            "raylib:static",
            
            -- Raylib's required system dependencies on Linux (MUST follow raylib):
            "m",       -- Math library
            "dl",      -- Dynamic linking loader
            "rt",      -- Real-time extensions
            "X11",     -- X Window System (main windowing dependency)
            "Xrandr",  
            "Xinerama",
            "Xi",      
            "Xcursor", 
            "pthread", 
            "GL",      
            "c"        -- C lib
        }

        filter "configurations:Debug"
            defines { "DEBUG" }
            symbols "on"

        filter "configurations:Release"
            defines { "NDEBUG" }
            optimize "on"

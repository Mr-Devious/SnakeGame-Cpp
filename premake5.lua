-- premake5.lua

workspace "SnakeGame"
    configurations { "Debug", "Release" }
    startproject "SnakeGame"

    -- Define common properties for Linux
    filter "system:linux"
        language "C++"
        buildoptions { "-std=c++14" }
        --DEFAULT_SOURCE is required for clock_gettime/CLOCK_MONOTONIC
        defines { "_DEFAULT_SOURCE" } 
    
    ---

    project "SnakeGAME"
        kind "ConsoleApp"
        targetdir "bin/%{cfg.buildcfg}"
        objdir "bin-int/%{cfg.buildcfg}"

        files { "Core/SnakeGame/**.cpp", "Core/SnakeGame/**.h" }

        includedirs { 
            "/home/coolguy1/Projects/SnakeGame/Core/raylib/build/raylib/include/" 
        }

        libdirs { 
            "/home/coolguy1/Projects/SnakeGame/Core/raylib/build/raylib" 
        }

        links { 
            "raylib:static", -- Link the raylib library (.a) statically
            
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

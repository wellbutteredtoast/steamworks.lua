cmake_minimum_required(VERSION "3.25")
project(steamlua
    VERSION 0.0.1
    DESCRIPTION "An awesome library that binds Steamworks to Lua."
    LANGUAGES C CXX
)

# Standard setup -- ISO standards, no gnu extensions, export compile commands
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Few options, we don't need many for this!
option(PEDANTIC_COMPILE "Enables the highest level of compiler warnings." OFF)

# Path to Steamworks SDK, we NEED this!
set(STEAMWORKS_PATH "" CACHE PATH "Path to the Steamworks SDK")

if(NOT STEAMWORKS_PATH)
    message(FATAL_ERROR "STEAMWORKS_PATH is not properly set!")
endif()

if(NOT EXISTS "${STEAMWORKS_PATH}/public/steam/steam_api.h")
    message(FATAL_ERROR "Invalid STEAMWORKS_PATH, could not find steam_api.h!")
endif()

file(GLOB SL_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

file(GLOB SL_HEADERS CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/include/*.hpp"
)

string(TIMESTAMP SL_BUILD_TIME "%Y-%m-%dT%H:%M:%SZ" UTC)

add_library(steamlua SHARED
    ${SL_SOURCES}
    ${SL_HEADERS}
)

if(PEDANTIC_COMPILE)
    message(WARNING "Enabling pedantic compilation and /WX | -Werror may render the project uncompilable!")
    if(MSVC)
        target_compile_options(steamlua PRIVATE /W4)
    else()
        target_compile_options(steamlua PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endif()

# Automagically fetching the steamapi library based on OS
if(WIN32)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(STEAMWORKS_LIB
            "${STEAMWORKS_PATH}/redistributable_bin/win64/steam_api64.lib"
        )
    else()
        set(STEAMWORKS_LIB
            "${STEAMWORKS_PATH}/redistributable_bin/steam_api.lib"
        )
    endif()

elseif(APPLE)
    set(STEAMWORKS_LIB
        "${STEAMWORKS_PATH}/redistributable_bin/osx/libsteam_api.dylib"
    )

elseif(UNIX)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(STEAMWORKS_LIB
            "${STEAMWORKS_PATH}/redistributable_bin/linux64/libsteam_api.so"
        )
    else()
        message(FATAL_ERROR "32-bit Linux Steamworks is not supported")
    endif()

else()
    message(FATAL_ERROR "Unsupported platform for Steamworks")
endif()

target_include_directories(steamlua
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${STEAMWORKS_PATH}/public
)

target_compile_definitions(steamlua PRIVATE
    SL_SYSTEM_TARGET="${CMAKE_SYSTEM_NAME}"
    SL_SYSTEM_ARCH="${CMAKE_SYSTEM_PROCESSOR}"
    SL_BUILD_TIME="${SL_BUILD_TIME}"
)

target_link_libraries(steamlua PRIVATE "${STEAMWORKS_LIB}")
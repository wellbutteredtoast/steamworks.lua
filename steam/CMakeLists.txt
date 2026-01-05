cmake_minimum_required(VERSION "3.25")
project(steamlua
    VERSION 0.0.1
    DESCRIPTION "An awesome library that binds Steamworks to Lua."
    LANGUAGES C
)

# Standard setup -- C standard, no gnu extensions, export compile commands
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Few options, we don't need many for this!
option(PEDANTIC_COMPILE "Enables the highest level of compiler warnings." OFF)
option(WARNS_ARE_ERRORS "Enables special flags that treat all compiler warnings as errors." OFF)

# Path to Steamworks SDK, we NEED this!
set(STEAMWORKS_PATH "" CACHE PATH "Path to the Steamworks SDK")

if(NOT STEAMWORKS_PATH)
    message(FATAL_ERROR "STEAMWORKS_PATH is not properly set!")
endif()

if(NOT EXISTS "${STEAMWORKS_PATH}/public/steam/steam_api.h")
    message(FATAL_ERROR "Invalid STEAMWORKS_PATH, could not find steam_api.h!")
endif()

file(GLOB SL_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.c"
)

file(GLOB SL_HEADERS CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/include/*.h"
)

string(TIMESTAMP BUILDTIME "%Y-%m-%dT%H:%M:%SZ" UTC)

add_library(steamlua
    ${SL_SOURCES}
    ${SL_HEADERS}
)

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
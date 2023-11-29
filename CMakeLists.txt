cmake_minimum_required(VERSION 3.13)
set(PICO_BOARD pico)
include(pico_sdk_import.cmake)
project(libs_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(libs
libs.c
)

add_subdirectory(./buttons)
add_subdirectory(./flash)
add_subdirectory(./ili9341)
add_subdirectory(./st7735)
add_subdirectory(./sound)

target_link_libraries(libs
		pico_stdlib
		buttons
		flash
		ili9341
		st7735
		sound
		)

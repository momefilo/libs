file(GLOB FILES *.c *.h)
add_library(sound ${FILES})
target_link_libraries(sound
	pico_stdlib
	hardware_pwm
	hardware_gpio
	hardware_clocks
)
target_include_directories(sound PUBLIC ./)

# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
# If a copy of the MPL was not distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

cmake_minimum_required(VERSION 3.22)

project(arm_cortex_m0_start LANGUAGES ASM C)

# Define all Files:
add_executable(testApp)

target_sources(
        testApp
        PRIVATE
        entry/entry.S
        entry/entry_c.c
        src/main.c
        src/misc/var_test_1.c
        src/misc/var_test_2.c
        src/misc/fibonacci.c
        src/misc/faculty.c
        src/devices/register_access.c
        src/devices/random.c
        src/devices/uart.c
        src/devices/timer.c
)

target_include_directories(
        testApp
        PRIVATE
        include
        include/devices
        include/misc
)

target_link_options(
        testApp
        PRIVATE
        -Wl,-Map=testApp.map
        -T ${CMAKE_SOURCE_DIR}/entry/linker_script.lds
)

set_target_properties(
        testApp
        PROPERTIES LINK_DEPENDS ${CMAKE_SOURCE_DIR}/entry/linker_script.lds
)


#####################################################################
# Post Build Commands:
# - extract binary


# To copy out the binary:
#arm-none-eabi-objcopy -O binary base.elf output.bin

add_custom_command(
        TARGET testApp
        POST_BUILD
        COMMAND "${OBJ_COPY}"
        ARGS -O binary $<TARGET_FILE:testApp> $<TARGET_FILE_BASE_NAME:testApp>.bin)

set_target_properties(
        testApp
        PROPERTIES ADDITIONAL_CLEAN_FILES $<TARGET_FILE_BASE_NAME:testApp>.bin)

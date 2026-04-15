cmake_minimum_required(VERSION 3.22.1)

project(GLST C)
message("Building ${PROJECT_NAME}")

set(CMAKE_VERBOSE_MAKEFILE on)
set(WARNS "-Wall -Wno-unused-function -Wimplicit-function-declaration")
if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
    list(APPEND WARNS "-Wno-discarded-qualifiers" "-Werror=incompatible-pointer-types")
else()
    list(APPEND WARNS "-Wno-incompatible-pointer-types-discards-qualifiers")
endif()
string(JOIN " " WARNS_STR ${WARNS})
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 ${WARNS_STR} -DGL_GLEXT_PROTOTYPES")

include_directories(include)

add_library(GL SHARED
            src/main.c
            src/gl_calls.c
            src/glx_calls.c
            src/arrays.c
            src/ring_buffer.c
            src/gl_buffer.c
            src/gl_vao.c)

if(ANDROID)
    target_compile_definitions(GL PRIVATE GLADIO_CLIENT)
    # Override NDK's --no-undefined (appended via CMAKE_SHARED_LINKER_FLAGS)
    # Use regex with word boundary to avoid mangling --no-undefined-version
    string(REGEX REPLACE "-Wl,--no-undefined( |$)" "" CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS}")
    find_library(log-lib log)
    target_link_libraries(GL ${log-lib})
endif()
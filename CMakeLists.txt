cmake_minimum_required(VERSION 3.10.2)
project(PocoExamples)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

# Enables address sanitizer. Needs to install llvm-symbolizer when using clang to
# be able to translate memory addresses to source code lines.
option(ADDRESS_SANITIZER "Address sanitizer" OFF)

if (CMAKE_BUILD_TYPE MATCHES Debug AND ADDRESS_SANITIZER)
    if (CMAKE_CXX_COMPILER_ID MATCHES Clang OR CMAKE_CXX_COMPILER_ID MATCHES GNU)
        message("Address sanitizer enabled")
        # Enable address sanitizer
        set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
        set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
    endif()
endif()

# Options for Debugging Your Program (https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html)
# @TODO Test Diferent Options (GDB Seems to crash due to DWARF level of debug)
option(GCC_DEBUG_ENABLE "Enable GCC Debug" OFF)

if (GCC_DEBUG_ENABLE)
  message("Gcc Enabled DEBUG")
  # Enable debug options
  set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -gw2")
  set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -gw2")

endif()

add_subdirectory(format_test)
add_subdirectory(page_compiler)
add_subdirectory(simple_http_server)
add_subdirectory(date_time_test)
add_subdirectory(intro_threads)
add_subdirectory(database_intro)




find_package(Boost REQUIRED filesystem program_options regex timer chrono)
find_package(Poco REQUIRED Foundation Util Net)

include(page_compiler_srcs.cmake)
add_library(page_compiler STATIC "${SYSTEM_SRCS}")


target_include_directories(page_compiler
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${Boost_INCLUDE_DIRS}
)


target_link_libraries(page_compiler
    PUBLIC
        Poco::Foundation
        Poco::Util
        Poco::Net
        ${Boost_INCLUDE_DIRS}
        ${Boost_FILESYSTEM_LIBRARY}               
)

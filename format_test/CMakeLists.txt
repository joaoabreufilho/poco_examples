cmake_minimum_required(VERSION 3.10.2)
find_package(Boost REQUIRED filesystem program_options regex timer chrono)
find_package(Poco REQUIRED Foundation Util Net)
set(FormatTest "${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

if (MSVC)
     if (MSVC_VERSION GREATER_EQUAL "1900")
          include(CheckCXXCompilerFlag)
          CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
          if (_cpp_latest_flag_supported)
               add_compile_options("/std:c++latest")
          endif()
     endif()
endif()

add_executable(FormatTest
	${SRC_FILES}
)

target_sources(FormatTest
	PRIVATE
	     main.cpp
)

target_link_libraries(FormatTest
    PRIVATE
        Poco::Foundation
        Poco::Util
        Poco::Net
        ${Boost_INCLUDE_DIRS}
        ${Boost_FILESYSTEM_LIBRARY}
)

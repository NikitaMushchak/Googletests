cmake_minimum_required(VERSION 2.6)
#start for win
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

#if(MSVC)
#    add_compile_options(/W4 /arch:SSE /arch:SSE2)
#    enable_testing()
#    include(GoogleTest)
#else()
#    add_compile_options(-Wall -Wextra -pedantic -Werror)
#    add_compile_options(-msse -msse2 -mssse3 -msse4 -msse4.1 -msse4.2 -ffast-math)
#    set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/modules)
#endif()

# Locate GTest
if(MSVC)
	find_package(GTest)
else()
	find_package(GTest REQUIRED)
endif()

include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

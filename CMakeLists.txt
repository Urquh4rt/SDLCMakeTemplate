cmake_minimum_required(VERSION 3.7)

project(SDL2Test)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(SDL2Test Main.cpp)
message("libs: " ${SDL2_LIBRARIES})
if (UNIX)
	target_link_libraries(SDL2Test ${SDL2_LIBRARIES} -lSDL2_image)
endif (UNIX)
if (MSVC)
	target_link_libraries(SDL2Test ${SDL2_LIBRARIES})
endif (MSVC)
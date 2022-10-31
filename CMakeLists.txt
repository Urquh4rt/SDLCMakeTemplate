cmake_minimum_required(VERSION 3.7)

project(SDL2Test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
if( ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    set(USE_FLAGS "-s USE_SDL=2 -s USE_SDL_IMAGE=2 --embed-file assets -s SDL2_IMAGE_FORMATS=\'[\"png\"]\'")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${USE_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${USE_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${USE_FLAGS}")
    set(CMAKE_EXECUTABLE_SUFFIX .html)
else()
    find_package(SDL2 REQUIRED)
endif()

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(SDL2Test Main.cpp)

if( ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
	target_link_libraries(SDL2Test)
elseif (UNIX)
	target_link_libraries(SDL2Test ${SDL2_LIBRARIES} -lSDL2_image)
else()
	target_link_libraries(SDL2Test ${SDL2_LIBRARIES})
endif()
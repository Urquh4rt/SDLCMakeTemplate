target_include_directories(SDL2Test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_sources(SDL2Test PRIVATE ${CMAKE_CURRENT_LIST_DIR}/MainLoop.cpp)


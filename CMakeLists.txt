cmake_minimum_required(VERSION 3.16)
project(CMakeSFMLProject LANGUAGES CXX)
message(${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(CMakeSFMLProject src/main.cpp src/Entity.cpp src/Monde.cpp src/Plateforme.cpp
        src/define.h
        )
target_link_libraries(CMakeSFMLProject PRIVATE sfml-graphics)
target_compile_features(CMakeSFMLProject PRIVATE cxx_std_17)
file(GLOB PNG_FILES ${CMAKE_SOURCE_DIR}/src/image/*.png)
file(COPY ${PNG_FILES} DESTINATION ${CMAKE_BINARY_DIR}/bin/image)
if(WIN32)
    add_custom_command(
            TARGET CMakeSFMLProject
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
            VERBATIM)
endif()

install(TARGETS CMakeSFMLProject)
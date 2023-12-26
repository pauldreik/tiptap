cmake_minimum_required(VERSION 3.25)

project(tiptap LANGUAGES CXX)

add_subdirectory(src)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    if(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
        add_compile_options(-Wall -Wextra -pedantic)
    elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
        add_compile_options(-Wall -Wextra -pedantic)
    elseif(MSVC)
        add_compile_options(/WX /W3 /D _CRT_SECURE_NO_WARNINGS /utf-8)
    endif()
    option(TIPTAP_SANITIZERS "use sanitizers" Off)
    option(TIPTAP_BUILD_TESTS "build unit tests" On)
    option(TIPTAP_BUILD_BENCHMARK "build benchmark" On)
    option(TIPTAP_BUILD_EXAMPLES "build examples" On)

    if(TIPTAP_SANITIZERS)
        add_compile_options(-fsanitize=undefined,address)
        add_link_options(-fsanitize=undefined,address)
    endif()

    if(TIPTAP_BUILD_TESTS)
        add_subdirectory(tests)
    endif()

    if(TIPTAP_BUILD_BENCHMARK)
        add_subdirectory(benchmark)
    endif()
    if(TIPTAP_BUILD_EXAMPLES)
        add_subdirectory(examples)
    endif()
endif()



cmake_minimum_required(VERSION 3.25)

project(tiptap LANGUAGES CXX)

add_subdirectory(src)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    add_compile_options(-Wall -Wextra -pedantic)

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



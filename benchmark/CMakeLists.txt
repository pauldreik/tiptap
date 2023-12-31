#Include(FetchContent)

#FetchContent_Declare(
#    Catch2
#    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#    GIT_TAG        v3.5.0 # or a later release
#)
#FetchContent_MakeAvailable(Catch2)
find_package(Catch2 REQUIRED)


find_package(vectorclass)

if(vectorclass_FOUND)
    add_compile_definitions(HAVE_VECTORCLASS=1)
endif()

add_executable(benchmark benchmark.cpp)
target_link_libraries(benchmark PRIVATE tiptap Catch2::Catch2WithMain)

add_executable(extensive_benchmark extensive_benchmark.cpp)
target_link_libraries(extensive_benchmark PRIVATE tiptap Catch2::Catch2WithMain)




add_executable(helloworld helloworld.cpp)
target_link_libraries(helloworld PRIVATE tiptap)

add_executable(constexpr constexpr.cpp)
target_link_libraries(constexpr PRIVATE tiptap)



#Include(FetchContent)

#FetchContent_Declare(
#    Catch2
#    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#    GIT_TAG        v3.5.0 # or a later release
#)
#FetchContent_MakeAvailable(Catch2)

find_package(Catch2 REQUIRED)


enable_testing()


add_executable(test_bignum test_bignum.cpp)
target_link_libraries(test_bignum PRIVATE tiptap Catch2::Catch2WithMain)
add_test(test_bignum test_bignum)

add_executable(test_integerselect test_integerselect.cpp)
target_link_libraries(test_integerselect PRIVATE tiptap Catch2::Catch2WithMain)
add_test(test_integerselect test_integerselect)

add_executable(test_lfsr_coefficients test_lfsr_coefficients.cpp)
target_link_libraries(test_lfsr_coefficients PRIVATE tiptap Catch2::Catch2WithMain)
add_test(test_lfsr_coefficients test_lfsr_coefficients)

add_executable(test_small_lfsr test_small_lfsr.cpp)
target_link_libraries(test_small_lfsr PRIVATE tiptap Catch2::Catch2WithMain)
add_test(test_small_lfsr test_small_lfsr)

add_executable(test_large_lfsr test_large_lfsr.cpp)
target_link_libraries(test_large_lfsr PRIVATE tiptap Catch2::Catch2WithMain)
add_test(test_large_lfsr test_large_lfsr)

find_package(vectorclass)

if(vectorclass_FOUND)
    add_executable(test_vectorclass_lfsr test_vectorclass_lfsr.cpp)
    target_link_libraries(test_vectorclass_lfsr PRIVATE vectorclass::vectorclass tiptap Catch2::Catch2WithMain vectorclass::vectorclass)
    add_test(test_vectorclass_lfsr test_vectorclass_lfsr)
endif()

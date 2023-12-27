add_executable(helloworld helloworld.cpp)
target_link_libraries(helloworld PRIVATE tiptap)

add_executable(hellobigworld hellobigworld.cpp)
target_link_libraries(hellobigworld PRIVATE tiptap)

add_executable(constexpr constexpr.cpp)
target_link_libraries(constexpr PRIVATE tiptap)



# check for aes-ni availability for the encrypted counter example
file(WRITE
    ${CMAKE_BINARY_DIR}/checkForAesIntrinsics.cpp
    "#include <wmmintrin.h>
    int main(){
    const char buf[16]{};
    __m128i m = _mm_loadu_si128((const __m128i*)&buf);
    __m128i key = _mm_loadu_si128((const __m128i*)&buf);
    m = _mm_aesenc_si128(m, key);
    _mm_storeu_si128((__m128i*)buf, m);
    return buf[0];}
    "
)

try_compile(HAS_AES_INTRINSICS
    ${CMAKE_BINARY_DIR}
    ${CMAKE_BINARY_DIR}/checkForAesIntrinsics.cpp
)

if(HAS_AES_INTRINSICS)
    message(STATUS "found aes intrinsics, will build the encrypted counter example")
    add_executable(encryptedcounter encryptedcounter.cpp)
    target_link_libraries(encryptedcounter PRIVATE tiptap)
else()
    message(STATUS "could not find aes intrinsics, won't build the encrypted counter example")
endif()

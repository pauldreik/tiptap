get_filename_component(include_dir ${CMAKE_CURRENT_SOURCE_DIR}/../include/tiptap ABSOLUTE)

add_library(tiptap
    ${include_dir}/lfsr_coefficients.h
    ${include_dir}/lfsr.h
    ${include_dir}/lfsr_big.h
    ${include_dir}/lfsr_small.h
    ${include_dir}/bignum.h
    ${include_dir}/integerselect.h
    ${include_dir}/lfsr_coefficients.h
    bignum.cpp
)

target_include_directories(tiptap PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    )

target_compile_features(tiptap PUBLIC cxx_std_20)
add_library(tiptap::tiptap ALIAS tiptap)

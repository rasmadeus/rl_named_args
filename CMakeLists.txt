cmake_minimum_required(VERSION 3.14)
project(rl_named_args VERSION 1.0 LANGUAGES CXX)

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_17)

set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(compiler_flags INTERFACE "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>")

include_directories(NamedType-1.0.0)

add_executable(
    rl_named_args
    main.cpp
)

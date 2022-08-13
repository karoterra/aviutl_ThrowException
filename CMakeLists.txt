cmake_minimum_required(VERSION 3.20)
project(aviutl_ThrowException)

set(AVIUTL_INCLUDE_DIR "vendor" CACHE PATH "AviUtl Plugin SDK include dir")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(ThrowException SHARED
    src/throw_exception.cpp
)
target_include_directories(ThrowException PRIVATE
    ${AVIUTL_INCLUDE_DIR}
    ${AVIUTL_INCLUDE_DIR}/aviutl_exedit_sdk
)
set_target_properties(ThrowException PROPERTIES SUFFIX .auf)

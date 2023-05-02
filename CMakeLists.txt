cmake_minimum_required(VERSION 3.25.2)

set(CMAKE_CXX_STANDARD 11)

project(blockchain)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(OpenSSL REQUIRED)

file(GLOB files
     "src/*.cpp"
     "src/*/*.cpp"
)

add_executable(${PROJECT_NAME} ${files})

target_link_libraries( ${PROJECT_NAME}
     OpenSSL::SSL
     OpenSSL::Crypto
)
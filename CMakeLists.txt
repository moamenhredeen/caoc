cmake_minimum_required(VERSION 3.10)

project(caoc VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Export compile commands for clangd/IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Project directories
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Source files
set(SOURCES
    ${SRC_DIR}/2024/01.c
    ${SRC_DIR}/2024/02.c
)


# Include directories
target_include_directories(caoc PRIVATE ${INCLUDE_DIR})


# Set output directory
set_target_properties(caoc PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Debug configuration
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(caoc PRIVATE DEBUG=1)
    target_compile_options(caoc PRIVATE -g -Wall -Wextra)
endif()

# file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})

#-------------------------------------------------------
# Testing Configuration
#-------------------------------------------------------

# Enable testing
enable_testing()

# Test directories
set(TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tests")
set(TEST_UNITY_DIR "${TEST_DIR}/unity")

# Unity test framework sources
set(UNITY_SOURCES
    ${TEST_UNITY_DIR}/unity.c
)

# Library for shared functionality (exclude main.c)
set(LIB_SOURCES
    ${SRC_DIR}/http_client.c
    ${SRC_DIR}/http_parser.c
    ${SRC_DIR}/store.c
)

# Create a library for testing (without main.c)
add_library(apikit_lib STATIC ${LIB_SOURCES} ${THIRD_PARTY_SOURCES})

target_include_directories(apikit_lib PUBLIC
    ${INCLUDE_DIR}
    ${LIBS_DIR}/nuklear
    ${LIBS_DIR}/tomlc99
    ${CURL_INCLUDE_DIR}
)

target_link_libraries(apikit_lib PUBLIC 
    ${CURL_LIBRARY}
)

# Test executable for HTTP parser
add_executable(test_http_parser
    ${TEST_DIR}/test_http_parser.c
    ${UNITY_SOURCES}
)

target_include_directories(test_http_parser PRIVATE
    ${INCLUDE_DIR}
    ${TEST_DIR}
)

target_link_libraries(test_http_parser PRIVATE
    apikit_lib
)

# Test executable for HTTP client
add_executable(test_http_client
    ${TEST_DIR}/test_http_client.c
    ${UNITY_SOURCES}
)

target_include_directories(test_http_client PRIVATE
    ${INCLUDE_DIR}
    ${TEST_DIR}
)

target_link_libraries(test_http_client PRIVATE
    apikit_lib
    pthread  # Required for threading in HTTP client tests
)

# Simple HTTP client test (without mock server)
add_executable(test_simple_client
    ${TEST_DIR}/test_simple_client.c
    ${UNITY_SOURCES}
)

target_include_directories(test_simple_client PRIVATE
    ${INCLUDE_DIR}
    ${TEST_DIR}
)

target_link_libraries(test_simple_client PRIVATE
    apikit_lib
)

# Add tests to CTest
add_test(NAME HttpParserTests COMMAND test_http_parser)
add_test(NAME HttpClientTests COMMAND test_http_client)
add_test(NAME SimpleClientTests COMMAND test_simple_client)

# Set test properties
set_tests_properties(HttpParserTests PROPERTIES
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    TIMEOUT 30
)

set_tests_properties(HttpClientTests PROPERTIES
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    TIMEOUT 60
)

set_tests_properties(SimpleClientTests PROPERTIES
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    TIMEOUT 30
)







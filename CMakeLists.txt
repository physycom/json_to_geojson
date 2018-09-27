cmake_minimum_required (VERSION 3.1)
project (json_to_geojson)

if (EXISTS "$ENV{WORKSPACE}/sysconfig/cmake/physycom_config.cmake")
   message(STATUS "Enabling physycom settings")
   include("$ENV{WORKSPACE}/sysconfig/cmake/physycom_config.cmake")
else()
   message(STATUS "Unable to find physycom settings file")
endif()

set(JSONCONS_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src/jsoncons/include)
include_directories(${JSONCONS_INCLUDE_DIR})

add_executable(json_to_geojson ${CMAKE_SOURCE_DIR}/src/json_to_geojson.cpp)
add_executable(geojson_to_json ${CMAKE_SOURCE_DIR}/src/geojson_to_json.cpp)

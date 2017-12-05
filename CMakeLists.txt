cmake_minimum_required(VERSION 3.8)
project(DynamicRoutingProject)

# Place targets into their own solution folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

file(GLOB_RECURSE HEADER_FILES src/*.h )
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
file(GLOB CONFIG_FILES CMakeLists.txt README.md .gitignore)

# Define source file groupings
source_group("Header" FILES ${HEADER_FILES})
source_group("Source" FILES ${SOURCE_FILES})
source_group("Config" FILES ${CONFIG_FILES})

# Define the executable
add_executable(${PROJECT_NAME}	${HEADER_FILES} ${SOURCE_FILES} ${CONFIG_FILES})

# Ensure C++14
set_target_properties(${PROJECT_NAME} PROPERTIES
    CMAKE_CXX_STANDARD 14
    CMAKE_CXX_STANDARD_REQUIRED on
    CXX_EXTENSIONS NO   
)
# Get the exercise name from the current directory
get_filename_component(root_folder ${CMAKE_CURRENT_SOURCE_DIR} NAME)

string(REPLACE "-" "_" project_name ${root_folder})

# Set the minimum version of CMake that can be used To find the cmake version
# run $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project(${project_name})

# Create a sources variable with a link to all cpp files to compile
set(SOURCES main.cpp catch2/catch_amalgamated.cpp)

# Add an executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Set the directories that should be included in the build command for this
# target when running g++ these will be included as -I/directory/path/
# target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/catch2)

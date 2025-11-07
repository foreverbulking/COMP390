cmake_minimum_required(VERSION 3.26)
project(Assignment3)
set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)

# Program 1 - OpenGL lighting & materials
add_executable(Program1_Lighting
        program_1/main.cpp
        program_1/program_1.cpp
)
target_link_libraries(Program1_Lighting "-framework OpenGL" "-framework GLUT")

# Program 2 - Manual lighting with specular term (vector3)
add_executable(Program2_Specular
        program_2/program_2.cpp
        program_2/vector3.cpp
        program_2/vector3.h
)
target_link_libraries(Program2_Specular "-framework OpenGL" "-framework GLUT")

# Program 3 - OpenGL lighting with background
add_executable(Program3_3D
        program_3/main.cpp
        program_3/program_3.cpp
        program_3/program_3.h
)
target_link_libraries(Program3_3D "-framework OpenGL" "-framework GLUT")
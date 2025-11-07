add_executable(Program1_3D program_1/main.cpp program_1/program_1.cpp
        program_2/program_2.cpp
        program_2/program_2.h)
target_link_libraries(Program1_3D "-framework OpenGL" "-framework GLUT")

add_executable(Program2_3D
        program_2/main.cpp
        program_2/program_2.cpp
)
target_link_libraries(Program2_3D "-framework OpenGL" "-framework GLUT")
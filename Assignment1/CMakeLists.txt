cmake_minimum_required(VERSION 3.26)
project(Assignment1)
set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)

# shared file used by both programs
set(COMMON_SRC house.cpp)

if(APPLE)
    if(APPLE)
        add_executable(Program1 program_1/main.cpp ${COMMON_SRC})
        target_link_libraries(Program1 "-framework OpenGL" "-framework GLUT")

        add_executable(Program2 program_2/main.cpp ${COMMON_SRC})
        target_link_libraries(Program2 "-framework OpenGL" "-framework GLUT")

        add_executable(Program3 program_3/main.cpp)
        target_link_libraries(Program3 "-framework OpenGL" "-framework GLUT")
    endif()
else()
    find_package(GLUT REQUIRED)
    include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
    add_executable(Program1 program_1/main.cpp ${COMMON_SRC})
    target_link_libraries(Program1 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
    add_executable(Program2 program_2/main.cpp ${COMMON_SRC})
    target_link_libraries(Program2 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
    add_executable(Program3 program_3/main.cpp ${COMMON_SRC})
    target_link_libraries(Program3 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
endif()
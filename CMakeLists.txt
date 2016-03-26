cmake_minimum_required(VERSION 3.5)

add_library(ELTEVectorMath include/Vector.h include/Matrix.h include/Quaternion.h include/SSEVector.h include/SSEMatrix.h include/SSEQuaternion.h src/Vector.cpp src/Matrix.cpp src/Quaternion.cpp src/SSEVector.cpp src/SSEMatrix.cpp src/SSEQuaternion.cpp)

add_executable(ELTEVectorMath_Test test/main.cpp)

target_link_libraries(ELTEVectorMath_Test ELTEVectorMath)
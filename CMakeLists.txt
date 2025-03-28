# CMakeList.txt : CMake project for raytracerFinishedCPU, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("raytracerFinishedCPU")

# Add source to this project's executable.
add_executable (raytracerFinishedCPU "main.cpp" "main.h" "tracer/fileIO/writeToBMP.cpp" "tracer/structs/ray.cpp" "tracer/structs/utils/rng.cpp" "tracer/structs/vectors.cpp" "tracer/structs/color.cpp" "tracer/structs/shapes.cpp" "tracer/structs/screen.cpp" "tracer/structs/screen.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET raytracerFinishedCPU PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

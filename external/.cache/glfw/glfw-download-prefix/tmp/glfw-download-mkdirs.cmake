# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/cmake/../external/glfw"
  "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/cmake-build-debug/glfw-build"
  "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/glfw/glfw-download-prefix"
  "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/glfw/glfw-download-prefix/tmp"
  "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/glfw/glfw-download-prefix/src/glfw-download-stamp"
  "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/glfw/glfw-download-prefix/src"
  "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/glfw/glfw-download-prefix/src/glfw-download-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/glfw/glfw-download-prefix/src/glfw-download-stamp/${subDir}")
endforeach()

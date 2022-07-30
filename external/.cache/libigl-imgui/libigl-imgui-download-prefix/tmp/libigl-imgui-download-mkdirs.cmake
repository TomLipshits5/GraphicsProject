# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/cmake/../external/libigl-imgui"
  "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/cmake-build-debug/libigl-imgui-build"
  "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/libigl-imgui/libigl-imgui-download-prefix"
  "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/libigl-imgui/libigl-imgui-download-prefix/tmp"
  "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/libigl-imgui/libigl-imgui-download-prefix/src/libigl-imgui-download-stamp"
  "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/libigl-imgui/libigl-imgui-download-prefix/src"
  "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/libigl-imgui/libigl-imgui-download-prefix/src/libigl-imgui-download-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/libigl-imgui/libigl-imgui-download-prefix/src/libigl-imgui-download-stamp/${subDir}")
endforeach()

# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if(EXISTS "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/libigl-imgui/libigl-imgui-download-prefix/src/libigl-imgui-download-stamp/libigl-imgui-download-gitclone-lastrun.txt" AND EXISTS "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/libigl-imgui/libigl-imgui-download-prefix/src/libigl-imgui-download-stamp/libigl-imgui-download-gitinfo.txt" AND
  "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/libigl-imgui/libigl-imgui-download-prefix/src/libigl-imgui-download-stamp/libigl-imgui-download-gitclone-lastrun.txt" IS_NEWER_THAN "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/libigl-imgui/libigl-imgui-download-prefix/src/libigl-imgui-download-stamp/libigl-imgui-download-gitinfo.txt")
  message(STATUS
    "Avoiding repeated git clone, stamp file is up to date: "
    "'/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/libigl-imgui/libigl-imgui-download-prefix/src/libigl-imgui-download-stamp/libigl-imgui-download-gitclone-lastrun.txt'"
  )
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/cmake/../external/libigl-imgui"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/cmake/../external/libigl-imgui'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git" -c http.sslVerify=false
            clone --no-checkout --config "advice.detachedHead=false" --config "advice.detachedHead=false" "https://github.com/libigl/libigl-imgui.git" "libigl-imgui"
    WORKING_DIRECTORY "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/cmake/../external"
    RESULT_VARIABLE error_code
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once: ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/libigl/libigl-imgui.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git" -c http.sslVerify=false
          checkout "7e1053e750b0f4c129b046f4e455243cb7f804f3" --
  WORKING_DIRECTORY "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/cmake/../external/libigl-imgui"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: '7e1053e750b0f4c129b046f4e455243cb7f804f3'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git" -c http.sslVerify=false
            submodule update --recursive --init 
    WORKING_DIRECTORY "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/cmake/../external/libigl-imgui"
    RESULT_VARIABLE error_code
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/cmake/../external/libigl-imgui'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/libigl-imgui/libigl-imgui-download-prefix/src/libigl-imgui-download-stamp/libigl-imgui-download-gitinfo.txt" "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/libigl-imgui/libigl-imgui-download-prefix/src/libigl-imgui-download-stamp/libigl-imgui-download-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/libigl-imgui/libigl-imgui-download-prefix/src/libigl-imgui-download-stamp/libigl-imgui-download-gitclone-lastrun.txt'")
endif()

# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if(EXISTS "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/glad/glad-download-prefix/src/glad-download-stamp/glad-download-gitclone-lastrun.txt" AND EXISTS "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/glad/glad-download-prefix/src/glad-download-stamp/glad-download-gitinfo.txt" AND
  "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/glad/glad-download-prefix/src/glad-download-stamp/glad-download-gitclone-lastrun.txt" IS_NEWER_THAN "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/glad/glad-download-prefix/src/glad-download-stamp/glad-download-gitinfo.txt")
  message(STATUS
    "Avoiding repeated git clone, stamp file is up to date: "
    "'/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/glad/glad-download-prefix/src/glad-download-stamp/glad-download-gitclone-lastrun.txt'"
  )
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/cmake/../external/glad"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/cmake/../external/glad'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git" -c http.sslVerify=false
            clone --no-checkout --config "advice.detachedHead=false" --config "advice.detachedHead=false" "https://github.com/libigl/libigl-glad.git" "glad"
    WORKING_DIRECTORY "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/cmake/../external"
    RESULT_VARIABLE error_code
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once: ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/libigl/libigl-glad.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git" -c http.sslVerify=false
          checkout "09b4969c56779f7ddf8e6176ec1873184aec890f" --
  WORKING_DIRECTORY "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/cmake/../external/glad"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: '09b4969c56779f7ddf8e6176ec1873184aec890f'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git" -c http.sslVerify=false
            submodule update --recursive --init 
    WORKING_DIRECTORY "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/cmake/../external/glad"
    RESULT_VARIABLE error_code
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/cmake/../external/glad'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/glad/glad-download-prefix/src/glad-download-stamp/glad-download-gitinfo.txt" "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/glad/glad-download-prefix/src/glad-download-stamp/glad-download-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/ProjectTomAndSteven/external/.cache/glad/glad-download-prefix/src/glad-download-stamp/glad-download-gitclone-lastrun.txt'")
endif()

# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/203/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/203/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb"

# Utility rule file for stb-download.

# Include any custom commands dependencies for this target.
include CMakeFiles/stb-download.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/stb-download.dir/progress.make

CMakeFiles/stb-download: CMakeFiles/stb-download-complete

CMakeFiles/stb-download-complete: stb-download-prefix/src/stb-download-stamp/stb-download-install
CMakeFiles/stb-download-complete: stb-download-prefix/src/stb-download-stamp/stb-download-mkdir
CMakeFiles/stb-download-complete: stb-download-prefix/src/stb-download-stamp/stb-download-download
CMakeFiles/stb-download-complete: stb-download-prefix/src/stb-download-stamp/stb-download-update
CMakeFiles/stb-download-complete: stb-download-prefix/src/stb-download-stamp/stb-download-patch
CMakeFiles/stb-download-complete: stb-download-prefix/src/stb-download-stamp/stb-download-configure
CMakeFiles/stb-download-complete: stb-download-prefix/src/stb-download-stamp/stb-download-build
CMakeFiles/stb-download-complete: stb-download-prefix/src/stb-download-stamp/stb-download-install
CMakeFiles/stb-download-complete: stb-download-prefix/src/stb-download-stamp/stb-download-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Completed 'stb-download'"
	/snap/clion/203/bin/cmake/linux/bin/cmake -E make_directory "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/CMakeFiles"
	/snap/clion/203/bin/cmake/linux/bin/cmake -E touch "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/CMakeFiles/stb-download-complete"
	/snap/clion/203/bin/cmake/linux/bin/cmake -E touch "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/stb-download-prefix/src/stb-download-stamp/stb-download-done"

stb-download-prefix/src/stb-download-stamp/stb-download-build: stb-download-prefix/src/stb-download-stamp/stb-download-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'stb-download'"
	cd "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/cmake-build-debug/stb-build" && /snap/clion/203/bin/cmake/linux/bin/cmake -E echo_append
	cd "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/cmake-build-debug/stb-build" && /snap/clion/203/bin/cmake/linux/bin/cmake -E touch "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/stb-download-prefix/src/stb-download-stamp/stb-download-build"

stb-download-prefix/src/stb-download-stamp/stb-download-configure: stb-download-prefix/tmp/stb-download-cfgcmd.txt
stb-download-prefix/src/stb-download-stamp/stb-download-configure: stb-download-prefix/src/stb-download-stamp/stb-download-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'stb-download'"
	cd "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/cmake-build-debug/stb-build" && /snap/clion/203/bin/cmake/linux/bin/cmake -E echo_append
	cd "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/cmake-build-debug/stb-build" && /snap/clion/203/bin/cmake/linux/bin/cmake -E touch "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/stb-download-prefix/src/stb-download-stamp/stb-download-configure"

stb-download-prefix/src/stb-download-stamp/stb-download-download: stb-download-prefix/src/stb-download-stamp/stb-download-gitinfo.txt
stb-download-prefix/src/stb-download-stamp/stb-download-download: stb-download-prefix/src/stb-download-stamp/stb-download-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'stb-download'"
	cd "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external" && /snap/clion/203/bin/cmake/linux/bin/cmake -P "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/stb-download-prefix/tmp/stb-download-gitclone.cmake"
	cd "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external" && /snap/clion/203/bin/cmake/linux/bin/cmake -E touch "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/stb-download-prefix/src/stb-download-stamp/stb-download-download"

stb-download-prefix/src/stb-download-stamp/stb-download-install: stb-download-prefix/src/stb-download-stamp/stb-download-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'stb-download'"
	cd "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/cmake-build-debug/stb-build" && /snap/clion/203/bin/cmake/linux/bin/cmake -E echo_append
	cd "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/cmake-build-debug/stb-build" && /snap/clion/203/bin/cmake/linux/bin/cmake -E touch "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/stb-download-prefix/src/stb-download-stamp/stb-download-install"

stb-download-prefix/src/stb-download-stamp/stb-download-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'stb-download'"
	/snap/clion/203/bin/cmake/linux/bin/cmake -P "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/stb-download-prefix/tmp/stb-download-mkdirs.cmake"
	/snap/clion/203/bin/cmake/linux/bin/cmake -E touch "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/stb-download-prefix/src/stb-download-stamp/stb-download-mkdir"

stb-download-prefix/src/stb-download-stamp/stb-download-patch: stb-download-prefix/src/stb-download-stamp/stb-download-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'stb-download'"
	/snap/clion/203/bin/cmake/linux/bin/cmake -E echo_append
	/snap/clion/203/bin/cmake/linux/bin/cmake -E touch "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/stb-download-prefix/src/stb-download-stamp/stb-download-patch"

stb-download-prefix/src/stb-download-stamp/stb-download-test: stb-download-prefix/src/stb-download-stamp/stb-download-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'stb-download'"
	cd "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/cmake-build-debug/stb-build" && /snap/clion/203/bin/cmake/linux/bin/cmake -E echo_append
	cd "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/cmake-build-debug/stb-build" && /snap/clion/203/bin/cmake/linux/bin/cmake -E touch "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/stb-download-prefix/src/stb-download-stamp/stb-download-test"

stb-download-prefix/src/stb-download-stamp/stb-download-update: stb-download-prefix/src/stb-download-stamp/stb-download-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'stb-download'"
	cd "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/stb" && /snap/clion/203/bin/cmake/linux/bin/cmake -P "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/stb-download-prefix/tmp/stb-download-gitupdate.cmake"

stb-download: CMakeFiles/stb-download
stb-download: CMakeFiles/stb-download-complete
stb-download: stb-download-prefix/src/stb-download-stamp/stb-download-build
stb-download: stb-download-prefix/src/stb-download-stamp/stb-download-configure
stb-download: stb-download-prefix/src/stb-download-stamp/stb-download-download
stb-download: stb-download-prefix/src/stb-download-stamp/stb-download-install
stb-download: stb-download-prefix/src/stb-download-stamp/stb-download-mkdir
stb-download: stb-download-prefix/src/stb-download-stamp/stb-download-patch
stb-download: stb-download-prefix/src/stb-download-stamp/stb-download-test
stb-download: stb-download-prefix/src/stb-download-stamp/stb-download-update
stb-download: CMakeFiles/stb-download.dir/build.make
.PHONY : stb-download

# Rule to build all files generated by this target.
CMakeFiles/stb-download.dir/build: stb-download
.PHONY : CMakeFiles/stb-download.dir/build

CMakeFiles/stb-download.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stb-download.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stb-download.dir/clean

CMakeFiles/stb-download.dir/depend:
	cd "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb" "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb" "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb" "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb" "/home/tomcooll/Desktop/Personal/Computer Science/Semester_D/FinalProjectSubmition/external/.cache/stb/CMakeFiles/stb-download.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/stb-download.dir/depend

# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2016.3.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2016.3.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\cmake-build-debug

# Include any dependencies generated for this target.
include lib/googletest-master/googlemock/CMakeFiles/gmock.dir/depend.make

# Include the progress variables for this target.
include lib/googletest-master/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include lib/googletest-master/googlemock/CMakeFiles/gmock.dir/flags.make

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.obj: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/flags.make
lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.obj: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/includes_CXX.rsp
lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.obj: ../lib/googletest-master/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.obj"
	cd /d C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\cmake-build-debug\lib\googletest-master\googlemock && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gmock.dir\__\googletest\src\gtest-all.cc.obj -c C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\lib\googletest-master\googletest\src\gtest-all.cc

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i"
	cd /d C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\cmake-build-debug\lib\googletest-master\googlemock && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\lib\googletest-master\googletest\src\gtest-all.cc > CMakeFiles\gmock.dir\__\googletest\src\gtest-all.cc.i

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s"
	cd /d C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\cmake-build-debug\lib\googletest-master\googlemock && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\lib\googletest-master\googletest\src\gtest-all.cc -o CMakeFiles\gmock.dir\__\googletest\src\gtest-all.cc.s

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.obj.requires:

.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.obj.requires

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.obj.provides: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.obj.requires
	$(MAKE) -f lib\googletest-master\googlemock\CMakeFiles\gmock.dir\build.make lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.obj.provides.build
.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.obj.provides

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.obj.provides.build: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.obj


lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/flags.make
lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/includes_CXX.rsp
lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj: ../lib/googletest-master/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj"
	cd /d C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\cmake-build-debug\lib\googletest-master\googlemock && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gmock.dir\src\gmock-all.cc.obj -c C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\lib\googletest-master\googlemock\src\gmock-all.cc

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /d C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\cmake-build-debug\lib\googletest-master\googlemock && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\lib\googletest-master\googlemock\src\gmock-all.cc > CMakeFiles\gmock.dir\src\gmock-all.cc.i

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /d C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\cmake-build-debug\lib\googletest-master\googlemock && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\lib\googletest-master\googlemock\src\gmock-all.cc -o CMakeFiles\gmock.dir\src\gmock-all.cc.s

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj.requires:

.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj.requires

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj.provides: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj.requires
	$(MAKE) -f lib\googletest-master\googlemock\CMakeFiles\gmock.dir\build.make lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj.provides.build
.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj.provides

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj.provides.build: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj


# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.obj" \
"CMakeFiles/gmock.dir/src/gmock-all.cc.obj"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

lib/googletest-master/googlemock/libgmock.a: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.obj
lib/googletest-master/googlemock/libgmock.a: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj
lib/googletest-master/googlemock/libgmock.a: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/build.make
lib/googletest-master/googlemock/libgmock.a: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libgmock.a"
	cd /d C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\cmake-build-debug\lib\googletest-master\googlemock && $(CMAKE_COMMAND) -P CMakeFiles\gmock.dir\cmake_clean_target.cmake
	cd /d C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\cmake-build-debug\lib\googletest-master\googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gmock.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/googletest-master/googlemock/CMakeFiles/gmock.dir/build: lib/googletest-master/googlemock/libgmock.a

.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock.dir/build

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/requires: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.obj.requires
lib/googletest-master/googlemock/CMakeFiles/gmock.dir/requires: lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.obj.requires

.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock.dir/requires

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/clean:
	cd /d C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\cmake-build-debug\lib\googletest-master\googlemock && $(CMAKE_COMMAND) -P CMakeFiles\gmock.dir\cmake_clean.cmake
.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock.dir/clean

lib/googletest-master/googlemock/CMakeFiles/gmock.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\lib\googletest-master\googlemock C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\cmake-build-debug C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\cmake-build-debug\lib\googletest-master\googlemock C:\Users\Alexandre\Documents\UQAM\principes_avances_des_langages_a_objets\FarStar\cmake-build-debug\lib\googletest-master\googlemock\CMakeFiles\gmock.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib/googletest-master/googlemock/CMakeFiles/gmock.dir/depend


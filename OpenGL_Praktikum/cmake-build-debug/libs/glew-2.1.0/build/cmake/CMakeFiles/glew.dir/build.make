# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.1.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.1.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum\cmake-build-debug

# Include any dependencies generated for this target.
include libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/progress.make

# Include the compile flags for this target's objects.
include libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/flags.make

libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.obj: libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/flags.make
libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.obj: libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/includes_C.rsp
libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.obj: C:/Users/dangm/Documents/OpenGL_Praktikum_Framework/OpenGL_Praktikum/libs/glew-2.1.0/src/glew.c
libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.obj: libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.obj"
	cd /d C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum\cmake-build-debug\libs\glew-2.1.0\build\cmake && C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.obj -MF CMakeFiles\glew.dir\__\__\src\glew.c.obj.d -o CMakeFiles\glew.dir\__\__\src\glew.c.obj -c C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum\libs\glew-2.1.0\src\glew.c

libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glew.dir/__/__/src/glew.c.i"
	cd /d C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum\cmake-build-debug\libs\glew-2.1.0\build\cmake && C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum\libs\glew-2.1.0\src\glew.c > CMakeFiles\glew.dir\__\__\src\glew.c.i

libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glew.dir/__/__/src/glew.c.s"
	cd /d C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum\cmake-build-debug\libs\glew-2.1.0\build\cmake && C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum\libs\glew-2.1.0\src\glew.c -o CMakeFiles\glew.dir\__\__\src\glew.c.s

libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/glew.rc.obj: libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/flags.make
libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/glew.rc.obj: C:/Users/dangm/Documents/OpenGL_Praktikum_Framework/OpenGL_Praktikum/libs/glew-2.1.0/build/glew.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building RC object libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/glew.rc.obj"
	cd /d C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum\cmake-build-debug\libs\glew-2.1.0\build\cmake && C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum\libs\glew-2.1.0\build\glew.rc CMakeFiles\glew.dir\__\glew.rc.obj

# Object files for target glew
glew_OBJECTS = \
"CMakeFiles/glew.dir/__/__/src/glew.c.obj" \
"CMakeFiles/glew.dir/__/glew.rc.obj"

# External object files for target glew
glew_EXTERNAL_OBJECTS =

bin/glew32d.dll: libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.obj
bin/glew32d.dll: libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/glew.rc.obj
bin/glew32d.dll: libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/build.make
bin/glew32d.dll: libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/linkLibs.rsp
bin/glew32d.dll: libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/objects1
bin/glew32d.dll: libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C shared library ..\..\..\..\bin\glew32d.dll"
	cd /d C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum\cmake-build-debug\libs\glew-2.1.0\build\cmake && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\glew.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/build: bin/glew32d.dll
.PHONY : libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/build

libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/clean:
	cd /d C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum\cmake-build-debug\libs\glew-2.1.0\build\cmake && $(CMAKE_COMMAND) -P CMakeFiles\glew.dir\cmake_clean.cmake
.PHONY : libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/clean

libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum\libs\glew-2.1.0\build\cmake C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum\cmake-build-debug C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum\cmake-build-debug\libs\glew-2.1.0\build\cmake C:\Users\dangm\Documents\OpenGL_Praktikum_Framework\OpenGL_Praktikum\cmake-build-debug\libs\glew-2.1.0\build\cmake\CMakeFiles\glew.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/depend


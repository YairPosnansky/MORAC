# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = C:\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\posna\Desktop\DEV\YaronJava\MORAC\src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\posna\Desktop\DEV\YaronJava\MORAC\build

# Include any dependencies generated for this target.
include CMakeFiles/morac.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/morac.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/morac.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/morac.dir/flags.make

CMakeFiles/morac.dir/src/main.c.obj: CMakeFiles/morac.dir/flags.make
CMakeFiles/morac.dir/src/main.c.obj: CMakeFiles/morac.dir/includes_C.rsp
CMakeFiles/morac.dir/src/main.c.obj: C:/Users/posna/Desktop/DEV/YaronJava/MORAC/src/src/main.c
CMakeFiles/morac.dir/src/main.c.obj: CMakeFiles/morac.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\posna\Desktop\DEV\YaronJava\MORAC\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/morac.dir/src/main.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/morac.dir/src/main.c.obj -MF CMakeFiles\morac.dir\src\main.c.obj.d -o CMakeFiles\morac.dir\src\main.c.obj -c C:\Users\posna\Desktop\DEV\YaronJava\MORAC\src\src\main.c

CMakeFiles/morac.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/morac.dir/src/main.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\posna\Desktop\DEV\YaronJava\MORAC\src\src\main.c > CMakeFiles\morac.dir\src\main.c.i

CMakeFiles/morac.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/morac.dir/src/main.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\posna\Desktop\DEV\YaronJava\MORAC\src\src\main.c -o CMakeFiles\morac.dir\src\main.c.s

# Object files for target morac
morac_OBJECTS = \
"CMakeFiles/morac.dir/src/main.c.obj"

# External object files for target morac
morac_EXTERNAL_OBJECTS =

morac.exe: CMakeFiles/morac.dir/src/main.c.obj
morac.exe: CMakeFiles/morac.dir/build.make
morac.exe: liblexer.a
morac.exe: libmoracc.a
morac.exe: CMakeFiles/morac.dir/linkLibs.rsp
morac.exe: CMakeFiles/morac.dir/objects1.rsp
morac.exe: CMakeFiles/morac.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\posna\Desktop\DEV\YaronJava\MORAC\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable morac.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\morac.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/morac.dir/build: morac.exe
.PHONY : CMakeFiles/morac.dir/build

CMakeFiles/morac.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\morac.dir\cmake_clean.cmake
.PHONY : CMakeFiles/morac.dir/clean

CMakeFiles/morac.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\posna\Desktop\DEV\YaronJava\MORAC\src C:\Users\posna\Desktop\DEV\YaronJava\MORAC\src C:\Users\posna\Desktop\DEV\YaronJava\MORAC\build C:\Users\posna\Desktop\DEV\YaronJava\MORAC\build C:\Users\posna\Desktop\DEV\YaronJava\MORAC\build\CMakeFiles\morac.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/morac.dir/depend


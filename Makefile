# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yqm/Git/MyUtil

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yqm/Git/MyUtil

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/yqm/Git/MyUtil/CMakeFiles /home/yqm/Git/MyUtil/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/yqm/Git/MyUtil/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named YUtil

# Build rule for target.
YUtil: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 YUtil
.PHONY : YUtil

# fast build rule for target.
YUtil/fast:
	$(MAKE) -f CMakeFiles/YUtil.dir/build.make CMakeFiles/YUtil.dir/build
.PHONY : YUtil/fast

src/Logger/Logger.o: src/Logger/Logger.cpp.o

.PHONY : src/Logger/Logger.o

# target to build an object file
src/Logger/Logger.cpp.o:
	$(MAKE) -f CMakeFiles/YUtil.dir/build.make CMakeFiles/YUtil.dir/src/Logger/Logger.cpp.o
.PHONY : src/Logger/Logger.cpp.o

src/Logger/Logger.i: src/Logger/Logger.cpp.i

.PHONY : src/Logger/Logger.i

# target to preprocess a source file
src/Logger/Logger.cpp.i:
	$(MAKE) -f CMakeFiles/YUtil.dir/build.make CMakeFiles/YUtil.dir/src/Logger/Logger.cpp.i
.PHONY : src/Logger/Logger.cpp.i

src/Logger/Logger.s: src/Logger/Logger.cpp.s

.PHONY : src/Logger/Logger.s

# target to generate assembly for a file
src/Logger/Logger.cpp.s:
	$(MAKE) -f CMakeFiles/YUtil.dir/build.make CMakeFiles/YUtil.dir/src/Logger/Logger.cpp.s
.PHONY : src/Logger/Logger.cpp.s

src/structure/Array/Array_NULLCPP.o: src/structure/Array/Array_NULLCPP.cpp.o

.PHONY : src/structure/Array/Array_NULLCPP.o

# target to build an object file
src/structure/Array/Array_NULLCPP.cpp.o:
	$(MAKE) -f CMakeFiles/YUtil.dir/build.make CMakeFiles/YUtil.dir/src/structure/Array/Array_NULLCPP.cpp.o
.PHONY : src/structure/Array/Array_NULLCPP.cpp.o

src/structure/Array/Array_NULLCPP.i: src/structure/Array/Array_NULLCPP.cpp.i

.PHONY : src/structure/Array/Array_NULLCPP.i

# target to preprocess a source file
src/structure/Array/Array_NULLCPP.cpp.i:
	$(MAKE) -f CMakeFiles/YUtil.dir/build.make CMakeFiles/YUtil.dir/src/structure/Array/Array_NULLCPP.cpp.i
.PHONY : src/structure/Array/Array_NULLCPP.cpp.i

src/structure/Array/Array_NULLCPP.s: src/structure/Array/Array_NULLCPP.cpp.s

.PHONY : src/structure/Array/Array_NULLCPP.s

# target to generate assembly for a file
src/structure/Array/Array_NULLCPP.cpp.s:
	$(MAKE) -f CMakeFiles/YUtil.dir/build.make CMakeFiles/YUtil.dir/src/structure/Array/Array_NULLCPP.cpp.s
.PHONY : src/structure/Array/Array_NULLCPP.cpp.s

src/timer/timer_NULLCPP.o: src/timer/timer_NULLCPP.cpp.o

.PHONY : src/timer/timer_NULLCPP.o

# target to build an object file
src/timer/timer_NULLCPP.cpp.o:
	$(MAKE) -f CMakeFiles/YUtil.dir/build.make CMakeFiles/YUtil.dir/src/timer/timer_NULLCPP.cpp.o
.PHONY : src/timer/timer_NULLCPP.cpp.o

src/timer/timer_NULLCPP.i: src/timer/timer_NULLCPP.cpp.i

.PHONY : src/timer/timer_NULLCPP.i

# target to preprocess a source file
src/timer/timer_NULLCPP.cpp.i:
	$(MAKE) -f CMakeFiles/YUtil.dir/build.make CMakeFiles/YUtil.dir/src/timer/timer_NULLCPP.cpp.i
.PHONY : src/timer/timer_NULLCPP.cpp.i

src/timer/timer_NULLCPP.s: src/timer/timer_NULLCPP.cpp.s

.PHONY : src/timer/timer_NULLCPP.s

# target to generate assembly for a file
src/timer/timer_NULLCPP.cpp.s:
	$(MAKE) -f CMakeFiles/YUtil.dir/build.make CMakeFiles/YUtil.dir/src/timer/timer_NULLCPP.cpp.s
.PHONY : src/timer/timer_NULLCPP.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... YUtil"
	@echo "... src/Logger/Logger.o"
	@echo "... src/Logger/Logger.i"
	@echo "... src/Logger/Logger.s"
	@echo "... src/structure/Array/Array_NULLCPP.o"
	@echo "... src/structure/Array/Array_NULLCPP.i"
	@echo "... src/structure/Array/Array_NULLCPP.s"
	@echo "... src/timer/timer_NULLCPP.o"
	@echo "... src/timer/timer_NULLCPP.i"
	@echo "... src/timer/timer_NULLCPP.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


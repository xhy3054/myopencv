# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xhy/cv/myopencv/03_imgproc_module/12_laplace

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xhy/cv/myopencv/03_imgproc_module/12_laplace/build

# Include any dependencies generated for this target.
include CMakeFiles/laplace.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/laplace.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/laplace.dir/flags.make

CMakeFiles/laplace.dir/laplace.cpp.o: CMakeFiles/laplace.dir/flags.make
CMakeFiles/laplace.dir/laplace.cpp.o: ../laplace.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xhy/cv/myopencv/03_imgproc_module/12_laplace/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/laplace.dir/laplace.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/laplace.dir/laplace.cpp.o -c /home/xhy/cv/myopencv/03_imgproc_module/12_laplace/laplace.cpp

CMakeFiles/laplace.dir/laplace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/laplace.dir/laplace.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xhy/cv/myopencv/03_imgproc_module/12_laplace/laplace.cpp > CMakeFiles/laplace.dir/laplace.cpp.i

CMakeFiles/laplace.dir/laplace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/laplace.dir/laplace.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xhy/cv/myopencv/03_imgproc_module/12_laplace/laplace.cpp -o CMakeFiles/laplace.dir/laplace.cpp.s

CMakeFiles/laplace.dir/laplace.cpp.o.requires:

.PHONY : CMakeFiles/laplace.dir/laplace.cpp.o.requires

CMakeFiles/laplace.dir/laplace.cpp.o.provides: CMakeFiles/laplace.dir/laplace.cpp.o.requires
	$(MAKE) -f CMakeFiles/laplace.dir/build.make CMakeFiles/laplace.dir/laplace.cpp.o.provides.build
.PHONY : CMakeFiles/laplace.dir/laplace.cpp.o.provides

CMakeFiles/laplace.dir/laplace.cpp.o.provides.build: CMakeFiles/laplace.dir/laplace.cpp.o


# Object files for target laplace
laplace_OBJECTS = \
"CMakeFiles/laplace.dir/laplace.cpp.o"

# External object files for target laplace
laplace_EXTERNAL_OBJECTS =

laplace: CMakeFiles/laplace.dir/laplace.cpp.o
laplace: CMakeFiles/laplace.dir/build.make
laplace: /usr/local/lib/libopencv_superres.so.3.4.1
laplace: /usr/local/lib/libopencv_dnn.so.3.4.1
laplace: /usr/local/lib/libopencv_videostab.so.3.4.1
laplace: /usr/local/lib/libopencv_shape.so.3.4.1
laplace: /usr/local/lib/libopencv_objdetect.so.3.4.1
laplace: /usr/local/lib/libopencv_stitching.so.3.4.1
laplace: /usr/local/lib/libopencv_ml.so.3.4.1
laplace: /usr/local/lib/libopencv_photo.so.3.4.1
laplace: /usr/local/lib/libopencv_video.so.3.4.1
laplace: /usr/local/lib/libopencv_calib3d.so.3.4.1
laplace: /usr/local/lib/libopencv_features2d.so.3.4.1
laplace: /usr/local/lib/libopencv_flann.so.3.4.1
laplace: /usr/local/lib/libopencv_highgui.so.3.4.1
laplace: /usr/local/lib/libopencv_videoio.so.3.4.1
laplace: /usr/local/lib/libopencv_imgcodecs.so.3.4.1
laplace: /usr/local/lib/libopencv_imgproc.so.3.4.1
laplace: /usr/local/lib/libopencv_core.so.3.4.1
laplace: CMakeFiles/laplace.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xhy/cv/myopencv/03_imgproc_module/12_laplace/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable laplace"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/laplace.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/laplace.dir/build: laplace

.PHONY : CMakeFiles/laplace.dir/build

CMakeFiles/laplace.dir/requires: CMakeFiles/laplace.dir/laplace.cpp.o.requires

.PHONY : CMakeFiles/laplace.dir/requires

CMakeFiles/laplace.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/laplace.dir/cmake_clean.cmake
.PHONY : CMakeFiles/laplace.dir/clean

CMakeFiles/laplace.dir/depend:
	cd /home/xhy/cv/myopencv/03_imgproc_module/12_laplace/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xhy/cv/myopencv/03_imgproc_module/12_laplace /home/xhy/cv/myopencv/03_imgproc_module/12_laplace /home/xhy/cv/myopencv/03_imgproc_module/12_laplace/build /home/xhy/cv/myopencv/03_imgproc_module/12_laplace/build /home/xhy/cv/myopencv/03_imgproc_module/12_laplace/build/CMakeFiles/laplace.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/laplace.dir/depend


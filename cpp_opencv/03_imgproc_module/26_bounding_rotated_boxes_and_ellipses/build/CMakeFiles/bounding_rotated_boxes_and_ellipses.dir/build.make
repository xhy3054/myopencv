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
CMAKE_SOURCE_DIR = /home/xhy/cv/myopencv/03_imgproc_module/26_bounding_rotated_boxes_and_ellipses

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xhy/cv/myopencv/03_imgproc_module/26_bounding_rotated_boxes_and_ellipses/build

# Include any dependencies generated for this target.
include CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/flags.make

CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.o: CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/flags.make
CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.o: ../bounding_rotated_boxes_and_ellipses.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xhy/cv/myopencv/03_imgproc_module/26_bounding_rotated_boxes_and_ellipses/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.o -c /home/xhy/cv/myopencv/03_imgproc_module/26_bounding_rotated_boxes_and_ellipses/bounding_rotated_boxes_and_ellipses.cpp

CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xhy/cv/myopencv/03_imgproc_module/26_bounding_rotated_boxes_and_ellipses/bounding_rotated_boxes_and_ellipses.cpp > CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.i

CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xhy/cv/myopencv/03_imgproc_module/26_bounding_rotated_boxes_and_ellipses/bounding_rotated_boxes_and_ellipses.cpp -o CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.s

CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.o.requires:

.PHONY : CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.o.requires

CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.o.provides: CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.o.requires
	$(MAKE) -f CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/build.make CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.o.provides.build
.PHONY : CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.o.provides

CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.o.provides.build: CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.o


# Object files for target bounding_rotated_boxes_and_ellipses
bounding_rotated_boxes_and_ellipses_OBJECTS = \
"CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.o"

# External object files for target bounding_rotated_boxes_and_ellipses
bounding_rotated_boxes_and_ellipses_EXTERNAL_OBJECTS =

bounding_rotated_boxes_and_ellipses: CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.o
bounding_rotated_boxes_and_ellipses: CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/build.make
bounding_rotated_boxes_and_ellipses: /usr/local/lib/libopencv_superres.so.3.4.1
bounding_rotated_boxes_and_ellipses: /usr/local/lib/libopencv_dnn.so.3.4.1
bounding_rotated_boxes_and_ellipses: /usr/local/lib/libopencv_videostab.so.3.4.1
bounding_rotated_boxes_and_ellipses: /usr/local/lib/libopencv_shape.so.3.4.1
bounding_rotated_boxes_and_ellipses: /usr/local/lib/libopencv_objdetect.so.3.4.1
bounding_rotated_boxes_and_ellipses: /usr/local/lib/libopencv_stitching.so.3.4.1
bounding_rotated_boxes_and_ellipses: /usr/local/lib/libopencv_ml.so.3.4.1
bounding_rotated_boxes_and_ellipses: /usr/local/lib/libopencv_photo.so.3.4.1
bounding_rotated_boxes_and_ellipses: /usr/local/lib/libopencv_video.so.3.4.1
bounding_rotated_boxes_and_ellipses: /usr/local/lib/libopencv_calib3d.so.3.4.1
bounding_rotated_boxes_and_ellipses: /usr/local/lib/libopencv_features2d.so.3.4.1
bounding_rotated_boxes_and_ellipses: /usr/local/lib/libopencv_flann.so.3.4.1
bounding_rotated_boxes_and_ellipses: /usr/local/lib/libopencv_highgui.so.3.4.1
bounding_rotated_boxes_and_ellipses: /usr/local/lib/libopencv_videoio.so.3.4.1
bounding_rotated_boxes_and_ellipses: /usr/local/lib/libopencv_imgcodecs.so.3.4.1
bounding_rotated_boxes_and_ellipses: /usr/local/lib/libopencv_imgproc.so.3.4.1
bounding_rotated_boxes_and_ellipses: /usr/local/lib/libopencv_core.so.3.4.1
bounding_rotated_boxes_and_ellipses: CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xhy/cv/myopencv/03_imgproc_module/26_bounding_rotated_boxes_and_ellipses/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bounding_rotated_boxes_and_ellipses"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/build: bounding_rotated_boxes_and_ellipses

.PHONY : CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/build

CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/requires: CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/bounding_rotated_boxes_and_ellipses.cpp.o.requires

.PHONY : CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/requires

CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/clean

CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/depend:
	cd /home/xhy/cv/myopencv/03_imgproc_module/26_bounding_rotated_boxes_and_ellipses/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xhy/cv/myopencv/03_imgproc_module/26_bounding_rotated_boxes_and_ellipses /home/xhy/cv/myopencv/03_imgproc_module/26_bounding_rotated_boxes_and_ellipses /home/xhy/cv/myopencv/03_imgproc_module/26_bounding_rotated_boxes_and_ellipses/build /home/xhy/cv/myopencv/03_imgproc_module/26_bounding_rotated_boxes_and_ellipses/build /home/xhy/cv/myopencv/03_imgproc_module/26_bounding_rotated_boxes_and_ellipses/build/CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bounding_rotated_boxes_and_ellipses.dir/depend


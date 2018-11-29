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
CMAKE_SOURCE_DIR = /home/xhy/cv/myopencv/03_imgproc_module/15_hough_circles

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xhy/cv/myopencv/03_imgproc_module/15_hough_circles/build

# Include any dependencies generated for this target.
include CMakeFiles/houghcircles.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/houghcircles.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/houghcircles.dir/flags.make

CMakeFiles/houghcircles.dir/houghcircles.cpp.o: CMakeFiles/houghcircles.dir/flags.make
CMakeFiles/houghcircles.dir/houghcircles.cpp.o: ../houghcircles.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xhy/cv/myopencv/03_imgproc_module/15_hough_circles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/houghcircles.dir/houghcircles.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/houghcircles.dir/houghcircles.cpp.o -c /home/xhy/cv/myopencv/03_imgproc_module/15_hough_circles/houghcircles.cpp

CMakeFiles/houghcircles.dir/houghcircles.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/houghcircles.dir/houghcircles.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xhy/cv/myopencv/03_imgproc_module/15_hough_circles/houghcircles.cpp > CMakeFiles/houghcircles.dir/houghcircles.cpp.i

CMakeFiles/houghcircles.dir/houghcircles.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/houghcircles.dir/houghcircles.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xhy/cv/myopencv/03_imgproc_module/15_hough_circles/houghcircles.cpp -o CMakeFiles/houghcircles.dir/houghcircles.cpp.s

CMakeFiles/houghcircles.dir/houghcircles.cpp.o.requires:

.PHONY : CMakeFiles/houghcircles.dir/houghcircles.cpp.o.requires

CMakeFiles/houghcircles.dir/houghcircles.cpp.o.provides: CMakeFiles/houghcircles.dir/houghcircles.cpp.o.requires
	$(MAKE) -f CMakeFiles/houghcircles.dir/build.make CMakeFiles/houghcircles.dir/houghcircles.cpp.o.provides.build
.PHONY : CMakeFiles/houghcircles.dir/houghcircles.cpp.o.provides

CMakeFiles/houghcircles.dir/houghcircles.cpp.o.provides.build: CMakeFiles/houghcircles.dir/houghcircles.cpp.o


# Object files for target houghcircles
houghcircles_OBJECTS = \
"CMakeFiles/houghcircles.dir/houghcircles.cpp.o"

# External object files for target houghcircles
houghcircles_EXTERNAL_OBJECTS =

houghcircles: CMakeFiles/houghcircles.dir/houghcircles.cpp.o
houghcircles: CMakeFiles/houghcircles.dir/build.make
houghcircles: /usr/local/lib/libopencv_superres.so.3.4.1
houghcircles: /usr/local/lib/libopencv_dnn.so.3.4.1
houghcircles: /usr/local/lib/libopencv_videostab.so.3.4.1
houghcircles: /usr/local/lib/libopencv_shape.so.3.4.1
houghcircles: /usr/local/lib/libopencv_objdetect.so.3.4.1
houghcircles: /usr/local/lib/libopencv_stitching.so.3.4.1
houghcircles: /usr/local/lib/libopencv_ml.so.3.4.1
houghcircles: /usr/local/lib/libopencv_photo.so.3.4.1
houghcircles: /usr/local/lib/libopencv_video.so.3.4.1
houghcircles: /usr/local/lib/libopencv_calib3d.so.3.4.1
houghcircles: /usr/local/lib/libopencv_features2d.so.3.4.1
houghcircles: /usr/local/lib/libopencv_flann.so.3.4.1
houghcircles: /usr/local/lib/libopencv_highgui.so.3.4.1
houghcircles: /usr/local/lib/libopencv_videoio.so.3.4.1
houghcircles: /usr/local/lib/libopencv_imgcodecs.so.3.4.1
houghcircles: /usr/local/lib/libopencv_imgproc.so.3.4.1
houghcircles: /usr/local/lib/libopencv_core.so.3.4.1
houghcircles: CMakeFiles/houghcircles.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xhy/cv/myopencv/03_imgproc_module/15_hough_circles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable houghcircles"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/houghcircles.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/houghcircles.dir/build: houghcircles

.PHONY : CMakeFiles/houghcircles.dir/build

CMakeFiles/houghcircles.dir/requires: CMakeFiles/houghcircles.dir/houghcircles.cpp.o.requires

.PHONY : CMakeFiles/houghcircles.dir/requires

CMakeFiles/houghcircles.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/houghcircles.dir/cmake_clean.cmake
.PHONY : CMakeFiles/houghcircles.dir/clean

CMakeFiles/houghcircles.dir/depend:
	cd /home/xhy/cv/myopencv/03_imgproc_module/15_hough_circles/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xhy/cv/myopencv/03_imgproc_module/15_hough_circles /home/xhy/cv/myopencv/03_imgproc_module/15_hough_circles /home/xhy/cv/myopencv/03_imgproc_module/15_hough_circles/build /home/xhy/cv/myopencv/03_imgproc_module/15_hough_circles/build /home/xhy/cv/myopencv/03_imgproc_module/15_hough_circles/build/CMakeFiles/houghcircles.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/houghcircles.dir/depend


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
CMAKE_SOURCE_DIR = /home/xhy/cv/myopencv/03_imgproc_module/13_canny_detector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xhy/cv/myopencv/03_imgproc_module/13_canny_detector/build

# Include any dependencies generated for this target.
include CMakeFiles/canny_detector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/canny_detector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/canny_detector.dir/flags.make

CMakeFiles/canny_detector.dir/canny_detector.cpp.o: CMakeFiles/canny_detector.dir/flags.make
CMakeFiles/canny_detector.dir/canny_detector.cpp.o: ../canny_detector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xhy/cv/myopencv/03_imgproc_module/13_canny_detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/canny_detector.dir/canny_detector.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/canny_detector.dir/canny_detector.cpp.o -c /home/xhy/cv/myopencv/03_imgproc_module/13_canny_detector/canny_detector.cpp

CMakeFiles/canny_detector.dir/canny_detector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/canny_detector.dir/canny_detector.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xhy/cv/myopencv/03_imgproc_module/13_canny_detector/canny_detector.cpp > CMakeFiles/canny_detector.dir/canny_detector.cpp.i

CMakeFiles/canny_detector.dir/canny_detector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/canny_detector.dir/canny_detector.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xhy/cv/myopencv/03_imgproc_module/13_canny_detector/canny_detector.cpp -o CMakeFiles/canny_detector.dir/canny_detector.cpp.s

CMakeFiles/canny_detector.dir/canny_detector.cpp.o.requires:

.PHONY : CMakeFiles/canny_detector.dir/canny_detector.cpp.o.requires

CMakeFiles/canny_detector.dir/canny_detector.cpp.o.provides: CMakeFiles/canny_detector.dir/canny_detector.cpp.o.requires
	$(MAKE) -f CMakeFiles/canny_detector.dir/build.make CMakeFiles/canny_detector.dir/canny_detector.cpp.o.provides.build
.PHONY : CMakeFiles/canny_detector.dir/canny_detector.cpp.o.provides

CMakeFiles/canny_detector.dir/canny_detector.cpp.o.provides.build: CMakeFiles/canny_detector.dir/canny_detector.cpp.o


# Object files for target canny_detector
canny_detector_OBJECTS = \
"CMakeFiles/canny_detector.dir/canny_detector.cpp.o"

# External object files for target canny_detector
canny_detector_EXTERNAL_OBJECTS =

canny_detector: CMakeFiles/canny_detector.dir/canny_detector.cpp.o
canny_detector: CMakeFiles/canny_detector.dir/build.make
canny_detector: /usr/local/lib/libopencv_superres.so.3.4.1
canny_detector: /usr/local/lib/libopencv_dnn.so.3.4.1
canny_detector: /usr/local/lib/libopencv_videostab.so.3.4.1
canny_detector: /usr/local/lib/libopencv_shape.so.3.4.1
canny_detector: /usr/local/lib/libopencv_objdetect.so.3.4.1
canny_detector: /usr/local/lib/libopencv_stitching.so.3.4.1
canny_detector: /usr/local/lib/libopencv_ml.so.3.4.1
canny_detector: /usr/local/lib/libopencv_photo.so.3.4.1
canny_detector: /usr/local/lib/libopencv_video.so.3.4.1
canny_detector: /usr/local/lib/libopencv_calib3d.so.3.4.1
canny_detector: /usr/local/lib/libopencv_features2d.so.3.4.1
canny_detector: /usr/local/lib/libopencv_flann.so.3.4.1
canny_detector: /usr/local/lib/libopencv_highgui.so.3.4.1
canny_detector: /usr/local/lib/libopencv_videoio.so.3.4.1
canny_detector: /usr/local/lib/libopencv_imgcodecs.so.3.4.1
canny_detector: /usr/local/lib/libopencv_imgproc.so.3.4.1
canny_detector: /usr/local/lib/libopencv_core.so.3.4.1
canny_detector: CMakeFiles/canny_detector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xhy/cv/myopencv/03_imgproc_module/13_canny_detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable canny_detector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/canny_detector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/canny_detector.dir/build: canny_detector

.PHONY : CMakeFiles/canny_detector.dir/build

CMakeFiles/canny_detector.dir/requires: CMakeFiles/canny_detector.dir/canny_detector.cpp.o.requires

.PHONY : CMakeFiles/canny_detector.dir/requires

CMakeFiles/canny_detector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/canny_detector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/canny_detector.dir/clean

CMakeFiles/canny_detector.dir/depend:
	cd /home/xhy/cv/myopencv/03_imgproc_module/13_canny_detector/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xhy/cv/myopencv/03_imgproc_module/13_canny_detector /home/xhy/cv/myopencv/03_imgproc_module/13_canny_detector /home/xhy/cv/myopencv/03_imgproc_module/13_canny_detector/build /home/xhy/cv/myopencv/03_imgproc_module/13_canny_detector/build /home/xhy/cv/myopencv/03_imgproc_module/13_canny_detector/build/CMakeFiles/canny_detector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/canny_detector.dir/depend

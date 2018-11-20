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
CMAKE_SOURCE_DIR = /home/xhy/cv/myopencv/03_imgproc_module/06_image_pyramids

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xhy/cv/myopencv/03_imgproc_module/06_image_pyramids/build

# Include any dependencies generated for this target.
include CMakeFiles/image_pyramids.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/image_pyramids.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/image_pyramids.dir/flags.make

CMakeFiles/image_pyramids.dir/image_pyramids.cpp.o: CMakeFiles/image_pyramids.dir/flags.make
CMakeFiles/image_pyramids.dir/image_pyramids.cpp.o: ../image_pyramids.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xhy/cv/myopencv/03_imgproc_module/06_image_pyramids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/image_pyramids.dir/image_pyramids.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/image_pyramids.dir/image_pyramids.cpp.o -c /home/xhy/cv/myopencv/03_imgproc_module/06_image_pyramids/image_pyramids.cpp

CMakeFiles/image_pyramids.dir/image_pyramids.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_pyramids.dir/image_pyramids.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xhy/cv/myopencv/03_imgproc_module/06_image_pyramids/image_pyramids.cpp > CMakeFiles/image_pyramids.dir/image_pyramids.cpp.i

CMakeFiles/image_pyramids.dir/image_pyramids.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_pyramids.dir/image_pyramids.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xhy/cv/myopencv/03_imgproc_module/06_image_pyramids/image_pyramids.cpp -o CMakeFiles/image_pyramids.dir/image_pyramids.cpp.s

CMakeFiles/image_pyramids.dir/image_pyramids.cpp.o.requires:

.PHONY : CMakeFiles/image_pyramids.dir/image_pyramids.cpp.o.requires

CMakeFiles/image_pyramids.dir/image_pyramids.cpp.o.provides: CMakeFiles/image_pyramids.dir/image_pyramids.cpp.o.requires
	$(MAKE) -f CMakeFiles/image_pyramids.dir/build.make CMakeFiles/image_pyramids.dir/image_pyramids.cpp.o.provides.build
.PHONY : CMakeFiles/image_pyramids.dir/image_pyramids.cpp.o.provides

CMakeFiles/image_pyramids.dir/image_pyramids.cpp.o.provides.build: CMakeFiles/image_pyramids.dir/image_pyramids.cpp.o


# Object files for target image_pyramids
image_pyramids_OBJECTS = \
"CMakeFiles/image_pyramids.dir/image_pyramids.cpp.o"

# External object files for target image_pyramids
image_pyramids_EXTERNAL_OBJECTS =

image_pyramids: CMakeFiles/image_pyramids.dir/image_pyramids.cpp.o
image_pyramids: CMakeFiles/image_pyramids.dir/build.make
image_pyramids: /usr/local/lib/libopencv_superres.so.3.4.1
image_pyramids: /usr/local/lib/libopencv_dnn.so.3.4.1
image_pyramids: /usr/local/lib/libopencv_videostab.so.3.4.1
image_pyramids: /usr/local/lib/libopencv_shape.so.3.4.1
image_pyramids: /usr/local/lib/libopencv_objdetect.so.3.4.1
image_pyramids: /usr/local/lib/libopencv_stitching.so.3.4.1
image_pyramids: /usr/local/lib/libopencv_ml.so.3.4.1
image_pyramids: /usr/local/lib/libopencv_photo.so.3.4.1
image_pyramids: /usr/local/lib/libopencv_video.so.3.4.1
image_pyramids: /usr/local/lib/libopencv_calib3d.so.3.4.1
image_pyramids: /usr/local/lib/libopencv_features2d.so.3.4.1
image_pyramids: /usr/local/lib/libopencv_flann.so.3.4.1
image_pyramids: /usr/local/lib/libopencv_highgui.so.3.4.1
image_pyramids: /usr/local/lib/libopencv_videoio.so.3.4.1
image_pyramids: /usr/local/lib/libopencv_imgcodecs.so.3.4.1
image_pyramids: /usr/local/lib/libopencv_imgproc.so.3.4.1
image_pyramids: /usr/local/lib/libopencv_core.so.3.4.1
image_pyramids: CMakeFiles/image_pyramids.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xhy/cv/myopencv/03_imgproc_module/06_image_pyramids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable image_pyramids"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/image_pyramids.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/image_pyramids.dir/build: image_pyramids

.PHONY : CMakeFiles/image_pyramids.dir/build

CMakeFiles/image_pyramids.dir/requires: CMakeFiles/image_pyramids.dir/image_pyramids.cpp.o.requires

.PHONY : CMakeFiles/image_pyramids.dir/requires

CMakeFiles/image_pyramids.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/image_pyramids.dir/cmake_clean.cmake
.PHONY : CMakeFiles/image_pyramids.dir/clean

CMakeFiles/image_pyramids.dir/depend:
	cd /home/xhy/cv/myopencv/03_imgproc_module/06_image_pyramids/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xhy/cv/myopencv/03_imgproc_module/06_image_pyramids /home/xhy/cv/myopencv/03_imgproc_module/06_image_pyramids /home/xhy/cv/myopencv/03_imgproc_module/06_image_pyramids/build /home/xhy/cv/myopencv/03_imgproc_module/06_image_pyramids/build /home/xhy/cv/myopencv/03_imgproc_module/06_image_pyramids/build/CMakeFiles/image_pyramids.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/image_pyramids.dir/depend


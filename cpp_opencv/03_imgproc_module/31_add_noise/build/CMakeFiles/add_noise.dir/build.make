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
CMAKE_SOURCE_DIR = /home/xhy/cv/myopencv/03_imgproc_module/31_add_noise

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xhy/cv/myopencv/03_imgproc_module/31_add_noise/build

# Include any dependencies generated for this target.
include CMakeFiles/add_noise.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/add_noise.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/add_noise.dir/flags.make

CMakeFiles/add_noise.dir/add_noise.cpp.o: CMakeFiles/add_noise.dir/flags.make
CMakeFiles/add_noise.dir/add_noise.cpp.o: ../add_noise.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xhy/cv/myopencv/03_imgproc_module/31_add_noise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/add_noise.dir/add_noise.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/add_noise.dir/add_noise.cpp.o -c /home/xhy/cv/myopencv/03_imgproc_module/31_add_noise/add_noise.cpp

CMakeFiles/add_noise.dir/add_noise.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/add_noise.dir/add_noise.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xhy/cv/myopencv/03_imgproc_module/31_add_noise/add_noise.cpp > CMakeFiles/add_noise.dir/add_noise.cpp.i

CMakeFiles/add_noise.dir/add_noise.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/add_noise.dir/add_noise.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xhy/cv/myopencv/03_imgproc_module/31_add_noise/add_noise.cpp -o CMakeFiles/add_noise.dir/add_noise.cpp.s

CMakeFiles/add_noise.dir/add_noise.cpp.o.requires:

.PHONY : CMakeFiles/add_noise.dir/add_noise.cpp.o.requires

CMakeFiles/add_noise.dir/add_noise.cpp.o.provides: CMakeFiles/add_noise.dir/add_noise.cpp.o.requires
	$(MAKE) -f CMakeFiles/add_noise.dir/build.make CMakeFiles/add_noise.dir/add_noise.cpp.o.provides.build
.PHONY : CMakeFiles/add_noise.dir/add_noise.cpp.o.provides

CMakeFiles/add_noise.dir/add_noise.cpp.o.provides.build: CMakeFiles/add_noise.dir/add_noise.cpp.o


# Object files for target add_noise
add_noise_OBJECTS = \
"CMakeFiles/add_noise.dir/add_noise.cpp.o"

# External object files for target add_noise
add_noise_EXTERNAL_OBJECTS =

add_noise: CMakeFiles/add_noise.dir/add_noise.cpp.o
add_noise: CMakeFiles/add_noise.dir/build.make
add_noise: /usr/local/lib/libopencv_superres.so.3.4.1
add_noise: /usr/local/lib/libopencv_dnn.so.3.4.1
add_noise: /usr/local/lib/libopencv_viz.so.3.4.1
add_noise: /usr/local/lib/libopencv_videostab.so.3.4.1
add_noise: /usr/local/lib/libopencv_shape.so.3.4.1
add_noise: /usr/local/lib/libopencv_objdetect.so.3.4.1
add_noise: /usr/local/lib/libopencv_stitching.so.3.4.1
add_noise: /usr/local/lib/libopencv_ml.so.3.4.1
add_noise: /usr/local/lib/libopencv_photo.so.3.4.1
add_noise: /usr/local/lib/libopencv_video.so.3.4.1
add_noise: /usr/local/lib/libopencv_calib3d.so.3.4.1
add_noise: /usr/local/lib/libopencv_features2d.so.3.4.1
add_noise: /usr/local/lib/libopencv_flann.so.3.4.1
add_noise: /usr/local/lib/libopencv_highgui.so.3.4.1
add_noise: /usr/local/lib/libopencv_videoio.so.3.4.1
add_noise: /usr/local/lib/libopencv_imgcodecs.so.3.4.1
add_noise: /usr/local/lib/libopencv_imgproc.so.3.4.1
add_noise: /usr/local/lib/libopencv_core.so.3.4.1
add_noise: CMakeFiles/add_noise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xhy/cv/myopencv/03_imgproc_module/31_add_noise/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable add_noise"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/add_noise.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/add_noise.dir/build: add_noise

.PHONY : CMakeFiles/add_noise.dir/build

CMakeFiles/add_noise.dir/requires: CMakeFiles/add_noise.dir/add_noise.cpp.o.requires

.PHONY : CMakeFiles/add_noise.dir/requires

CMakeFiles/add_noise.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/add_noise.dir/cmake_clean.cmake
.PHONY : CMakeFiles/add_noise.dir/clean

CMakeFiles/add_noise.dir/depend:
	cd /home/xhy/cv/myopencv/03_imgproc_module/31_add_noise/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xhy/cv/myopencv/03_imgproc_module/31_add_noise /home/xhy/cv/myopencv/03_imgproc_module/31_add_noise /home/xhy/cv/myopencv/03_imgproc_module/31_add_noise/build /home/xhy/cv/myopencv/03_imgproc_module/31_add_noise/build /home/xhy/cv/myopencv/03_imgproc_module/31_add_noise/build/CMakeFiles/add_noise.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/add_noise.dir/depend

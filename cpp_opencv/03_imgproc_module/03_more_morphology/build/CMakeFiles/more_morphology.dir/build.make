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
CMAKE_SOURCE_DIR = /home/xhy/cv/myopencv/03_imgproc_module/03_more_morphology

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xhy/cv/myopencv/03_imgproc_module/03_more_morphology/build

# Include any dependencies generated for this target.
include CMakeFiles/more_morphology.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/more_morphology.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/more_morphology.dir/flags.make

CMakeFiles/more_morphology.dir/more_morphology.cpp.o: CMakeFiles/more_morphology.dir/flags.make
CMakeFiles/more_morphology.dir/more_morphology.cpp.o: ../more_morphology.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xhy/cv/myopencv/03_imgproc_module/03_more_morphology/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/more_morphology.dir/more_morphology.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/more_morphology.dir/more_morphology.cpp.o -c /home/xhy/cv/myopencv/03_imgproc_module/03_more_morphology/more_morphology.cpp

CMakeFiles/more_morphology.dir/more_morphology.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/more_morphology.dir/more_morphology.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xhy/cv/myopencv/03_imgproc_module/03_more_morphology/more_morphology.cpp > CMakeFiles/more_morphology.dir/more_morphology.cpp.i

CMakeFiles/more_morphology.dir/more_morphology.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/more_morphology.dir/more_morphology.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xhy/cv/myopencv/03_imgproc_module/03_more_morphology/more_morphology.cpp -o CMakeFiles/more_morphology.dir/more_morphology.cpp.s

CMakeFiles/more_morphology.dir/more_morphology.cpp.o.requires:

.PHONY : CMakeFiles/more_morphology.dir/more_morphology.cpp.o.requires

CMakeFiles/more_morphology.dir/more_morphology.cpp.o.provides: CMakeFiles/more_morphology.dir/more_morphology.cpp.o.requires
	$(MAKE) -f CMakeFiles/more_morphology.dir/build.make CMakeFiles/more_morphology.dir/more_morphology.cpp.o.provides.build
.PHONY : CMakeFiles/more_morphology.dir/more_morphology.cpp.o.provides

CMakeFiles/more_morphology.dir/more_morphology.cpp.o.provides.build: CMakeFiles/more_morphology.dir/more_morphology.cpp.o


# Object files for target more_morphology
more_morphology_OBJECTS = \
"CMakeFiles/more_morphology.dir/more_morphology.cpp.o"

# External object files for target more_morphology
more_morphology_EXTERNAL_OBJECTS =

more_morphology: CMakeFiles/more_morphology.dir/more_morphology.cpp.o
more_morphology: CMakeFiles/more_morphology.dir/build.make
more_morphology: /usr/local/lib/libopencv_superres.so.3.4.1
more_morphology: /usr/local/lib/libopencv_dnn.so.3.4.1
more_morphology: /usr/local/lib/libopencv_videostab.so.3.4.1
more_morphology: /usr/local/lib/libopencv_shape.so.3.4.1
more_morphology: /usr/local/lib/libopencv_objdetect.so.3.4.1
more_morphology: /usr/local/lib/libopencv_stitching.so.3.4.1
more_morphology: /usr/local/lib/libopencv_ml.so.3.4.1
more_morphology: /usr/local/lib/libopencv_photo.so.3.4.1
more_morphology: /usr/local/lib/libopencv_video.so.3.4.1
more_morphology: /usr/local/lib/libopencv_calib3d.so.3.4.1
more_morphology: /usr/local/lib/libopencv_features2d.so.3.4.1
more_morphology: /usr/local/lib/libopencv_flann.so.3.4.1
more_morphology: /usr/local/lib/libopencv_highgui.so.3.4.1
more_morphology: /usr/local/lib/libopencv_videoio.so.3.4.1
more_morphology: /usr/local/lib/libopencv_imgcodecs.so.3.4.1
more_morphology: /usr/local/lib/libopencv_imgproc.so.3.4.1
more_morphology: /usr/local/lib/libopencv_core.so.3.4.1
more_morphology: CMakeFiles/more_morphology.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xhy/cv/myopencv/03_imgproc_module/03_more_morphology/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable more_morphology"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/more_morphology.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/more_morphology.dir/build: more_morphology

.PHONY : CMakeFiles/more_morphology.dir/build

CMakeFiles/more_morphology.dir/requires: CMakeFiles/more_morphology.dir/more_morphology.cpp.o.requires

.PHONY : CMakeFiles/more_morphology.dir/requires

CMakeFiles/more_morphology.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/more_morphology.dir/cmake_clean.cmake
.PHONY : CMakeFiles/more_morphology.dir/clean

CMakeFiles/more_morphology.dir/depend:
	cd /home/xhy/cv/myopencv/03_imgproc_module/03_more_morphology/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xhy/cv/myopencv/03_imgproc_module/03_more_morphology /home/xhy/cv/myopencv/03_imgproc_module/03_more_morphology /home/xhy/cv/myopencv/03_imgproc_module/03_more_morphology/build /home/xhy/cv/myopencv/03_imgproc_module/03_more_morphology/build /home/xhy/cv/myopencv/03_imgproc_module/03_more_morphology/build/CMakeFiles/more_morphology.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/more_morphology.dir/depend


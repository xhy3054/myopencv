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
CMAKE_SOURCE_DIR = /home/xhy/cv/myopencv/08_feature2d_module/07_feature_match

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xhy/cv/myopencv/08_feature2d_module/07_feature_match/build

# Include any dependencies generated for this target.
include CMakeFiles/fs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fs.dir/flags.make

CMakeFiles/fs.dir/feature_statistic.cpp.o: CMakeFiles/fs.dir/flags.make
CMakeFiles/fs.dir/feature_statistic.cpp.o: ../feature_statistic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xhy/cv/myopencv/08_feature2d_module/07_feature_match/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fs.dir/feature_statistic.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fs.dir/feature_statistic.cpp.o -c /home/xhy/cv/myopencv/08_feature2d_module/07_feature_match/feature_statistic.cpp

CMakeFiles/fs.dir/feature_statistic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fs.dir/feature_statistic.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xhy/cv/myopencv/08_feature2d_module/07_feature_match/feature_statistic.cpp > CMakeFiles/fs.dir/feature_statistic.cpp.i

CMakeFiles/fs.dir/feature_statistic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fs.dir/feature_statistic.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xhy/cv/myopencv/08_feature2d_module/07_feature_match/feature_statistic.cpp -o CMakeFiles/fs.dir/feature_statistic.cpp.s

CMakeFiles/fs.dir/feature_statistic.cpp.o.requires:

.PHONY : CMakeFiles/fs.dir/feature_statistic.cpp.o.requires

CMakeFiles/fs.dir/feature_statistic.cpp.o.provides: CMakeFiles/fs.dir/feature_statistic.cpp.o.requires
	$(MAKE) -f CMakeFiles/fs.dir/build.make CMakeFiles/fs.dir/feature_statistic.cpp.o.provides.build
.PHONY : CMakeFiles/fs.dir/feature_statistic.cpp.o.provides

CMakeFiles/fs.dir/feature_statistic.cpp.o.provides.build: CMakeFiles/fs.dir/feature_statistic.cpp.o


# Object files for target fs
fs_OBJECTS = \
"CMakeFiles/fs.dir/feature_statistic.cpp.o"

# External object files for target fs
fs_EXTERNAL_OBJECTS =

fs: CMakeFiles/fs.dir/feature_statistic.cpp.o
fs: CMakeFiles/fs.dir/build.make
fs: /usr/local/opencv-4.0.0/lib/libopencv_stitching.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_gapi.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_dnn_objdetect.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_xphoto.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_structured_light.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_phase_unwrapping.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_aruco.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_superres.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_stereo.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_optflow.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_bgsegm.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_hdf.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_ccalib.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_sfm.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_surface_matching.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_fuzzy.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_hfs.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_videostab.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_line_descriptor.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_rgbd.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_tracking.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_bioinspired.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_freetype.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_reg.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_datasets.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_saliency.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_img_hash.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_xfeatures2d.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_dpm.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_xobjdetect.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_face.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_ximgproc.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_shape.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_viz.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_video.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_plot.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_text.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_dnn.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_ml.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_photo.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_objdetect.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_calib3d.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_features2d.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_flann.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_highgui.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_videoio.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_imgcodecs.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_imgproc.so.4.0.0
fs: /usr/local/opencv-4.0.0/lib/libopencv_core.so.4.0.0
fs: CMakeFiles/fs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xhy/cv/myopencv/08_feature2d_module/07_feature_match/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fs.dir/build: fs

.PHONY : CMakeFiles/fs.dir/build

CMakeFiles/fs.dir/requires: CMakeFiles/fs.dir/feature_statistic.cpp.o.requires

.PHONY : CMakeFiles/fs.dir/requires

CMakeFiles/fs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fs.dir/clean

CMakeFiles/fs.dir/depend:
	cd /home/xhy/cv/myopencv/08_feature2d_module/07_feature_match/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xhy/cv/myopencv/08_feature2d_module/07_feature_match /home/xhy/cv/myopencv/08_feature2d_module/07_feature_match /home/xhy/cv/myopencv/08_feature2d_module/07_feature_match/build /home/xhy/cv/myopencv/08_feature2d_module/07_feature_match/build /home/xhy/cv/myopencv/08_feature2d_module/07_feature_match/build/CMakeFiles/fs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fs.dir/depend

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
CMAKE_SOURCE_DIR = /home/xhy/cv/myopencv/08_feature2d_module/09_orb_kaze_surf_compare

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xhy/cv/myopencv/08_feature2d_module/09_orb_kaze_surf_compare/build

# Include any dependencies generated for this target.
include CMakeFiles/feature_compare.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/feature_compare.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/feature_compare.dir/flags.make

CMakeFiles/feature_compare.dir/feature_compare.cpp.o: CMakeFiles/feature_compare.dir/flags.make
CMakeFiles/feature_compare.dir/feature_compare.cpp.o: ../feature_compare.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xhy/cv/myopencv/08_feature2d_module/09_orb_kaze_surf_compare/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/feature_compare.dir/feature_compare.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/feature_compare.dir/feature_compare.cpp.o -c /home/xhy/cv/myopencv/08_feature2d_module/09_orb_kaze_surf_compare/feature_compare.cpp

CMakeFiles/feature_compare.dir/feature_compare.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/feature_compare.dir/feature_compare.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xhy/cv/myopencv/08_feature2d_module/09_orb_kaze_surf_compare/feature_compare.cpp > CMakeFiles/feature_compare.dir/feature_compare.cpp.i

CMakeFiles/feature_compare.dir/feature_compare.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/feature_compare.dir/feature_compare.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xhy/cv/myopencv/08_feature2d_module/09_orb_kaze_surf_compare/feature_compare.cpp -o CMakeFiles/feature_compare.dir/feature_compare.cpp.s

CMakeFiles/feature_compare.dir/feature_compare.cpp.o.requires:

.PHONY : CMakeFiles/feature_compare.dir/feature_compare.cpp.o.requires

CMakeFiles/feature_compare.dir/feature_compare.cpp.o.provides: CMakeFiles/feature_compare.dir/feature_compare.cpp.o.requires
	$(MAKE) -f CMakeFiles/feature_compare.dir/build.make CMakeFiles/feature_compare.dir/feature_compare.cpp.o.provides.build
.PHONY : CMakeFiles/feature_compare.dir/feature_compare.cpp.o.provides

CMakeFiles/feature_compare.dir/feature_compare.cpp.o.provides.build: CMakeFiles/feature_compare.dir/feature_compare.cpp.o


# Object files for target feature_compare
feature_compare_OBJECTS = \
"CMakeFiles/feature_compare.dir/feature_compare.cpp.o"

# External object files for target feature_compare
feature_compare_EXTERNAL_OBJECTS =

feature_compare: CMakeFiles/feature_compare.dir/feature_compare.cpp.o
feature_compare: CMakeFiles/feature_compare.dir/build.make
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_stitching.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_gapi.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_freetype.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_rgbd.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_hdf.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_xobjdetect.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_face.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_superres.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_sfm.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_stereo.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_bioinspired.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_videostab.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_bgsegm.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_hfs.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_dnn_objdetect.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_reg.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_optflow.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_surface_matching.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_fuzzy.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_saliency.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_xphoto.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_tracking.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_line_descriptor.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_ccalib.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_xfeatures2d.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_plot.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_img_hash.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_aruco.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_dpm.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_structured_light.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_ximgproc.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_shape.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_photo.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_video.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_datasets.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_text.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_dnn.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_ml.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_objdetect.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_calib3d.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_features2d.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_highgui.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_videoio.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_imgcodecs.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_flann.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_viz.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_phase_unwrapping.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_imgproc.so.4.0.0
feature_compare: /usr/local/opencv-4.0.0/lib/libopencv_core.so.4.0.0
feature_compare: CMakeFiles/feature_compare.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xhy/cv/myopencv/08_feature2d_module/09_orb_kaze_surf_compare/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable feature_compare"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/feature_compare.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/feature_compare.dir/build: feature_compare

.PHONY : CMakeFiles/feature_compare.dir/build

CMakeFiles/feature_compare.dir/requires: CMakeFiles/feature_compare.dir/feature_compare.cpp.o.requires

.PHONY : CMakeFiles/feature_compare.dir/requires

CMakeFiles/feature_compare.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/feature_compare.dir/cmake_clean.cmake
.PHONY : CMakeFiles/feature_compare.dir/clean

CMakeFiles/feature_compare.dir/depend:
	cd /home/xhy/cv/myopencv/08_feature2d_module/09_orb_kaze_surf_compare/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xhy/cv/myopencv/08_feature2d_module/09_orb_kaze_surf_compare /home/xhy/cv/myopencv/08_feature2d_module/09_orb_kaze_surf_compare /home/xhy/cv/myopencv/08_feature2d_module/09_orb_kaze_surf_compare/build /home/xhy/cv/myopencv/08_feature2d_module/09_orb_kaze_surf_compare/build /home/xhy/cv/myopencv/08_feature2d_module/09_orb_kaze_surf_compare/build/CMakeFiles/feature_compare.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/feature_compare.dir/depend


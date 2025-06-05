add_catch(test_matrix test_matrix.cpp)
add_catch(test_image test_image.cpp)
add_catch(test_image_bonus test_bonus.cpp)

# TODO(@kalabukdima): .cc extension is used to exclude it from clang-format check.
# Change it after moving out from cpp checker.
add_executable(images_demo demo.cpp helpers/image_io.cc)
patch_include_directories(images_demo)
target_link_libraries(images_demo X11 png)
target_include_directories(images_demo PUBLIC X11 png)

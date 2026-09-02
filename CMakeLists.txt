cmake_minimum_required(VERSION 4.2)

if(WIN32)
SET(VCPKG_HOST_TRIPLET "x64-mingw-dynamic")
SET(VCPKG_TARGET_TRIPLET "x64-mingw-dynamic")
endif()

project(F28GE)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML COMPONENTS Network Graphics Window Audio System CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(rapidcsv CONFIG REQUIRED)
find_package(PalSigslot CONFIG REQUIRED)

function(copy_media TARGET_NAME)
    # Ensure the target actually exists before adding the command
    if(NOT TARGET ${TARGET_NAME})
        message(FATAL_ERROR "target_copy_directory_post_build: '${TARGET_NAME}' is not a valid target.")
    endif()

    # Add the post-build command to copy the directory recursively
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/media")
        add_custom_command(
            TARGET ${TARGET_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${CMAKE_CURRENT_SOURCE_DIR}/media"
                "${CMAKE_CURRENT_BINARY_DIR}/media"
            COMMENT "Copying directory from ${CMAKE_CURRENT_SOURCE_DIR}/media to ${CMAKE_CURRENT_BINARY_DIR}/media"
            VERBATIM
        )
    else()
        message(STATUS "copy_media: No media directory found at ${CMAKE_CURRENT_SOURCE_DIR}, skipping copy.")
    endif ()
endfunction()

add_subdirectory(projects/CommonGameCode)
add_subdirectory(projects/SFMLTemplate)
# New subdirectories here...

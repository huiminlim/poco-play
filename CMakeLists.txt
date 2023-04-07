################################################
# Poco Exploration Programs
################################################
cmake_minimum_required( VERSION 3.25.1 )
project( PocoPlay LANGUAGES CXX )

# Force overwrite install prefix path
set( CMAKE_INSTALL_PREFIX
     ${CMAKE_SOURCE_DIR}/build
     CACHE PATH " " FORCE
)

# Use folders in IDE to organize targets
set_property( GLOBAL PROPERTY USE_FOLDERS ON )

set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

################################################
# Build dependencies as external projects
################################################
option( BUILD_EXTERNAL_POCO OFF )

if( BUILD_EXTERNAL_POCO )
     include( ExternalProject )

     ExternalProject_Add( poco
                         URL https://github.com/pocoproject/poco/archive/refs/tags/poco-1.12.4-release.tar.gz
                         INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/external/poco
                         CMAKE_ARGS
                         -D CMAKE_INSTALL_PREFIX=<INSTALL_DIR>
                         -D BUILD_SHARED_LIBS=TRUE
                         -D POCO_DISABLE_INTERNAL_OPENSSL=OFF
                         -D ENABLE_CRYPTO=ON
                         )
     set_target_properties( Poco PROPERTIES FOLDER ExternalProjectTarget )
else()
     set( Poco_DIR ${CMAKE_INSTALL_PREFIX}/poco-1.12.5/vc17_x64/cmake )
     find_package( Poco REQUIRED COMPONENTS Foundation )
endif()

################################################
# Create App to test Poco
################################################
add_subdirectory( types )

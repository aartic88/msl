cmake_minimum_required(VERSION 3.10)

# set the project name
project(msl)

# Marking the directory as include directory so that tests and other can #include them
include_directories(include)
# Create a source set named library_sources which contains only 1 file now
set(library_sources
    src/sieve.cpp 
    src/prime.cpp
)
# Transform the library_sources set to prepend 'src'  
#list(TRANSFORM library_sources PREPEND "src/")
# Use the 'library_sources' and create a static library named msl
add_library(msl STATIC ${library_sources})

# Add the tests. They can access the msl library
add_subdirectory(tests)
add_subdirectory(examples)
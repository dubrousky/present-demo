cmake_minimum_required(VERSION 3.0)
project(demo)

file(GLOB demoSources *.cc)

include_directories(/usr/include/cairo /usr/include/pango-1.0/ /usr/include/glib-2.0)

link_libraries(-lcairo -lxcb -lpangocairo)

add_executable(demo ${demoSources})

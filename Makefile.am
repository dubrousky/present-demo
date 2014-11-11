AM_CPPFLAGS = $(XCBPRESENT_CFLAGS) $(PANGOCAIRO_CFLAGS)
AM_CXXFLAGS = $(PICKY_CXXFLAGS)

source = display.hh display.cc demo.cc

bin_PROGRAMS = demo
demo_SOURCES = display.hh display.cc cairo_objects.hh cairo_objects.cc demo.cc
demo_LDADD = $(XCBPRESENT_LIBS) $(PANGOCAIRO_LIBS)

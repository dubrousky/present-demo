#include <unistd.h>

#include <cstdlib>

#include "display.hh"
#include "cairo_objects.hh"

using namespace std;

struct CairoPixmap
{
  XPixmap pixmap;
  Cairo cairo;

  CairoPixmap( XWindow & window )
    : pixmap( window ),
      cairo( pixmap )
  {}
};

int main( void )
{
  /* create an X11 window */
  XWindow window { 640, 480 };

  /* display it on the screen */
  window.set_name( "X11 Present Demo" );
  window.map();
  window.flush();

  /* initialize pixmap and Cairo context */
  CairoPixmap cairo_pixmap { window };

  /* alternate black and white */
  double gray = 1.0;

  /* count up */
  const unsigned int divisor = 60;
  unsigned int remainder = 0;

  /* draw in a loop */
  while ( true ) {
    /* resize pixmap and Cairo context if necessary */
    const auto window_size = window.size();
    if ( window_size != cairo_pixmap.cairo.size() ) {
      cairo_pixmap = CairoPixmap( window );
    }

    /* draw all black */
    cairo_new_path( cairo_pixmap.cairo );
    cairo_rectangle( cairo_pixmap.cairo, 0, 0, window_size.first, window_size.second );
    cairo_set_source_rgb( cairo_pixmap.cairo, gray, gray, gray );
    cairo_fill( cairo_pixmap.cairo );

    /* flip gray value */
    gray = (gray > 0.5) ? 0 : 1;

    /* present pixmap */
    window.present( cairo_pixmap.pixmap, divisor, remainder );
    remainder = (remainder + 1) % divisor;
  }

  return EXIT_SUCCESS;
}

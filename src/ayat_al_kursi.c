#include <pebble.h>

static Window *window;
static BitmapLayer *image_layer;
static GBitmap *image;

// No function prototypes since all functions are defined before first use.

static void init_app() {

  window = window_create();
  window_stack_push(window, true /* Animated */);

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  image = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_AYAT_AL_KURSI);

  image_layer = bitmap_layer_create(bounds);
  bitmap_layer_set_bitmap(image_layer, image);
  bitmap_layer_set_alignment(image_layer, GAlignTop);

  layer_add_child(window_layer, bitmap_layer_get_layer(image_layer));
  
}

static void deinit_app() {

  // Frees up the memory used by initialized image.
  gbitmap_destroy(image);
  bitmap_layer_destroy(image_layer);
  window_destroy(window);

}

int main(void) {

  init_app();

  // Kickstart event loop.
  app_event_loop();

  deinit_app();

  return 0;
  
}

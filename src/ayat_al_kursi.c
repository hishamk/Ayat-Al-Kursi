#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"

#define MY_UUID { 0xB4, 0x1E, 0x41, 0x83, 0x5B, 0x69, 0x46, 0x3F, 0xA8, 0xF1, 0x20, 0x25, 0x3C, 0xC0, 0x10, 0x64 }
PBL_APP_INFO(MY_UUID,
             "Ayat Al Kursi", "Binary Bakery",
             1, 0, /* App version */
             DEFAULT_MENU_ICON,
             APP_INFO_STANDARD_APP);

Window window;
BmpContainer image_container;

void handle_init(AppContextRef ctx) {

  window_init(&window, "Ayat Al Kursi");
  window_stack_push(&window, true /* Animated */);
  resource_init_current_app(&AYAT_AL_KURSI_IMAGE_RESOURCES);
  
  // Initializes BmpContainer and loads the image resource with given identifier.
  bmp_init_container(RESOURCE_ID_IMAGE_AYAT_AL_KURSI, &image_container);
  layer_add_child(&window.layer, &image_container.layer.layer);
  
}

void handle_deinit(AppContextRef ctx) {

  // Frees up the memory used by initialized BmpContainer.
  bmp_deinit_container(&image_container);

}

void pbl_main(void *params) {

  PebbleAppHandlers handlers = {
    .init_handler = &handle_init,
    .deinit_handler = &handle_deinit
  };
  
  app_event_loop(params, &handlers);
  
}

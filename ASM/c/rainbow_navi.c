#include <stdint.h>
#include "rainbow_navi.h"
#include "z64.h"

static uint32_t frames = 0;

void update_navi_colors() {
  frames++;
  color8RGBA_t *navi_addresses = (color8RGBA_t *)0x800E8214;

  color8RGB_t color_inner = get_rainbow(frames, CYCLE_FRAMES_INNER);
  color8RGB_t color_outer = get_rainbow(frames, CYCLE_FRAMES_OUTER);
  for(int i = 0; i < 26; i++) {
    if(i % 2 == 0) {
      navi_addresses[i].color = color_inner;
    }
    else {
      navi_addresses[i].color = color_outer;
    }
  }

  if (z64_game.actor_list[7].first != NULL) {
    z64_actor_t *fairy = z64_game.actor_list[7].first;
    if (fairy->actor_id != 0x18 || fairy->variable != 0x00)
    {
      while (fairy->next != NULL)
      {
        fairy = fairy->next;
        if (fairy->actor_id == 0x18 && fairy->variable == 0x00)
          break;
      }
    }
    if (fairy != NULL)
    {
      float *fairyrgb = (float *)(((uint32_t)fairy) + 0x234);
      fairyrgb[0] = (float) color_inner.r;
      fairyrgb[1] = (float) color_inner.g;
      fairyrgb[2] = (float) color_inner.b;

      fairyrgb[4] = (float)color_outer.r;
      fairyrgb[5] = (float)color_outer.g;
      fairyrgb[6] = (float)color_outer.b;
    }
  }
}
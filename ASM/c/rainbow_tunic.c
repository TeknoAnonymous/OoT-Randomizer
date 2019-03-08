#include <stdint.h>
#include "rainbow_tunic.h"

// Massive thanks to Krimtonz for the coding help, and MZX for the tweening function!~

static uint32_t frames = 0;

void update_tunic_colors()
{
    frames++;
    color8RGB_t *tunic = (color8RGB_t *)0x800F7AD8;
    color8RGB_t tunicColor = get_rainbow(frames, CYCLE_FRAMES_INNER);

      tunic[0] = tunicColor;

//      tunicColor = get_color(frames, CYCLE_FRAMES_INNER);
      tunic[1] = tunicColor;

//      tunicColor = get_color(frames, CYCLE_FRAMES_INNER);
      tunic[2] = tunicColor;
}
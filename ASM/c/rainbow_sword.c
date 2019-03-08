#include <stdint.h>
#include "rainbow_sword.h"

// Massive thanks to Krimtonz for the coding help, and MZX for the tweening function!~

static uint32_t frames = 0;

extern uint8_t CFG_RAINBOW_SWORD_INNER_ENABLED;
extern uint8_t CFG_RAINBOW_SWORD_OUTER_ENABLED;
extern uint8_t CFG_RAINBOW_SWORD_INNER_FADE_ENABLED;
extern uint8_t CFG_RAINBOW_SWORD_OUTER_FADE_ENABLED;

void update_sword_colors()
{
    frames++;
    color8RGBA_t *sword_trail = (color8RGBA_t*)0x80115DCE;

    if (CFG_RAINBOW_SWORD_INNER_ENABLED)
    {
        color8RGB_t colorInner = get_rainbow(frames, CYCLE_FRAMES_INNER);
        sword_trail[1].color = colorInner;
    }

    if (CFG_RAINBOW_SWORD_INNER_FADE_ENABLED)
    {
        color8RGB_t colorInnerFade = get_rainbow(frames, CYCLE_FRAMES_INNER);
        sword_trail[3].color = colorInnerFade;
    }

    if (CFG_RAINBOW_SWORD_OUTER_ENABLED)
    {
        color8RGB_t colorOuter = get_rainbow(frames, CYCLE_FRAMES_OUTER);
        sword_trail[0].color = colorOuter;
    }

    if (CFG_RAINBOW_SWORD_OUTER_FADE_ENABLED)
    {
        color8RGB_t colorOuterFade = get_rainbow(frames, CYCLE_FRAMES_OUTER);
        sword_trail[2].color = colorOuterFade;
    }
}
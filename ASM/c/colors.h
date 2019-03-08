#include <stdint.h>
#ifndef COLORS_H
#define COLORS_H

#define CYCLE_FRAMES_OUTER 10
#define CYCLE_FRAMES_INNER 12

//TODO: Figure out etiquette because I'm bad

typedef struct
{
  uint8_t r;
  uint8_t g;
  uint8_t b;
} color8RGB_t;

typedef struct
{
  uint16_t r;
  uint16_t g;
  uint16_t b;
} color16RGB_t;

typedef struct
{
  union {
    struct
    {
      uint8_t r;
      uint8_t g;
      uint8_t b;
    };
    color8RGB_t color;
  };
  uint8_t a;
} color8RGBA_t;

static color8RGB_t rainbow_colors[] = {
        {0xE0, 0x10, 0x10}, //red
        {0xE0, 0xE0, 0x10}, //yellow
        {0x10, 0xE0, 0x10}, //green
        {0x10, 0xE0, 0xE0}, //cyan
        {0x10, 0x10, 0xE0}, //blue
        {0xE0, 0x10, 0xE0}, //purple
        {0xE0, 0x10, 0x10}, //red
};

static color8RGB_t get_rainbow(uint32_t f, uint32_t step_frames)
{
  int index;
  float tweenA, tweenB;

  index = (f / step_frames) % 6;

  tweenB = ((float)(f % step_frames) / step_frames);
  tweenA = 1 - tweenB;

  color8RGB_t cA = rainbow_colors[index];
  color8RGB_t cB = rainbow_colors[index + 1];

  color8RGB_t ret;
  ret.r = (uint8_t)((cA.r * tweenA) + (cB.r * tweenB));
  ret.g = (uint8_t)((cA.g * tweenA) + (cB.g * tweenB));
  ret.b = (uint8_t)((cA.b * tweenA) + (cB.b * tweenB));
  return ret;
}

#endif
#ifndef EFFECTS_ENUM_H
#define EFFECTS_ENUM_H

enum class Effects : int
{
  Still,
  ColorWipe,
  BackAndForth,
  Rainbow,
  MovingRainbow,
  Sinelon,

  EnumCount
};

Effects operator++(Effects &e);

Effects operator--(Effects &e);

#endif

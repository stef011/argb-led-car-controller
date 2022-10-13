#include <EffectsEnum.h>

Effects operator++(Effects &e)
{
  e = static_cast<Effects>((static_cast<int>(e) + 1) % (static_cast<int>(Effects::EnumCount)));
  return e;
}

Effects operator--(Effects &e)
{
  e = static_cast<Effects>((static_cast<int>(e) - 1) % (static_cast<int>(Effects::EnumCount)));
  return e;
}

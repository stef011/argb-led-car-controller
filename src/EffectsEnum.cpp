#include <EffectsEnum.h>

Effects operator++(Effects &e)
{
  e = static_cast<Effects>((static_cast<int>(e) + 1) % (static_cast<int>(Effects::EnumCount)));
  return e;
}

Effects operator--(Effects &e)
{
  e = static_cast<Effects>((static_cast<int>(e) - 1) % (static_cast<int>(Effects::EnumCount)));
  if (static_cast<int>(e) < 0)
  {
    e = static_cast<Effects>(static_cast<int>(Effects::EnumCount) - 1);
  }
  return e;
}

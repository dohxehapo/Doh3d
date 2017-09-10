#include "PrecompiledHeader.h"
#include "RectI.h"


namespace Doh3d
{

RectI::RectI()
  : RectI(0, 0, 0, 0)
{
}

RectI::RectI(int pLeft, int pTop, int pRight, int pBottom)
  : d_left(pLeft), d_top(pTop), d_right(pRight), d_bottom(pBottom)
{
}

RectI::RectI(const Vector2I& pPosition, const Size2I& pSize)
  : d_left(pPosition.x), d_top(pPosition.y), d_right(pPosition.x + pSize.x), d_bottom(pPosition.y + pSize.y)
{
}


RectI RectI::operator + (const Vector2I& pOffset) const
{
  return RectI(d_left + pOffset.x, d_top + pOffset.y, d_right + pOffset.x, d_bottom + pOffset.y);
}

RectI RectI::operator - (const Vector2I& pOffset) const
{
  return RectI(d_left - pOffset.x, d_top - pOffset.y, d_right - pOffset.x, d_bottom - pOffset.y);
}


bool RectI::containsPoint(const Vector2I& i_point) const
{
  return !((i_point.x < d_left) || (d_right < i_point.x) || (i_point.y < d_top) || (d_bottom < i_point.y));
}

bool RectI::containsPoint(const Vector2F& i_point) const
{
  return !((i_point.x < d_left) || (d_right < i_point.x) || (i_point.y < d_top) || (d_bottom < i_point.y));
}


bool RectI::containsRect(const RectI& pRect) const
{
  return d_left <= pRect.d_left && pRect.d_right <= d_right && d_top <= pRect.d_top && pRect.d_bottom <= d_bottom;
}

} // Doh3d

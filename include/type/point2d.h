/* Created type/point2d.h by CybernikLee
 *
 * E-Mail <cyberniklee@gmail.com>
 *
 * Copyright 2018 GuangZhou SmartGiant Tech 
 * 
 */

#ifndef _TYPE_POINT2D_H_
#define _TYPE_POINT2D_H_

#include <common/exception.h>
#include <linear-algebra/vector.h>

namespace sgbot {

  class Point2D {
  public:
    Point2D()
    {
      point_(0) = 0.0f;
      point_(1) = 0.0f;
    }

    Point2D(float px, float py)
    {
      point_(0) = px;
      point_(1) = py;
    }
    
    virtual ~Point2D() {}
   
    // Copy constructor
    Point2D(const Point2D& other)
    {
      point_(0) = other.x();
      point_(1) = other.y();
    }

    Point2D& operator =(const Point2D& other)
    {
      point_(0) = other.x();
      point_(1) = other.y();
      return *this;
    }

    Point2D& operator *=(float factor)
    {
      point_ *= factor;
      return *this;
    }

    Point2D& operator /=(float factor)
    {
      point_ /= factor;
      return *this;
    }

    float& x()
    {
      return point_(0);
    }

    const float x() const
    {
      return point_(0);
    }

    float& y()
    {
      return point_(1);
    }

    const float y() const
    {
      return point_(1);
    }

  private:
    sgbot::la::Vector<float, 2> point_;
  };  // class Point2D

}  // namespace sgbot

#endif  // _TYPE_POINT2D_H_

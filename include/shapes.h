#ifndef SHAPES_H
#define SHAPES_H

#include <string>

class BasicShape
{
  double area_m;
  std::string name_m;
public:
  inline double getArea(void) const 
  { return area_m; }

  inline std::string getName(void) const 
  { return name_m; }

  inline void setArea(double area)
  { area_m = area; }

  inline void setName(std::string name)
  { name_m = name; } 

  virtual void calcArea(void) const = 0;
};

class Circle: public BasicShape 
{
  double xCenter, yCenter;
  double radius;
public:
  Circle(double x, double y, double r, std::string name = "Circle");

  void calcArea(void) const override;

  inline double getCenterX(void) const 
  { return xCenter; }

  inline double getCenterY(void) const
  { return yCenter; } 
  
  inline double getRadius(void) const
  { return radius; }

  inline void setCenterX(double x)
  { xCenter = x; }

  inline void setCenterY(double y)
  { yCenter = y; } 

  inline void setRadius(double rad)
  { radius = rad; } 
};

class Rectangle: public BasicShape 
{
};

class Square: public Rectangle 
{
};

#endif

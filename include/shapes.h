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

  inline void setName(std::string name)
  { name_m = name; } 
protected:
  // user code shouldn't be able to do this
  inline void setArea(double area)
  { area_m = area; }

  // user code won't need to call this since setters do it anyway
  virtual void calcArea(void) const = 0;
};

class Circle: public BasicShape 
{
  double xCenter, yCenter;
  double radius;
public:
  Circle(double x, double y, double r, std::string name = "Circle");

  inline double getCenterX(void) const 
  { return xCenter; }

  inline double getCenterY(void) const
  { return yCenter; } 
  
  inline double getRadius(void) const
  { return radius; }

  void setCenterX(double x);

  void setCenterY(double y);

  void setRadius(double rad);
protected:
  void calcArea(void) const override;
};

class Rectangle: public BasicShape 
{
  double length, width;
public: 
  Rectangle(double l, double w, std::string name = "Rectangle");

  inline double getLength(void) const
  { return length; } 

  inline double getWidth(void) const
  { return width; }

  void setLength(double l);

  void setWidth(double l);
protected:
  void calcArea(void) const override;
};

class Square: public Rectangle 
{
  // in directions but no necessary since rectangle sides are equivalent and can
  // be used to store one less double variable.
  //
  // double side;
public:
  Square(double s, std::string name = "Square"); 
  
  inline double getSide(void) const;

  void setSide(double s);
};

#endif

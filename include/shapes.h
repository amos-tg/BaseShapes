#ifndef SHAPES_H
#define SHAPES_H

#include <string>

class BasicShape
{
  double area_m;
  std::string name_m;
public:
  /// returns the area of the shape
  inline double getArea(void) const 
  { return area_m; }

  /// returns the name of the shape
  inline std::string getName(void) const 
  { return name_m; }

  /// sets the name of the shape
  inline void setName(std::string name)
  { name_m = name; } 
protected:
  /// sets the area of the shape
  inline void setArea(double area)
  { area_m = area; }

  /// calculates the area of the shape and sets
  /// the area member using internally stored measurements
  virtual void calcArea(void) = 0;
};

class Circle: public BasicShape 
{
  double xCenter, yCenter;
  double radius;
public:
  /// x: the x coordinate of the circle's center
  /// y: the y coordinate of the circle's center
  /// r: the radius of the circle
  /// name: the name of the circle, defaults to "Circle"
  ///
  /// constructs a Circle object
  explicit Circle(double x, double y, double r, std::string name = "Circle");

  /// returns the x coordinate the circle's center is present at
  inline double getCenterX(void) const 
  { return xCenter; }
  
  /// returns the y coordinate the circle's center is present at
  inline double getCenterY(void) const
  { return yCenter; } 
  
  /// returns the radius of the circle
  inline double getRadius(void) const
  { return radius; }

  /// x: the x coordinate the circle's center is set to
  ///
  /// sets the x coordinate of the circle's center
  inline void setCenterX(double x)
  { xCenter = x; }

  /// y: the y coordinate the circle's center is set to
  ///
  /// sets the y coordinate of the circle's center
  inline void setCenterY(double y)
  { yCenter = y; }

  /// rad: the radius of the circle updated to via this call
  ///
  /// sets the radius of the circle and updates its area
  void setRadius(double rad);
protected:
  /// calculates the area of a circle with pi*radius^2
  void calcArea(void) override;
};

class Rectangle: public BasicShape 
{
  double length, width;
public: 
  /// l: the length of the Rectangle
  /// w: the width of the Rectangle
  /// name: the name of the Rectangle, defaults to "Rectangle"
  ///
  /// constructs a Rectangle object
  explicit Rectangle(double l, double w, std::string name = "Rectangle");

  /// returns the length of the rectangle
  inline double getLength(void) const
  { return length; } 

  /// returns the width of the rectangle
  inline double getWidth(void) const
  { return width; }

  /// l: the length updated to
  ///
  /// sets the length of the rectangle and updates its area
  void setLength(double l);

  /// w: the width updated to
  ///
  /// sets the width of the rectangle and updates its area
  void setWidth(double w);
protected:
  /// calculates the area of a rectangle or square with length*width
  void calcArea(void) override;

  /// Sets length to (double: l) without updating its area
  inline void setLength_unchecked(double l)
  { length = l; }

  /// Sets width to (double: w) without updating its area
  inline void setWidth_unchecked(double w)
  { width = w; }
};

class Square: public Rectangle 
{
public:
  /// side: the length and width of the square
  /// name: the name of the square, defaults to "Square"
  ///
  /// constructs a square object
  explicit Square(double side, std::string name = "Square"); 
  
  /// returns the side length of the square, i.e. both length and width, where
  /// length = width.
  inline double getSide(void) const
  { return getLength(); };

  /// s: the side length set to
  ///
  /// sets the side length of the square
  void setSide(double s);
};

#endif

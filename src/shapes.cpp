#include "shapes.h"
#include <string>
#include <numbers>

using namespace std;

Circle::Circle(double x, double y, double r, string name)
  : xCenter(x), yCenter(y), radius(r)
{
  setName(name);
  calcArea();
}

void Circle::calcArea(void) 
{
  // pi * radius^2 = area of circ
  double area = radius * radius * numbers::pi;
  setArea(area);
}

void Circle::setRadius(double rad)
{
  radius = rad;
  calcArea();
}

Rectangle::Rectangle(double l, double w, string name) 
  : length(l), width(w)
{
  setName(name);
  calcArea();
}

void Rectangle::calcArea(void) 
{
  double area = length * width;
  setArea(area);
}

void Rectangle::setLength(double l)
{
  length = l;
  calcArea();
}

void Rectangle::setWidth(double w)
{
  width = w;
  calcArea();
}

Square::Square(double side, string name) 
  : Rectangle(side, side, name) {}

void Square::setSide(double s)
{
  // don't need to calcArea for each setter call
  setLength_unchecked(s);
  setWidth_unchecked(s);

  calcArea();
}

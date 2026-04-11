#include "shapes.h"
#include <string>
#include <numbers>

using namespace std;

Circle::Circle(double x, double y, double r, std::string name)
  : xCenter(x), yCenter(y), radius(r)
{
  setName(name);
  calcArea();
}

void Circle::calcArea(void) 
{
  double area = radius * 2 * numbers::pi;
  setArea(area);
}

void Circle::setCenterX(double x)
{
  xCenter = x;
  calcArea();
}

void Circle::setCenterY(double y)
{
  yCenter = y;
  calcArea();
}

void Circle::setRadius(double rad)
{
  radius = rad;
  calcArea();
}

Rectangle::Rectangle(double l, double w, std::string name) 
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

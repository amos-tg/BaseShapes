#include "shapes.h"
#include <string>
#include <numbers>

using namespace std;

Circle::Circle(double x, double y, double r, std::string name)
  : xCenter(x), yCenter(y), radius(r)
{
  this->setName(name);
  this->calcArea();
}

void Circle::calcArea(void) 
{
  double area = radius * 2 * numbers::pi;
  setArea(area);
}

void Circle::setCenterX(double x)
{
  xCenter = x;
  this->calcArea();
}

void Circle::setCenterY(double y)
{
  yCenter = y;
  this->calcArea();
}

void Circle::setRadius(double rad)
{
  radius = rad;
  this->calcArea();
}

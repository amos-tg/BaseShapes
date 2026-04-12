#include "shapes.h"
#include <iostream>
#include <cassert>
#include <numbers>

using namespace std;

const char 
  *TEST_PASS { "PASSED" },
  *CONSTRUCTION_TESTS { "Test (shapes.h objects constructors): " },
  *POLYMORPHISM_TESTS { "Test (shapes.h objects polymorphism): " },
  *SETTER_TESTS { "Test (shapes.h setters): " };

// for all shapes.h object derivations of BasicShape 
void construction_tests(void);
void polymorphism_tests(void);
void setter_tests(void);

int main(void) 
{
  construction_tests();
  polymorphism_tests();
  setter_tests();     

  return 0;
}

void construction_tests(void)
{
  cout << CONSTRUCTION_TESTS;

  // create two rectangle objects with diff args
  Rectangle 
    rect1 { 5, 10, "box1" },
    rect2 { 11, 12, "box2" };
  
  // create two circle objects with diff args
  Circle
    circ1 { 1, 2, 15, "Circ1" },
    circ2 { 2, 4, 22, "Circ2" };

  // create one square object
  Square square { 2, "Square" };

  cout << TEST_PASS << endl;
}

void polymorphism_tests(void)
{
  cout << POLYMORPHISM_TESTS;

  BasicShape* arr[3];

  Rectangle box { 5, 5 };
  Square box2 { 12 };
  Circle circ { 12, 12, 12 };
  // store all objects in a BasicShape* array  
  arr[0] = &box;
  arr[1] = &box2;
  arr[2] = &circ;

  // loop through array and print data
  for (BasicShape *shape: arr)
  {
    cout << "Name: " << shape->getName() << '\n';
    cout << "Area: " << shape->getArea() << '\n';
  }

  cout.flush();

  cout << TEST_PASS << endl;
}

void setter_tests(void)
{
  // circle setter tests  
  Circle circ { 10, 12, 15 };
  circ.setRadius(20);

  double rad { circ.getRadius() };
  assert(rad == 20);

  // formula for area of a circ with radius
  //  Area = r^2 * pi
  double expected_area { numbers::pi * rad * rad };
  assert(circ.getArea() == expected_area);

  circ.setCenterX(111);
  assert(circ.getArea() == expected_area);

  circ.setCenterY(222);
  assert(circ.getArea() == expected_area);
}

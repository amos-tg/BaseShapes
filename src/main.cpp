#include "shapes.h"
#include <iostream>
#include <cassert>
#include <numbers>

// tests for the shapes.h classes

using namespace std;

const char 
  *TEST_PASS { "PASSED" },
  *CONSTRUCTION_TESTS { "Test (shapes.h objects constructors): " },
  *POLYMORPHISM_TESTS { "Test (shapes.h objects polymorphism): " },
  *SETTER_TESTS { "Test (shapes.h setters): " };

// constructor tests for all shapes.h object derivations of BasicShape 
void construction_tests(void);

/// tests pointer conversion of "derived_class*"s to BasicShape* through array
/// iteration and virtual member function calls.
void polymorphism_tests(void);

// tests the setters for all objs
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

  cout << TEST_PASS << '\n' << endl;
}

void polymorphism_tests(void)
{
  cout << POLYMORPHISM_TESTS << '\n';

  // instantiate pointed to objs
  Rectangle box { 5, 5 };
  Square box2 { 12 };
  Circle circ { 12, 12, 12 };

  // test implicit base class pointer conversion
  BasicShape* arr[3] = { &box, &box2, &circ };

  // loop through array and print data
  for (BasicShape *shape: arr)
  {
    // test virtual member function calls respect overrides
    cout << "Name: " << shape->getName() << '\n';
    cout << "Area: " << shape->getArea() << "\n\n";
  }

  cout << TEST_PASS << '\n' << endl;
}

void setter_tests(void)
{
  cout << SETTER_TESTS;

  //-- test that circle setters update area
  Circle circ { 10, 12, 15 };
  circ.setRadius(20);

  double rad { circ.getRadius() };
  assert(rad == 20);

  double expected_area { numbers::pi * rad * rad };
  assert(circ.getArea() == expected_area);
  //----

  //-- test circle setters that don't update area
  circ.setCenterX(111);
  assert(circ.getArea() == expected_area);
  assert(circ.getCenterX() == 111);

  circ.setCenterY(222);
  assert(circ.getArea() == expected_area);
  assert(circ.getCenterY() == 222);
  //----

  //-- test that rectangle setters update the area--
  Rectangle r { 10, 10 };
  assert(r.getArea() == 100);

  r.setLength(20);
  assert(r.getArea() == 200);

  r.setWidth(20);
  assert(r.getArea() == 400);
  //----

  //-- test square setters
  Square s { 5 };
  assert(s.getArea() == 25);

  // square is a complete proxy of Rectangle
  s.setSide(10);
  assert(s.getArea() == 100);

  assert(s.getLength() == 10);
  assert(s.getWidth() == 10);
  //----

  cout << TEST_PASS << endl;
}

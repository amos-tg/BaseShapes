#include "shapes.h"
#include <iostream>

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
  
}

void setter_tests(void)
{

}

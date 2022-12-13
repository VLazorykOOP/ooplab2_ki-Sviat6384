// #include "stdafx.h"
#include <iostream>
#include <clocale>
#include <math.h>

using namespace std ;

int main() {
  setlocale(LC_CTYPE , "ukr");
  cout << "введіть a b c d" << endl ;
  int a , b , c, d , x, y ;
  cin >> a >> b >> c >> d ;
  x = ((a<<2) + (a<<3)) + ((((d<<4)-d)+((b<<2)+(b<<3)))>>10)-((c<<2)+(c<<3))+((d<<4)-d);
  y= 12*a+((d*15+12*b)/1024)-12*c+d*15 ;
  cout << "x=" << x << "y="<< y << " a,b,c,d="<< a << b << c << d << endl ;
  return 0 ;
}
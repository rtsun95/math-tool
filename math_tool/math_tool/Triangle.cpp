#define _USE_MATH_DEFINES

#include "Triangle.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

Triangle::Triangle()
{
	system("CLS");
	point_A = read_coord('A');
	point_B = read_coord('B');
	point_C = read_coord('C');
}

Triangle::~Triangle()
{
}

coord read_coord(char _name){
	coord vertex;
	cout << "Please enter the X and Y coordinate of the vertex " << _name << endl;
	cin >> vertex.x >> vertex.y;
	return vertex;
}


double angle_convert(double _radian){
	return _radian * 180.0 / M_PI;
}


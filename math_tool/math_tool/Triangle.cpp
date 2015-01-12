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
	point_A = Triangle::read_coord('A');
	point_B = Triangle::read_coord('B');
	point_C = Triangle::read_coord('C');
	sideAB = sqrt(pow(point_B.x - point_A.x, 2) + pow(point_B.y - point_A.y, 2));
	sideBC = sqrt(pow(point_B.x - point_A.x, 2) + pow(point_B.y - point_A.y, 2));
	sideCA = sqrt(pow(point_B.x - point_A.x, 2) + pow(point_B.y - point_A.y, 2));
	angleA = angle_convert(acos((pow(sideAB, 2) - pow(sideBC, 2) - pow(sideCA, 2)) / (-2 * sideBC*sideCA)));
	angleB = angle_convert(acos((pow(sideBC, 2) - pow(sideAB, 2) - pow(sideCA, 2)) / (-2 * sideAB*sideCA)));
	angleC = angle_convert(acos((pow(sideCA, 2) - pow(sideBC, 2) - pow(sideAB, 2)) / (-2 * sideBC*sideAB)));
}

Triangle::~Triangle()
{
}

coord Triangle::read_coord(char _name){
	coord vertex;
	cout << "Please enter the X and Y coordinate of the vertex " << _name << endl;
	cin >> vertex.x >> vertex.y;
	return vertex;
}


double Triangle::angle_convert(double _radian){
	return _radian * 180.0 / M_PI;
}

double Triangle::getAngle(char _angle){
	if (_angle == 'a' || _angle == 'A')
		return angleA;
	else if (_angle == 'b' || _angle == 'B')
		return angleB;
	else if (_angle == 'c' || _angle == 'C')
		return angleC;
	else return 0;
}

double Triangle::getArea(){

	return 0;
}

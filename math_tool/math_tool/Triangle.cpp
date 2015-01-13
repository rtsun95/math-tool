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
	sideBC = sqrt(pow(point_C.x - point_B.x, 2) + pow(point_C.y - point_B.y, 2));
	sideCA = sqrt(pow(point_A.x - point_C.x, 2) + pow(point_A.y - point_C.y, 2));
	if (checkError()) return;
	setPerimeter();
	setArea();
	angleA = angle_convert(acos((pow(sideAB, 2) - pow(sideBC, 2) - pow(sideCA, 2)) / (-2 * sideBC*sideCA)));
	angleB = angle_convert(acos((pow(sideBC, 2) - pow(sideAB, 2) - pow(sideCA, 2)) / (-2 * sideAB*sideCA)));
	angleC = angle_convert(acos((pow(sideCA, 2) - pow(sideBC, 2) - pow(sideAB, 2)) / (-2 * sideBC*sideAB)));
	showInfo();
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

double Triangle::getSide(char _side){
	if (_side == 'a' || _side == 'A')
		return sideAB;
	else if (_side == 'b' || _side == 'B')
		return sideBC;
	else if (_side == 'c' || _side == 'C')
		return sideCA;
	else return 0;
}

void Triangle::setPerimeter(){
	perimeter = sideAB + sideBC + sideCA;
}

void Triangle::setArea(){
	double semi_perimeter = perimeter / 2;
	area = sqrt(semi_perimeter*(semi_perimeter - sideAB)*(semi_perimeter - sideBC)*(semi_perimeter - sideCA));
}

bool Triangle::checkError(){
	if (sideAB + sideBC < sideCA || sideBC + sideCA < sideAB || sideAB + sideCA < sideBC) return true;
	else return false;
}

void Triangle::showInfo(){
	system("CLS");
	cout << fixed << setprecision(3);
	cout << "Vertex A = ( " << setw(10) << point_A.x << ","
		<< setw(10) << point_A.y << " )" << endl
		<< "Vertex B = ( " << setw(10) << point_B.x << ","
		<< setw(10) << point_B.y << " )" << endl
		<< "Vertex C = ( " << setw(10) << point_C.x << ","
		<< setw(10) << point_C.y<< " )" << endl << endl;
	cout << "Length of side.........AB = " << setw(10) << sideAB << endl
		<< "Length of side.........BC = " << setw(10) << sideBC << endl
		<< "Length of side.........AC = " << setw(10) << sideCA << endl
		<< "Perimeter of the triangle = " << setw(10) << perimeter << endl
		<< "Area of the triangle..... = " << setw(10) << area << endl << endl;
	cout << "Angle A = " << setw(10) << angleA << "" << endl
		<< "Angle B = " << setw(10) << angleB << "" << endl
		<< "Angle C = " << setw(10) << angleC << "" << endl;
}
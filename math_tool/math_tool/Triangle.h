struct coord{
	double x, y;
};
class Triangle
{
	coord point_A, point_B, point_C;
	double sideAB, sideBC, sideCA;
	double angleA, angleB, angleC;
	double perimeter, area;

	coord read_coord(char _name);
	double angle_convert(double _radian);
	
public:
	double getArea();
	double getPerimeter();
	Triangle();
	~Triangle();
	double getAngle(char _angle);
	double getSide(char _side);
	void showInfo();

};



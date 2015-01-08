struct coord{
	double x, y;
};
class Triangle
{
	coord point_A, point_B, point_C;
	double sideA, sideB, sideC;
	double angleA, angleB, angleC;
	double perimeter, area;

	coord read_coord(char _name);
	double angle_convert(double _radian);
	
public:
	double getArea();
	double getPerimeter();
	Triangle();
	~Triangle();
	double getAngle();
	double getSide();
	void showInfo();

};


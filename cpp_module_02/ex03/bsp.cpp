#include "Point.hpp"

static Fixed area(Point const x, Point const y, Point const z) {
    return Fixed(
		//I choose the matrix area calculation method
		(0.5f) * fabsf(((x.getX().toFloat() * y.getY().toFloat()) +
		(y.getX().toFloat() * z.getY().toFloat()) +
		(z.getX().toFloat() * x.getY().toFloat())) - 
		(y.getX().toFloat() * x.getY().toFloat() +
		z.getX().toFloat() * y.getY().toFloat() +
		x.getX().toFloat() * z.getY().toFloat()))
	);
}

bool bsp(Point const x, Point const y, Point const z, Point const point) {
    Fixed areaXYZ = area(x, y, z);
    Fixed areaPXY = area(point, x, y);
    Fixed areaPYZ = area(point, y, z);
    Fixed areaPZX = area(point, z, x);

    if (areaPXY == 0 || areaPYZ == 0 || areaPZX == 0)
        return false;

    return (areaXYZ == areaPXY + areaPYZ + areaPZX);
}

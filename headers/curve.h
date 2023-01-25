#include<vector>
#include<string>
#include<iostream>

class Point {
	std::vector<double> coord; // добавить оператор квадратные скобки и size;
public:

	Point(std::vector<double> args = {}) : coord(args)
	{ }

	std::string to_str() const
	{
		std::string point = "(";
		for (const auto& o : coord)
		{
			point += std::to_string(o) + ", ";
		}
		point.erase(point.size() - 2);
		point += ')';
		
		return point;
	}

	int size() const
	{
		return coord.size();
	}

	double& operator[] (int index) 
	{
		try
		{
			 return coord[index];
		}
		catch (std::runtime_error)
		{
			std::cout << std::endl << "Index " << index << " out of range demension point" << std::endl;
		}
	}
};

class Curve {
	std::string name;
public:
	Curve(std::string name = "") : name(name)
	{ }

	virtual ~Curve()
	{ }

	std::string getName() const
	{
		return name;
	}

	virtual Point calc_point(double t = 0) = 0;
	virtual Point calc_der(double t = 0) = 0;
};

class Circle : public Curve {
	Point center;
	double r;
public:
	Circle(Point p = {}, double r = 0) : Curve("Circle"), center(p), r(r)
	{ }

	~Circle()
	{ }

	Point GetPoint() const
	{
		return center;
	}

	void SetPoint(Point c)
	{
		center = c;
	}

	double GetR() const
	{
		return r;
	}

	void SetR(double rad)
	{
		r = rad;
	}

	virtual Point calc_point(double t) override
	{
		Point res({ 0, 0 });
		res[0] = center[0] + r * (cos(t));
		res[1] = center[1] + r * (sin(t));
		return res;
	}

	virtual Point calc_der(double t) override
	{
		Point res({ 0, 0 });
		res[0] = center[0] - r * (sin(t));
		res[1] = center[1] + r * (cos(t));
		return res;
	}
};
class Ellipse : public Curve {
	Point center;
	double xr; 
	double yr;
public:
	Ellipse(Point p = {}, double xr = 0, double yr = 0) : Curve("Ellipse"), center(p), xr(xr), yr(yr)
	{ }

	~Ellipse()
	{ }

	Point GetPoint()
	{
		return center;
	}

	void SetPoint(Point c)
	{
		center = c;
	}

	double GetXr()
	{
		return xr;
	}

	void SetXr(double r)
	{
		xr = r;
	}

	double GetYr()
	{
		return yr;
	}

	void SetYr(double r)
	{
		yr = r;
	}

	virtual Point calc_point(double t) override
	{
		Point res({ 0, 0 });
		res[0] = center[0] + xr * (cos(t));
		res[1] = center[1] + yr * (sin(t));
		return res;
	}

	virtual Point calc_der(double t) override
	{
		Point res({ 0, 0 });
		res[0] = center[0] - xr * (sin(t));
		res[1] = center[1] + yr * (cos(t));
		return res;
	}
};

class Helix : public Curve {
	Point center;
	double r;
	double step;
public:
	Helix(Point p = {}, double r = 0, double step = 0) : Curve("Helix"), center(p), r(r), step(step)
	{ }

	~Helix()
	{ }

	Point GetPoint()
	{
		return center;
	}

	void SetPoint(Point c)
	{
		center = c;
	}

	double GetR()
	{
		return r;
	}

	void SetR(double rad)
	{
		r = rad;
	}

	double GetStep()
	{
		return step;
	}

	void SetStep(double st)
	{
		step = st;
	}

	virtual Point calc_point(double t) override
	{
		Point res({ 0, 0, 0 });
		res[0] = center[0] + r * (cos(t));
		res[1] = center[1] + r * (sin(t));
		res[2] = center[2] + step * t;
		return res;
	}

	virtual Point calc_der(double t) override
	{
		Point res({ 0, 0, 0 });
		res[0] = center[0] - r * (sin(t));
		res[1] = center[1] + r * (cos(t));
		res[0] = center[2] + step;
		return res;
	}
};
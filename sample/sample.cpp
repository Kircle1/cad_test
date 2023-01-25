#include <iostream>
#include <vector>
#include "curve.h"
#include <random>
#include <ctime>
#include <algorithm>
static const double PI = 3.1415926535;

double rnd(double l, double r, int accur)
{
	static std::mt19937 m{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::uniform_int_distribution<> uid{ 0, accur };
	return l + ((r - l) / accur) * uid(m);
}
int main()
{
	double left_bound = -10, right_bound = 10;
	int accur = 1000;
	///////////////////  2,3,4,6  ///////////////////
	std::vector<Curve*> v1;
	std::vector<Circle*> v2;
	double sum = 0;
	std::cout << "t = PI/4" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		int32_t what_is_curve = rnd(0, 2, 2);
		switch (what_is_curve)
		{
		case 0:
		{
			v1.push_back(new Circle({{rnd(left_bound, right_bound, accur),
									 rnd(left_bound, right_bound, accur)}},
									 rnd(0, right_bound, accur)));
			auto circle = dynamic_cast<Circle*>(v1.back());
			std::cout << i << " : " << circle->getName() << ": center = " << circle->GetPoint().to_str()
				<< ", r = " << circle->GetR() << ", F(t) = " << circle->calc_point(PI / 4).to_str()
				<< ", F'(t) = " << circle->calc_der(PI / 4).to_str() << std::endl;
			v1.pop_back();
			v2.push_back(circle);
			sum += circle->GetR();
			break;
		}
		case 1: 
		{
			v1.push_back(new Ellipse({{rnd(left_bound, right_bound, accur),
									  rnd(left_bound, right_bound, accur)}},
									  rnd(0, right_bound, accur),
									  rnd(0, right_bound, accur)));
			auto ellipse = dynamic_cast<Ellipse*>(v1.back());
			std::cout << i << " : " << ellipse->getName() << ": center = " << ellipse->GetPoint().to_str()
				<< ", xr = " << ellipse->GetXr() << ", yr = " << ellipse->GetYr() 
				<< ", F(t) = " << ellipse->calc_point(PI / 4).to_str()
				<< ", F'(t) = " << ellipse->calc_der(PI / 4).to_str() << std::endl;
			break;
		}
		case 2: 
		{
			v1.push_back(new Helix({{rnd(left_bound, right_bound, accur),
									rnd(left_bound, right_bound, accur),
									rnd(left_bound, right_bound, accur)}},
									rnd(0, right_bound, accur),
									rnd(0, right_bound, accur)));
			auto helix = dynamic_cast<Helix*>(v1.back());
			std::cout << i << " : " << helix->getName() << ": center = " << helix->GetPoint().to_str()
				<< ", r = " << helix->GetR() << ", step = " << helix->GetStep()
				<< ", F(t) = " << helix->calc_point(PI / 4).to_str()
				<< ", F'(t) = " << helix->calc_der(PI / 4).to_str() << std::endl;
			break;
		}
		}
	}
	///////////////////  5  ///////////////////
	std::cout << std::endl;
	std::sort(v2.begin(), v2.end(), [](Circle* l, Circle* r) {
		return l->GetR() < r->GetR();
		});
	for (int i = 0; i < v2.size(); i++)
	{
		std::cout << i << " : " << v2[i]->getName() << ": center = " << v2[i]->GetPoint().to_str()
			<< ", r = " << v2[i]->GetR() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "sum of radiuses = " << sum << std::endl;
	return 0;
}

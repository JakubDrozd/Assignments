#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;


class Point : public vector<double> {
public:
	Point(int dimension) {
		random_device random_dev;
		default_random_engine random_gen(random_dev());
		normal_distribution<double> dist(0.0, 10.0);
		resize(dimension);
		generate(this->begin(), this->end(),
			[&]() {
				return dist(random_gen);
			}
		);
	}
};

class Cloud : public vector<Point> {
private:
public:
	Cloud(int points_count, int dimension) {
		generate_n(std::back_inserter(*this), points_count, 
			[dimension]() {
				return Point(dimension);
			}
		);
	}
};


int main() {
	Cloud chmura_A(100, 2);
	Point p1(2);
	Point p2(2);
	Point p3(4);
	return 0;
}
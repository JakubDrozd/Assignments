#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

template <class T>
class Average {
private:
	T n;
public:
	Average(const T& n) : n(n) {};
	void operator() (T& src) const {
		src /= n;
	}
};

static double DiffPower2(double x, double y) {
	return pow((x - y), 2.0);
}


class Point : public vector<double> {
public:
	double mean;
	double omega;

	Point() :mean(0), omega(0){};
	Point(int dimension, double mean, double omega) {
		this->mean = mean;
		this->omega = omega;
		random_device random_dev;
		default_random_engine random_gen(random_dev());
		normal_distribution<double> dist(mean, omega);
		resize(dimension);
		generate(this->begin(), this->end(),
											[&]() {
												return dist(random_gen);
											}
		);
	}
	Point operator+(const Point &src) {
		Point result((int)size(), src.mean, src.omega);
		transform(begin(), end(), src.begin(), result.begin(), plus<>());
		return result;
	}
	friend ostream& operator<<(ostream& stream, const Point& src);
};

ostream& operator<<(ostream& stream, const Point& src) {
	copy(src.begin(), src.end(), ostream_iterator<double>(stream, " "));
	return stream;
}

class Cloud : public vector<Point> {
private:
public:
	Point centroid;
	Cloud(int points_count, int dimension, double mean, double omega) {
		generate_n(back_inserter(*this), points_count, 
														[dimension, mean, omega]() {
															return Point(dimension, mean, omega);
														}
		);

		centroid = accumulate(begin(), end(), Point(dimension, mean, omega));
		for_each(centroid.begin(), centroid.end(), Average<double>(points_count));
	}
};


int main() {
	Cloud chmura_A(100, 2, 0, 10);
	cout << "Centroid A: " << chmura_A.centroid << endl;
	Cloud chmura_B(100, 2, 10, 10);
	cout << "Centroid B: " << chmura_B.centroid << endl;
	double distance;
	distance = sqrt(inner_product(chmura_A.centroid.begin(), chmura_A.centroid.end(), chmura_B.centroid.begin(), 0.0, plus<double>(), DiffPower2));
	cout << "Dystans miedzy centroidami: " << distance << endl;
	return 0;
}
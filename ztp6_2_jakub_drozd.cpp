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

class Cloud;

class Point : public vector<double> {
public:
	Cloud* origin;
	double mean;
	double omega;
	Point() : mean(0), omega(0), origin(nullptr) {};
	Point(int dimension, double mean, double omega, Cloud* origin = nullptr) : mean(mean), omega(omega), origin(origin) {
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
	Point operator+(const Point& src) {
		Point result((int)size(), src.mean, src.omega);
		transform(begin(), end(), src.begin(), result.begin(), plus<>());
		return result;
	}
	friend ostream& operator<<(ostream& stream, const Point& src);
};

static double define_distance(const Point& a, const Point& b) {
	return sqrt(inner_product(a.begin(), a.end(), b.begin(), 0.0, plus<double>(), DiffPower2));
}
ostream& operator<<(ostream& stream, const Point& src) {
	copy(src.begin(), src.end(), ostream_iterator<double>(stream, " "));
	return stream;
}

class Cloud : public vector<Point> {
private:
public:
	int moved_counter;
	Point centroid;
	Cloud(int points_count, int dimension, double mean, double omega) {
		moved_counter = 0;
		generate_n(back_inserter(*this), points_count,
			[dimension, mean, omega, this]() {
				return Point(dimension, mean, omega, this);
			}
		);

		centroid = accumulate(begin(), end(), Point(dimension, mean, omega));
		for_each(centroid.begin(), centroid.end(), Average<double>(points_count));
	}
};

class DefineOrigin {
private:
	Cloud& chmura_A;
	Cloud& chmura_B;
public:
	DefineOrigin(Cloud& chmura_A, Cloud& chmura_B) : chmura_A(chmura_A), chmura_B(chmura_B) {};
	void operator()(Point& element) {
		double distance_to_A = (define_distance(element, chmura_A.centroid));
		double distance_to_B = (define_distance(element, chmura_B.centroid));
		if ( distance_to_A < distance_to_B )
		{
			if (element.origin == &chmura_A) {
				return;
			}
			else
			{
				element.origin = &chmura_A;
				chmura_A.moved_counter++;
			}
		}
		else
		{
			if (element.origin == &chmura_B)
			{
				return;
			}
			else
			{
				element.origin = &chmura_B;
				chmura_B.moved_counter++;
			}
			
		}
	}
};


int main() {
	Cloud chmura_A(100, 2, 0, 10);
	cout << "Centroid A: " << chmura_A.centroid << endl;
	Cloud chmura_B(100, 2, 10, 10);
	cout << "Centroid B: " << chmura_B.centroid << endl;
	cout << "Dystans miedzy centroidami: " << define_distance(chmura_A.centroid, chmura_B.centroid) << endl;

	for_each(chmura_A.begin(), chmura_A.end(), DefineOrigin(chmura_A, chmura_B));
	for_each(chmura_B.begin(), chmura_B.end(), DefineOrigin(chmura_A, chmura_B));

	cout << "Przeszlo z A do B: " << chmura_A.moved_counter << endl;
	cout << "Przeszlo z B do A: " << chmura_B.moved_counter << endl;

	return 0;
}
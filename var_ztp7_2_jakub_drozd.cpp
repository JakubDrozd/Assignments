#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <random>
#include <numeric>
#include <string>
#include <iomanip>

using namespace std;

class divide {
private:
	double divider;
public:
	divide(double divider) : divider(divider) {};
	double operator()(double& number) {
		return number /= divider;
	}
};

class multiply {
private:
	double multiplier;
public:
	multiply(double multiplier) : multiplier(multiplier) {};
	double operator()(double number) {
		return number * multiplier;
	}
};

class greaterThan {
private:
	double base;
public:
	greaterThan(double base) : base(base) {};
	bool operator()(double element){
		return element > base;
	}
};

class lesserThan {
private:
	double base;
public:
	lesserThan(double base) : base(base) {};
	bool operator()(double element) {
		return element < base;
	}
};

class generatorLiczbNormalny {
private:
	static default_random_engine generator;
	normal_distribution<double> distribution;
public:
	generatorLiczbNormalny(int mi = 0, int sigma = 1) : distribution(mi, sigma) {};

	double operator()() {
		return distribution(generator);
	}
};

class Point : public vector<double> {
private:
public:
	int dimension;
	int mi;
	int sigma;
	Point() : vector<double>() {};
	Point(int dimension, int mi, int sigma) : dimension(dimension), mi(mi), sigma(sigma) {
		generate_n(back_inserter(*this), dimension, generatorLiczbNormalny(mi, sigma));
	}

	friend ostream& operator<<(ostream& stream, const Point& p);

	Point operator+(const Point& src) {
		Point result_point(src.dimension, src.mi, src.sigma);
		transform(this->begin(), this->end(), src.begin(), result_point.begin(), plus<>());
		return result_point;
	}
	Point operator-(const Point& src) {
		Point result_point(src.dimension, src.mi, src.sigma);
		transform(begin(), end(), src.begin(), result_point.begin(), minus<>());
		return result_point;
	}
	Point operator*(const double scalar) {
		Point result_point(this->dimension, this->mi, this->sigma);
		transform(begin(), end(), result_point.begin(), multiply(scalar));
		return result_point;
	}
};
ostream& operator<<(ostream& stream, const Point& p) {
	copy(p.begin(), p.end(), ostream_iterator<double>(cout, " "));
	stream << fixed << setprecision(5);
	return stream;
}

class PointContainer : public vector<Point> {
private:
public:
	int dimension = 2;
	int mi = 5;
	int sigma = 10;
	int howManyPoints;
	Point centroid;

	PointContainer() : vector<Point>() {};
	PointContainer(int dimension) : vector<Point>(dimension) {};
	PointContainer(int dimension, int howManyPoints, int mi, int sigma) : dimension(dimension),
		mi(mi), sigma(sigma), howManyPoints(howManyPoints) {
		generate_n(back_inserter(*this), howManyPoints, [dimension, mi, sigma]() {
			return Point(dimension, mi, sigma);
			}
		);
	}

	void calculateCentroid() {
		centroid = accumulate(begin(), end(), Point(dimension, mi, sigma), plus<>());
		for_each(centroid.begin(), centroid.end(), divide((double)size()));

	}
	friend ostream& operator<<(ostream& stream, const PointContainer& c);
};
ostream& operator<<(ostream& stream, const PointContainer& c) {
	copy(c.begin(), c.end(), ostream_iterator<Point>(cout, "\n"));
	stream << fixed << setprecision(5);
	return stream;
}


default_random_engine generatorLiczbNormalny::generator;


double diffPow2(double x, double y) { return pow((x - y), 2.0); };

static double define_distance(const Point& a, const Point& b) {
		return sqrt(inner_product(a.begin(), a.end(), b.begin(), 0.0, plus<double>(), diffPow2));
}

int main() {
	int dimension;
	cout << "Podaj wymiar: ";
	cin >> dimension;

	PointContainer chmuraA(dimension, 100, 5, 10);
	chmuraA.calculateCentroid();
	cout << "CENTROID A: ";
	cout << chmuraA.centroid << endl;

	PointContainer chmuraAPrim((int)chmuraA.size());
	transform(chmuraA.begin(), chmuraA.end(), chmuraAPrim.begin(),
		[&](Point& point) {
			return (chmuraA.centroid * 2) - point;
		});

	chmuraAPrim.calculateCentroid();
	cout << "CENTROID A': ";
	cout << chmuraAPrim.centroid << endl;

	vector<double> distances;
	transform(chmuraA.begin(), chmuraA.end(), back_inserter(distances),
		[&](Point& point) {
			double distance = define_distance(point, chmuraA.centroid);
			return distance;
		});
	
	double promienR = *max_element(distances.begin(), distances.end());
	cout << "Promien R: " << promienR << endl;
	int ponizej = count_if(distances.begin(), distances.end(), lesserThan(promienR/2));
	int powyzej = count_if(distances.begin(), distances.end(), greaterThan(promienR/2));
	cout << "Ponizej R/2 od centroidu: " << ponizej << endl;
	cout << "Powyzej R od centroidu: " << powyzej << endl;


	vector<double> distancesPrim;
	transform(chmuraAPrim.begin(), chmuraAPrim.end(), back_inserter(distancesPrim),
		[&](Point& point) {
			double distance = define_distance(point, chmuraAPrim.centroid);
			return distance;
		});

	double promienRPrim = *max_element(distancesPrim.begin(), distancesPrim.end());
	cout << "[PRIM] Promien R: " << promienRPrim << endl;
	int ponizejPrim = count_if(distancesPrim.begin(), distancesPrim.end(), lesserThan(promienRPrim / 2));
	int powyzejPrim = count_if(distancesPrim.begin(), distancesPrim.end(), greaterThan(promienRPrim / 2));
	cout << "[PRIM] Ponizej R/2 od centroidu: " << ponizejPrim << endl;
	cout << "[PRIM] Powyzej R od centroidu: " << powyzejPrim << endl;

	return 0;
}
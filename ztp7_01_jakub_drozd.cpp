//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <functional>
//#include <random>
//#include <numeric>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//
//class generatorLiczbNormalny {
//private:
//	static default_random_engine generator;
//	normal_distribution<double> distribution;
//public:
//	generatorLiczbNormalny(double mi = 0, double sigma = 1) : distribution(mi, sigma) {};
//
//	double operator()() {
//		return distribution(generator);
//	}
//};
//
//
//class Point : public vector<double> {
//private:
//public:
//	Point(int dimension, double mi, double sigma) {
//		generate_n(back_inserter(*this), dimension, generatorLiczbNormalny(mi, sigma));
//	}
//
//	friend ostream& operator<<(ostream& stream, const Point& p);
//};
//ostream& operator<<(ostream& stream, const Point& p) {
//	copy(p.begin(), p.end(), ostream_iterator<double>(cout, " "));
//	return stream;
//}
//
//class PointContainer : public vector<Point> {
//private:
//public:
//	PointContainer() : vector<Point>() {};
//	PointContainer(int dimension, int howManyPoints, double mi, double sigma) {
//		generate_n(back_inserter(*this), howManyPoints, [dimension, mi, sigma]() {
//															return Point(dimension, mi, sigma);
//														}
//		);
//	}
//	friend ostream& operator<<(ostream& stream, const PointContainer& c);
//};
//ostream& operator<<(ostream& stream, const PointContainer& c) {
//	copy(c.begin(), c.end(), ostream_iterator<Point>(cout, "\n"));
//	return stream;
//}
//
//class isNotDominated {
//private:
//	const PointContainer& allPoints;
//public:
//	isNotDominated(const PointContainer& allPoints) : allPoints(allPoints) {}
//
//	bool operator()(const Point& source) {
//		return std::none_of(allPoints.begin(), allPoints.end(), [&](const Point& other) {
//			if (other == source) return false;
//			auto pair = std::mismatch(source.begin(), source.end(), other.begin(), std::less_equal<>());
//			return (pair.first == source.end());
//			});
//	}
//};
//
//static double diffPow2(double x, double y) { return pow((x - y), 2.0); };
//
//static double define_distance(const Point& a, const Point& b) {
//	return sqrt(inner_product(a.begin(), a.end(), b.begin(), 0.0, plus<double>(), diffPow2));
//}
//
//default_random_engine generatorLiczbNormalny::generator;
//int main() {
//	PointContainer p(2, 10000, 5, 10);
//	PointContainer a;
//	copy_if(p.begin(), p.end(), back_inserter(a), isNotDominated(p));
//	cout << "\nNIEZDOMINOWANE:\n" << endl;
//	cout << a;
//	PointContainer b = a;
//	cout << "\nGESTOSCI:\n" << endl;
//
//	std::for_each(a.begin(), a.end(), [&](const Point& pointA) {
//		vector<double> distances;
//
//		std::transform(b.begin(), b.end(), std::back_inserter(distances),
//			[&](const Point& pointB) {
//				return (pointA != pointB) ? define_distance(pointA, pointB) : numeric_limits<double>::max();
//			});
//
//		size_t kIndex = static_cast<size_t>(sqrt(distances.size())) - 1;
//		nth_element(distances.begin(), distances.begin() + kIndex, distances.end());
//		double density = distances[kIndex];
//
//		cout << pointA << " : " << density << "\n";
//		});
//	
//
//	return 0;
//}
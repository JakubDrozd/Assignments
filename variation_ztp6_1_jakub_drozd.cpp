//#include <iostream>
//#include <algorithm>
//#include <functional>
//#include <vector>
//#include <random>
//#include <numeric>
//
//using namespace std;
//
//class rand_double {
//protected:
//    static random_device gen;
//};
//random_device rand_double::gen;
//
//class Urand_double : public rand_double {
//    // This distribution produces random numbers in a range[a, b) 
//    // where all intervals of the same length within it are equally probable.
//    uniform_real_distribution<double> Udist;
//public:
//    Urand_double(double a, double b) : Udist(a, b) {};
//    double operator()() { return Udist(gen); }
//};
//
//class Nrand_double : public rand_double {
//    // This distribution produces random numbers around the distribution 
//    // mean (mi) with a specific standard deviation (sigma).
//    normal_distribution<double> Ndist;
//public:
//    Nrand_double(double mi, double sigma) : Ndist(mi, sigma) {};
//    double operator()() { return Ndist(gen); }
//};
//
//class Sum {
//private:
//    double result;
//public:
//    Sum() : result(0) {};
//    void operator()(double element) {
//        result += element;
//    }
//    double get_result() const { return result; };
//};
//
//static double Power2(double x) {
//    return pow(x, 2.0);
//};
//
//class Diff {
//private:
//    double value;
//public:
//    Diff(const double & value) : value(value) {};
//    double operator()(double element) const {
//        return element -= value;
//    }
//};
//
//class ValueSeries : public std::vector<double>{
//private:
//public:
//    ValueSeries(int data_count) {
//        generate_n(back_inserter(*this), data_count, [&]() {return 0; });
//    };
//    ValueSeries(int data_count, bool generate_values) {
//        generate_n(back_inserter(*this), data_count, Nrand_double(0, 10));
//        Sum summary = for_each(begin(), end(), Sum());
//        double average = summary.get_result() / data_count; // x^
//        
//        ValueSeries differences(data_count);
//        transform(begin(), end(), differences.begin(), Diff(average));
//
//        transform(differences.begin(), differences.end(), differences.begin(), Power2); // (xi - x^)^2
//
//        double sum = accumulate(differences.begin(), differences.end(), 0.0);
//
//        double variation = sum / (data_count - 1);
//        cout << "Variation: " << variation << endl;
//	}
//};
//
//
//int main() {
//    ValueSeries container1(100, true);
//	return 0;
//}
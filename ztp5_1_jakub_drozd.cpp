//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
//#include <list>
//#include <algorithm>
//#include <queue>
//#include <sstream>
//
//
//using namespace std;
//
//ostream& operator<<(ostream& stream, const list<string>& src) {
//	if (!src.empty())
//	{
//		stream << src.front().length() << ": ";
//		for (const auto &word : src)
//		{
//			stream << word << " ";
//		}
//	}
//	stream << "\n";
//	return stream;
//}
//
//static bool alfabet(const string &a, const string &b) {
//	return a < b;
//}
//
//class CompareFirstWordLength {
//public:
//	bool operator()(list<string>& a, list<string> b) {
//		if (a.empty() || b.empty())
//		{
//			return false;
//		}
//		return a.front().length() < b.front().length();
//	}
//};
//
//class Mikser : public priority_queue <list<string>, vector<list<string>>, CompareFirstWordLength> {
//private:
//public:
//	Mikser(string filename) { open(filename); };
//	~Mikser() {};
//	void open(string filename) {
//		ifstream file(filename);
//		string line;
//		while (getline(file, line))
//		{
//			if (line.empty())
//			{
//				continue;
//			}
//			istringstream iss(line);
//			list<string> words;
//			string word;
//			while (iss >> word)
//			{
//				words.push_back(word);
//			}
//			words.sort(alfabet);
//			this->push(words);
//		}
//	};
//	friend ostream& operator<<(ostream& stream, list<string>& src);
//	void write(string filename) {
//		ofstream file(filename);
//		while (!this->empty()) {
//			file << top();
//			pop();
//		}
//	}
//};
//
//
//
//int main() {
//	Mikser wiersz("mistrz.txt");
//	wiersz.write("mistrz2.txt");
//}
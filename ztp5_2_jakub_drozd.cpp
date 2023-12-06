#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
#include <queue>
#include <sstream>
#include <set>


using namespace std;

ostream& operator<<(ostream& stream, const list<string>& src) {
	if (!src.empty())
	{
		stream << src.front().length() << ": ";
		for (const auto& word : src)
		{
			stream << word << " ";
		}
	}
	stream << "\n";
	return stream;
}

ostream& operator<<(ostream& stream, const set<string>& src) {
	if (!src.empty())
	{
		stream << src.size() << ": ";
		for (const auto& word : src)
		{
			stream << word << " ";
		}
	}
	stream << "\n";
	return stream;
}

static bool alfabet(const string& a, const string& b) {
	return a < b;
}

class CompareFirstWordLength {
public:
	bool operator()(list<string>& a, list<string> b) {
		if (a.empty() || b.empty())
		{
			return false;
		}
		return a.front().length() < b.front().length();
	}
};

class CompareSetSize {
private:
public:
	bool operator()(set<string>& a, set<string>& b) {
		if (a.empty() || b.empty())
		{
			return false;
		}
		return a.size() < b.size();
	}
};

class Mikser : public priority_queue <list<string>, vector<list<string>>, CompareFirstWordLength> {
private:
public:
	Mikser() {};
	Mikser(string filename) { open(filename); };
	~Mikser() {};
	void open(string filename) {
		ifstream file(filename);
		string line;
		while (getline(file, line))
		{
			if (line.empty())
			{
				continue;
			}
			istringstream iss(line);
			list<string> words;
			string word;
			while (iss >> word)
			{
				words.push_back(word);
			}
			words.sort(alfabet);
			this->push(words);
		}
	};
	friend ostream& operator<<(ostream& stream, list<string>& src);
	void write(string filename) {
		ofstream file(filename);
		while (!this->empty()) {
			file << top();
			pop();
		}
	}
};

template <class T>
class Mikser2 : public priority_queue<set<string>, vector<set<string>>, CompareSetSize>, public T {
private:
public:
	Mikser2() {};
	Mikser2(string filename) { open(filename); };
	~Mikser2() {};
	void open(string filename) {
		ifstream file(filename);
		string line;
		while (getline(file, line))
		{
			istringstream iss(line);
			string word;
			set<string> words;
			while (iss >> word)
			{
				words.insert(word);
			}
			if (!words.empty())
			{
				priority_queue<set<string>, vector<set<string>>, CompareSetSize>::push(words);
			}
		}
	};
	friend ostream& operator<<(ostream& stream, set<string>& src);
	void write(string filename) {
		ofstream file(filename);
		while (!priority_queue<set<string>, vector<set<string>>, CompareSetSize>::empty()) {
			file << top();
			pop();
		}
	}
};



int main() {
	Mikser2<Mikser> quovadis("quovadis.txt");
	quovadis.write("quovadis2.txt");
}
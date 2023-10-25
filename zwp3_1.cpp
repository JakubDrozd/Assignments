#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

class tex_error : public exception{
public:
	string error_message;
	tex_error(const string& message, int linijka) {
		this->error_message = "Linijka: " + to_string(linijka) + " [" + message + "]";
	}
	const char* what() const override {
		return error_message.c_str();
	}
};


class Stos {
public:
	string kolekcja[20];
	int kursor;
	void push(string& linia) {
		kolekcja[kursor++] = linia;
	}
	string pop() {
		if (kursor <= 0)
		{
			throw out_of_range("Stos jest pusty");
		}
		return kolekcja[--kursor];
	}
	string peek() {
		if (kursor <= 0)
		{
			throw out_of_range("Stos jest pusty");
		}
		return kolekcja[kursor - 1];
	}
	bool is_empty() {
		if (kursor == 0)
		{
			return true;
		}
		return false;
	}
	Stos() : kursor(0) {};
	~Stos() {
		while (kursor > 0)
		{
			pop();
		}
	}
};

void sprawdzanie(istream& stream) {
	string linia;
	int licznik = 0;
	Stos tagi;
	
	try
	{
		while (getline(stream, linia))
		{
			licznik++;
			size_t begin_Pos = linia.find("\\begin{");
			size_t end_Pos = linia.find("\\end{");
			size_t item_Pos = linia.find("\\item ");

			if (begin_Pos != string::npos)
			{
				string in_tag = linia.substr(begin_Pos + 7, linia.find('}', begin_Pos) - (begin_Pos + 7));
				tagi.push(in_tag);
			}
			else if (end_Pos != string::npos)
			{
				if (tagi.is_empty())
				{
					throw tex_error("Brak pasujacego begin{", licznik);
				}
				string in_tag = linia.substr(end_Pos + 5, linia.find('}', end_Pos) - (end_Pos + 5));
				string topTag = tagi.pop();
				if (topTag != in_tag)
				{
					throw tex_error("Niepoprawne sparowanie tagow begin{ i end{", licznik);
				}
			}
			else if (item_Pos != string::npos)
			{
				if (tagi.is_empty() || tagi.peek() != "itemize" && tagi.peek() != "enumerate")
				{
					throw tex_error("\\Item musi zawierac sie w liscie", licznik);
				}

			}
		}
		cout << "Syntatyka pliku poprawna, nie znaleziono zadnych bledow." << endl;

		if (!tagi.is_empty())
		{
			throw tex_error("Bledne dopasowanie tagow", licznik);
		}
	}
	catch (const tex_error &e)
	{
		cout << e.what() << endl;
	}
}


int main() {

	ifstream plik("tex.txt");
	if (!plik)
	{
		cerr << "Blad przy otwieraniu pliku" << endl;
	}
	sprawdzanie(plik);

}
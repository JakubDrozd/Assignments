#include <string>
#include <iostream>
#include <iomanip>


class Zbior_z_powtorzeniami
{
private:

	class Element {
	public:
		std::string content;
		Element* nast;
		Element() {
			this->content = "";
			this->nast = nullptr;
		}
		Element(std::string content) {
			this->content = content;
			this->nast = nullptr;
		}
		void display() {
			std::cout << this->content << std::endl;
		}
	};



	Element* pierwszy;

public:
	Zbior_z_powtorzeniami();
	~Zbior_z_powtorzeniami();
	void insert(std::string data);
	void remove(std::string data);
	bool exists(std::string data);
	void display();
};

Zbior_z_powtorzeniami::Zbior_z_powtorzeniami()
{
	pierwszy = nullptr;
}

Zbior_z_powtorzeniami::~Zbior_z_powtorzeniami()
{
	while (pierwszy != nullptr)
	{
		Element* aktualny = pierwszy;
		pierwszy = pierwszy->nast;
		delete aktualny;
	}
}

bool Zbior_z_powtorzeniami::exists(std::string data) {
	Element* aktualny = pierwszy;
	while (aktualny != nullptr)
	{
		if (aktualny->content == data)
		{
			return true;
		}
		else
		{
			aktualny = aktualny->nast;
		}
	}
	return false;
}

void Zbior_z_powtorzeniami::insert(std::string data) {
	Element* nowy = new Element(data);

	if (this->pierwszy == nullptr)
	{
		pierwszy = nowy;
		return;
	}
	else
	{
		Element* aktualny = pierwszy;
		while (aktualny->nast != nullptr)
		{
			aktualny = aktualny->nast;
		}
		aktualny->nast = nowy;
	}
}

void Zbior_z_powtorzeniami::remove(std::string data) {
	if (exists(data))
	{
		Element* aktualny = pierwszy;
		Element* poprz = nullptr;
		while (aktualny != nullptr)
		{
			if (aktualny->content == data)
			{
				Element* temp = aktualny;
				aktualny = aktualny->nast;

				if (temp == pierwszy)
				{
					pierwszy = aktualny;
				}
				else
				{
					poprz->nast = aktualny;
				}

			}
			else
			{
				poprz = aktualny;
				aktualny = aktualny->nast;
			}
		}
	}
	else
	{
		return;
	}
}

void Zbior_z_powtorzeniami::display(){
	Element* aktualny = this->pierwszy;
	while (aktualny != nullptr)
	{
		aktualny->display();
		aktualny = aktualny->nast;
	}
}




int main() {
	Zbior_z_powtorzeniami* zbiorek = new Zbior_z_powtorzeniami();
	zbiorek->insert("Jakub");
	zbiorek->insert("Sniezynka");
	zbiorek->insert("Jakub");
	zbiorek->insert("Drozd");
	zbiorek->insert("Jakub");
	zbiorek->insert("Kukuszka");
	zbiorek->display();
	printf("\n");
	zbiorek->remove("Jakub");
	zbiorek->remove("Kukuszka");
	std::cout << "Jakub: " << (zbiorek->exists("Jakub") ? "true" : "false") << std::endl;
	std::cout << "Kukuszka: " << (zbiorek->exists("Kukuszka") ? "true" : "false") << std::endl;
	std::cout << "Drozd: " << (zbiorek->exists("Drozd") ? "true" : "false") << std::endl;
	printf("\n");
	zbiorek->display();
	delete zbiorek;
	return 0;
}
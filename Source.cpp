#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const char DF[] = "Duomenys.txt";
const char RF[] = "Rezultatai.txt";
const int cmax = 20;

class vanduo 
{
private:
	string name;
	int id, salary;
public:
	void vistiena()
	{
		cout << "Iveskite:" << endl;
		cout << "Vardas: ";
		cin >> name;
		cout << "ID: ";
		cin >> id;
		cout << "Alga";
		cin >> salary;		
	}

	void kalakutiena()
	{
		cout << "Jusu:  \n" << " Vardas: "<< name <<" \n" << "ID: " << id << "\n" << "Altyginimas: " << salary << "\n";
	}
};

int main(){

	vanduo darbuotojas, vadovas;

	darbuotojas.vistiena();
	darbuotojas.kalakutiena();
	vadovas.vistiena();
	vadovas.kalakutiena();






	return 0;
}
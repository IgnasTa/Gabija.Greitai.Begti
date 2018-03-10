#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
//----------------------------------------------------
const int Cn = 100;
const char Fd[] = "Duom.txt";
//----------------------------------------------------
class Dviratis
{
private:
  int metai;     // pagaminimo metai
  double kaina;
public:
  void Deti(int metai, double kaina);
  int ImtiMetus() { return metai;  }
  double ImtiKaina() { return kaina; }
};
//----------------------------------------------------
void Dviratis::Deti(int metai, double kaina)
{
   this->metai = metai;
   this->kaina = kaina;
}
//----------------------------------------------------
void Skaityti( Dviratis D[], int & n, int & am);
void Pinigai( Dviratis D[], int n, int amPr, int amPb, int & kiek, double & suma);
double Vidurkis(Dviratis D[], int n, int amPr, int amPb);
//----------------------------------------------------
int main()
{
  Dviratis D[Cn];  // dviraciu duomenys
  int n;           // dviraciu skaicius
  int am;          // dviracio tinkamumo naudoti kritinis amzius
  Skaityti(D, n, am);
  int kiekTinka, kiekNetinka;
  double sumaTinka, sumaNetinka;
  Pinigai(D, n, 0, am, kiekTinka, sumaTinka);
  cout << "Tinkami naudoti: " << kiekTinka << " "
       <<  sumaTinka << endl;
  Pinigai(D, n, am + 1, 1000, kiekNetinka, sumaNetinka);
  cout << "Netinkami naudoti: " << kiekNetinka << " "
       <<  sumaNetinka << endl;
  cout << "Tinkamu naudoti dviraciu vidutinis amzius: " << Vidurkis(D, n, 0, am) << endl;
  cout << "Netinkamu naudoti dviraciu vidutinis amzius: " << Vidurkis(D, n, am + 1, 1000) << endl;
  return 0;
}
//---------------------------------------------------
void Skaityti(Dviratis D[], int & n, int & am)
{
    int metai; double kaina;
    ifstream F(Fd);
    F >> am >> n;
    for(int i = 0; i < n; i++){
      F >> metai >> kaina;
      D[i].Deti(metai, kaina);
    }
    F.close();
}
//---------------------------------------------------
void Pinigai( Dviratis D[], int n, int amPr, int amPb, int & kiek, double & suma)
{
    kiek = 0;
    suma = 0.0;
    int amzius;
    for(int i = 0; i < n; i++){
      amzius = 2012 - D[i].ImtiMetus();
      if((amPr <= amzius) && (amzius <= amPb))
      {
        kiek++;
        suma += D[i].ImtiKaina();
      }
    }
}
//---------------------------------------------------
double Vidurkis(Dviratis D[], int n, int amPr, int amPb)
{
  int kiek = 0, suma = 0;
  int amzius;
  for(int i = 0; i < n; i++){
     amzius = 2012 - D[i].ImtiMetus();
     if((amPr <= amzius) && (amzius <= amPb))
     {
        kiek++; suma += amzius;
     }
  }
  if(kiek > 0) return (double) suma / kiek;
  else return 0.0;
}
//---------------------------------------------------


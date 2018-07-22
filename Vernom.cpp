//Zbigniew Smaza szyfr Vernoma wersja finalna
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;

string szyfruj(string tekst, string klucz){
	string zaszyfrowane; 
	for(int i=0; i < tekst.size(); i++){ // iteracja po dlugosci tekstu jawnego
		zaszyfrowane += tekst[i] ^ klucz[i]; // xor danej litery tekstu jawnego i danej wartosci klucza
	}
	return zaszyfrowane;//zwraca szyfrogram
}

string odszyfruj(int kryptogram[], string klucz){
	string odszyfrowane;	
	for(int i=0; i < klucz.size(); i++){// iteracja po dlugosci klucza ktory musi byc tak samo dlugi jak kryptogram
		odszyfrowane += kryptogram[i] ^ klucz[i]; //xor danej litery tekstu jawnego i danej wartosci klucza
	}
	return odszyfrowane; //zwraca tekst jawny
}

int main(int argc, char** argv) {
string tekst, kryptogram, jawny;
	cout<< "Szyfr Vernona" <<endl;
	cout<< "\n***SZYFROWANIE***\n" << endl;
	cout<< "Podaj tekst jawny: \n\t";
	getline(cin, tekst);
	
	cout<< "Klucz: " ;
	char klucz[tekst.size()];//tworzenie tablicy typu char o dlugosci tekstu jawnego
	srand (time(NULL));//zerowanie zegara do losowania
		for(int i=0; i<tekst.size(); i++){
			klucz[i] = rand();//uzupelnianie klucza losowymi wartosciami
			cout<< int(klucz[i]) << " | "; // wypisanie klucza
		}
	
	kryptogram = szyfruj(tekst, klucz);	//szyfrowanie
		cout<< "\n\nZaszyfrowany tekst: \n\t";//
		for (int i = 0; i< kryptogram.size(); i++){ //iterowanie po dlugosci kryptogramu
			cout<< int(kryptogram[i]) << " | ";// wyswierlenie kryptogramu
		}
		cout<<endl;

	cout << "\n\n***ODSZYFROWANIE***\n" << endl;
	int dl_krypto;
	cout<< "Podaj dlugosc kryptogramu do odszyfrowania: "; // potrzebujemy dlugosci slowa by stworzyc tablice o odpowiedniej dlugosci
	cin>> dl_krypto;
	
	cout<< "Podaj klucz" <<endl;
	int zmienna, int_klucz[dl_krypto];
	for(int i=0; i<dl_krypto; i++){//iterowanie po dlugosci kryptogramu bo taka sama dlugosc musi miec tez klucz
		cout<< "podaj liczbe k[" << i <<"] = ";//uzytkownik moze wprowadz dane do klucza
		cin>> zmienna;
		cin.ignore();
		int_klucz[i] = zmienna; //przypisanie wartosci do tab_krypt
	}	
	
	char char_klucz[dl_krypto]; // tablica potrzebna do funkcji odszyfrujacej poniewa¿ potrzebujemy tablicy typu char poniewaz argumentem funkcji jest string
	for(int i =0; i<dl_krypto; i++){
		char_klucz[i] = char(int_klucz[i]);
	}

	int tab_krypto[dl_krypto]; //tablica wartosci typu int ktora bedzie naszym kryptogramem.
	cout<< "Podaj kryptogram: " <<endl;
	for(int i=0; i<dl_krypto; i++){//
		cout<< "podaj liczbe k[" << i <<"] = ";//uzytkownik uzupelnia kryptogram
		cin>> zmienna;
		cin.ignore();
		tab_krypto[i] = zmienna; //przypisanie wartosci do tab_krypto
	}
			
	jawny = odszyfruj(tab_krypto, char_klucz); // funkcja odszyfrujaca
	cout<< "\nOdszyfrowany kryptogram: \n\t" <<jawny <<endl;
	
return 0;
}

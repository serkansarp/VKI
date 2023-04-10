#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;

// Kilo fazlal���nda 3 ayr� a�amada kullan�lacak optimize ama�l� idealKiloyaDonus prototipi
void idealKiloyaDonus(int,float);

// Kapakta bolca kullan�lan yan yana bo�luk ve - karakterleri i�in optimizasyon yanYanaChar prototipi
void yanYanaChar(char, int);

int main() {
	setlocale(LC_ALL, "Turkish");

	int kilo = 0;
	// boy yaz�l�rken ./, karma�as�ndan kurtarmak istiyoruz ama k�s�ratl� gerekecek
	float boy = 0, vki = 0, zayif_idealKilo = 0, kilolu_idealKilo = 0;
	
	


	// Kapak
	cout << " " << char(11) << " ";
	yanYanaChar('-', 55);	//	yanYanaChar ilk kullan�l��, 55 adet yan yana - karakteri.
	cout << " " << char(12) << endl;
	cout << " | V�CUT K�TLE �NDEKS�";
	yanYanaChar(' ', 21);
	cout << " by Serkan SARP |" << endl;
	cout << " |";
	yanYanaChar('-', 57);
	cout << "|" << endl;
	
	// A��klama
	cout << " | V�cut/boy Kitle �ndeksi, bir ki�inin boy ve kilosu esas |" << endl;
	cout << " | al�narak v�cudundaki tahmini ya� oran�n�n g�sterildi�i  |" << endl;
	cout << " | tahmini bir hesaplama y�ntemidir. Sonuca g�re ki�inin   |" << endl;
	cout << " | kilosunun, ideal kilosuna yak�nl��� hesaplan�r.         |" << endl;
	cout << " |";
	yanYanaChar(' ', 57);
	cout << "|" << endl;
	
	// Sorumluluk ama�l� a��klama
	cout << " | Ancak y�ntemde, ki�inin v�cut tipi, ya��, sahip olunan  |" << endl;
	cout << " | hastal�klar, ya� ve kas dokusu, metabolizma h�z� gibi   |" << endl;
	cout << " | di�er etkenler hari� tutulur. Daha hassas �l��mler,     |" << endl;
	cout << " | kilonuz ve di�er sa�l�k problemleriniz i�in mutlaka bir |" << endl;
	cout << " | hekime kontrol�ne ihtiyac�n�z oldu�unu unutmay�n.       |" << endl;
	cout << " | Sa�l�kl� g�nler.                                        | " << endl;
	cout << " " << char(12) << " ";
	yanYanaChar('-', 55);
	cout << " " << char(11) << endl << endl;
	

	// Inputlar�n al�n���
	cout << " " << char(15) << " L�tfen boyunuzu cm cinsinden giriniz: ";
	
	cin >> boy;
	cout << " " << char(15) << " L�tfen kilonuzu kg cinsinden giriniz: ";
	cin >> kilo;

	//	V�cut kitle hesaplan���
	boy = boy / 100;
	vki = kilo / pow(boy, 2);
	
	//	'Tan�m ve �neri'de kullan�lmak �zere hesaplan�p kullan�c�ya g�sterilmeyen de�i�kenler
	zayif_idealKilo = pow(boy, 2) * 18.5;
	kilolu_idealKilo = pow(boy, 2) * 24.99;
	cout << " " << char(3) << "� V�cut Kitle �ndeksiniz: " << setprecision(2) << fixed << vki << " kg/metrekaredir." << endl << endl;


	//	VK�'ye g�re Tan�m ve �neri
	if (vki < 18.5) {
		cout << " " << char(5) << " �deal kilonuzun alt�ndas�n�z. �deal kilonuza d�nmek i�in en az ";
		if (int(zayif_idealKilo - kilo) == 0) {		// 0.01-0,99 aras� "0 kilo almal�s�n�z" yazd�rman�n
			cout << "1";							// �n�ne ge�mek i�in "1" yazd�r�yoruz ideal s�n�r�nda
		} else {									// olduklar� i�in.
			cout << int(zayif_idealKilo - kilo);	// Bu k�s�m tek oldu�undan fonksiyon yerine kod blo�unda
		}											// yaz�ld�.
		cout << " kilo almal�s�n�z.";
	}
	else if (vki >= 18.5 && vki <= 24.99) {
		cout << " " << char(1) << " �deal kilo s�n�rlar�n�z i�erisindesiniz, tebrikler.";
	}
	else if (vki > 24.99 && vki <= 29.99) {
		cout << " " << char(5) << " �deal kilonuzun �zerindesiniz.";
		idealKiloyaDonus(kilo, kilolu_idealKilo);	// S�n�r �zerinde olan 3 durum, fonksiyona y�nlendirildi.
	}
	else if (vki > 29.99 && vki <= 39.99) {
		cout << " " << char(5) << " �deal kilonuzun �ok �zerindesiniz (Obez).";
		idealKiloyaDonus(kilo, kilolu_idealKilo);
		}
	else if (vki > 39.99) {
		cout << " " << char(5) << " �deal kilonuzun fazlas�yla �zerindesiniz (Morbid obez).";
		idealKiloyaDonus(kilo, kilolu_idealKilo);
		cout << endl << " " << char(5) << " Bunun i�in uzmanlardan yard�m alman�z gerekebilir." << endl;
	}
	else { cout << "-S�STEM HATASI!-" << endl; }

	cout << endl << endl;

	system("pause");

	return 0;
}


// Kilo fazlal���nda 3 ayr� a�amada kullan�lacak optimize ama�l� idealKiloyaDonus tan�m�
// Yoksa yukar�da fazla kilolu, obez ve morbid obez b�l�mlerinde ayn� hesap ve stringler kullan�lacakt�.
void idealKiloyaDonus(int _kilo,float _kilolu_idealKilo) {
	int a = _kilo - _kilolu_idealKilo;
	cout << " �deal kilonuza d�nmek i�in en az ";
	if (a == 0) { a = 1; }		//	Fonksiyonda s�n�rdakiler i�in "0 kilo vermelisiniz" outputunun
	cout << a << " kilo vermelisiniz.";		// �n�ne ge�ildi.
}

// Kapakta bolca kullan�lan yan yana bo�luk ve - karakterleri i�in optimizasyon yanYanaChar tan�m�
void yanYanaChar(char x, int y) {
	for (int i = 0; i < y; i++) {	cout << x; }
}
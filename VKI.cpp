#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;

// Kilo fazlalýðýnda 3 ayrý aþamada kullanýlacak optimize amaçlý idealKiloyaDonus prototipi
void idealKiloyaDonus(int,float);

// Kapakta bolca kullanýlan yan yana boþluk ve - karakterleri için optimizasyon yanYanaChar prototipi
void yanYanaChar(char, int);

int main() {
	setlocale(LC_ALL, "Turkish");

	int kilo = 0;
	// boy yazýlýrken ./, karmaþasýndan kurtarmak istiyoruz ama küsüratlý gerekecek
	float boy = 0, vki = 0, zayif_idealKilo = 0, kilolu_idealKilo = 0;
	
	


	// Kapak
	cout << " " << char(11) << " ";
	yanYanaChar('-', 55);	//	yanYanaChar ilk kullanýlýþ, 55 adet yan yana - karakteri.
	cout << " " << char(12) << endl;
	cout << " | VÜCUT KÝTLE ÝNDEKSÝ";
	yanYanaChar(' ', 21);
	cout << " by Serkan SARP |" << endl;
	cout << " |";
	yanYanaChar('-', 57);
	cout << "|" << endl;
	
	// Açýklama
	cout << " | Vücut/boy Kitle Ýndeksi, bir kiþinin boy ve kilosu esas |" << endl;
	cout << " | alýnarak vücudundaki tahmini yað oranýnýn gösterildiði  |" << endl;
	cout << " | tahmini bir hesaplama yöntemidir. Sonuca göre kiþinin   |" << endl;
	cout << " | kilosunun, ideal kilosuna yakýnlýðý hesaplanýr.         |" << endl;
	cout << " |";
	yanYanaChar(' ', 57);
	cout << "|" << endl;
	
	// Sorumluluk amaçlý açýklama
	cout << " | Ancak yöntemde, kiþinin vücut tipi, yaþý, sahip olunan  |" << endl;
	cout << " | hastalýklar, yað ve kas dokusu, metabolizma hýzý gibi   |" << endl;
	cout << " | diðer etkenler hariç tutulur. Daha hassas ölçümler,     |" << endl;
	cout << " | kilonuz ve diðer saðlýk problemleriniz için mutlaka bir |" << endl;
	cout << " | hekime kontrolüne ihtiyacýnýz olduðunu unutmayýn.       |" << endl;
	cout << " | Saðlýklý günler.                                        | " << endl;
	cout << " " << char(12) << " ";
	yanYanaChar('-', 55);
	cout << " " << char(11) << endl << endl;
	

	// Inputlarýn alýnýþý
	cout << " " << char(15) << " Lütfen boyunuzu cm cinsinden giriniz: ";
	
	cin >> boy;
	cout << " " << char(15) << " Lütfen kilonuzu kg cinsinden giriniz: ";
	cin >> kilo;

	//	Vücut kitle hesaplanýþý
	boy = boy / 100;
	vki = kilo / pow(boy, 2);
	
	//	'Taným ve Öneri'de kullanýlmak üzere hesaplanýp kullanýcýya gösterilmeyen deðiþkenler
	zayif_idealKilo = pow(boy, 2) * 18.5;
	kilolu_idealKilo = pow(boy, 2) * 24.99;
	cout << " " << char(3) << "• Vücut Kitle Ýndeksiniz: " << setprecision(2) << fixed << vki << " kg/metrekaredir." << endl << endl;


	//	VKÝ'ye göre Taným ve Öneri
	if (vki < 18.5) {
		cout << " " << char(5) << " Ýdeal kilonuzun altýndasýnýz. Ýdeal kilonuza dönmek için en az ";
		if (int(zayif_idealKilo - kilo) == 0) {		// 0.01-0,99 arasý "0 kilo almalýsýnýz" yazdýrmanýn
			cout << "1";							// önüne geçmek için "1" yazdýrýyoruz ideal sýnýrýnda
		} else {									// olduklarý için.
			cout << int(zayif_idealKilo - kilo);	// Bu kýsým tek olduðundan fonksiyon yerine kod bloðunda
		}											// yazýldý.
		cout << " kilo almalýsýnýz.";
	}
	else if (vki >= 18.5 && vki <= 24.99) {
		cout << " " << char(1) << " Ýdeal kilo sýnýrlarýnýz içerisindesiniz, tebrikler.";
	}
	else if (vki > 24.99 && vki <= 29.99) {
		cout << " " << char(5) << " Ýdeal kilonuzun üzerindesiniz.";
		idealKiloyaDonus(kilo, kilolu_idealKilo);	// Sýnýr üzerinde olan 3 durum, fonksiyona yönlendirildi.
	}
	else if (vki > 29.99 && vki <= 39.99) {
		cout << " " << char(5) << " Ýdeal kilonuzun çok üzerindesiniz (Obez).";
		idealKiloyaDonus(kilo, kilolu_idealKilo);
		}
	else if (vki > 39.99) {
		cout << " " << char(5) << " Ýdeal kilonuzun fazlasýyla üzerindesiniz (Morbid obez).";
		idealKiloyaDonus(kilo, kilolu_idealKilo);
		cout << endl << " " << char(5) << " Bunun için uzmanlardan yardým almanýz gerekebilir." << endl;
	}
	else { cout << "-SÝSTEM HATASI!-" << endl; }

	cout << endl << endl;

	system("pause");

	return 0;
}


// Kilo fazlalýðýnda 3 ayrý aþamada kullanýlacak optimize amaçlý idealKiloyaDonus tanýmý
// Yoksa yukarýda fazla kilolu, obez ve morbid obez bölümlerinde ayný hesap ve stringler kullanýlacaktý.
void idealKiloyaDonus(int _kilo,float _kilolu_idealKilo) {
	int a = _kilo - _kilolu_idealKilo;
	cout << " Ýdeal kilonuza dönmek için en az ";
	if (a == 0) { a = 1; }		//	Fonksiyonda sýnýrdakiler için "0 kilo vermelisiniz" outputunun
	cout << a << " kilo vermelisiniz.";		// önüne geçildi.
}

// Kapakta bolca kullanýlan yan yana boþluk ve - karakterleri için optimizasyon yanYanaChar tanýmý
void yanYanaChar(char x, int y) {
	for (int i = 0; i < y; i++) {	cout << x; }
}
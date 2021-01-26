////****************************************************************************
//**					       SAKARYA �N�VERS�TES�
//**			        B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
//**						 B�LG�SAYAR M�HEND�SL��� B�L�M�
//**				          PROGRAMLAMAYA G�R��� DERS�
//**
//**				�DEV NUMARASI�...: 3
//**				��RENC� ADI......: Davud Samed Tombul
//**				��RENC� NUMARASI.: B171210007
//**				DERS GRUBU.......: 1D
//****************************************************************************/

#include<iostream>//Cout gibi temel komutlar� kullanmam�z� sa�layan k�t�phane.
#include<locale.h>//T�rk�e karakterleri kullanabilmemiz i�in gerekli k�t�phane.
#include<math.h>//Kare alma i�lemini yapabilmemiz i�in gerekli k�t�phane.
//Her seferinde std:: yazarak u�ra�mamak i�in kulland���m�z komut.
using namespace std;

//Global de�i�kenler


//Fonksiyon bildirisi
void yazdir();

//Giri� matrisimizin boyutu


//Yap� i�erisinde �ye olarak matrislerimizi, �ekirdek ve sonu� matrisinin boyutunu ve kayma miktar�n� tan�mlad�m.
struct �slem
{

	int giris[5][5] = { 2,3,4,5,4,
						4,3,2,1,3,
						5,6,7,8,5,
						2,3,7,5,4,
						2,4,6,2,1 };

	int sonuc[100][100], cekirdek[100][100];

	int cekirdekBoyut, kaymaMiktari, sonucBoyut;
	
	
}Yap�;//Yap� olu�turuluyor.



int main()
{
	int toplam = 0, sayac1 = 0, sayac2 = 0;

	setlocale(LC_ALL, "Turkish");
	

	//Giri� matrisimizi main yani ana fonksiyonda kullanabilmek i�in �a��r�yoruz.
	�slem girisM;

	int girisBoyut = sqrt(sizeof(girisM.giris) / 4);

	cout << "�ekirde�in boyutunu giriniz: " << endl;
	cin >> Yap�.cekirdekBoyut;

	cout << "�ekirde�in kayma miktar�n� giriniz: " << endl;
	cin >> Yap�.kaymaMiktari;

	Yap�.sonucBoyut = ((girisBoyut - Yap�.cekirdekBoyut) / Yap�.kaymaMiktari) + 1;

	//Kayma miktar� ve �ekirdek boyutunun toplam�n�n giri� boyutundan b�y�k oldu�u durumlarda i�lem yap�lamaz.
	if (Yap�.cekirdekBoyut+Yap�.kaymaMiktari>girisBoyut|| (girisBoyut-Yap�.cekirdekBoyut)%Yap�.kaymaMiktari !=0)
	{
		cout << "Bu i�lem yap�lamaz" << endl;
	}
	else
	{
		cout << "�ekirde�in elemanlar�n� giriniz: ";

		//�ekirde�in elemanlar�n� kullan�c�dan almam�z i�in gerekli iteratif i�lemler.
		for (int i = 0; i < Yap�.cekirdekBoyut; i++)
		{
			for (int j = 0; j < Yap�.cekirdekBoyut; j++)
			{
				cout << "cekirdek[" << i << "][" << j << "] = ";
				cin >> Yap�.cekirdek[i][j];
				cout << "\n";
			}
		}

		//Kullan�c�n�n girdi�i �ekirdek elemanlar� ve �ekirdek kayma miktar�n� kullanarak sonuc matrisinin elemanlar�n� �retmemizi sa�layan for d�ng�leri.
		for (int k = 0; k < Yap�.sonucBoyut; k++)
		{
			for (int t = 0; t < Yap�.sonucBoyut; t++)
			{
				for (int q = 0; q < Yap�.cekirdekBoyut; q++)
				{
					for (int w = 0; w < Yap�.cekirdekBoyut; w++)
					{
						toplam += girisM.giris[q + sayac2][w + sayac1] * Yap�.cekirdek[q][w];
					}
				}
				sayac1 += Yap�.kaymaMiktari;
				Yap�.sonuc[k][t] = toplam;
				toplam = 0;

				//�ekirdek giri� matrisinde bulundu�un sat�r�n en sonuna gitti�inde sayac1 s�f�rlan�r ve �ekirde�in alt sat�ra ge�mesi i�in sayac 2 kayma miktar� kadar artt�r�l�r.
				if (sayac1+ Yap�.cekirdekBoyut>girisBoyut)
				{
					sayac2 += Yap�.kaymaMiktari;
					sayac1 = 0;
				}
				//Giri� matrisi �zerinde dolanan �ekirde�imiz son sat�r ve s�t�na kadar geldikten sonra i�lemi bitirmek i�in goto komutunu kulland�m.
				if (sayac2+Yap�.cekirdekBoyut > girisBoyut)
				{
					goto Paris;
				}
			}
		}

		//Gerekli �arp�m i�lemleri sona erdi�inde goto komutu kullanarak derleyicinin i�leme buradan devam etmesini sa�lad�m.
	Paris:

		//Sonuc fonksiyonunun ekrana yazd�r�lmas�n� sa�layan fonksiyonumuzu �a��rma i�lemi.
		yazdir();
	}

	//Giri� verileri hatal� girildi�inde derleyici ara basamaklar� atlayarak goto komutu ile bu sat�ra gelir.

	system("pause");

	return 0;
}

//Sonu� matrisini yazd�rmaya yarayan fonksiyonun ana g�vdesi.
void yazdir()
{
	for (int i = 0; i < Yap�.sonucBoyut; i++)
	{
		for (int j = 0; j < Yap�.sonucBoyut; j++)
		{
			cout << "\t" << Yap�.sonuc[i][j];
		}

		cout << "\n";
	}
}

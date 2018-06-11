#include <iostream>
#include <fstream> // dosya i�lemleri i�in
#include <clocale> // t�rk�e karakter i�n
#include <time.h> // sleep() fonksiyonu i�in
#include <unistd.h> // T�rk�e karakter i�in

using namespace std;

int main(int argc, char** argv) {
	 
	string no, isim, soyisim, sinif, bolum, noAra;	// ogrenci.txt dosyas�n� okumak i�in de�i�kenler
	string sicil, OEAd, OESoyad, OEBolum;	// ogretimelemani.txt dosyas�n� okumak i�in de�i�kenler
	string dersAd, dersKredi, dersBolum;	// bolum.txt dosyas�n� okumak i�in de�i�kenler
	string numaraDersEkle, dersEkleAd ;	// dersEkle.txt dosyas�n� okumak i�in de�i�kenler
	string noNotGiris, dersAdiNotGiris, puanNotGiris ;	//notEkle.txt dosyas�n� okumak de�i�kenler
	int donus, m=0; 
	
	
	
	enbas:
		
	setlocale(LC_ALL, "Turkish");	// T�rk�e karakter i�in
	system("COLOR 3f");	// ekran renklendirme i�in
	
	int secim;
	
			cout<<"\t\t\t\t��RENC� OTOMASYONU\n\n";
	cout<<"\t\tXXXXXXXXXXXXXXXX ANA MEN� XXXXXXXXXXXXXXXXX\n\n";
	cout<<"\t\t��RENC� ��LEMLER�                      -> 1\n";
	cout<<"\t\t��RET�M ELEMANI ��LEMLER�              -> 2\n";
	cout<<"\t\tDERS ��LEMLER�                         -> 3\n";
	cout<<"\t\tNOT G�R�� ��LEMLER�                    -> 4\n";
	cout<<"\t\t�IKI�                                  -> 5\n";
	cout<<"\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	
	cout<<"\n\nSe�iminiz : ";
	cin>>secim;
	system("cls");
	
	switch(secim)
	{
		case 1:	// ��renci mod�l�
		{	
			ogrenci:
			
			cout<<"\t\t\t\t��RENC� ��LER�\n\n";
			cout<<"\t\tXXXXXXXXXXXXXXXX MENU XXXXXXXXXXXXXXXXXXXXX\n\n";
			cout<<"\t\t��RENC� KAYIT                          -> 1\n";
			cout<<"\t\t��RENC� ARAMA                          -> 2\n";
			cout<<"\t\t��RENC� L�STELEME                      -> 3\n";
			cout<<"\t\t��RENC� B�LG�LER�N� D�ZELTME           -> 4\n";
			cout<<"\t\tANA MEN�YE D�N                         -> 5\n";
			cout<<"\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
		
			cout<<"\n\nSe�iminiz : ";
			cin>>secim;
			system("cls");
			
			switch(secim)
			{
				case 1:	// ��renci kay�t i�lemi
					{
						cout<<"*****�GRENCI KAYIT*****"<<endl<<endl;
					ofstream kaydet;	// yaz�lacak dosyaya ait de�i�ken tan�mlan�yor
					kaydet.open("ogrenci.txt",ios::out | ios::in | ios::app);	// dosyaya yazma i�lemi i�in mod belirleniyor
					cout<<"Ogrenci Numarasi : ";		cin>>no;
					cout<<"Ogrenci Adi      : ";		cin>>isim;
					cout<<"Ogrenci Soyadi   : ";		cin>>soyisim;
					cout<<"Ogrenci Sinifi   : ";		cin>>sinif;
					cout<<"Ogrenci Bolumu   : ";		cin>>bolum;
					kaydet<<no<<" "<<isim<<" "<<soyisim<<" "<<sinif<<" "<<bolum<<endl;	//	kullan�c�dan al�nan veriler dosyaya yaz�l�yor
					kaydet.close(); //	dosya kapama
 					cout<<"Kay�t Ba�ar�l� ! "<<endl<<"�nceki men�ye d�nmek i�in l�tfen 1'e basiniz...";
					cin>>donus;
					if(donus==1){
						system("cls");	// ekran sonraki i�lem i�in temizleniyor
						goto ogrenci;	// kay�t i�lemi bitince �nceki men�ye y�nlendiriliyor
					}
					
						break;	
					}
				case 2: // ��renci arama i�lemi
					{
						arama:
							
						cout<<"\t\t\t\t��RENC� ARAMA\n\n";
						cout<<"\t\tXXXXXXXXXXXXXXXX MENU XXXXXXXXXXXXXXXXXXXXX\n\n";
						cout<<"\t\tNUMARAYA G�RE ARA                      -> 1\n";
						cout<<"\t\t�S�ME G�RE ARA                         -> 2\n";
						cout<<"\t\t�NCEK� MEN�YE D�N                      -> 3\n";
						cout<<"\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
						
							cout<<"\n\nSe�iminiz : ";
							cin>>secim;
							system("cls");
						
						switch(secim)
						{
							case 1:// ��renci numaras�na g�re arama
								{
									cout<<"*****��RENC� NO �LE ARAMA*****"<<endl<<endl;
									ifstream araNo;	// dosya okuma i�in de�i�ken belirleniyor
									araNo.open("ogrenci.txt",ios::in);	// dosya okuma modunda a��l�yor
									
									cout<<"��renci No Giriniz : ";
									cin>>noAra;
									m=0;
									do 
							        { 	
										if(araNo>>no>>isim>>soyisim>>sinif>>bolum)	// veriler dosyadan okunuyor, veri varsa if �al���yor
										{
											 if (noAra == no)	// girilen numara dosyada varsa if �al���yor
												{ 
												system("cls");
												cout<<endl<<"*****OGRENCI BILGILERI*****"<<endl;
												cout<<"Ogrenci No     : "<<no<<endl;
												cout<<"Ogrenci Adi    : "<<isim<<endl;
												cout<<"Ogrenci Soyadi : "<<soyisim<<endl;
												cout<<"Ogrenci Sinif  : "<<sinif<<endl;
												cout<<"Ogrenci Bolumu : "<<bolum<<endl; 
												m++; 
												} 
										}
							           
							        } while (!araNo.eof()); // dosyan�n sonuna kadar okuma yap�l�yor
							        araNo.close(); //dosya kapatma
							        if(m==0)	// m=0 ise hi� kay�t bulunamam��t�r
							        cout<<endl<<"Kay�t bulunamad�!"<<endl;
									cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto arama;	
									}
									
									break;	
								}
							case 2:	// ��renci ismine g�re arama
								{
									cout<<"*****�S�M �LE ARAMA*****"<<endl<<endl;
									ifstream araIsim; 
									araIsim.open("ogrenci.txt",ios::in);
									string isimAra;
									cout<<"��rencinin �smini Giriniz : ";
									cin>>isimAra;
									m=0;
									do 
							        { 	
										if(araIsim>>no>>isim>>soyisim>>sinif>>bolum)
										{
											 if (isimAra == isim) 
										{ 
										cout<<endl<<"*****OGRENCI BILGILERI*****"<<endl;
										cout<<"Ogrenci No     : "<<no<<endl;
										cout<<"Ogrenci Adi    : "<<isim<<endl;
										cout<<"Ogrenci Soyadi : "<<soyisim<<endl;
										cout<<"Ogrenci Sinif  : "<<sinif<<endl;
										cout<<"Ogrenci Bolumu : "<<bolum<<endl; 
										m++; 
										} 
										} 
							        } while (!araIsim.eof()); 
							        araIsim.close(); 
							        if(m==0)
							        cout<<endl<<"Kay�t bulunamad�!"<<endl;
									cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto arama;	
									}
									
									
									break;
								}
							case 3:	// �nceki men�
								{
									goto ogrenci;
								}
						}	
						break;
					}
				case 3:	// �renci listeleme i�lemi
					{
						listele:
							
						cout<<"\t\t\t\t��RENC� L�STELEME\n\n";
						cout<<"\t\tXXXXXXXXXXXXXXXX MENU XXXXXXXXXXXXXXXXXXXXX\n\n";
						cout<<"\t\tB�L�ME G�RE L�STELE                    -> 1\n";
						cout<<"\t\tSINIFA G�RE L�STELE                    -> 2\n";
						cout<<"\t\t�NCEK� MEN�YE D�N                      -> 3\n";
						cout<<"\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
						
						cout<<"\n\nSe�iminiz : ";
						cin>>secim;
						system("cls");
						
						switch(secim)
						{
							case 1:	// ��renci b�l�m�ne g�re
								{
									cout<<"*****B�L�ME G�RE ��RENC� L�STELEME*****"<<endl<<endl;
									ifstream listeleBolum;
									listeleBolum.open("ogrenci.txt",ios::in);
									string bolumListele;
									cout<<"B�l�m : ";
									cin>>bolumListele;
									cout<<endl;
									
									m=0;
									do 
							        { 	
							        	if(listeleBolum>>no>>isim>>soyisim>>sinif>>bolum)
							        	{
							        		 if (bolum == bolumListele) 
										{ 
										cout<<endl<<endl<<"*****OGRENCI BILGILERI*****"<<endl;
										cout<<"Ogrenci No     : "<<no<<endl;
										cout<<"Ogrenci Adi    : "<<isim<<endl;
										cout<<"Ogrenci Soyadi : "<<soyisim<<endl;
										cout<<"Ogrenci Sinif  : "<<sinif<<endl;
										cout<<"Ogrenci Bolumu : "<<bolum<<endl; 
										m++; 
										} 
										}
							        } while (!listeleBolum.eof()); 
							        listeleBolum.close();
							        if(m==0)
							        cout<<endl<<"B�l�m bulunamad�!"<<endl;
									cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto listele;	
									}
									
									break;
								}
							case 2:	// ��renci s�n�f�na g�re listeleme
								{
										cout<<"*****SINIFA G�RE ��RENC� L�STELEME*****"<<endl<<endl;
									ifstream listeleSinif;
									listeleSinif.open("ogrenci.txt",ios::in);
									string sinifListele;
									cout<<"S�n�f : ";
									cin>>sinifListele;
									cout<<endl;
									m=0;
									do 
							        { 	
							        	if(listeleSinif>>no>>isim>>soyisim>>sinif>>bolum)
							        	{
							        		if (sinif == sinifListele) 
										{ 
										cout<<endl<<endl<<"*****��RENC� B�LG�LER�*****"<<endl;
										cout<<"Ogrenci No     : "<<no<<endl;
										cout<<"Ogrenci Adi    : "<<isim<<endl;
										cout<<"Ogrenci Soyadi : "<<soyisim<<endl;
										cout<<"Ogrenci Sinif  : "<<sinif<<endl;
										cout<<"Ogrenci Bolumu : "<<bolum<<endl; 
										m++; 
										} 
										}
							        } while (!listeleSinif.eof()); 
							        listeleSinif.close(); 
							        if(m==0)
							        cout<<endl<<"S�n�f bulunamad�!"<<endl;
									cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto listele;	
									}
									break;
								}
							case 3:	// �nceki men�
								{
									goto ogrenci;
								}
							
						}
						break;
					}
					
				case 4:	// ��renci bilgilerini d�zeltme i�lemleri
					{
						// d�zeltme i�lemi i�in iki dosya gerekli: varolan ve ge�i�i
						ifstream okuEski;
						ofstream yazYeni;
						cout<<"��renci No : ";
						cin>>noAra;
						cout<<endl;
						okuEski.open("ogrenci.txt",ios::in);	// varolan dosya okunur
						yazYeni.open("geciciOgrenci.txt",ios::out | ios::in  | ios::app);	// ge�ici dosyaya yaz�l�r
								m=0;
								do 
							        { 	
							        	if(okuEski>>no>>isim>>soyisim>>sinif>>bolum)
							        	{
							        		if (no == noAra) 
												{ 
												cout<<endl<<endl<<"*****OGRENCI B�LG�S�N� D�ZENLE*****"<<endl;
												cout<<"Ogrenci No     : ";		cin>>no;
												cout<<"Ogrenci Adi    : ";		cin>>isim;
												cout<<"Ogrenci Soyadi : ";		cin>>soyisim;
												cout<<"Ogrenci Sinif  : ";		cin>>sinif;
												cout<<"Ogrenci Bolumu : ";		cin>>bolum; 
												// varolan dosyada bulunan bilgiler d�zenlenince ge�ici dosyaya yaz�l�r.
												yazYeni<<no<<" "<<" "<<" "<<isim<<" "<<soyisim<<" "<<sinif<<" "<<bolum<<endl ;
												m++; 
												} 
											else
												{
														yazYeni<<no<<" "<<" "<<" "<<isim<<" "<<soyisim<<" "<<sinif<<" "<<bolum<<endl ;	
												}
										}
							        } while (!okuEski.eof()); 
							          
							          okuEski.close(); 
							          yazYeni.close();
							          remove("ogrenci.txt");	// varolan dosya kald�r�l�r.
							          rename("geciciOgrenci.txt" , "ogrenci.txt");		// ge�ici dosyan�n ad� eski dosyayla de�i�tirilir
							          if(m==0)
							        	cout<<endl<<"D�zenlenecek kay�t bulunamad�!"<<endl;
							        else
							        	cout<<"Kay�t d�zenlendi."<<endl;
							        	cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto ogrenci;	
					}
						
						break;
					}
					
				case 5:// �nceki men�
				{
					goto enbas;
				}
			}
			break;
		}//case1
		
		case 2:	// ��retim eleman� mod�l�
			{
				ogretimElemani:
					
				cout<<"\t\t\t\t��RET�M ELEMANI ��LEMLER�\n\n";
			cout<<"\t\tXXXXXXXXXXXXXXXX MENU XXXXXXXXXXXXXXXXXXXXX\n\n";
			cout<<"\t\t��RET�M ELEMANI KAYIT                  -> 1\n";
			cout<<"\t\t��RET�M ELEMANI ARAMA                  -> 2\n";
			cout<<"\t\t��RET�M ELEMANI B�LG�LER� D�ZELT       -> 3\n";
			cout<<"\t\t��RET�M ELEMANI L�STELEME              -> 4\n";
			cout<<"\t\tANA MEN�YE D�N                         -> 5\n";
			cout<<"\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
		
			cout<<"\n\nSe�iminiz : ";
			cin>>secim;
			system("cls");
				
				switch(secim)
				{
					case 1:	// ��retim eleman� kay�t
						{
							cout<<"*****��RET�M ELEMANI KAYIT*****"<<endl<<endl;
							ofstream kaydetOE;
							kaydetOE.open("ogretimElemani.txt",ios::out | ios::in | ios::app);
							cout<<"Sicil No   : ";		cin>>sicil;
							cout<<"Ad	      : ";		cin>>OEAd;
							cout<<"Soyad	  : ";		cin>>OESoyad;
							cout<<"B�l�m	  : ";		cin>>OEBolum;
							kaydetOE<<sicil<<" "<<OEAd<<" "<<OESoyad<<" "<<OEBolum<<endl;
							kaydetOE.close(); 
		 					cout<<"Kay�t Ba�ar�l� ! "<<endl<<"�nceki men�ye d�nmek i�in l�tfen 1'e basiniz...";
							cin>>donus;
							
							if(donus==1){
								system("cls");
								goto ogretimElemani;	
					}	
							break;
						}
					case 2:	// sicil no ile arama
						{
							cout<<"*****S�C�L NO �LE ARAMA*****"<<endl<<endl;
									ifstream araSicil;
									araSicil.open("ogretimElemani.txt",ios::in);
									string sicilAra;
									cout<<"Sicil No Giriniz : ";
									cin>>sicilAra;
									m=0;
									do 
							        { 	
										if(araSicil>>sicil>>OEAd>>OESoyad>>OEBolum)
										{
											 if (sicil == sicilAra) 
												{ 
												system("cls");
												cout<<endl<<"*****OGRENCI BILGILERI*****"<<endl;
												cout<<"Sicil No  : "<<sicil<<endl;
												cout<<"Ad�       : "<<OEAd<<endl;
												cout<<"Soyad�    : "<<OESoyad<<endl;
												cout<<"B�l�m     : "<<OEBolum<<endl;
												m++; 
												} 
										}
							           
							        } while (!araSicil.eof()); 
							        araSicil.close(); 
							        if(m==0)
							        cout<<endl<<"Kay�t bulunamad�!"<<endl;
									cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto ogretimElemani;	
						}	
							break;
						}
					case 3:	// ��retim eleman� bilgilerini d�zeltme
					{
							ifstream okuOE;
							ofstream yazOE;
							string sicilNo;
							cout<<"Sicil No : ";
							cin>>sicilNo;
							cout<<endl;
							okuOE.open("ogretimElemani.txt",ios::in);
							yazOE.open("geciciOE.txt",ios::out | ios::in  | ios::app);
								m=0;
								do 
							        { 	
							        	if(okuOE>>sicil>>OEAd>>OESoyad>>OEBolum)
							        	{
							        		if (sicil == sicilNo ) 
												{ 
												cout<<endl<<endl<<"*****OGRENT�M ELEMANI B�LG�LER�N� D�ZENLEME*****"<<endl;
												cout<<"Sicil No  : ";		cin>>sicil;
												cout<<"Ad    	 : ";		cin>>OEAd;
												cout<<"Soyad     : ";		cin>>OESoyad;
												cout<<"B�l�m     : ";		cin>>OEBolum;
												
												yazOE<<sicil<<" "<<OEAd<<" "<<OESoyad<<" "<<OEBolum<<endl ;
												m++; 
												} 
											else
												{
													yazOE<<sicil<<" "<<OEAd<<" "<<OESoyad<<" "<<OEBolum<<endl ;	
												}
										}
							        } while (!okuOE.eof()); 
							          
							          okuOE.close();
							          yazOE.close();
							          remove("ogretimElemani.txt");
							          rename("geciciOE.txt" , "ogretimElemani.txt");
							          if(m==0)
							        	cout<<endl<<"D�zenlenecek kay�t bulunamad�!"<<endl;
							          else
							          	cout<<"Kay�t D�zenlendi."<<endl;
							        	cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto ogretimElemani;
									}
							break;
						}
					case 4:	// b�l�me g�re ��retim eleman� listeleme
						{
								cout<<"*****B�L�ME G�RE ��RET�M ELEMANI L�STELEME*****"<<endl<<endl;
									ifstream listeleOE;
									listeleOE.open("ogretimElemani.txt",ios::in);
									string bolumBul;
									cout<<"B�l�m : ";
									cin>>bolumBul;
									m=0;
									do 
							        { 	
							        	if(listeleOE>>sicil>>OEAd>>OESoyad>>OEBolum)
							        	{
							        		 if (OEBolum == bolumBul) 
										{ 
										cout<<endl<<endl<<"*****��RET�M ELEMANI B�LG�LER� L�STELEME*****"<<endl;
										cout<<"Sicil No  : "<<sicil<<endl;		
										cout<<"Ad    	 : "<<OEAd<<endl;	
										cout<<"Soyad     : "<<OESoyad<<endl;	
										cout<<"B�l�m     : "<<OEBolum<<endl;		
										m++; 
										} 
										}
							        } while (!listeleOE.eof()); 
							        listeleOE.close(); 
							        if(m==0)
							        cout<<endl<<"B�l�m bulunamad�!"<<endl;
									cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto ogretimElemani;	
									}
							break;
						}
					case 5:// �nceki men�
						{
							goto enbas;
						}	
				}
				break;
			}//case2
		
		case 3:	// ders mod�l�
			{
				ders:
					cout<<"\t\t\t\tDERS ��LEMLER�\n\n";
				cout<<"\t\tXXXXXXXXXXXXXXXX MENU XXXXXXXXXXXXXXXXXXXXX\n\n";
				cout<<"\t\tDERS EKLEME                            -> 1\n";
				cout<<"\t\tDERS B�LG�LER�N� G�NCELLEME            -> 2\n";
				cout<<"\t\tDERS L�STELEME                         -> 3\n";
				cout<<"\t\tDERS ARAMA                             -> 4\n";
				cout<<"\t\tANA MEN�YE D�N                         -> 5\n";
				cout<<"\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	
				cout<<"\n\nSe�iminiz : ";
				cin>>secim;
				system("cls");
				
				switch(secim)
				{
					case 1:	// ders ekleme
						{
							cout<<"*****DERS KAYIT*****"<<endl<<endl;
					ofstream dersEkle;
					dersEkle.open("ders.txt",ios::out | ios::in | ios::app);
					cout<<"Ders Ad�       : ";	   	cin>>dersAd;
					cout<<"Ders Kredisi   : ";		cin>>dersKredi;
					cout<<"Dersin B�l�m�  : ";		cin>>dersBolum;
				
					dersEkle<<dersAd<<" "<<dersKredi<<" "<<dersBolum<<endl;
					dersEkle.close(); 
 					cout<<"Kay�t Ba�ar�l� ! "<<endl<<"�nceki men�ye d�nmek i�in l�tfen 1'e basiniz...";
					cin>>donus;
					
					if(donus==1){
							system("cls");
							goto ders;
						}
							break;		
						}
					case 2:	// der bilgilerini g�ncelleme
						{
							ifstream okuEskiDers;//dosya okuma ve dosyay� acma 
							ofstream yazYeniDers;
							cout<<"Ders �smi : ";
							string dersIsim;
							cin>>dersIsim;
							cout<<endl;
							okuEskiDers.open("ders.txt",ios::in);
							yazYeniDers.open("geciciDers.txt",ios::out | ios::in  | ios::app);
								m=0;
								do 
							        { 	
							        	if(okuEskiDers>>dersAd>>dersKredi>>dersBolum)
							        	{
							        		if (dersIsim == dersAd) 
												{ 
												cout<<endl<<endl<<"*****DERS B�LG�S�N� D�ZENLE*****"<<endl;
												cout<<"Ders Ad�        : ";		cin>>dersAd;
												cout<<"Ders Kredisi    : ";		cin>>dersKredi;
												cout<<"Dersin B�l�m�   : ";		cin>>dersBolum;
											
												yazYeniDers<<dersAd<<" "<<dersKredi<<" "<<dersBolum<<endl ;
												m++; 
												} 
											else
												{
														yazYeniDers<<dersAd<<" "<<dersKredi<<" "<<dersBolum<<endl ;	
												}
										}
							        } while (!okuEskiDers.eof()); 
							          
							          okuEskiDers.close(); 
							          yazYeniDers.close();
							          remove("ders.txt");
							          rename("geciciDers.txt" , "ders.txt");
							          if(m==0)
							        	cout<<endl<<"D�zenlenecek kay�t bulunamad�!"<<endl;
							          else
							          	cout<<"Kay�t d�zenlendi"<<endl;
							        	cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto ders;	
					}
							break;
						}
					case 3:	// ders listeleme
						{
								cout<<"*****DERS L�STELEME*****"<<endl<<endl;
									ifstream listeleDers;
									listeleDers.open("ders.txt",ios::in);
								m=0;
									do 
							        { 	
							        	if(listeleDers>>dersAd>>dersKredi>>dersBolum)
							        	{
											cout<<endl<<"*****DERS*****"<<endl;
											cout<<"Ders Ad�       : "<<dersAd<<endl;
											cout<<"Ders Kredisi   : "<<dersKredi<<endl;
											cout<<"Dersin B�l�m�  : "<<dersBolum<<endl;
											m++; 
										}
							           
							        } while (!listeleDers.eof()); 
							        listeleDers.close(); 
							        if(m==0)
							        cout<<endl<<"Ders bulunamad�!"<<endl;
									cout<<endl<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto ders;	
									}
							break;
						}
					case 4:	// ders arama
						{	
								cout<<"*****DERS ADI �LE ARAMA*****"<<endl<<endl;
									ifstream araDers;
									araDers.open("ders.txt",ios::in);
									string dersAra;
									cout<<"Ders Ad�n� Giriniz : ";
									cin>>dersAra;
									m=0;
									do 
							        { 	
										if(araDers>>dersAd>>dersKredi>>dersBolum)
										{
											 if (dersAra == dersAd) 
										{ 
											cout<<endl<<"*****DERS B�LG�LER�*****"<<endl;
											cout<<"Ders Ad�       : "<<dersAd<<endl;
											cout<<"Ders Kredisi   : "<<dersKredi<<endl;
											cout<<"Dersin B�l�m�  : "<<dersBolum<<endl;
											m++; 
										} 
										} 
							           
							        } while (!araDers.eof());
							        araDers.close();
							        if(m==0)
							        cout<<endl<<"Ders bulunamad�!";
									cout<<endl<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto ders;	
									}
							
							break;
						}
					case 5:// �nceki men�
						{
							goto enbas;
						}
					
				}
				break;
			}//case 3
		
		case 4:	// not giri� mod�l�
			{
				notgiris:
					cout<<"\t\t\t\tNOT G�R���\n\n";
				cout<<"\t\tXXXXXXXXXXXXXXXX MENU XXXXXXXXXXXXXXXXXXXXX\n\n";
				cout<<"\t\t��RENC�YE DERS EKLEME                  -> 1\n";
				cout<<"\t\t��RENC� NOT G�R���                     -> 2\n";
				cout<<"\t\t��RENC� DERS L�STELEME                 -> 3\n";
				cout<<"\t\tKARNE OLU�TURMA VE G�RSELLE�T�RME      -> 4\n";
				cout<<"\t\tANA MEN�YE D�N                         -> 5\n";
				cout<<"\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	
				cout<<"\n\nSe�iminiz : ";
				cin>>secim;
				system("cls");
				
				switch(secim)
				{
					case 1:	// ��renciye ders ekleme
						{
							cout<<"*****��RENC�YE DERS EKLEME*****"<<endl<<endl;
									ifstream okuOgrenci;
									okuOgrenci.open("ogrenci.txt",ios::in);
									ifstream okuDers;
									okuDers.open("ders.txt",ios::in);
									ofstream yazDersEkle;
									yazDersEkle.open("dersEkle.txt",ios::in | ios::app);
									
									string numara, derss;
									int n=0;
									cout<<"��renci Numaras�n� Giriniz : ";
									cin>>numara;
									cout<<"Ders Ad�n� Giriniz : ";
									cin>>derss;
									m=0;
									do 
							        { 	
										if(okuOgrenci>>no>>isim>>soyisim>>sinif>>bolum)	
										{
											 if (numara == no)	// girilen numara ogrenci.txt dosyas�nda varsa
											{ 
													do 
											        { 	
														if(okuDers>>dersAd>>dersKredi>>dersBolum )
														{
															 if ( derss == dersAd) // girilen ders ders.txt dosyas�nda varsa
															{ 
																	yazDersEkle<<numara<<" "<<derss<<endl;	// dersEkle.txt dosyas�na yaz�l�r
																	 n++;	
															}
														} 
												    } while (!okuDers.eof());
												m++;
											} 
										}	
							        } while (!okuOgrenci.eof()); 
							        
							        okuDers.close(); 
							        okuOgrenci.close();
							        yazDersEkle.close();
							        if(m==0)	// ��renci no sistemde kay�tl� de�ilse ekleme yap�lamaz.
							       		cout<<endl<<"Kay�tl� ��renci bulunamad�!";
							        else if(n==0)	// sistemdeki dersler haricinde ders girildi�inde ekleme yap�lamaz.
							        	cout<<endl<<"Yanl��(sistemde olmayan) ders ad� girdiniz!";
							        else
							        	cout<<endl<<"��renciye ders eklendi";
									cout<<endl<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto notgiris;	
									}
							break;		
						}
					case 2:	//��rencinin ald��� ders i�in not giri�i
						{
							cout<<"*****��RENC�YE NOT EKLEME*****"<<endl<<endl;
									ifstream okuOgrenci2; 
									okuOgrenci2.open("ogrenci.txt",ios::in);
									
									ifstream okuDersEkle;
									okuDersEkle.open("dersEkle.txt",ios::in);
									
									ofstream yazNotEkle;
									yazNotEkle.open("notEkle.txt",ios::in | ios::app);
									
									string numara2, derss2;
									int n=0, puan;
									cout<<"��renci Numaras�n� Giriniz : ";
									cin>>numara2;
									cout<<"Ders Ad�n� Giriniz : ";
									cin>>derss2;
									cout<<"��rencini Notunu Giriniz : ";
									cin>>puan;
									m=0;
									do 
							        { 	
										if(okuOgrenci2>>no>>isim>>soyisim>>sinif>>bolum)
										{
											 if (numara2 == no)	// girilen numara ogrenci.txt dosyas�nda varsa
											{ 
													do 
											        { 	
														if(okuDersEkle>>numaraDersEkle>>dersEkleAd )
														{
															 if ( derss2 == dersEkleAd && numara2 == numaraDersEkle )	// ��renci e�er belirtilen dersi alm��sa ancak not eklenebilir
															{ 
																	yazNotEkle<<numara2<<" "<<derss2<<" "<<puan<<endl;	// ��rencinin notu notEkle.txt ye yaz�l�r.
																	 n++;	
																	 break;
															}
														} 
												    } while (!okuDersEkle.eof());
												m++;
												
											} 
										}	
							        } while (!okuOgrenci2.eof()); 
							        
							        okuDersEkle.close(); 
							        okuOgrenci2.close();
							        yazNotEkle.close();
							        if(m==0)	// girilen numara sistemde kay�tl� de�ilse not eklenemez.
							       		cout<<endl<<"Kay�tl� ��renci bulunamad�!";
							        else if(n==0)	// girilen ders sistemde kay�tl� de�ilse not eklenemez.
							        	cout<<endl<<"Yanl��(sistemde olmayan) ders ad� girdiniz!";
							        else
							        	cout<<endl<<"��renciye not eklendi";
									cout<<endl<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto notgiris;	
									}
							
							
							break;
						}
					case 3:	// ��renci ders listeleme
						{
							cout<<"*****��RENC� DERS L�STELEME*****"<<endl<<endl;
									ifstream ogrenciDersListele;
									ogrenciDersListele.open("dersEkle.txt",ios::in);
									string no3;
									cout<<"��renci No : ";
									cin>>no3;
									m=0;
									do 
							        { 	
							        	if(ogrenciDersListele>>numaraDersEkle>>dersEkleAd)
							        	{
							        		if(no3 == numaraDersEkle) {
							        			if(m==0){
							        							cout<<endl<<"*****ALDI�I DERSLER*****"<<endl;
														}
							        		
												cout<<"Ders Ad�   : "<<dersEkleAd<<endl;
												m++; 
																	  }
										
										}
							           
							        } while (!ogrenciDersListele.eof()); 
							        ogrenciDersListele.close(); 
							        if(m==0)
							        cout<<endl<<"��renci bulunamad�!"<<endl;
									cout<<endl<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto notgiris;	
									}
							
							
							break;
						}
					case 4: // ��renci karnesi(traskript) olu�turma ve g�rselle�irme
						{
							        cout<<"*****��RENC� TRANSKR�PT OLU�TURMA*****"<<endl<<endl;
									ifstream notEkleTrans; 
									notEkleTrans.open("notEkle.txt",ios::in);
									ifstream ogrenciTrans;
									ogrenciTrans.open("ogrenci.txt",ios::in);
									 
									int n =0;
									string no4;
									cout<<"��renci No:";
									cin>>no4;
									system("cls");
									m=0;
									// ilgili dosyalardan veriler okunur ve ekrana g�rselli�i iyile�tirilerek yazd�r�l�r.
										do 
							        { 	
										if(ogrenciTrans>>no>>isim>>soyisim>>sinif>>bolum)
										{
											 if (no == no4) // girilen no sistemde kay�tl�ysa transkript haz�rlan�r.
											{ 
												cout<<"\t\t\t\t---TRANSKR�PT---"<<endl<<endl;
																cout<<"\t\t/////////////////��RENC� B�LG�LER�/////////////////"<<endl;
																cout<<"\t\t//\t\tNUMARA   : "<<no<<"\t\t //"<<endl;
																cout<<"\t\t//\t\tAD       : "<<isim<<"\t\t //"<<endl;
																cout<<"\t\t//\t\tSOYAD    : "<<soyisim<<"\t\t //"<<endl;
																cout<<"\t\t//\t\tSINIF    : "<<sinif<<"\t\t         //"<<endl;
																cout<<"\t\t//\t\tB�L�M    : "<<bolum<<"\t\t //"<<endl;
																cout<<"\t\t///////////////////////////////////////////////////"<<endl<<endl;
																cout<<"\t\t//////////////////NOT B�LG�LER�////////////////////"<<endl;
																cout<<"\t\t//\tDERS "<<"\t\t\t NOT\t\t //"<<endl;
																cout<<"\t\t//\t---- "<<"\t\t\t ---\t\t //"<<endl;
													do 
											        { 	
														if(notEkleTrans>>noNotGiris>>dersAdiNotGiris>>puanNotGiris)
														{
															 if ( noNotGiris == no4) 
															{ 
																cout<<"\t\t//\t"<<dersAdiNotGiris<<"\t\t\t "<<puanNotGiris<<"\t\t //"<<endl;		
															    n++;		
															}
														} 
												    }while (!notEkleTrans.eof());
												m++;	
											} 
										}
											
							        } while (!ogrenciTrans.eof()); 
							        cout<<"\t\t///////////////////////////////////////////////////"<<endl<<endl;
							        
							        ogrenciTrans.close(); 
							        notEkleTrans.close();
							        
							        if(m==0 || n==0)
							       		cout<<endl<<"Kay�tl� ��renci bulunamad�!";
							        else
							        	cout<<endl<<"Transkript ba�ar�yla olu�turuldu.";
									cout<<endl<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto notgiris;	
									}
							break;
						}
					case 5:// �nceki men�
						{
							goto enbas;
						}
				}
				break;
			}//case 4
		
		case 5:	// ��k��
			{
				return 0;
			
			}// case 5
		default:
			{	// farkl� bir rakam girlirse uyar� verilir
				cout<<"Lutfen 1 le 5 arasinda bir rakam giriniz!"<<endl;
				sleep(3); // 3 saniye beklenir
				system("cls"); // ekran temizlenir
				goto enbas; // ve program�n en ba��na y�nlendirlir
			}
	}
	return 0;
}

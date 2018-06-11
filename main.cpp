#include <iostream>
#include <fstream> // dosya iþlemleri için
#include <clocale> // türkçe karakter içn
#include <time.h> // sleep() fonksiyonu için
#include <unistd.h> // Türkçe karakter için

using namespace std;

int main(int argc, char** argv) {
	 
	string no, isim, soyisim, sinif, bolum, noAra;	// ogrenci.txt dosyasýný okumak için deðiþkenler
	string sicil, OEAd, OESoyad, OEBolum;	// ogretimelemani.txt dosyasýný okumak için deðiþkenler
	string dersAd, dersKredi, dersBolum;	// bolum.txt dosyasýný okumak için deðiþkenler
	string numaraDersEkle, dersEkleAd ;	// dersEkle.txt dosyasýný okumak için deðiþkenler
	string noNotGiris, dersAdiNotGiris, puanNotGiris ;	//notEkle.txt dosyasýný okumak deðiþkenler
	int donus, m=0; 
	
	
	
	enbas:
		
	setlocale(LC_ALL, "Turkish");	// Türkçe karakter için
	system("COLOR 3f");	// ekran renklendirme için
	
	int secim;
	
			cout<<"\t\t\t\tÖÐRENCÝ OTOMASYONU\n\n";
	cout<<"\t\tXXXXXXXXXXXXXXXX ANA MENÜ XXXXXXXXXXXXXXXXX\n\n";
	cout<<"\t\tÖÐRENCÝ ÝÞLEMLERÝ                      -> 1\n";
	cout<<"\t\tÖÐRETÝM ELEMANI ÝÞLEMLERÝ              -> 2\n";
	cout<<"\t\tDERS ÝÞLEMLERÝ                         -> 3\n";
	cout<<"\t\tNOT GÝRÝÞ ÝÞLEMLERÝ                    -> 4\n";
	cout<<"\t\tÇIKIÞ                                  -> 5\n";
	cout<<"\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	
	cout<<"\n\nSeçiminiz : ";
	cin>>secim;
	system("cls");
	
	switch(secim)
	{
		case 1:	// öðrenci modülü
		{	
			ogrenci:
			
			cout<<"\t\t\t\tÖÐRENCÝ ÝÞLERÝ\n\n";
			cout<<"\t\tXXXXXXXXXXXXXXXX MENU XXXXXXXXXXXXXXXXXXXXX\n\n";
			cout<<"\t\tÖÐRENCÝ KAYIT                          -> 1\n";
			cout<<"\t\tÖÐRENCÝ ARAMA                          -> 2\n";
			cout<<"\t\tÖÐRENCÝ LÝSTELEME                      -> 3\n";
			cout<<"\t\tÖÐRENCÝ BÝLGÝLERÝNÝ DÜZELTME           -> 4\n";
			cout<<"\t\tANA MENÜYE DÖN                         -> 5\n";
			cout<<"\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
		
			cout<<"\n\nSeçiminiz : ";
			cin>>secim;
			system("cls");
			
			switch(secim)
			{
				case 1:	// öðrenci kayýt iþlemi
					{
						cout<<"*****ÖGRENCI KAYIT*****"<<endl<<endl;
					ofstream kaydet;	// yazýlacak dosyaya ait deðiþken tanýmlanýyor
					kaydet.open("ogrenci.txt",ios::out | ios::in | ios::app);	// dosyaya yazma iþlemi için mod belirleniyor
					cout<<"Ogrenci Numarasi : ";		cin>>no;
					cout<<"Ogrenci Adi      : ";		cin>>isim;
					cout<<"Ogrenci Soyadi   : ";		cin>>soyisim;
					cout<<"Ogrenci Sinifi   : ";		cin>>sinif;
					cout<<"Ogrenci Bolumu   : ";		cin>>bolum;
					kaydet<<no<<" "<<isim<<" "<<soyisim<<" "<<sinif<<" "<<bolum<<endl;	//	kullanýcýdan alýnan veriler dosyaya yazýlýyor
					kaydet.close(); //	dosya kapama
 					cout<<"Kayýt Baþarýlý ! "<<endl<<"Önceki menüye dönmek için lütfen 1'e basiniz...";
					cin>>donus;
					if(donus==1){
						system("cls");	// ekran sonraki iþlem için temizleniyor
						goto ogrenci;	// kayýt iþlemi bitince önceki menüye yönlendiriliyor
					}
					
						break;	
					}
				case 2: // öðrenci arama iþlemi
					{
						arama:
							
						cout<<"\t\t\t\tÖÐRENCÝ ARAMA\n\n";
						cout<<"\t\tXXXXXXXXXXXXXXXX MENU XXXXXXXXXXXXXXXXXXXXX\n\n";
						cout<<"\t\tNUMARAYA GÖRE ARA                      -> 1\n";
						cout<<"\t\tÝSÝME GÖRE ARA                         -> 2\n";
						cout<<"\t\tÖNCEKÝ MENÜYE DÖN                      -> 3\n";
						cout<<"\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
						
							cout<<"\n\nSeçiminiz : ";
							cin>>secim;
							system("cls");
						
						switch(secim)
						{
							case 1:// öðrenci numarasýna göre arama
								{
									cout<<"*****ÖÐRENCÝ NO ÝLE ARAMA*****"<<endl<<endl;
									ifstream araNo;	// dosya okuma için deðiþken belirleniyor
									araNo.open("ogrenci.txt",ios::in);	// dosya okuma modunda açýlýyor
									
									cout<<"Öðrenci No Giriniz : ";
									cin>>noAra;
									m=0;
									do 
							        { 	
										if(araNo>>no>>isim>>soyisim>>sinif>>bolum)	// veriler dosyadan okunuyor, veri varsa if çalýþýyor
										{
											 if (noAra == no)	// girilen numara dosyada varsa if çalýþýyor
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
							           
							        } while (!araNo.eof()); // dosyanýn sonuna kadar okuma yapýlýyor
							        araNo.close(); //dosya kapatma
							        if(m==0)	// m=0 ise hiç kayýt bulunamamýþtýr
							        cout<<endl<<"Kayýt bulunamadý!"<<endl;
									cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto arama;	
									}
									
									break;	
								}
							case 2:	// öðrenci ismine göre arama
								{
									cout<<"*****ÝSÝM ÝLE ARAMA*****"<<endl<<endl;
									ifstream araIsim; 
									araIsim.open("ogrenci.txt",ios::in);
									string isimAra;
									cout<<"Öðrencinin Ýsmini Giriniz : ";
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
							        cout<<endl<<"Kayýt bulunamadý!"<<endl;
									cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto arama;	
									}
									
									
									break;
								}
							case 3:	// önceki menü
								{
									goto ogrenci;
								}
						}	
						break;
					}
				case 3:	// örenci listeleme iþlemi
					{
						listele:
							
						cout<<"\t\t\t\tÖÐRENCÝ LÝSTELEME\n\n";
						cout<<"\t\tXXXXXXXXXXXXXXXX MENU XXXXXXXXXXXXXXXXXXXXX\n\n";
						cout<<"\t\tBÖLÜME GÖRE LÝSTELE                    -> 1\n";
						cout<<"\t\tSINIFA GÖRE LÝSTELE                    -> 2\n";
						cout<<"\t\tÖNCEKÝ MENÜYE DÖN                      -> 3\n";
						cout<<"\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
						
						cout<<"\n\nSeçiminiz : ";
						cin>>secim;
						system("cls");
						
						switch(secim)
						{
							case 1:	// öðrenci bölümüne göre
								{
									cout<<"*****BÖLÜME GÖRE ÖÐRENCÝ LÝSTELEME*****"<<endl<<endl;
									ifstream listeleBolum;
									listeleBolum.open("ogrenci.txt",ios::in);
									string bolumListele;
									cout<<"Bölüm : ";
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
							        cout<<endl<<"Bölüm bulunamadý!"<<endl;
									cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto listele;	
									}
									
									break;
								}
							case 2:	// öðrenci sýnýfýna göre listeleme
								{
										cout<<"*****SINIFA GÖRE ÖÐRENCÝ LÝSTELEME*****"<<endl<<endl;
									ifstream listeleSinif;
									listeleSinif.open("ogrenci.txt",ios::in);
									string sinifListele;
									cout<<"Sýnýf : ";
									cin>>sinifListele;
									cout<<endl;
									m=0;
									do 
							        { 	
							        	if(listeleSinif>>no>>isim>>soyisim>>sinif>>bolum)
							        	{
							        		if (sinif == sinifListele) 
										{ 
										cout<<endl<<endl<<"*****ÖÐRENCÝ BÝLGÝLERÝ*****"<<endl;
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
							        cout<<endl<<"Sýnýf bulunamadý!"<<endl;
									cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto listele;	
									}
									break;
								}
							case 3:	// önceki menü
								{
									goto ogrenci;
								}
							
						}
						break;
					}
					
				case 4:	// öðrenci bilgilerini düzeltme iþlemleri
					{
						// düzeltme iþlemi için iki dosya gerekli: varolan ve geçiçi
						ifstream okuEski;
						ofstream yazYeni;
						cout<<"Öðrenci No : ";
						cin>>noAra;
						cout<<endl;
						okuEski.open("ogrenci.txt",ios::in);	// varolan dosya okunur
						yazYeni.open("geciciOgrenci.txt",ios::out | ios::in  | ios::app);	// geçici dosyaya yazýlýr
								m=0;
								do 
							        { 	
							        	if(okuEski>>no>>isim>>soyisim>>sinif>>bolum)
							        	{
							        		if (no == noAra) 
												{ 
												cout<<endl<<endl<<"*****OGRENCI BÝLGÝSÝNÝ DÜZENLE*****"<<endl;
												cout<<"Ogrenci No     : ";		cin>>no;
												cout<<"Ogrenci Adi    : ";		cin>>isim;
												cout<<"Ogrenci Soyadi : ";		cin>>soyisim;
												cout<<"Ogrenci Sinif  : ";		cin>>sinif;
												cout<<"Ogrenci Bolumu : ";		cin>>bolum; 
												// varolan dosyada bulunan bilgiler düzenlenince geçici dosyaya yazýlýr.
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
							          remove("ogrenci.txt");	// varolan dosya kaldýrýlýr.
							          rename("geciciOgrenci.txt" , "ogrenci.txt");		// geçici dosyanýn adý eski dosyayla deðiþtirilir
							          if(m==0)
							        	cout<<endl<<"Düzenlenecek kayýt bulunamadý!"<<endl;
							        else
							        	cout<<"Kayýt düzenlendi."<<endl;
							        	cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto ogrenci;	
					}
						
						break;
					}
					
				case 5:// önceki menü
				{
					goto enbas;
				}
			}
			break;
		}//case1
		
		case 2:	// öðretim elemaný modülü
			{
				ogretimElemani:
					
				cout<<"\t\t\t\tÖÐRETÝM ELEMANI ÝÞLEMLERÝ\n\n";
			cout<<"\t\tXXXXXXXXXXXXXXXX MENU XXXXXXXXXXXXXXXXXXXXX\n\n";
			cout<<"\t\tÖÐRETÝM ELEMANI KAYIT                  -> 1\n";
			cout<<"\t\tÖÐRETÝM ELEMANI ARAMA                  -> 2\n";
			cout<<"\t\tÖÐRETÝM ELEMANI BÝLGÝLERÝ DÜZELT       -> 3\n";
			cout<<"\t\tÖÐRETÝM ELEMANI LÝSTELEME              -> 4\n";
			cout<<"\t\tANA MENÜYE DÖN                         -> 5\n";
			cout<<"\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
		
			cout<<"\n\nSeçiminiz : ";
			cin>>secim;
			system("cls");
				
				switch(secim)
				{
					case 1:	// öðretim elemaný kayýt
						{
							cout<<"*****ÖÐRETÝM ELEMANI KAYIT*****"<<endl<<endl;
							ofstream kaydetOE;
							kaydetOE.open("ogretimElemani.txt",ios::out | ios::in | ios::app);
							cout<<"Sicil No   : ";		cin>>sicil;
							cout<<"Ad	      : ";		cin>>OEAd;
							cout<<"Soyad	  : ";		cin>>OESoyad;
							cout<<"Bölüm	  : ";		cin>>OEBolum;
							kaydetOE<<sicil<<" "<<OEAd<<" "<<OESoyad<<" "<<OEBolum<<endl;
							kaydetOE.close(); 
		 					cout<<"Kayýt Baþarýlý ! "<<endl<<"Önceki menüye dönmek için lütfen 1'e basiniz...";
							cin>>donus;
							
							if(donus==1){
								system("cls");
								goto ogretimElemani;	
					}	
							break;
						}
					case 2:	// sicil no ile arama
						{
							cout<<"*****SÝCÝL NO ÝLE ARAMA*****"<<endl<<endl;
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
												cout<<"Adý       : "<<OEAd<<endl;
												cout<<"Soyadý    : "<<OESoyad<<endl;
												cout<<"Bölüm     : "<<OEBolum<<endl;
												m++; 
												} 
										}
							           
							        } while (!araSicil.eof()); 
							        araSicil.close(); 
							        if(m==0)
							        cout<<endl<<"Kayýt bulunamadý!"<<endl;
									cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto ogretimElemani;	
						}	
							break;
						}
					case 3:	// öðretim elemaný bilgilerini düzeltme
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
												cout<<endl<<endl<<"*****OGRENTÝM ELEMANI BÝLGÝLERÝNÝ DÜZENLEME*****"<<endl;
												cout<<"Sicil No  : ";		cin>>sicil;
												cout<<"Ad    	 : ";		cin>>OEAd;
												cout<<"Soyad     : ";		cin>>OESoyad;
												cout<<"Bölüm     : ";		cin>>OEBolum;
												
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
							        	cout<<endl<<"Düzenlenecek kayýt bulunamadý!"<<endl;
							          else
							          	cout<<"Kayýt Düzenlendi."<<endl;
							        	cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto ogretimElemani;
									}
							break;
						}
					case 4:	// bölüme göre öðretim elemaný listeleme
						{
								cout<<"*****BÖLÜME GÖRE ÖÐRETÝM ELEMANI LÝSTELEME*****"<<endl<<endl;
									ifstream listeleOE;
									listeleOE.open("ogretimElemani.txt",ios::in);
									string bolumBul;
									cout<<"Bölüm : ";
									cin>>bolumBul;
									m=0;
									do 
							        { 	
							        	if(listeleOE>>sicil>>OEAd>>OESoyad>>OEBolum)
							        	{
							        		 if (OEBolum == bolumBul) 
										{ 
										cout<<endl<<endl<<"*****ÖÐRETÝM ELEMANI BÝLGÝLERÝ LÝSTELEME*****"<<endl;
										cout<<"Sicil No  : "<<sicil<<endl;		
										cout<<"Ad    	 : "<<OEAd<<endl;	
										cout<<"Soyad     : "<<OESoyad<<endl;	
										cout<<"Bölüm     : "<<OEBolum<<endl;		
										m++; 
										} 
										}
							        } while (!listeleOE.eof()); 
							        listeleOE.close(); 
							        if(m==0)
							        cout<<endl<<"Bölüm bulunamadý!"<<endl;
									cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto ogretimElemani;	
									}
							break;
						}
					case 5:// önceki menü
						{
							goto enbas;
						}	
				}
				break;
			}//case2
		
		case 3:	// ders modülü
			{
				ders:
					cout<<"\t\t\t\tDERS ÝÞLEMLERÝ\n\n";
				cout<<"\t\tXXXXXXXXXXXXXXXX MENU XXXXXXXXXXXXXXXXXXXXX\n\n";
				cout<<"\t\tDERS EKLEME                            -> 1\n";
				cout<<"\t\tDERS BÝLGÝLERÝNÝ GÜNCELLEME            -> 2\n";
				cout<<"\t\tDERS LÝSTELEME                         -> 3\n";
				cout<<"\t\tDERS ARAMA                             -> 4\n";
				cout<<"\t\tANA MENÜYE DÖN                         -> 5\n";
				cout<<"\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	
				cout<<"\n\nSeçiminiz : ";
				cin>>secim;
				system("cls");
				
				switch(secim)
				{
					case 1:	// ders ekleme
						{
							cout<<"*****DERS KAYIT*****"<<endl<<endl;
					ofstream dersEkle;
					dersEkle.open("ders.txt",ios::out | ios::in | ios::app);
					cout<<"Ders Adý       : ";	   	cin>>dersAd;
					cout<<"Ders Kredisi   : ";		cin>>dersKredi;
					cout<<"Dersin Bölümü  : ";		cin>>dersBolum;
				
					dersEkle<<dersAd<<" "<<dersKredi<<" "<<dersBolum<<endl;
					dersEkle.close(); 
 					cout<<"Kayýt Baþarýlý ! "<<endl<<"Önceki menüye dönmek için lütfen 1'e basiniz...";
					cin>>donus;
					
					if(donus==1){
							system("cls");
							goto ders;
						}
							break;		
						}
					case 2:	// der bilgilerini güncelleme
						{
							ifstream okuEskiDers;//dosya okuma ve dosyayý acma 
							ofstream yazYeniDers;
							cout<<"Ders Ýsmi : ";
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
												cout<<endl<<endl<<"*****DERS BÝLGÝSÝNÝ DÜZENLE*****"<<endl;
												cout<<"Ders Adý        : ";		cin>>dersAd;
												cout<<"Ders Kredisi    : ";		cin>>dersKredi;
												cout<<"Dersin Bölümü   : ";		cin>>dersBolum;
											
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
							        	cout<<endl<<"Düzenlenecek kayýt bulunamadý!"<<endl;
							          else
							          	cout<<"Kayýt düzenlendi"<<endl;
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
								cout<<"*****DERS LÝSTELEME*****"<<endl<<endl;
									ifstream listeleDers;
									listeleDers.open("ders.txt",ios::in);
								m=0;
									do 
							        { 	
							        	if(listeleDers>>dersAd>>dersKredi>>dersBolum)
							        	{
											cout<<endl<<"*****DERS*****"<<endl;
											cout<<"Ders Adý       : "<<dersAd<<endl;
											cout<<"Ders Kredisi   : "<<dersKredi<<endl;
											cout<<"Dersin Bölümü  : "<<dersBolum<<endl;
											m++; 
										}
							           
							        } while (!listeleDers.eof()); 
							        listeleDers.close(); 
							        if(m==0)
							        cout<<endl<<"Ders bulunamadý!"<<endl;
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
								cout<<"*****DERS ADI ÝLE ARAMA*****"<<endl<<endl;
									ifstream araDers;
									araDers.open("ders.txt",ios::in);
									string dersAra;
									cout<<"Ders Adýný Giriniz : ";
									cin>>dersAra;
									m=0;
									do 
							        { 	
										if(araDers>>dersAd>>dersKredi>>dersBolum)
										{
											 if (dersAra == dersAd) 
										{ 
											cout<<endl<<"*****DERS BÝLGÝLERÝ*****"<<endl;
											cout<<"Ders Adý       : "<<dersAd<<endl;
											cout<<"Ders Kredisi   : "<<dersKredi<<endl;
											cout<<"Dersin Bölümü  : "<<dersBolum<<endl;
											m++; 
										} 
										} 
							           
							        } while (!araDers.eof());
							        araDers.close();
							        if(m==0)
							        cout<<endl<<"Ders bulunamadý!";
									cout<<endl<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto ders;	
									}
							
							break;
						}
					case 5:// önceki menü
						{
							goto enbas;
						}
					
				}
				break;
			}//case 3
		
		case 4:	// not giriþ modülü
			{
				notgiris:
					cout<<"\t\t\t\tNOT GÝRÝÞÝ\n\n";
				cout<<"\t\tXXXXXXXXXXXXXXXX MENU XXXXXXXXXXXXXXXXXXXXX\n\n";
				cout<<"\t\tÖÐRENCÝYE DERS EKLEME                  -> 1\n";
				cout<<"\t\tÖÐRENCÝ NOT GÝRÝÞÝ                     -> 2\n";
				cout<<"\t\tÖÐRENCÝ DERS LÝSTELEME                 -> 3\n";
				cout<<"\t\tKARNE OLUÞTURMA VE GÖRSELLEÞTÝRME      -> 4\n";
				cout<<"\t\tANA MENÜYE DÖN                         -> 5\n";
				cout<<"\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	
				cout<<"\n\nSeçiminiz : ";
				cin>>secim;
				system("cls");
				
				switch(secim)
				{
					case 1:	// öðrenciye ders ekleme
						{
							cout<<"*****ÖÐRENCÝYE DERS EKLEME*****"<<endl<<endl;
									ifstream okuOgrenci;
									okuOgrenci.open("ogrenci.txt",ios::in);
									ifstream okuDers;
									okuDers.open("ders.txt",ios::in);
									ofstream yazDersEkle;
									yazDersEkle.open("dersEkle.txt",ios::in | ios::app);
									
									string numara, derss;
									int n=0;
									cout<<"Öðrenci Numarasýný Giriniz : ";
									cin>>numara;
									cout<<"Ders Adýný Giriniz : ";
									cin>>derss;
									m=0;
									do 
							        { 	
										if(okuOgrenci>>no>>isim>>soyisim>>sinif>>bolum)	
										{
											 if (numara == no)	// girilen numara ogrenci.txt dosyasýnda varsa
											{ 
													do 
											        { 	
														if(okuDers>>dersAd>>dersKredi>>dersBolum )
														{
															 if ( derss == dersAd) // girilen ders ders.txt dosyasýnda varsa
															{ 
																	yazDersEkle<<numara<<" "<<derss<<endl;	// dersEkle.txt dosyasýna yazýlýr
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
							        if(m==0)	// öðrenci no sistemde kayýtlý deðilse ekleme yapýlamaz.
							       		cout<<endl<<"Kayýtlý öðrenci bulunamadý!";
							        else if(n==0)	// sistemdeki dersler haricinde ders girildiðinde ekleme yapýlamaz.
							        	cout<<endl<<"Yanlýþ(sistemde olmayan) ders adý girdiniz!";
							        else
							        	cout<<endl<<"Öðrenciye ders eklendi";
									cout<<endl<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto notgiris;	
									}
							break;		
						}
					case 2:	//öðrencinin aldýðý ders için not giriþi
						{
							cout<<"*****ÖÐRENCÝYE NOT EKLEME*****"<<endl<<endl;
									ifstream okuOgrenci2; 
									okuOgrenci2.open("ogrenci.txt",ios::in);
									
									ifstream okuDersEkle;
									okuDersEkle.open("dersEkle.txt",ios::in);
									
									ofstream yazNotEkle;
									yazNotEkle.open("notEkle.txt",ios::in | ios::app);
									
									string numara2, derss2;
									int n=0, puan;
									cout<<"Öðrenci Numarasýný Giriniz : ";
									cin>>numara2;
									cout<<"Ders Adýný Giriniz : ";
									cin>>derss2;
									cout<<"Öðrencini Notunu Giriniz : ";
									cin>>puan;
									m=0;
									do 
							        { 	
										if(okuOgrenci2>>no>>isim>>soyisim>>sinif>>bolum)
										{
											 if (numara2 == no)	// girilen numara ogrenci.txt dosyasýnda varsa
											{ 
													do 
											        { 	
														if(okuDersEkle>>numaraDersEkle>>dersEkleAd )
														{
															 if ( derss2 == dersEkleAd && numara2 == numaraDersEkle )	// öðrenci eðer belirtilen dersi almýþsa ancak not eklenebilir
															{ 
																	yazNotEkle<<numara2<<" "<<derss2<<" "<<puan<<endl;	// öðrencinin notu notEkle.txt ye yazýlýr.
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
							        if(m==0)	// girilen numara sistemde kayýtlý deðilse not eklenemez.
							       		cout<<endl<<"Kayýtlý öðrenci bulunamadý!";
							        else if(n==0)	// girilen ders sistemde kayýtlý deðilse not eklenemez.
							        	cout<<endl<<"Yanlýþ(sistemde olmayan) ders adý girdiniz!";
							        else
							        	cout<<endl<<"Öðrenciye not eklendi";
									cout<<endl<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto notgiris;	
									}
							
							
							break;
						}
					case 3:	// öðrenci ders listeleme
						{
							cout<<"*****ÖÐRENCÝ DERS LÝSTELEME*****"<<endl<<endl;
									ifstream ogrenciDersListele;
									ogrenciDersListele.open("dersEkle.txt",ios::in);
									string no3;
									cout<<"Öðrenci No : ";
									cin>>no3;
									m=0;
									do 
							        { 	
							        	if(ogrenciDersListele>>numaraDersEkle>>dersEkleAd)
							        	{
							        		if(no3 == numaraDersEkle) {
							        			if(m==0){
							        							cout<<endl<<"*****ALDIÐI DERSLER*****"<<endl;
														}
							        		
												cout<<"Ders Adý   : "<<dersEkleAd<<endl;
												m++; 
																	  }
										
										}
							           
							        } while (!ogrenciDersListele.eof()); 
							        ogrenciDersListele.close(); 
							        if(m==0)
							        cout<<endl<<"Öðrenci bulunamadý!"<<endl;
									cout<<endl<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto notgiris;	
									}
							
							
							break;
						}
					case 4: // öðrenci karnesi(traskript) oluþturma ve görselleþirme
						{
							        cout<<"*****ÖÐRENCÝ TRANSKRÝPT OLUÞTURMA*****"<<endl<<endl;
									ifstream notEkleTrans; 
									notEkleTrans.open("notEkle.txt",ios::in);
									ifstream ogrenciTrans;
									ogrenciTrans.open("ogrenci.txt",ios::in);
									 
									int n =0;
									string no4;
									cout<<"Öðrenci No:";
									cin>>no4;
									system("cls");
									m=0;
									// ilgili dosyalardan veriler okunur ve ekrana görselliði iyileþtirilerek yazdýrýlýr.
										do 
							        { 	
										if(ogrenciTrans>>no>>isim>>soyisim>>sinif>>bolum)
										{
											 if (no == no4) // girilen no sistemde kayýtlýysa transkript hazýrlanýr.
											{ 
												cout<<"\t\t\t\t---TRANSKRÝPT---"<<endl<<endl;
																cout<<"\t\t/////////////////ÖÐRENCÝ BÝLGÝLERÝ/////////////////"<<endl;
																cout<<"\t\t//\t\tNUMARA   : "<<no<<"\t\t //"<<endl;
																cout<<"\t\t//\t\tAD       : "<<isim<<"\t\t //"<<endl;
																cout<<"\t\t//\t\tSOYAD    : "<<soyisim<<"\t\t //"<<endl;
																cout<<"\t\t//\t\tSINIF    : "<<sinif<<"\t\t         //"<<endl;
																cout<<"\t\t//\t\tBÖLÜM    : "<<bolum<<"\t\t //"<<endl;
																cout<<"\t\t///////////////////////////////////////////////////"<<endl<<endl;
																cout<<"\t\t//////////////////NOT BÝLGÝLERÝ////////////////////"<<endl;
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
							       		cout<<endl<<"Kayýtlý öðrenci bulunamadý!";
							        else
							        	cout<<endl<<"Transkript baþarýyla oluþturuldu.";
									cout<<endl<<"Ust menuye donmek icin lutfen 1 e basiniz...";
									cin>>donus;
									if(donus==1){
										system("cls");
										goto notgiris;	
									}
							break;
						}
					case 5:// önceki menü
						{
							goto enbas;
						}
				}
				break;
			}//case 4
		
		case 5:	// çýkýþ
			{
				return 0;
			
			}// case 5
		default:
			{	// farklý bir rakam girlirse uyarý verilir
				cout<<"Lutfen 1 le 5 arasinda bir rakam giriniz!"<<endl;
				sleep(3); // 3 saniye beklenir
				system("cls"); // ekran temizlenir
				goto enbas; // ve programýn en baþýna yönlendirlir
			}
	}
	return 0;
}

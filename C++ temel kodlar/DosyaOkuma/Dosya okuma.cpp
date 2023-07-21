int main()
{	
    // string * firstName=new string();
    // string * lastName=new string();
    // string * displayName=new string();

    // cout << "Enter your first name: " << endl;
    // getline(cin,*firstName);

    // cout << "Enter your last name: " << endl;
    // getline(cin,*lastName);
  
    // *displayName= *lastName + ", " + *firstName;

    // cout << "Here's the information in a single string: " << *displayName;
    // cin.get();
    

	// string depoSatir;
	// ifstream dosyaNesnesi;
	// dosyaNesnesi.open("veri.txt");
	// int sayac = 0;	
	// while(getline(dosyaNesnesi,depoSatir))
	// {		
		// sayac++;
	// }
	// dosyaNesnesi.close();
	// int sistemSayisi = sayac/2000;
	// cout << sistemSayisi << endl << endl;
	
	string depoSatir2;
	ifstream dosyaNesnesi2;
	dosyaNesnesi2.open("veri.txt");
	getline(dosyaNesnesi2,depoSatir2);	
	string* diziT = new string[2];
	diziT[0] = depoSatir2;
	getline(dosyaNesnesi2,depoSatir2);
	diziT[1] = depoSatir2;
	string okunuyor = diziT[0];
	cout << "diziT no1: " << diziT[0] << endl;
	cout << "diziT no2: " << diziT[1] << endl;
	cout << "tekrar okunuyor(diziT no1): " << okunuyor;
	return 0;
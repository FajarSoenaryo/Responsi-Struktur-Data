#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#define max 10

using namespace std;

void setcolor(unsigned short color)
{
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleTextAttribute(hCon,color);
}
//Struct Yang Berisi Info Mahasiswa
struct MahaSiswa {
	int id;
	string nama;
	string nim;
	string strukdat;
	string jarkom;
	string statistika;
};
//Stack Berisi Mahasiswa
struct StackMA {
	int top;
	struct MahaSiswa MahaSiswa[max];
}MA;
//inisialisasi semua fungsi
void pembuka();
void tampiMA();
int isEmptyKA();
void pushMA(string nama, string nim, string strukdat, string jarkom, string statistika);
void sortMA();
void initMA();
void cariMA();
void exit();

void pembuka()
{
	int pill;
	string nama, nim, strukdat, jarkom, statistika;
	do 
	{
		cout<<"========================"<<endl;
		cout<<" RESPONSI STRUKTUR DATA "<<endl;
		cout<<" Nama   : FAJAR ANSORI K. W  "<<endl;
		cout<<" NIM    : 5180411423    "<<endl;
		cout<<"========================"<<endl;
		cout<<""<<endl;
		cout<<"1. Input Data"<<endl
			<<"2. Menampilkan Data"<<endl
			<<"3. Mengurutkan Data"<<endl
			<<"4. Mencari Data"<<endl
			<<"5. Keluar"<<endl
			<<endl
			<<"Pilihan anda :";
		cin>>pill;
		
		switch(pill)
		{
			case 1:
				system ("CLS");
				cout<<"Lengkapi Data Berikut!"<<endl<<"======================="<<endl;
				cout<<"Nama Mahasiswa : "; cin >> nama;
				cout<<"NIM : "; cin >> nim;
				cout<<"Nilai Struktur Data : "; cin >>strukdat;
				cout<<"Nilai Jaringan Komputer : "; cin >>jarkom;
				cout<<"Nilai statistika: "; cin >>statistika;
				pushMA(nama,nim,strukdat,jarkom,statistika);
				break;
			case 2:
				tampiMA();
				break;
			case 3:
				system("CLS");
				sortMA();
				break;
			case 4:
				system("CLS");
			cariMA();
			break;
			case 5:
				exit();
				break;
			default: 
				cout<<endl;
				cout<<"Mohon Masukan Pilihan Dengan Benar"<<endl<<endl;
				
		}
		
			
	} while(pill!=5);
	{
		cout<<"Mohon Masukan Pilihan Dengan Benar";
	}
}
//Inilisiasi stack Mahasiswa
void initMA()
{
	MA.top = -1;
}
//Mengisi STack dan Info Mahasiswa
void pushMA(string nama, string nim, string strukdat, string jarkom, string statistika)
{
	MA.top++;
	MA.MahaSiswa[MA.top].id =MA.top;
	MA.MahaSiswa[MA.top].nim = nim;
	MA.MahaSiswa[MA.top].nama = nama;
	MA.MahaSiswa[MA.top].jarkom = jarkom;
	MA.MahaSiswa[MA.top].strukdat = strukdat;
	MA.MahaSiswa[MA.top].statistika= statistika;
	system("CLS");
	cout<<"=============================================="<<endl;
    cout<<"    Mahasiswa Bernama :	";
	cout<<"    "<<MA.MahaSiswa[MA.top].nama<<"           "<<endl;
	cout<<"    Dengan NIM :	";
	cout<<"    "<<MA.MahaSiswa[MA.top].nim<<"            "<<endl; 
	cout<<"                  SUKSES                      "<<endl;
	setcolor(3);
	cout<<"                DITAMBAHKAN !                 "<<endl;
	setcolor(7);
	cout<<"=============================================="<<endl;
	Sleep(3000);
	system("CLS");
	
}
//menampilkan seluruh Mahasiswa
void tampiMA()
{
		system("CLS");
	
		cout << "===========================================================================" << endl;
		cout << "                                DAFTAR NAMA                                " << endl;
		cout << "                         MAHASISWA TEKNIK INFORMATIKA                      " << endl;
		cout << "                        UNIVERSITAS TEKNOLOGI YOGYAKATA                    " << endl;
		cout << "===========================================================================" << endl;
		cout<<"No.	 Nama	 NIM	Jarkom		Struktur Data	Statistika"<<endl;
		for(int i = 1; i<=MA.top;i++)
		{
			cout<<i<<"\t"<<MA.MahaSiswa[i].nama<<"\t"<<MA.MahaSiswa[i].nim<<"\t"<<MA.MahaSiswa[i].jarkom<<"\t\t"<<MA.MahaSiswa[i].strukdat<<"\t\t"<<MA.MahaSiswa[i].statistika<<endl;
		}	
		cout<<"==========================================================================="<<endl;
		char yt;
		cout<<"Press any key to continue ";
		cin>>yt;
    cout<<endl;
    if(yt=='Y'||yt=='y'){
    	system("CLS");
        pembuka();
    }else
    system("CLS");
        pembuka();


}
//menyorting mahasiswa menurut NIM
void sortMA()
{
	StackMA tempMA;
	
	//coppy data dari struct ke temporary
	tempMA.top = -1;
	for (int i = 0; i<= MA.top;i++)
	{
		tempMA.top++;
		tempMA.MahaSiswa[i].id = MA.MahaSiswa[i].id;
		tempMA.MahaSiswa[i].nama = MA.MahaSiswa[i].nama;
		tempMA.MahaSiswa[i].nim = MA.MahaSiswa[i].nim;
		tempMA.MahaSiswa[i].jarkom = MA.MahaSiswa[i].jarkom;
		tempMA.MahaSiswa[i].strukdat = MA.MahaSiswa[i].strukdat;
		tempMA.MahaSiswa[i].statistika= MA.MahaSiswa[i].statistika;
		
	}
	string nama[max],nim[max],jarkom[max],strukdat[max],statistika[max];
	
	//short menggunakan bubble short
	for (int i=1;i<=MA.top;i++)
	{
		for(int j = 0; j <=MA.top - i; j++)
		{
			if(tempMA.MahaSiswa[j].nim < tempMA.MahaSiswa[j+1].nim)
			{
			
			//Proses Pertukaran Data
				nama[j]=tempMA.MahaSiswa[j].nama;
				nim[j]=tempMA.MahaSiswa[j].nim;
				jarkom[j]=tempMA.MahaSiswa[j].jarkom;
				strukdat[j]=tempMA.MahaSiswa[j].strukdat;
				statistika[j]=tempMA.MahaSiswa[j].statistika;
			
				tempMA.MahaSiswa[j].nama = tempMA.MahaSiswa[j+1].nama;
				tempMA.MahaSiswa[j].nim = tempMA.MahaSiswa[j+1].nim;
				tempMA.MahaSiswa[j].jarkom = tempMA.MahaSiswa[j+1].jarkom;
				tempMA.MahaSiswa[j].strukdat = tempMA.MahaSiswa[j+1].strukdat;
				tempMA.MahaSiswa[j].statistika= tempMA.MahaSiswa[j+1].statistika;
			
				tempMA.MahaSiswa[j+1].nama = nama[j];
				tempMA.MahaSiswa[j+1].nim = nim[j];
				tempMA.MahaSiswa[j+1].jarkom = jarkom[j];
				tempMA.MahaSiswa[j+1].strukdat = strukdat [j];
				tempMA.MahaSiswa[j+1].statistika= statistika[j];
			}
		}
	}
	//menampilkan hasil sorting
	cout<<"HASIL SORTING BERDASARKAN NIM"<<endl;
	cout<<"Nama		NIM		Jarkom		Struktur Data	Kalkulus"<<endl;
	for (int i = MA.top; i >= 0; i--)
	{
		cout<<tempMA.MahaSiswa[i].nama<<"\t\t";
		cout<<tempMA.MahaSiswa[i].nim<<"\t\t";
		cout<<tempMA.MahaSiswa[i].jarkom<<"\t\t";
		cout<<tempMA.MahaSiswa[i].strukdat<<"\t\t";
		cout<<tempMA.MahaSiswa[i].statistika<<"\t\t";
		cout<<endl;
		
		
	}
	char yt;
	cout<<endl;
		cout<<"Press any key to continue ";
		cin>>yt;
    cout<<endl;
    if(yt=='Y'||yt=='y'){
    	system("CLS");
        pembuka();
    }else
    system("CLS");
        pembuka();
	
}
//Searching 
void cariMA()
{
	string nim;
	int j = 0;
	int index [max];
	
	cout<<"Masukan NIM :";
	cin >>nim;
	for (int pr = 0; pr <=MA.top;pr++)
	{
		if (MA.MahaSiswa[pr].nim == nim)
		{
			index[j]=pr;
			j++;
		}
	}
	if (j>0)
	{
		cout<<"Terdapat "<<j<<" orang " <<endl;
		cout<<"Nama		Nim		Jarkom		StrukturData	Statistika"<<endl;
		for (int pr = 0;pr<j;pr++)
		{
				cout<<MA.MahaSiswa[index[pr]].nama<<"\t\t";
				cout<<MA.MahaSiswa[index[pr]].nim<<"\t\t";
				cout<<MA.MahaSiswa[index[pr]].jarkom<<"\t\t";
				cout<<MA.MahaSiswa[index[pr]].strukdat<<"\t\t";
				cout<<MA.MahaSiswa[index[pr]].statistika<<"\t\t\t";
		}
	
		
	}
	cout<<endl;
	char yt;
		cout<<"Press any key to continue ";
		cin>>yt;
    cout<<endl;
    if(yt=='Y'||yt=='y'){
    	system("CLS");
        pembuka();
    }else
    system("CLS");
        pembuka();
}
void exit()
{
	system("CLS");
	cout<<endl;
	cout<<"5180411423 "<<endl;
	cout<<"FAJAR ANSORI K. W "<<endl;
	cout<<"TEKNIK INFORMATIKA "<<endl;
	
	
	exit(0);
	
}

int main()
{

	pembuka();

}


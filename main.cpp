#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include <windows.h>

#define BLACK 0
#define BLUE  1
#define GREEN  2
#define CYAN 3
#define RED  4
#define MAGENTA  5
#define BROWN  6
#define LIGHT_GRAY  7
#define DARK_GRAY  8
#define LIGHT_BLUE  9
#define LIGHT_GREEN 10
#define LIGHT_CYAN  11
#define LIGHT_RED  12
#define LIGHT_MAGENTA  13
#define YELLOW 14
#define WHITE 15

#define USERNAME "admin"
#define PASSWORD "4dm1n"

using namespace std;

struct Tanggal {
	int tgl;
	int bln;
	int thn;
};

struct IKehilangan {
	string Nama;
	string Telp;
	string Alamat;
	string Barang;
	Tanggal tanggal;
	string Keterangan;
};

struct NodeIK {
	IKehilangan info;
	NodeIK *next;
	NodeIK *prev;
};

struct Pengumuman {
	string judul;
	string keterangan;
	int id;
};

struct NodeP {
	Pengumuman png;
	NodeP *next;
	NodeP *prev;
};

struct kegiatan {
	string judul;
	string keterangan;
	string tanggal;
	int id;
};

struct NodeK {
	kegiatan kgt;
	NodeK *next;
	NodeK *prev;
};

struct IMenemukan {
	string Nama;
	string Telp;
	string Alamat;
	string Barang;
	Tanggal tanggal;
	string Keterangan;
};

struct NodeIM {
	IMenemukan info;
	NodeIM *next;
	NodeIM *prev;
};

void sisi_depan(NodeIK* &awal, NodeIK* &akhir, IKehilangan IK) {
	NodeIK *baru = new NodeIK;
	baru->info = IK;
	baru->prev = NULL;
	
	if(awal == NULL) {
		akhir = NULL;
		baru->next = NULL;
	} else {
		baru->next = awal;
		awal->prev = baru;
	}
	
	awal = baru;
}

void sisip_belakang(NodeIK* &awal, NodeIK* &akhir, IKehilangan IK) {
	NodeIK *baru = new NodeIK;
	
	baru->info = IK;
	baru->next = NULL;
	
	if(awal == NULL) {
		baru->prev = NULL;
		awal = baru;
	} else {
		baru->prev = akhir;
		akhir->next = baru;
	}
	
	akhir = baru;
}

void sisip_belakang(NodeIM* &awal, NodeIM* &akhir, IMenemukan IM) {
	NodeIM *baru = new NodeIM;
	
	baru->info = IM;
	baru->next = NULL;
	
	if(awal == NULL) {
		baru->prev = NULL;
		awal = baru;
	} else {
		baru->prev = akhir;
		akhir->next = baru;
	}
	
	akhir = baru;
}

void gotoxy(int column, int line) 
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

void textcolor(int ForgC)
{
	WORD wColor;
	
	
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	
	if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

void login() 
{
	
	bool loggedIn = false;
	int chance = 3;
	string username;
	string password;
  	// menampilkan login

     gotoxy(26,  8);cout<<"                                     ";
     gotoxy(26,  9);cout<<"    ADMINISTRATOR LOGIN              ";
     gotoxy(26, 10);cout<<"                                     ";

     gotoxy(26, 11);cout<<"                                     ";
     gotoxy(26, 12);cout<<"    Username                         ";
     gotoxy(26, 13);cout<<"             --------------------    ";
     gotoxy(26, 14);cout<<"    Password                         ";
     gotoxy(26, 15);cout<<"             --------------------    ";
     gotoxy(26, 16);cout<<"                                     ";
     
     do {
           chance = chance - 1;

           textcolor(WHITE);
           gotoxy(39, 12);
		   fflush(stdin);
		   getline(cin, username);
           gotoxy(39, 14);
           
           fflush(stdin);
		   getline(cin, password);
		   
           if((username == USERNAME) && (password == PASSWORD)) {
                loggedIn = true;
           } else {
               textcolor(RED);
               if(chance > 0) {
			   		gotoxy(26, 17);cout<<"    Username atau password salah !   ";
                    gotoxy(26, 18);cout<<"    Kesempatan ', chance, ' kali                ";
                    gotoxy(26, 19);cout<<"                                     ";
                    gotoxy(39, 12);cout<<"                        ";
                    gotoxy(39, 14);cout<<"                        ";
            	} else {
					gotoxy(26, 17);cout<<"     Anda telah 3 kali gagal login   ";
					gotoxy(26, 18);cout<<"     Keluar program ...              ";
                    gotoxy(26, 19);cout<<"                                     ";
                }
           }
    } while(!loggedIn) ;
    
}

void Tampil_IKehilangan(NodeIK *node)
{
	gotoxy(0, 3);cout<<"INFO KEHILANGAN BARANG";
	
	
	int i = 0;
	NodeIK *bantu = node;
	while(bantu != NULL) {
		gotoxy(0, 5+i);cout<<bantu->info.Nama<<" - "<<bantu->info.Barang<<endl;	
		bantu = bantu->next;
		
		i += 1;
	}
}

void Tampil_IMenemukan(NodeIM *node)
{
	gotoxy(30, 3);cout<<"INFO MENEMUKAN BARANG";
	
	
	int i = 0;
	NodeIM *bantu = node;
	while(bantu != NULL) {
		gotoxy(30, 5+i);cout<<bantu->info.Nama<<" - "<<bantu->info.Barang<<endl;	
		bantu = bantu->next;
		
		i += 1;
	}
}

void Input_IKehilangan(NodeIK* &awal, NodeIK* &akhir)
{
	IKehilangan *baru = new IKehilangan;
			
	cout<<"Nama : ";
	fflush(stdin);
	getline(cin, baru->Nama);
				
	cout<<"Alamat : ";
	fflush(stdin);
	getline(cin, baru->Alamat);
				
	cout<<"No. Telepon : ";
	fflush(stdin);
	getline(cin, baru->Telp);
				
	cout<<"Barang : ";
	fflush(stdin);
	getline(cin, baru->Barang);
				
	cout<<"Tanggal : ";
	cin>>baru->tanggal.tgl;
	cout<<"Bulan : ";
	cin>>baru->tanggal.bln;
	cout<<"Tahun : ";
	cin>>baru->tanggal.thn;
			
	cout<<"Keterangan : "<<endl;
	fflush(stdin);
	getline(cin, baru->Keterangan);
				
				
	sisip_belakang(awal, akhir, *baru);
}

void Input_IMenemukan(NodeIM* &awal, NodeIM* &akhir)
{
	IMenemukan *baru = new IMenemukan;
			
	cout<<"Nama : ";
	fflush(stdin);
	getline(cin, baru->Nama);
				
	cout<<"Alamat : ";
	fflush(stdin);
	getline(cin, baru->Alamat);
				
	cout<<"No. Telepon : ";
	fflush(stdin);
	getline(cin, baru->Telp);
				
	cout<<"Barang : ";
	fflush(stdin);
	getline(cin, baru->Barang);
				
	cout<<"Tanggal : ";
	cin>>baru->tanggal.tgl;
	cout<<"Bulan : ";
	cin>>baru->tanggal.bln;
	cout<<"Tahun : ";
	cin>>baru->tanggal.thn;
			
	cout<<"Keterangan : "<<endl;
	fflush(stdin);
	getline(cin, baru->Keterangan);
				
				
	sisip_belakang(awal, akhir, *baru);
}

void sisip_belakang(NodeP* &awal, NodeP* &akhir, Pengumuman png) {
	NodeP *baru = new NodeP;
	
	baru->png = png;
	baru->next = NULL;
	
	if(awal == NULL) {
		baru->prev = NULL;
		awal = baru;
	} else {
		baru->prev = akhir;
		akhir->next = baru;
	}
	
	akhir = baru;
}

void Input_Pengumuman(NodeP* &awal, NodeP* &akhir)
{
	Pengumuman *baru = new Pengumuman;
			
	
				cout<<"Judul : ";
				fflush(stdin);
				getline(cin, baru->judul);
				
				cout<<"Keterangan : ";
				fflush(stdin);
				getline(cin, baru->keterangan);
				
				cout<<"ID : ";
				cin>>baru->id;
				
				sisip_belakang(awal, akhir, *baru);
}

void Tampil_Pengumuman(NodeP *node)
{
	gotoxy(30, 12);cout<<"PENGUMUMAN";
	
	
	int i = 0;
	NodeP *bantu = node;
	while(bantu != NULL) {
		gotoxy(30, 14+i);cout<<bantu->png.judul<<endl;	
		bantu = bantu->next;
		
		i += 1;
	}
}

void sample_IKehilangan(NodeIK* &awal, NodeIK* &akhir) {
	IKehilangan *baru = new IKehilangan;
	baru->Nama = "Egi Soleh Hasdi";
	baru->Alamat = "Jalan H.Nawawi No.13/107";
	baru->Telp = "08118711382";
	baru->Barang = "Laptop";
	baru->Keterangan = "Terakhir ada di kelas";
	sisip_belakang(awal, akhir,*baru);
	
	baru = new IKehilangan;
	baru->Nama = "H Mutha Arif";
	baru->Alamat = "Perum Mekarsari";
	baru->Telp = "085211555518";
	baru->Barang = "Uang";
	baru->Keterangan = "Terakhir ada di kantong";
	sisip_belakang(awal, akhir,*baru);
	
	baru = new IKehilangan;
	baru->Nama = "Raka Adit";
	baru->Alamat = "Jalan remed No.13/107";
	baru->Telp = "0811222222";
	baru->Barang = "Rambut";
	baru->Keterangan = "Terakhir ada di kepala";
	sisip_belakang(awal, akhir,*baru);
	
	baru = new IKehilangan;
	baru->Nama = "Maya Wulan";
	baru->Alamat = "Jalan Haji aji No.13/07";
	baru->Telp = "08118711382";
	baru->Barang = "HP";
	baru->Keterangan = "Terakhir ada di baju";
	sisip_belakang(awal, akhir,*baru);
  
    baru = new IKehilangan;
	baru->Nama = "Satria W";
	baru->Alamat = "Jalan wawi No.13/107";
	baru->Telp = "0811999999";
	baru->Barang = "Char Dota";
	baru->Keterangan = "Terakhir ada di steam";
	sisip_belakang(awal, akhir,*baru);

}

void sample_menemukan(NodeIM* &awal, NodeIM* &akhir) {
	IMenemukan *baru = new IMenemukan;
	baru->Nama = "Egi Soleh Hasdi";
	baru->Alamat = "Jalan H.Nawawi No.13/107";
	baru->Telp = "08118711382";
	baru->Barang = "Laptop";
	baru->Keterangan = "Terakhir ada di kelas";
	sisip_belakang(awal, akhir,*baru);
	
	baru = new IMenemukan;
	baru->Nama = "H Mutha Arif";
	baru->Alamat = "Perum Mekarsari";
	baru->Telp = "085211555518";
	baru->Barang = "Uang";
	baru->Keterangan = "Terakhir ada di kantong";
	sisip_belakang(awal, akhir,*baru);
	
	baru = new IMenemukan;
	baru->Nama = "Raka Adit";
	baru->Alamat = "Jalan remed No.13/107";
	baru->Telp = "0811222222";
	baru->Barang = "Rambut";
	baru->Keterangan = "Terakhir ada di kepala";
	sisip_belakang(awal, akhir,*baru);
	
	baru = new IMenemukan;
	baru->Nama = "Maya Wulan";
	baru->Alamat = "Jalan Haji aji No.13/07";
	baru->Telp = "08118711382";
	baru->Barang = "HP";
	baru->Keterangan = "Terakhir ada di baju";
	sisip_belakang(awal, akhir,*baru);
  
    baru = new IMenemukan;
	baru->Nama = "Satria W";
	baru->Alamat = "Jalan wawi No.13/107";
	baru->Telp = "0811999999";
	baru->Barang = "Char Dota";
	baru->Keterangan = "Terakhir ada di steam";
	sisip_belakang(awal, akhir,*baru);

}

void sample_pengumuman(NodeP* &awal, NodeP* &akhir) {
	Pengumuman *baru = new Pengumuman;
	baru->judul = "libur";
	baru->keterangan = "besok libur";
	baru->id = 1;
	sisip_belakang(awal, akhir,*baru);
	
	baru->judul = "Sangatsu kokonoka";
	baru->keterangan = "1 litre of tears";
	baru->id = 2;
	sisip_belakang(awal, akhir,*baru);
	
	baru->judul = "boom boom";
	baru->keterangan = "nice people";
	baru->id = 3;
	sisip_belakang(awal, akhir,*baru);
	
	baru->judul = "autodebet";
	baru->keterangan = "besok bayar";
	baru->id = 4;
	sisip_belakang(awal, akhir,*baru);
  
    baru->judul = "kuliah";
	baru->keterangan = "atur";
	baru->id = 5;
	sisip_belakang(awal, akhir,*baru);

}

void sisip_belakang(NodeK* &awal, NodeK* &akhir,kegiatan kgt) {
	NodeK *baru = new NodeK;
	
	baru->kgt = kgt;
	baru->next = NULL;
	
	if(awal == NULL) {
		baru->prev = NULL;
		awal = baru;
	} else {
		baru->prev = akhir;
		akhir->next = baru;
	}
	
	akhir = baru;
}

void Input_kegiatan(NodeK* &awal, NodeK* &akhir)
{
	kegiatan *baru = new kegiatan;
			
	
				cout<<"Judul : ";
				fflush(stdin);
				getline(cin, baru->judul);
				
				cout<<"Keterangan : ";
				fflush(stdin);
				getline(cin, baru->keterangan);
				
				cout<<"Tanggal : ";
				fflush(stdin);
				getline(cin, baru->tanggal);
				
				cout<<"ID : ";
				cin>>baru->id;
				
				sisip_belakang(awal, akhir, *baru);
}

void Tampil_kegiatan(NodeK *node)
{
	gotoxy(0, 12);cout<<"INFO KEGIATAN";
	
	
	int i = 0;
	NodeK *bantu = node;
	while(bantu != NULL) {
		gotoxy(0, 14+i);cout<<bantu->kgt.judul<<endl;	
		bantu = bantu->next;
		
		i += 1;
	}
}

void sample_kegiatan(NodeK* &awal, NodeK* &akhir) {
	kegiatan *baru = new kegiatan;
	baru->judul = "libur";
	baru->keterangan = "besok libur";
	baru->id = 1;
	sisip_belakang(awal, akhir,*baru);
	
	baru->judul = "Sangatsu kokonoka";
	baru->keterangan = "1 litre of tears";
	baru->id = 2;
	sisip_belakang(awal, akhir,*baru);
	
	baru->judul = "boom boom";
	baru->keterangan = "nice people";
	baru->id = 3;
	sisip_belakang(awal, akhir,*baru);
	
	baru->judul = "autodebet";
	baru->keterangan = "besok bayar";
	baru->id = 4;
	sisip_belakang(awal, akhir,*baru);
  
    baru->judul = "kuliah";
	baru->keterangan = "atur";
	baru->id = 5;
	sisip_belakang(awal, akhir,*baru);

}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	//login();
	NodeIK *awal  = NULL,
		   *akhir = NULL;
	NodeP *Pawal = NULL,
		  *Pakhir = NULL;
     NodeK *Kawal = NULL,
		  *Kakhir = NULL;
     NodeIM *Mawal = NULL,
		  *Makhir = NULL;
		  
		  
	
	int menu;
	sample_IKehilangan(awal, akhir);
	sample_pengumuman(Pawal, Pakhir);
	sample_kegiatan(Kawal, Kakhir);
	sample_menemukan(Mawal, Makhir);
	
	do {
		system("cls");
		
		gotoxy(0,0);cout<<"| MENU  | 1. Menemukan Barang\t2. Kehilangan\t3. Pengumuman\t| Menu Pilihan"<<endl;
		gotoxy(0,1);cout<<"| UTAMA | 4. Info Autodebet\t5. Kegiatan\t6. Admin\t| ";
		
		
		Tampil_IKehilangan(awal);
		Tampil_Pengumuman(Pawal);
		Tampil_kegiatan(Kawal);
		Tampil_IMenemukan(Mawal);
		gotoxy(68,1);cin>>menu;
		system("cls");
		switch(menu) {
		
			case 6:
				login();
				break;
			case 2:
				Input_IKehilangan(awal, akhir);
				getch();
				break;
			case 3:
				Input_Pengumuman(Pawal, Pakhir);
				getch();
				break;
			case 5:
                 Input_kegiatan(Kawal, Kakhir);
                 getch();
                 break;
            case 1:
                 Input_IMenemukan(Mawal,Makhir);
                 getch();
                 break;
		}
	} while(menu != 4);
	
	return EXIT_SUCCESS;
}
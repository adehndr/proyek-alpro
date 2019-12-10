/******************************************************************************

                            Program Proyek Akhir
                        Mata Kuliah Algoritma Pemrograman
                                    oleh
                        Adam Doni Mauladi   1706037144
                        Ade Hendra          17060371

*******************************************************************************/

//Library yang digunakan
#include <stdio.h>          //Standard Libarary
#include "fungsikalkulasi.h"    //Header Function
#include <stdlib.h>         //Standard library
#include <string.h>         //Fungsi untuk  mengolah string
#include <time.h>           //Fungsi untuk mengaplikasikan waktu
#include <ctype.h>          //Fungsi klasifikasi Karakter
#include <math.h>           //Fungsi Matematika
#define Max 100
#define Min 1
#define mid 4


//VARIABLE UNIVERSAL YANG DAPAT DIGUNAKAN DALAM SETIAP FUNGSI

//Define variable struck dalam variable "car"
struct car
{
	char listmobil[Max];
	int mobilada;
	int hargam;
};

//Define variable struck dalam variable "peminjam mobil"
struct peminjam_mobil
{
	char nama[Max];
	int pinjammobil;
	int tagihan;
	int durasi;
	clock_t stamp;
	double telat;
	int denda;
};

//DEFINE FUNGSI MODULAR
void pageMenu(struct peminjam_mobil peminjam[],struct car mobil[],int orang);
void pagesewamobil(	struct peminjam_mobil peminjam[],struct car mobil[],int orang);
void pagecekpeminjam(struct peminjam_mobil peminjam[],struct car mobil[],int orang);
void pagecekmobil(struct peminjam_mobil peminjam[],struct car mobil[],int orang);
void pagebalikin(struct peminjam_mobil peminjam[],struct car mobil[],int orang);
int getInputInteger(const char *teks, int MIN, int MAX);
int pagehelp(struct peminjam_mobil peminjam[],struct car mobil[],int orang);
int pageExit();
int isValid(char input[]);
void delay(int number_of_seconds);

//FUNGSI UTAMA
int main ()
{
	struct peminjam_mobil peminjam[mid];
	struct car mobil[mid] =
	{
		{"Avanza", 1, 5000},
		{"Kijang", 1, 10000},
		{"Xenia", 1, 15000},
		{"APV", 1, 20000}
	};
	int orang = 0;
	pageMenu(peminjam,mobil,orang);
	return 0;
}


void pageMenu(struct peminjam_mobil peminjam[],struct car mobil[],int orang){
	system("cls");
    printf("Silahkan Pilih Menu : \n1. Penyewaan Mobil\n2. Cek Peminjam Mobil\n3. Cek Unit Mobil\n4. Mengembalikan Kendaraan\n5. Help\n6. Keluar\n");
    int menu = getInputInteger("Menu", 1, 100);
    if(menu == 1)
        pagesewamobil(peminjam,mobil,orang);
    else if(menu == 2)
		pagecekpeminjam(peminjam,mobil,orang);
    else if(menu == 3)
        pagecekmobil(peminjam,mobil,orang);
    else if(menu == 4)
    	pagebalikin(peminjam,mobil,orang);
    else if(menu == 5)
        pagehelp(peminjam,mobil,orang);
    else if(menu == 6)
        pageExit();
    else
        pageMenu(peminjam,mobil,orang);
}

//MENU PENYEWAAN MOBIL
void pagesewamobil(struct peminjam_mobil peminjam[],struct car mobil[],int orang)
{
	int i,total,x,y,z;
	printf("Silahkan masukkan nama anda : ");
	scanf("%s", peminjam[orang].nama);
	printf("Selamat datang %s,berikut daftar mobil yang bisa disewa\n",peminjam[orang].nama);
	printf("\nNo.     Daftar Mobil :      Jumlah Unit :       Harga sewa perhari :\n");
	for(i=0;i<4;i++)    //Membuat loop untuk menuliskan list mobil yang tersedia
	{
		printf("%d      %15s        %8d    Rp.%18d\n", i+1,mobil[i].listmobil, mobil[i].mobilada,mobil[i].hargam);//Menampilkan dalam sistem list mobil
	}
	do
	{
	printf("Silahkan pilih nomor dari mobil yang diinginkan : ");
	scanf("%d", &x);//Memasukan nomor mobil yang diinginkan
	getchar();
	if (x > 4)
		{
			continue;
		}
	else
	{
		if (mobil[x-1].mobilada == 0)
		{
			printf("Mobil yang anda pilih tidak tersedia\n");
			printf("Silahkan memilih mobil yang lain\n\n");
			continue;
		}
		else
		{
			mobil[x-1].mobilada = mobil[x-1].mobilada - 1;
			peminjam[orang].pinjammobil = x-1;
			break;
		}

	}
	}
	while(1);
	printf("Mau sewa berapa hari : ");
	scanf("%d",&y);
	getchar();
	peminjam[orang].durasi = y;
	peminjam[orang].tagihan = mobil[x-1].hargam*y;
	printf("\n1 Unit mobil %s telah disewa dengan harga %d  \n\n",mobil[x-1].listmobil,peminjam[orang].tagihan);
	do
	{
		printf("Silahkan masukan jumlah uang untuk membayar : ");
		scanf("%d",&z);
		getchar();
		fungsikalkulasi(z, peminjam[orang].tagihan);
		if ( fungsikalkulasi(z, peminjam[orang].tagihan)< 0)
		{
			printf("Kembalian : %d \n",z);
			printf("Uang Kurang\n");
			continue;
		}
		else
		{
			printf("Kembalian : %d \n",fungsikalkulasi(z, peminjam[orang].tagihan));
			peminjam[orang].stamp = clock();
			printf("Transaksi berhasil\n");
			orang++;
			break;
		}
	}
	while (1);
	printf("\nTekan Enter untuk kembali ke menu awal");
	getchar();
	pageMenu(peminjam,mobil,orang);
}

//MENU PEMINJAMAN MOBIL
void pagecekpeminjam(struct peminjam_mobil peminjam[],struct car mobil[],int orang)
{
	int i;
	printf("No. Nama : \t Mobil yang dipinjam :  \t Tagihan : \n");
	for(i=0;i<orang;i++)
	{
		printf("%d\t %s \t\t %s \t\t\t %d \n", i+1,peminjam[i].nama,mobil[peminjam[i].pinjammobil].listmobil,peminjam[i].tagihan);
	}
	printf("\nTekan Enter untuk kembali ke menu awal");
	getchar();
	getchar();
	pageMenu(peminjam,mobil,orang);
}

//MENU CEK MOBIL
void pagecekmobil(struct peminjam_mobil peminjam[],struct car mobil[],int orang)
{
	int i,result;
	char c1 = 89;
	printf("No.     Daftar Mobil :      Jumlah Unit :       Harga sewa perhari :\n");
	for(i=0;i<4;i++)    //Membuat loop untuk menuliskan list mobil yang tersedia
	{
	printf("%d      %15s        %8d     %18d\n", i+1,mobil[i].listmobil, mobil[i].mobilada,mobil[i].hargam);//Menampilkan dalam sistem list mobil
	}
	printf("\nTekan Enter untuk kembali ke menu awal");
	getchar();
	getchar();
	pageMenu(peminjam,mobil,orang);
}

//MENU PENGEMBALIAN MOBIL
void pagebalikin(struct peminjam_mobil peminjam[],struct car mobil[],int orang)
{
	int i,x,z;
	char input;
	clock_t t;
	double taken;
	for(i=0;i<orang;i++)
	{
		t = clock() - peminjam[i].stamp;
		taken = ((double)t)/CLOCKS_PER_SEC;
		peminjam[i].telat = ((double)t)/CLOCKS_PER_SEC;
		peminjam[i].telat = floor(peminjam[i].telat/10.0);
		if(peminjam[i].durasi*10.0 < peminjam[i].telat*10.0)
        {
            peminjam[i].telat = 0;
        }
		printf("waktu ke-%d = %.2f detik\n",i+1, taken);
	}

	for(i=0;i<orang;i++)
	{
		if(peminjam[i].durasi > peminjam[i].telat)
		{
			peminjam[i].denda = 0.0;
		}
		else
		{
			peminjam[i].denda = 1000.00*peminjam[i].telat;
		}
	}

	printf("\nBerikut Merupakan daftar mobil yang dipinjam beserta peminjamnya.\n");
	printf("No.  Nama: \t Mobil:\t     Durasi Peminjam :\t Telah Dibayar:  Keterlambatan:\t Denda:\n");
	for(i=0;i<orang;i++)
	{
		printf("%d     %s\t %s\t\t %d Hari\t\t %d\t\t %.0f Hari \t %d Rupiah\n",i+1,peminjam[i].nama,mobil[peminjam[i].pinjammobil].listmobil,
		peminjam[i].durasi,peminjam[i].tagihan,peminjam[i].telat,peminjam[i].denda);
	}
	do{
		printf("Apakah anda ingin mengembalikan kendaraan (y/n)? ");
		scanf(" %c",&input);
		if(input == 'y')
		{
			printf("Pilih nomor : ");
			scanf(" %d",&x);
			if(peminjam[x-1].denda == 0)
			{
				printf("Anda berhasil mengembalikan kendaraan %s atas nama %s\n", mobil[peminjam[x-1].pinjammobil].listmobil,peminjam[x-1].nama);
				mobil[peminjam[x-1].pinjammobil].mobilada += 1;
				orang = orang - 1;
				for(i=x-1;i<orang;i++)
				{
				peminjam[i] = peminjam[i+1];
				}
			}
			else
			{
				do
				{
					printf("Anda memiliki denda sebesar Rp.%d Karena telat mengembalikan mobil selama %.0f Hari\n",peminjam[x-1].denda,peminjam[x-1].telat);
					printf("Masukkan uang untuk membayar denda : ");
					scanf("%d",&z);
					getchar();
					fungsikalkulasi(z, peminjam[x-1].denda);
				if ( fungsikalkulasi(z, peminjam[x-1].denda)< 0)
				{
					printf("Kembalian : %d \n",z);
					printf("Uang Kurang\n");
					continue;
				}
				else
				{
					printf("Kembalian : %d \n",fungsikalkulasi(z, peminjam[x-1].denda));
					printf("%s Telah membayar denda", peminjam[x-1].nama);
					printf("Denda telah terbayar\n");
					mobil[peminjam[x-1].pinjammobil].mobilada += 1;
					orang = orang - 1;
					for(i=x-1;i<orang;i++)
					{
					peminjam[i] = peminjam[i+1];
					}
					break;
					}
				}
				while (1);
			}
			continue;
		}
		else
		{
			break;
		}
	}
	while(1);
	printf("\nTekan Enter untuk kembali ke menu awal");
	getchar();
	getchar();
	pageMenu(peminjam,mobil,orang);
}

//FUNGSI UNTUK ERROR HANDLING
int getInputInteger(const char *teks, int MIN, int MAX)
{
    char input[100];

    printf("%s (%d-%d) : ", teks, MIN, MAX);
    scanf("%s", &input);

    if(isValid(input) && MIN <= atoi(input) && atoi(input) <= MAX){
        return atoi(input);
    } else
        return getInputInteger(teks, MIN, MAX);
}

//FUNGSI UNTUK MEMBANDINGKAN INPUT DENGAN PILIHAN YANG TERSEDIA
int isValid(char input[])
{
    int length = strlen (input);
    int i = 0;
    for (i=0;i<length; i++)
        if (!isdigit(input[i]))
            return 0;
    return 1;
}


//FUNGSI HELP (APABILA USER  BINGUNG DENGAN FITUR DAN APLIKASI)
int pagehelp(struct peminjam_mobil peminjam[],struct car mobil[],int orang)
{
    system("cls");
    printf("Selamat datang di program Penyewaan Mobil\noleh Adam Doni dan Ade Hendra");
    printf("\n\nKetika Program ini dijalankan maka akan muncul menu seperti ini\n");
    printf("||Silahkan Pilih Menu : \n||1. Penyewaan Mobil\n||2. Cek Peminjam Mobil\n||3. Cek Unit Mobil\n||4. Mengembalikan Kendaraan\n||5. Help\n||6. Keluar\n");
    printf("\n\nAnda dapat memilih salah satu dari pilihan 1 hingga 6\n");
    printf("program nomor 1 adalah program untuk menyewa mobil.\ntiap ada penyewa baru maka silahkan masukkan nama penyewa\ndan silahkan pilih mobil yang akan disewa jika anda ingin mengecek apakah mobil masih available\ndapat anda cek pada pilihan 'cek mobil'");
    printf("\n");
    printf("Ketika anda memilih menu '1' maka anda akan diarahkan untuk memasukkan nama user\n|Silahkan masukkan nama anda : Adam (Contoh)|\nkemudian akan ditampilkan list mobil yang dapat disewa\nSelamat datang Adam,berikut daftar mobil yang bisa disewa\n\n|No.     Daftar Mobil :      Jumlah Unit :       Harga sewa perhari :|\n|1               Avanza               1    Rp.              5000     |\n|2               Kijang               1    Rp.             10000     |\n|3                Xenia               1    Rp.             15000     |\n|4                  APV               1    Rp.             20000     |");
    printf("\nSilahkan pilih 1 untuk kembali ke menu dan pilih 2 untuk keluar dari program\n");
	printf("setelah itu anda akan diarahkan untuk memilih mobil mana yang akan disewa\n|Silahkan pilih nomor dari mobil yang diinginkan : 3 (contoh)|\n\njika anda menekan nomor '2' maka akan muncul \n|No. Nama :       Mobil yang dipinjam :           Tagihan :|\n|1   Adam            Kijang                       30000    |\n");
	printf("\nsilahkan pilih nomor 3 untuk cek ketersediaan unit mobil yang masil available untuk dipinjam.\n|No.     Daftar Mobil :      Jumlah Unit :       Harga sewa perhari :|\n|1               Avanza               1                   5000       |\n|2               Kijang               0                  10000       |\n|3                Xenia               1                  15000       |\n|4                  APV               1                  20000       |");
	printf("\n\nsilahkan pilih nomor 4 untuk mengembalikan mobil. akan ditampilkan\n|waktu ke-1 = 286.80 detik                                                                     |\n|                                                                                              |\n|Berikut Merupakan daftar mobil yang dipinjam beserta peminjamnya.                             |\n|No.  Nama:       Mobil:      Durasi Peminjam :   Telah Dibayar:  Keterlambatan:  Denda:       |\n|1     Adam       Kijang          3 Hari          30000           9 Hari          9000 Rupiah  |\n");
	printf("\nTekan Enter untuk kembali ke menu awal");
	getchar();
	getchar();
}

//FUNGSI UNTUK MENGHENTIKAN PROGRAM (EXIT)
int pageExit(){
    printf("\n\nSayonara: Sampai Berjumpa Lagi");
    return 0;
}

//FUNGSI UNTUK DELAY WAKTU PENAMPILAN HASIL PENGECEKAN MOBIL
void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

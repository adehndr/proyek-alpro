#include <stdio.h>
#include "fungsikalkulasi.h"
#include <stdlib.h>
#include <string.h>         //Fungsi untuk  mengolah string
#include <time.h>           //Fungsi untuk mengaplikasikan waktu
#include <ctype.h> 
#define max 100
#define min 1
#define mid 4
struct car
{
	char listmobil[max];
	int mobilada;
	int hargam;
	
};
struct peminjam_mobil
{
	char nama[max];
	int pinjammobil;
	int tagihan;
};
void pageMenu(struct peminjam_mobil peminjam[],struct car mobil[],int orang);
void pagesewamobil(	struct peminjam_mobil peminjam[],struct car mobil[],int orang);
void pagecekpeminjam(struct peminjam_mobil peminjam[],struct car mobil[],int orang);
void pagecekmobil(struct peminjam_mobil peminjam[],struct car mobil[],int orang);
int getInputInteger(const char *teks, int MIN, int MAX);
int pageExit();
int isValid(char input[]);
void delay(int number_of_seconds);
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
    printf("Silahkan Pilih Menu : \n1. Penyewaan Mobil\n2. Cek Peminjam Mobil\n3. Cek Unit Mobil\n4. Keluar\n");
        int menu = getInputInteger("Menu", 1, 100);
    if(menu == 1)
        pagesewamobil(peminjam,mobil,orang);
    else if(menu == 2)
		pagecekpeminjam(peminjam,mobil,orang);	
    else if(menu == 3)
        pagecekmobil(peminjam,mobil,orang);
    else if(menu == 4)
        pageExit();
    else
        pageMenu(peminjam,mobil,orang);
}
void pagesewamobil(struct peminjam_mobil peminjam[],struct car mobil[],int orang)
{
	int i,total,x,y,z;
	printf("Silahkan masukkan nama anda : ");
	scanf("%s", peminjam[orang].nama);
	printf("Selamat datang %s,berikut daftar mobil yang bisa disewa\n",peminjam[orang].nama);
	printf("\nNo.     Daftar Mobil :      Jumlah Unit :       Harga sewa perhari :\n");	
	for(i=0;i<4;i++)    //Membuat loop untuk menuliskan list mobil yang tersedia
	{
		printf("%d      %15s        %8d     %18d\n", i+1,mobil[i].listmobil, mobil[i].mobilada,mobil[i].hargam);//Menampilkan dalam sistem list mobil
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
			printf("Transaksi berhasil\n");
			orang++;
			break;
		}
	}
	while (1);
	delay(3);
	pageMenu(peminjam,mobil,orang);	
}

void pagecekpeminjam(struct peminjam_mobil peminjam[],struct car mobil[],int orang)
{
	int i;
	printf("No. Nama : \t Mobil yang dipinjam :  \t Tagihan : \n");
	for(i=0;i<orang;i++)
	{
		printf("%d\t %s \t\t %s \t\t\t %d \n", i+1,peminjam[i].nama,mobil[peminjam[i].pinjammobil].listmobil,peminjam[i].tagihan);
	}
	delay(3);
	pageMenu(peminjam,mobil,orang);	
}

void pagecekmobil(struct peminjam_mobil peminjam[],struct car mobil[],int orang)
{
	int i,result;
	char c1 = 89;
	printf("No.     Daftar Mobil :      Jumlah Unit :       Harga sewa perhari :\n");
	for(i=0;i<4;i++)    //Membuat loop untuk menuliskan list mobil yang tersedia
	{
	printf("%d      %15s        %8d     %18d\n", i+1,mobil[i].listmobil, mobil[i].mobilada,mobil[i].hargam);//Menampilkan dalam sistem list mobil
	}
	printf("\nTunggu untuk ke menu awal");
	delay(3);
	pageMenu(peminjam,mobil,orang);
	}

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

int isValid(char input[])
{
    int length = strlen (input);
    int i = 0;
    for (i=0;i<length; i++)
        if (!isdigit(input[i]))
            return 0;
    return 1;
}

int pageExit(){
    printf("\n\nSayonara: Sampai Berjumpa Lagi");
    return 0;
}

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

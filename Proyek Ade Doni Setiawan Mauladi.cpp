/******************************************************************************

                            Algoritma dan Pemrgraman
                     Project sebelum Ujian Tengah Semester
                Algoritma Aplikasi Sistem Penyewaan (rental) Mobil
                                    oleh:
                    Adam Doni Mauladi            1706037144
                    Ade Hendra Setiawan Nugraha  1706037106

*******************************************************************************/



//INPUT LIBRARY
#include <stdio.h>      //librari standar
#define MAX 100         //Mendefinisikan bahwa MAX=100
#include "fungsikalkulasi.h" //Fungsi baru dari header yang kami susun sendiri
#include <stdlib.h>
#include <string.h>         //Fungsi untuk  mengolah string
#include <time.h>           //Fungsi untuk mengaplikasikan waktu
#include <ctype.h>      //Fungsi untuk mengaktifkan beberapa kode

//Pendefinisian Fungsi Modular dalam algoritma
int getInputInteger(const char *teks, int min, int max);
int isValid(char input[]);
int pageSewamobil(char listmobil[][100],int mobilada[],int hargam[],char peminjam[10][100],int orang);
int pageCekmobil(char listmobil[][100],int mobilada[],int hargam[],char peminjam [10][100],int orang);
void delay(int number_of_seconds);
void pageMenu(int mobilada[],char peminjam[10][100],int orang);
int fungsiPinjam(char peminjam[][100],int orang,int mobilada[]);
int pageExit();


//FUNGSI UTAMA
int main()
{   //Mendefinisikan Variabel yang digunakan
	int i,mobilada[4],orang = 0;
	char peminjam[MAX][MAX];
	for(i=0;i<4;i++)
	{
	mobilada[i] = 1;
	}
	pageMenu(mobilada,peminjam,orang);
	return 0;
}

void pageMenu(int mobilada[],char peminjam[10][100],int orang){
	system("cls");
	char listmobil[MAX][MAX] = {"Avanza", "APV", "Xenia", "Kijang"};
	int hargam[MAX] = {10000,20000,10000,5000};
	int total;
    printf("Silahkan Pilih Menu : \n1. Penyewaan Mobil\n2. Cek daftar Mobil\n3. Cek Peminjam Mobil\n4. Keluar\n");
        int menu = getInputInteger("Menu", 1, 100);
    if(menu == 1)
        pageSewamobil(listmobil,mobilada,hargam,peminjam,orang);
    else if(menu == 2)
    	pageCekmobil(listmobil,mobilada,hargam,peminjam,orang);
    else if(menu == 3)
        fungsiPinjam(peminjam,orang,mobilada);
    else if(menu == 4)
        pageExit();
    else
        pageMenu(mobilada,peminjam,orang);
}


int pageSewamobil(char listmobil[][100],int mobilada[],int hargam[],char peminjam[10][100],int orang)
{
	int i,x,y,z,total;
	fflush(stdin);
	printf("Silahkan Masukkan Nama Anda :");
	gets(peminjam[orang]);
	orang++;
	//fungsiPinjam(peminjam,orang);
	printf("Selamat datang %s,berikut daftar mobil yang bisa disewa\n",peminjam[orang]);
	printf("\nNo.     Daftar Mobil :      Jumlah Unit :       Harga sewa perhari :\n");
	for(i=0;i<4;i++)    //Membuat loop untuk menuliskan list mobil yang tersedia
	{
		printf("%d      %15s        %8d     %18d\n", i+1,listmobil[i], mobilada[i],hargam[i]);//Menampilkan dalam sistem list mobil
	}

	do
	{
	printf("Silahkan pilih mobil yang diinginkan : ");
	scanf("%d", &x);//Memasukan nomor mobil yang diinginkan
	getchar();
	if (x > 4)
		{
			continue;
		}
	else
	{
		if (mobilada[x-1] == 0)
		{
			printf("Mobil yang anda pilih tidak tersedia\n");
			printf("Silahkan memilih mobil yang lain\n\n");
			continue;
		}
		else
		{
			break;
		}

	}
	}
	while(1);
	for (i=0;i<4;i++)
	{
	if(i == x-1)
		{
			mobilada[i] = mobilada[i] - 1;
		}
	}
	printf("Mau sewa berapa hari : ");
	scanf("%d",&y);
	getchar();
	total =y*hargam[x-1];
	printf("\n1 Unit mobil %s telah disewa dengan harga %d  \n\n", listmobil[x-1],total);
		for(i=0;i<4;i++)
	{
		printf("%d %10s       %7d\n",i+1, listmobil[i], mobilada[i]);
	}
	do
	{
		printf("Silahkan masukan jumlah uang untuk membayar : ");
		scanf("%d",&z);
		getchar();
		fungsikalkulasi(z, total);
		if ( fungsikalkulasi(z, total)< 0)
		{
			printf("Kembalian : %d \n",z);
			printf("Uang Kurang\n");
			continue;
		}
		else
		{
			printf("Kembalian : %d \n",fungsikalkulasi(z, total));
			printf("Transaksi berhasil\n");
			break;
		}
	}
	while (1);
	delay(3);
	pageMenu(mobilada,peminjam,orang);
}

int pageCekmobil(char listmobil[][100],int mobilada[],int hargam[],char peminjam[10][100],int orang)
{
	int i,result;
	char c1 = 89;
	printf("No.     Daftar Mobil :      Jumlah Unit :       Harga sewa perhari :\n");
	for(i=0;i<4;i++)    //Membuat loop untuk menuliskan list mobil yang tersedia
	{
	printf("%d      %15s        %8d     %18d\n", i+1,listmobil[i], mobilada[i],hargam[i]);//Menampilkan dalam sistem list mobil
	}
	printf("\nTunggu untuk ke menu awal");
	delay(3);
	pageMenu(mobilada,peminjam,orang);
	}
int fungsiPinjam(char peminjam[10][100],int orang,int mobilada[])
	{   int i;
        printf("Daftar Peminjam : \n");
        for(i=0;i<orang;i++)
        {
            printf("No.%d %s\n",i+1,peminjam[i]);
        }
        printf("\nTunggu untuk kembali ke menu awal");
        delay(3);
        pageMenu(mobilada,peminjam,orang);
	}

int getInputInteger(const char *teks, int min, int max)
{
    char input[100];

    printf("%s (%d-%d) : ", teks, min, max);
    scanf("%s", &input);

    if(isValid(input) && min <= atoi(input) && atoi(input) <= max){
        return atoi(input);
    } else
        return getInputInteger(teks, min, max);
}

int isValid(char input[])
{
    int length = strlen (input);
    for (int i=0;i<length; i++)
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

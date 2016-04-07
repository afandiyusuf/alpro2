#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
struct{
char KB[20];
char NB[10];
float STOK;
}DATA;

char lastBarang[20] = "init";
float totalBarang;

void readData();
FILE *FN;

void readData(){
FN=fopen("barang.txt","rt");
	
	fscanf(FN,"%s\t%s\t%s\t\%f\t",DATA.KB,DATA.NB,&DATA.STOK);
	
	if(feof(FN)){
		printf ("File kosong\n");
	}else{
		while(! feof(FN)){
			
			if( strcmp(lastBarang,"init")==0)
			{
				strcpy(lastBarang,DATA.KB);	
			}
			
			if(strcmp(DATA.KB,lastBarang)==0){
				totalBarang += 1;
			}else {	
				printf("Kode barang %s : Jumlah barang = %f \n", DATA.KB,totalBarang);
				strcpy(lastBarang,DATA.KB);
			}
			
	fscanf(FN,"%s\t%s\t%s\t",DATA.KB,DATA.NB,&DATA.STOK);
	}
	printf("Proses penghitungan Berhasil\n");
}
fclose(FN);
}

int main(){
	readData();
//	tampildata();
}



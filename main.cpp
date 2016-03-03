#include<iostream>
#include<stdio.h>
#include<string>
#include<conio.h>

struct{
	char c,
	ch,
	file1[20],
	file2[20],
	file3[20],
	input1[20],
	input2[25];
}file;

void InputData();
void MergingData();

FILE *PF1,*PF2,*ft;

int main()
{
	
	InputData();
	MergingData();
	
	return 0;
}

void InputData()
{
	
	printf("Membuat 2 file  yang akan di merging \n");
	
	/*Inputkan data pada file pertama*/
	printf("Masukkan input untuk file 1 \n");
	gets(file.input1);
	
	/*Inputkan data pada file kedua */
	printf("Masukkan input untuk file 2 \n");
	gets(file.input2);
	
	//jika salah satu file ternyata tidak ada maka akan menghasilkan null
	if((PF1 = fopen("file1.txt","w")) == NULL || (PF2 = fopen("file2.txt","w"))== NULL){
		
		//keluarkan peringatan error
		printf("File tidak ditemukan");
		exit(0);
	}else{
		
		//memasukkan string ke dalam masing masing file (fputs)
		fputs(file.input1,PF1);
		fputs(file.input2,PF2);
	}
	
	
	fclose(PF1);
	fclose(PF2);
}

void MergingData()
{
	printf("Masukkan nama file yang digunakan untuk menyimpan file baru gabungan dari file1 dan file2 \n");
	gets(file.file3);
	
	PF1 = fopen("file1.txt","r");
	PF2 = fopen("file2.txt","r");
	
	if(PF1 == NULL || PF2 == NULL)
	{
		perror("error");
		printf("ketik apapun untuk keluar");
		getch();
	}
	
	ft = fopen(file.file3,"w");
	if(ft == NULL)
	{
		perror("error");
		printf("ketik apapun untuk keluar");
		
	}
	
	//proses penggabungan file
	while((file.ch = fgetc(PF1)) != EOF)
	fputc(file.ch,ft);
	while((file.ch=fgetc(PF2)) != EOF)
	fputc(file.ch,ft);
	
	printf("2 file telah berhasil digabung file %s \n",file.file3);
	
	fclose(PF1);
	fclose(PF2);
	fclose(ft);
	
}

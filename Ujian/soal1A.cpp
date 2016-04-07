#include<iostream>
#include<stdio.h>
#include<string.h>

struct{
	char npm[10];
	char nm[10];
	char mk[10];
	char nl[10];
}mhs;

FILE *mhsFile,*file1,*file2;





int main(){
	
	mhsFile = fopen("soal1/mahasiswa.txt","rw");
	file1 = fopen("soal1/file1.txt","w+");
	file2 = fopen("soal1/file2.txt","w+");
	fscanf(mhsFile,"%s\t%s\t%s\t%s\t\n",mhs.npm,mhs.nm,mhs.mk,mhs.nl);
	if(feof(mhsFile)){
		printf("FIle kosong \n");
	}else{
		while(!feof(mhsFile))
		{
			fscanf(mhsFile,"%s\t%s\t%s\t%s\t\n",mhs.npm,mhs.nm,mhs.mk,mhs.nl);
			if(strcmp(mhs.mk,"Alpro2")==0)
			{
				fprintf(file1,"%s\t%s\t%s\t%s\t\n",mhs.npm,mhs.nm,mhs.mk,mhs.nl);
			}else{
				
				fprintf(file2,"%s\t%s\t%s\t%s\t\n",mhs.npm,mhs.nm,mhs.mk,mhs.nl);
			}
			
				
		//	printf("%s\t%s\t%s\t%s\t",mhs.npm,mhs.nm,mhs.mk,mhs.nl);
		}
		printf("Penggabungan selesai");
		
	}
	fclose(mhsFile);
	fclose(file1);
	fclose(file2);
			
	return 0;
}

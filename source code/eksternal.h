#ifndef _EKSTERNAL_H_
#define _EKSTERNAL_H_
#include <time.h>
#include "listeks.h"
#include "capslock.h"
void pickword(list *L,char b[255], int round, int urutsudah[]){
	char a[14];
	srand(time(NULL));
	FILE *baca=fopen("kata.txt","r");
	int i=0;
	if(!baca){
		printf("data tidak ada");
	}else{
		while(!feof(baca)){
			i++;			
			fscanf(baca,"%s\n",a);
			fgets(b,255,baca);
		}
	}
	fclose(baca);
	baca=fopen("kata.txt","r");
	int l,N=i;
	checkrandom:
		i=rand()%N+1;
		for(l=0;l<round;l++){
			if(i==urutsudah[l])
				goto checkrandom;
		}
	
	urutsudah[round]=i;
	
	int j=0;
	while(!feof(baca)){
		j++;
		fscanf(baca,"%s\n",a);//fflush(stdin);
		fgets(b,255,baca);//fflush(stdin);
		if(j==i){
			break;
		}
	}
	j=0;
	while(a[j]!='\0'&&a[j]!='\n'){
		convertcapslock(&a[j]);
		InsertLast(L,alokasi(a[j]));
		j++;
	}
}

void printisikamus(){
	char a[14], b[255];
	FILE *cetak=fopen("kata.txt","r");
	int i=1;
	while(!feof(cetak)){
		fscanf(cetak,"%s\n",a);
		fgets(b,255,cetak);
		printf("%d.%s\n",i,a);
		i++;
	}
	fclose(cetak);
}

void putword(){
	char a[14],b[255];
	FILE *baca=fopen("kata.txt","a");
	int i=0;
	printf("Masukkan kata: ");
	inputkata:
		i=0;
		//input kata

		do{
			scanf("%c",&a[i]);
			if(a[i]!='\n')
				i++;
		}while(a[i]!='\n');
		a[i]='\0';
		if(i>=14||i<6)
			goto inputkata;
	
	i=0;
	//input hint
	printf("Masukkan Hint: ");
	do{
		scanf("%c",&b[i]);
		if(b[i]!='\n')
			i++;
	}while(b[i]!='\n');
	b[i]='\0';
	fprintf(baca, "\n%s\n%s",a,b);
	
	fclose(baca);
}

void deleteisi(){
	listeks L;
	int x;
	CreateEmptyEks(&L);
	char a[14],b[255];
	FILE *read=fopen("kata.txt","r");
	//cek ada file atau tidak
	if(!read)
		printf("no file!");
	else{
		//still buggy can't run
		while(!feof(read)){
			fscanf(read,"%s\n",a);
			fgets(b,255,read);
			printf("%s\t%s\n",a,b);
			InsertLastEks(&L,alokasiEks(a,b));
		}
		//print isi
		PROSESHAPUS:
			system("cls");
			printisiEks(L,1);
			printf("Hapus Nomor (<=0 untuk berhenti): "); scanf("%d",&x);
			if(!IsEmptyEks(L)){
				if(x>NbElmntEks(L)){
					printf("Maks input %d\n", NbElmntEks(L));
					system("pause");
					goto PROSESHAPUS;
				}else if(x>0){
					delurutke(&L,x,1);
					goto PROSESHAPUS;
				}
			}else{
				printf("DATA KOSONG!\n");
			}	
	}
	FILE *ow=fopen("kata.txt","w");
	fclose(ow);
	ow=fopen("kata.txt","a");
	if(ow){
		addresseks P=L;
		while(P!=NULL){ //tadi pas presentasi bug disini pak lupa diganti !IsEmpty(P)
			fprintf(ow, "%s\n%s",isieks(P),hinteks(P));
			P=nexteks(P); //DelAwal(P)
		}
	}
	fclose(ow);
}
#endif

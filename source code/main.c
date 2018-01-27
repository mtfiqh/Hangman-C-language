#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "list.h"
#include "eksternal.h"
#include "gambarhangman.h"
#include "listscore.h"
#include "capslock.h"
boolean gameover=false;

void singlepgame(int *round, int urutsudah[], int *score){
	boolean finish=false;
	*score=*score+100;
	char digunakan[26];
	list L1,L2,L3;
	int chance =4, x=0;
	char a,b[255];
	
	CreateEmpty(&L1);CreateEmpty(&L2);CreateEmpty(&L3);
	pickword(&L1,b,*round, urutsudah);
	BuatL2(L1,&L2);
	*round=*round+1;
	
	do{
		INPUTAN:
		system("cls");
		printf("round: %d\t\tScore: %d\n",*round,*score);
		CreateEmpty(&L3);
		printgambar(chance);
		printisi(L2);

		printf("HINT :%d kata - %s\n",NbElmnt(L1),b);
		printf("INPUT: ");
		do{
			scanf("%c",&a);
			convertcapslock(&a);
			if(a!='\n')
				InsertLast(&L3,alokasi(a));
		}while(a!='\n');
		
		if(NbElmnt(L3)==NbElmnt(L1)){
			if(ceksemuaisi(L1,L3)){
				gantiisi(L1,L2,L3);
				if(chance==4)
					*score=*score+200;
				finish=true;
			}else{
				chance--;
				*score=*score-25;
			}
		}else if(NbElmnt(L3)==1){			
			int z=0;
			for(z=0;z<=x;z++){
				if(isi(L3)==digunakan[z]){
					printf("Huruf sudah digunakan\n");
					system("pause");
					goto INPUTAN;
				}
			}
			if(findchar(L1,L3)){
				printisi(L3);
				gantiisi(L1,L2,L3);
			}else{
				printf("%c Tidak Ditemukan!\n",isi(L3));system("pause");
			}
			chance--;
			*score=*score-25;
			digunakan[x]=isi(L3);
			x=x+1;
		}
		
		if(chance==0){
			finish=true;gameover=true;
		}
	}while(!finish);
	if(gameover){
		system("cls");
		printgambar(chance);
		printf("The Answer: ");printisi(L1);
	}
}

void inputscore(int score){
	char Name[4];
	List L;
	BuatKosong(&L);
	int i=0,tempscore;
	FILE *open=fopen("score.txt","r");
	if(!open){
		fclose(open);
		open=fopen("score.txt","a");
	}else{
		while(!feof(open)){
			fscanf(open,"%s\n",Name);
			fscanf(open,"%d\n",&tempscore);
			MasukAkhir(&L,Alokasi(tempscore,Name));
		}
	}
	fclose(open);
	MASUKNAMA:
	i=0;
	printf("ENTER YOUR NAME (3LETTERS): ");
	do{
		scanf("%c",&Name[i]);
		convertcapslock(&Name[i]);
		if(Name[i]!='\n')
			i++;
	}while(Name[i]!='\n');
	if(i>3){
		goto MASUKNAMA;
	}
	Name[i]='\0';
	MasukUrut(&L,score,Name);
	alamat P=First(L);
	open=fopen("score.txt","w");
	fprintf(open,"%s\n%d",Nama(P),Info(P));
	P=Kanan(P);
	while(P!=NULL){
		fprintf(open,"\n%s\n%d",Nama(P),Info(P));
		P=Kanan(P);
	}
	fclose(open);
}

int main(){
	int round=0;
				char a[4];
			int s;
	int urutsudah[5];
	int pilih;
	int score=0;
		HOME:
			system("cls");
			printf("MAIN MENU\n");
			printf("1. Mulai Game\n");
			printf("2. Setting kamus\n");
			printf("3. Lihat Leader\n");
			printf("4.Exit\n");
			printf("pilih: "); scanf("%d",&pilih);
	switch(pilih){
		case 1: 
			do{
				singlepgame(&round, urutsudah, &score);
			}while(round<5&&!gameover);
			if(gameover){
				printf("YOU LOSE!\nYour Score: %d\n",score);
			}else{
				printf("YOU WIN!\nYOU GOT: %d\n",score);
			}
			inputscore(score);
			goto HOME;
			break;
		case 2:
			settingkamus:
				system("cls");
				printf("1. Print Isi Kamus\n2. Delete Isi Kamus\n3. Tambah Isi Kamus\n4. Back\n");
				printf("pilih: "); scanf("%d",&pilih);
				switch(pilih){
					case 1: printisikamus();system("pause");goto settingkamus; break;
					case 2: deleteisi();goto settingkamus; break; //still have bug
					case 3: putword();goto settingkamus; break;
					case 4: goto HOME; break;
					default: goto settingkamus;
				}
		case 3:
			system("cls");
			FILE *open=fopen("score.txt","r");
			if(!open)
				printf("File Not Found!\n");
			else{
				int i=1;
				while(!feof(open)){
					fscanf(open,"%s\n",a);
					fscanf(open,"%d\n",&s);
					printf("%d. %s\t%d\n",i,a,s);
					i++;
				}
			}
			system("pause");
			goto HOME;
			break;
		case 4:
			return 0;
			break;
		default: goto HOME;
	}
}

#ifndef _LISTSCORE_H_
#define _LISTSCORE_H_
#include "boolean.h"
#include <string.h>
typedef int infotype;
typedef char infonama;
typedef struct tElmtlist *alamat;
typedef struct tElmtlist {
	infotype info;
	infonama nama[3];
	alamat kanan;
	alamat kiri;
} ElmtList;
typedef struct {
	alamat First;
	alamat Last;
} List;

#define Info(P) (P)->info
#define Kanan(P) (P)->kanan
#define Kiri(P) (P)->kiri
#define First(L) ((L).First)
#define Last(L) ((L).Last)
#define Nama(P) (P)->nama

boolean CekKosong(List L){
	return (First(L)==NULL&&Last(L)==NULL);
}

void BuatKosong (List *L){
	First(*L)=NULL; Last(*L)=NULL;
}

alamat Alokasi(infotype x, infonama y[]){
	alamat P;
	P=(alamat) malloc (sizeof(ElmtList));
	if(P!=NULL){
		strcpy(Nama(P),y);
		Info(P)=x;
		Kanan(P)=NULL;Kiri(P)=NULL;
	}
	return P;
}

void MasukAwal(List *L,alamat P){
	Kanan(P)=First(*L);
	if(!CekKosong(*L)){
		Kanan(Last(*L))=P;
	}else{
		First(*L)=P;
	}
	Last(*L)=P;
}

void MasukAkhir(List *L, alamat P){
	Kiri(P)=Last(*L);
	if(!CekKosong(*L)){
		Kanan(Last(*L))=P;
	}else{
		First(*L)=P;
	}
	Last(*L)=P;
}
void MasukSetelah (List *L, alamat P, alamat Prec) {
	if (Kanan(Prec) != NULL) {
		Kiri(Kanan(Prec)) = P;
	} else { 
		Last(*L) = P;
	}
	Kanan(P) = Kanan(Prec);
	Kiri(P) = Prec;
	Kanan(Prec) = P;
}
void MasukSebelum (List *L, alamat P, alamat Succ){
	if (Kiri(Succ) != NULL) { /* Succ bukan elemen pertama */
		Kanan(Kiri(Succ)) = P;
	} else { /* Succ elemen pertama */
		First(*L) = P;
	}
	Kiri(P) = Kiri(Succ);
	Kanan(P) = Succ;
	Kiri(Succ) = P;
}
void MasukUrut (List *L, infotype X, infonama Y[]){
	alamat Q=Alokasi(X,Y);
	alamat P=First(*L);
	if(CekKosong(*L)){
		MasukAwal(L, Q);
	}else{
		while(Kanan(P)!=NULL){
			if(X>=Info(P)){
				break;
			}
			P=Kanan(P);
		}
		if(X>=Info(P)){
			MasukSebelum(L,Q,P);
		}else{
			MasukSetelah(L,Q,P);
		}
	}
}	

void CetakIsi(List L){
	if(!CekKosong(L)){
		alamat P=First(L);
		int i=1;
		while(P!=NULL){
			printf("%d.%s\t\t%d\n",i,Nama(P),Info(P));
			P=Kanan(P);
			i++;
		}
	}
}
#endif

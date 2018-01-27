#ifndef _LIST_H_
#define _LIST_H_

#include "boolean.h"

typedef char infodata;
typedef struct listlink *address;
typedef struct listlink {
	infodata isi;
	address next;
}linked;

typedef address list;

#define next(P) (P)->next
#define isi(P) (P)->isi

void CreateEmpty (list *L){
	*L=NULL;
}

address alokasi (infodata y){
	address P;
	P=(address) malloc (sizeof(linked));
	if(P!=NULL){
		next(P)=NULL;
		isi(P)=y;
	}
	return P;
}

boolean IsEmpty(list L){
	return ((L)==NULL);
}

int NbElmnt(list L){
	if(L==NULL)
		return 0;
	else
		return 1+(NbElmnt(next(L)));
}

void InsertFirst(list *L, address P){
	next(P)=*L;
	*L=P;
}

void InsertLast(list *L, address P){
	if(IsEmpty(*L))
		InsertFirst(L,P);
	else if(next(*L)==NULL){
		next(*L)=P;
	}else{
		InsertLast(&(next(*L)),P);
	}
}

void printisi(list P){
	if(P!=NULL){
		printf("%c ",isi(P));
		printisi(next(P));
	}else{
		printf("\n");
	}
}

void BuatL2(list P, list *L2){
	if(P!=NULL){
		InsertLast(L2, alokasi('#'));
		BuatL2(next(P), L2);
	}
}
void gantiisi2(list L1, list L2, list L3){
	if(L1!=NULL){
		if(isi(L3)==isi(L1)){
			isi(L2)=isi(L3);
		}
		gantiisi2(next(L1),next(L2),L3);
	}
}
void gantiisi(list L1, list L2,list L3){
	if(L3!=NULL){
		gantiisi2(L1,L2,L3);
		gantiisi(L1,L2,next(L3));
	}
}
boolean ceksemuaisi(list L,list L2){
	if(L!=NULL){
		if(isi(L)==isi(L2)){
			return ceksemuaisi(next(L), next(L2));
		}else{
			return 0;
		}
	}else{
		return 1;
	}
}

boolean findchar(list L, list L2){
	if(L==NULL)
		return 0;
	else{
		if(isi(L)==isi(L2))
			return 1;
		else
			findchar(next(L),L2);
	}
}

#endif
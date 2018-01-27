#ifndef _LISTEKS_H_
#define _LISTEKS_H_
#include "boolean.h"
#include <string.h>
typedef char infodata;
typedef struct listlinkeks *addresseks;
typedef struct listlinkeks {
	infodata isieks[14];
	infodata hinteks[255];
	addresseks nexteks;
	addresseks preveks;
}linkedeks;

typedef addresseks listeks;

#define nexteks(P) (P)->nexteks
#define isieks(P) (P)->isieks
#define hinteks(P) (P)->hinteks
#define preveks(P) (P)->preveks

void CreateEmptyEks (listeks *L){
	*L=NULL;
}

addresseks alokasiEks (infodata x[], infodata y[]){
	addresseks P;
	P=(addresseks) malloc (sizeof(linkedeks));
	if(P!=NULL){
		nexteks(P)=NULL;
		preveks(P)=NULL;
		strcpy(isieks(P),x);
		strcpy(hinteks(P),y);
	}
	return P;
}

boolean IsEmptyEks(listeks L){
	return ((L)==NULL);
}

void InsertFirstEks(listeks *L, listeks P){
	if(IsEmptyEks(*L)){
		*L=P;
	}else{
		nexteks(P)=*L;
		preveks(*L)=P;
		*L=P;
	}
}

void InsertLastEks(listeks *L, addresseks P){
	if(IsEmptyEks(*L))
		InsertFirstEks(L,P);
	else if(nexteks(*L)==NULL){
		preveks(P)=*L;
		nexteks(*L)=P;
	}else{
		InsertLastEks(&(nexteks(*L)),P);
	}
}

void DelFirstEks(listeks *L){
	if(NbElmntEks(*L)==1){
		CreateEmptyEks(L);
	}else{
		addresseks P=*L;
		*L=nexteks(*L);
		nexteks(preveks(*L))=NULL;
		preveks(*L)=NULL;
	}
}
void DelLastEks(listeks *L){
	if(nexteks(*L)==NULL){
		addresseks P=*L;
		nexteks(preveks(P))=NULL;
		preveks(P)=NULL;
		free(P);
	}else{
		DelLastEks(&(nexteks(*L)));
	}
}


void printisiEks(listeks P,int i){
	if(P!=NULL){
		printf("%d.",i);
		printf("%s\n",isieks(P));
		//printf("%s\n\n",hinteks(P));
		printisiEks(nexteks(P),i+1);
	}else{
		printf("\n");
	}
}
int NbElmntEks(listeks L){
	if(L==NULL)
		return 0;
	else
		return 1+(NbElmntEks(nexteks(L)));
}

void delurutke(listeks *L,int x,int i){
	if(*L!=NULL){
		if(i==x){
			if(preveks(*L)==NULL){
				DelFirstEks(L);
			}else if(nexteks(*L)==NULL){
				DelLastEks(L);
			}else{
				
				addresseks P=*L;
				nexteks(preveks(P))=nexteks(P);
				preveks(nexteks(P))=preveks(P);
				nexteks(P)=NULL;
				preveks(P)=NULL;
				free(P);
			}
		}else{
			delurutke(&nexteks(*L),x,i+1);
		}
	}
}
#endif

#ifndef _GAMBARHANGMAN_H_
#define _GAMBARHANGMAN_H_

void printgambar(int chance){

	if(chance==4){
		printf("=====\n");
		printf("I\n");
		printf("I\n");
		printf("I\n");
		printf("I\n");
		printf("I\n");
	}else if(chance==3){
		printf("=====\n");
		printf("I   O\n");
		printf("I\n");
		printf("I\n");
		printf("I\n");
		printf("I\n");
	}else if(chance==2){
		printf("=====\n");
		printf("I   O\n");
		printf("I   |\n");
		printf("I\n");
		printf("I\n");
		printf("I\n");
	}else if(chance==1){
		printf("=====\n");
		printf("I   O\n");
		printf("I  /|/\n");
		printf("I\n");
		printf("I\n");
		printf("I\n");
	}else{
		printf("=====\n");
		printf("I   O\n");
		printf("I  /|/\n");
		printf("I  //\n");
		printf("I\n");
		printf("I\n");
	}
}
#endif
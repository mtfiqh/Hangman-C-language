#ifndef _CAPSLOCK_H_
#define _CAPSLOCK_H_
void convertcapslock(infodata *y){
	switch(*y){
		case 'a': *y='A'; break;
		case 'b': *y='B'; break;
		case 'c': *y='C'; break;
		case 'd': *y='D'; break;
		case 'e': *y='E'; break;
		case 'f': *y='F'; break;
		case 'g': *y='G'; break;
		case 'h': *y='H'; break;
		case 'i': *y='I'; break;
		case 'j': *y='J'; break;
		case 'k': *y='K'; break;
		case 'l': *y='L'; break;
		case 'm': *y='M'; break;
		case 'n': *y='N'; break;
		case 'o': *y='O'; break;
		case 'p': *y='P'; break;
		case 'q': *y='Q'; break;
		case 'r': *y='R'; break;
		case 's': *y='S'; break;
		case 't': *y='T'; break;
		case 'u': *y='U'; break;
		case 'v': *y='V'; break;
		case 'w': *y='W'; break;
		case 'x': *y='X'; break;
		case 'y': *y='Y'; break;
		case 'z': *y='Z'; break;
		default: break;
	}
}
#endif

#include "printf.h"

int main ()
{
	char tab[] = "supa sayajin";
	int i = 255;

	printf("test\n");
	printf("width avec string -0:/%-0s\n", tab);
	printf("width avec string -:/%-s\n", tab);
	printf("width avec string 0:/%0s\n", tab);
	printf("width avec string 25:/%25s\n", tab);
	printf("width avec string 25 et -:/%-25s\n", tab);
	printf("width avec int :/%#-9o\n", i);
	printf("width avec string etoiles:/%*s\n", tab);
}
//FLAGS 
// # = affiche 0 devant les octal ou 0x devnt les hex
// ' ' 
// 0 affiche des 0 a la place des esapce de width
//  - met les espace de width a droite

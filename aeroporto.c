#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int geraRand(int min, int max);

int main ()
{
	int teste;

	teste = geraRand(0,3);
	
	printf("%d", &teste);

	return 0;
}

int geraRand(int min, int max)
{
	int r;

	srand(time(NULL));
	r=min+rand()%(max-min+1);

	return r;
}

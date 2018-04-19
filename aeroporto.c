#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct noh {
	int info;
	struct noh* prox;
};
typedef struct noh Node;

struct fila {
	Node* inicio;
	Node* fim;
};
typedef struct fila Fila;

Fila* cria_fila();
int geraRand(int min, int max);

int main ()
{
	int teste;

	teste = geraRand(0,3);
	
	printf("%d", &teste);

	return 0;
}

Fila* cria_fila()
{
	Fila* fila = (Fila*) malloc(sizeof(Fila));

	fila->inicio = fila->fim = NULL;

	return fila;

}

int geraRand(int min, int max)
{
	int r;

	srand(time(NULL));
	r=min+rand()%(max-min+1);

	return r;
}

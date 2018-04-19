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
Node* insere_fim (Node* fim, int v);
void insere (Fila* f, int v);
int geraRand(int min, int max);

int main ()
{
	int teste;

	//teste = geraRand(0,3);
	
	//printf("%d", &teste);

	return 0;
}

Fila* cria_fila()
{
	Fila* fila = (Fila*) malloc(sizeof(Fila));

	fila->inicio = fila->fim = NULL;

	return fila;

}

Node* insere_fim (Node* fim, int v)
{
	Node* no = (Node*) malloc(sizeof(Node));

	no->info = v;
	no->prox = NULL;

	if(fim != NULL)
		fim->prox = no;
	
	return no;
}

void insere (Fila* f, int v)
{
	f->fim = insere_fim(f->fim, v);

	if(f->inicio == NULL)
		f->inicio = f->fim;
}

int geraRand(int min, int max)
{
	int r;

	srand(time(NULL));
	r=min+rand()%(max-min+1);

	return r;
}

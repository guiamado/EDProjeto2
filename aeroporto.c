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
Node* retira_inicio (Node* ini);
int vazia (Fila* f);
int retira (Fila* f);
void libera(Fila* f);
void imprime_fila (Fila* f);
int geraRand(int min, int max);

int main ()
{
	Fila* f = cria_fila ();

	insere(f,2);
	insere(f,5);
	insere(f,1);
	insere(f,4);
	imprime_fila(f);
	retira(f);
	printf("\n");
	imprime_fila(f);
	retira(f);
	printf("\n");
	imprime_fila(f);
	libera(f);	

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

Node* retira_inicio (Node* ini)
{
	Node* no = ini->prox;
	free(ini);
	return no;
}

int vazia (Fila* f)
{
	return (f->inicio == NULL);
}

int retira (Fila* f)
{
	int v;

	if(vazia(f))
	{
		printf("A Fila esta vazia!!");
		return 0;
	}

	v = f->inicio->info;

	f->inicio = retira_inicio(f->inicio);

	if (f->inicio ==NULL)
	{
		f->fim = NULL;
	}
}

void libera(Fila* f)
{
	Node* no = f->inicio;

	while (no != NULL)
	{
		Node* t = no->prox;
		free(no);
		no = t;
	}

	free(f);
}

void imprime_fila (Fila* f)
{
	Node* no;

	for (no = f->inicio; no != NULL; no = no->prox)
	{
		printf("%d", no->info);
	}
}


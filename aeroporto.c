#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct noh {
	int info;
	struct noh* prox;
};
typedef struct noh Node;

struct noh2 {
	int info;
	struct noh2* prox;
	struct noh2* ant;
};
typedef struct noh2 Node2;

struct fila {
	Node* inicio;
	Node* fim;
};
typedef struct fila Fila;

struct fila2 {
	Node2* inicio;
	Node2* fim;
};
typedef struct fila2 Fila2;

//-------------------------------
Fila* cria_fila();
Node* insere_fim (Node* fim, int v);
void insere (Fila* f, int v);
Node* retira_inicio (Node* ini);
int vazia (Fila* f);
int retira (Fila* f);
void libera(Fila* f);
void imprime_fila (Fila* f);
int geraRand(int min, int max);
//-------------------------------
Node2* insere2_inicio (Node2* f, int v);
Node2* insere2_fim (Node2* f, int v);
void insereIni (Fila2* f, int v);
void insereFim (Fila2* f, int v);
Node2* retira2_inicio (Node2* inicio);
Node2* retira2_fim (Node2* fim);
int retiraIni (Fila2* f);
int retiraFim (Fila2* f);
void libera2 (Fila2* f);
int vazia2 (Fila2* f);
//-------------------------------
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

//-------------------------------
Node2* insere2_inicio (Node2* inicio, int v)
{
	Node2* no = (Node2*) malloc(sizeof(Node2));

	no->info = v;
	no->prox = inicio;
	no->ant = NULL;

	if (inicio != NULL)
		inicio->ant = no;
	return no;
}

Node2* insere2_fim (Node2* fim, int v)
{
	Node2* no = (Node2*) malloc(sizeof(Node2));

	no->info = v;
	no->prox = NULL;
	no->ant = fim;

	if (fim != NULL)
		fim->prox = no;
	return no;
}

void insereIni (Fila2* f, int v)
{
	f->inicio = insere2_inicio(f->inicio,v);
	if (f->fim == NULL)
		f->fim = f->inicio;
}

void insereFim (Fila2* f, int v)
{
	f->fim = insere2_fim(f->fim,v);
	if (f->fim == NULL)
		f->inicio = f->fim;
}

Node2* retira2_inicio (Node2* inicio)
{
	Node2* no = inicio->prox;
	if (no != NULL)
		no->ant = NULL;
	free(inicio);
	return no;
}

Node2* retira2_fim (Node2* fim)
{
	Node2* no = fim->ant;
	if (no != NULL)
		no->prox = NULL;
	free(fim);
	return no;
}

int retiraIni (Fila2* f)
{
	int v;

	if (vazia2(f))
	{
		printf("Fila Vazia!! \n");
		return 0;
	}

	v = f->inicio->info;
	f->inicio = retira2_inicio(f->inicio);
	if (f->inicio == NULL)
		f->fim = NULL;
	return v;
}

int retiraFim (Fila2* f)
{
	int v;

	if (vazia2(f))
	{
		printf("Fila Vazia!! \n");
		return 0;
	}

	v = f->fim->info;
	f->fim = retira2_fim(f->fim);
	if (f->fim == NULL)
		f->inicio = NULL;
	return v;
}

void libera2(Fila2* f)
{
	Node2* no = f->inicio;

	while (no != NULL)
	{
		Node2* t = no->prox;
		free(no);
		no = t;
	}

	free(f);
}

int vazia2 (Fila2* f)
{
	return (f->inicio == NULL);
}

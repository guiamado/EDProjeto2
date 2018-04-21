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

//-------------------------------
struct informa {
	int NomeVoo;
	int comb;
};
typedef struct informa info;
//-------------------------------

struct noh2 {
	struct informa info;
	struct noh2* prox;
	struct noh2* ant;
};
typedef struct noh2 Node2;

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

Fila2* cria_fila2();
Node2* insere2_inicio (Node2* f, int v, int p);
Node2* insere2_fim (Node2* f, int v, int p);
void insereIni (Fila2* f, int v, int p);
void insereFim (Fila2* f, int v, int p);
Node2* retira2_inicio (Node2* inicio);
Node2* retira2_fim (Node2* fim);
int retiraIni (Fila2* f);
int retiraFim (Fila2* f);
void libera2 (Fila2* f);
int vazia2 (Fila2* f);
void imprime_fila2 (Fila2* f);

//-------------------------------
int geraNumRand ();
//-------------------------------

int main ()
{
	int i,NVoos = 0, combustivel;

	printf("Aeroporto Internacional de Guadalupe");

	NVoos = rand() % 42;
	Fila2* fila = cria_fila2();
	combustivel = rand() % 13;
	for (i = 0; i<= NVoos; i++)
	{
		if (fila->inicio == NULL)
			insereIni(fila, geraNumRand(), combustivel);
		else if (fila->inicio->prox->info.comb > fila->inicio->info.comb)
			insereIni(fila, geraNumRand(), combustivel);
		else
			insereFim(fila,geraNumRand(), combustivel);
	}
	
	imprime_fila2(fila);
	libera2(fila);	

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
Fila2* cria_fila2()
{
	Fila2* fila = (Fila2*) malloc(sizeof(Fila2));

	fila->inicio = fila->fim = NULL;

	return fila;

}

Node2* insere2_inicio (Node2* inicio, int v, int p)
{
	Node2* no = (Node2*) malloc(sizeof(Node2));

	no->info.NomeVoo = v;
	no->info.comb = p;
	no->prox = inicio;
	no->ant = NULL;

	if (inicio != NULL)
		inicio->ant = no;
	return no;
}

Node2* insere2_fim (Node2* fim, int v, int p)
{
	Node2* no = (Node2*) malloc(sizeof(Node2));

	no->info.NomeVoo = v;
	no->info.comb = p;
	no->prox = NULL;
	no->ant = fim;

	if (fim != NULL)
		fim->prox = no;
	return no;
}

void insereIni (Fila2* f, int v, int p)
{
	f->inicio = insere2_inicio(f->inicio, v, p);
	if (f->fim == NULL)
		f->fim = f->inicio;
}

void insereFim (Fila2* f, int v, int p)
{
	f->fim = insere2_fim(f->fim, v, p);
	if (f->inicio == NULL)
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
	int v,p;

	if (vazia2(f))
	{
		printf("Fila Vazia!! \n");
		return 0;
	}

	v = f->inicio->info.NomeVoo;
	p = f->inicio->info.comb;
	f->inicio = retira2_inicio(f->inicio);
	if (f->inicio == NULL)
		f->fim = NULL;
	return v,p;
}

int retiraFim (Fila2* f)
{
	int v,p;

	if (vazia2(f))
	{
		printf("Fila Vazia!! \n");
		return 0;
	}

	v = f->fim->info.NomeVoo;
	p = f->fim->info.comb;
	f->fim = retira2_fim(f->fim);
	if (f->fim == NULL)
		f->inicio = NULL;
	return v,p;
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


void imprime_fila2 (Fila2* f)
{
	Node2* no;

	for (no = f->inicio; no != NULL; no = no->prox)
	{
		printf("%d", no->info);
	}
}

//-------------------------------

int geraNumRand ()
{
	int v;
	v = 1000 + rand() % 9999;
	if (v <= 9999)
		return v;

}

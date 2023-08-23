#include<stdio.h>
#include<stdlib.h>
typedef struct no{
	int numero;
	struct no *left, *right;
}No;
typedef struct arvorebinaria{
	No *raiz;
}ArvoreBinaria;
void inserirDireita(No* no, int valor);
void inserirEsquerda (No* no, int valor){
	if(no->left==NULL){
		No *novo = (No*)malloc(sizeof(No));
		novo->numero = valor;
		novo->left=NULL;
		novo->right=NULL;
		no->left=novo;
	}else{
		if(valor<=no->left->numero){
			inserirEsquerda(no->left,valor);
		}else{
			inserirDireita(no->left,valor);
		}
	}
}
void inserirDireita(No* no, int valor){
	if(no->right==NULL){
		No *novo = (No*)malloc(sizeof(No));
		novo->numero = valor;
		novo->left=NULL;
		novo->right=NULL;
		no->right=novo;
	}else{
		if(valor>no->right->numero){
			inserirEsquerda(no->right,valor);
		}else{
			inserirDireita(no->right,valor);
		}
	}
}

void inserir(ArvoreBinaria *arvore, int valor){
	if (arvore->raiz==NULL){
		No *novo = (No*)malloc(sizeof(No));
		novo->numero = valor;
		novo->left=NULL;
		novo->right=NULL;
		arvore->raiz=novo;
	}else{
		if(valor<=arvore->raiz->numero){
			inserirEsquerda(arvore->raiz,valor);
		}else{
			inserirDireita(arvore->raiz,valor);
		}
	}
}

void imprimir(No *raiz){
	if(raiz!=NULL){
		printf("%d",raiz->numero);
		imprimir(raiz->left);
		printf("\n");
		imprimir(raiz->right);
		printf("\t");
	}
}

/*
void busca_profundidade(){
	
}
void busca_largura (){
	
}
void criarpilha(){
	
}
void empilhar(){
	
}*/
int main(int argc, char** argv){
	ArvoreBinaria arvore;
	arvore.raiz=NULL;
	inserir(&arvore,7);
	inserir(&arvore,20);
	inserir(&arvore,5);
	inserir(&arvore,3);
	inserir(&arvore,14);
	inserir(&arvore,1);
	inserir(&arvore,6);
	inserir(&arvore,9);
	inserir(&arvore,72);
	inserir(&arvore,17);
	inserir(&arvore,13);
	inserir(&arvore,45);
	inserir(&arvore,7);
	inserir(&arvore,35);
	inserir(&arvore,20);
	inserir(&arvore,7);
	inserir(&arvore,10);
	inserir(&arvore,8);
	inserir(&arvore,51);
	inserir(&arvore,10);
	imprimir(arvore.raiz);
	return 0;
}

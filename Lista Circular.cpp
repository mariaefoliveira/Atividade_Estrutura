#include<iostream>
#include<new>
#include<stdlib.h>

using namespace std;


struct lista{
	int numero;
	struct lista *prox;
	//struct lista *ant;
};

int Tamanho(lista *ponteiroEncadeada)
{
	if(ponteiroEncadeada == NULL)
	{
		return 0;
	}
	
	int tamanho=0;
	
	lista *p = ponteiroEncadeada;
	
	while(p!=ponteiroEncadeada)
	{
		tamanho++;
		p = p->prox;
	}
	
	return tamanho;
}

void imprime(lista *ponteiroEncadeada)
{
	lista *p = ponteiroEncadeada;
	
	while(p!=ponteiroEncadeada)
	{
		cout<<p->numero<<" - ";
		p = p->prox;
	}
}

void insere(lista *&ponteiroEncadeada, int x)
{
	lista *novoValor = new lista;
	
	novoValor->numero = x;
	lista *p = ponteiroEncadeada;
	
	if(p==NULL)
	{
		p = novoValor;
		p->prox=p;
		ponteiroEncadeada = p;
		
	}else{
		
		while(p->prox!=ponteiroEncadeada)
		{
			p=p->prox;
		}
		p->prox=novoValor;
		novoValor->prox=ponteiroEncadeada;
	}
	
}


int main()
{
	int vetor[5]={1,2,3,4,5};
	
	lista *ponteiroEncadeada = new lista;
	
	cout<< "LISTA CIRCULAR\n";
	cout<< "1. Inserir no comeco\n";
	
	cout<<"Tamanho: "<<Tamanho(ponteiroEncadeada)<<"\n";
	
	insere(ponteiroEncadeada,1);
	insere(ponteiroEncadeada,2);	
	insere(ponteiroEncadeada,3);
	
	cout<<"Tamanho apos insercao: "<<Tamanho(ponteiroEncadeada)<<"\n";
	
	imprime(ponteiroEncadeada);
	
	cout<< "2. Concatenar duas listas circulares\n";
	cout<< "3. Intercalar duas listas ordenadas\n";
	cout<< "4. Fazer copia da lista";
	

	
	
	return 0;
}

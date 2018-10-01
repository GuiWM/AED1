#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *pbuffer;


typedef struct P {
	char nome[20];
	int telefone;
} pessoa;
typedef struct var {
	int cont, choice, i, j;
	pessoa definida;
} variaveis;	

void insere(variaveis *inicio);
void exclui();
void busca(variaveis *inicio);
void mostra(variaveis *inicio);
void insertionsort(variaveis *inicio);


int main () {

    variaveis *inicio;
	//void *aux;
	
	pbuffer = malloc(sizeof(variaveis));
	
	inicio = pbuffer;
	inicio->cont = 0;
	//inicio->cont2 = 1;
	//aux = pbuffer;
	while (inicio->choice != 5) {

		printf("\n[>1<] Inserir\n[>2<] Excluir\n[>3<] Buscar\n[>4<] Mostrar \n[>5<] Sair\n");
		scanf("%d", &inicio->choice);

		if (inicio->choice == 1) {
			insere(inicio);
		} else if (inicio->choice == 2) {
			exclui(inicio);
		} else if (inicio->choice == 3) {
			//inicio = pbuffer;
			busca(inicio);
		} else if (inicio->choice == 4){
			mostra(inicio);
		}
	};
	free(pbuffer);

}
void insere(variaveis *inicio) {
	
	pessoa *name;
	//variaveis *contador;
		
	pbuffer = (pessoa *)realloc(pbuffer,sizeof(variaveis) + sizeof(pessoa) + (inicio->cont * sizeof(pessoa)));	
	name = pbuffer + sizeof(variaveis) + (inicio->cont * sizeof(pessoa));	
	
	printf("Nome para a posicao %d: ", inicio->cont);
    scanf("%s",name->nome);
	printf("Numero de %s: ", name->nome);
	scanf("%d", &name->telefone);
	
    inicio->cont++;
	
	insertionsort(inicio);
}
void exclui(variaveis *inicio) {
	if (inicio->cont >= 1) {
		pbuffer = (pessoa *) realloc(pbuffer, sizeof(variaveis) + (inicio->cont * sizeof(pessoa)));	
		inicio->cont--;
		printf("Última pessoa excluida com sucesso...");
	}
	else {	
		printf("Não há pessoas para excluir...");	
	}
} 
void busca(variaveis *inicio) {
	pessoa *name;
	name = pbuffer + sizeof(variaveis);
	printf("Pessoa a ser buscada (Posicao): ");
	scanf("%d", &inicio->choice);
	if (inicio->choice > inicio->cont) {
		printf("Pessoa inexistente na agenda...\n");	
	}	
	else {
		for (inicio->i = 0; inicio->i < inicio->choice; inicio->i++) {
				name++;
		}	
		printf("Nome: %s || Telefone: %d\n" , name->nome, name->telefone);
	}
}
void mostra(variaveis *inicio) {
	pessoa *name;
	name = pbuffer + sizeof(variaveis);
	for (inicio->i = 0; inicio->i < inicio->cont; inicio->i++) {
		printf("Nome: %s || Posicao: %d\n", name->nome, inicio->i);
		name++;
	}	
}
void insertionsort(variaveis *inicio){
	pessoa *info;
	info = pbuffer + sizeof(variaveis);
	if(inicio->cont > 1){
		for (inicio->i = 1; inicio->i < inicio->cont; inicio->i++) {
			inicio->definida = info[inicio->i];
			for (inicio->j = inicio->i - 1; (inicio->j >= 0) && (info[inicio->j].nome > inicio->definida.nome); inicio->j--) {
				info[inicio->j + 1] = info[inicio->j];
			}
			info[inicio->j+1] = inicio->definida;
		}
	}
}

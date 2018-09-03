#include <stdio.h>
#include <stdlib.h>

typedef struct P {
	char nome[20];
} pessoa;
typedef struct{
	int i;
} variaveis;

void insere();
void exclui();
void busca();
void mostra();

int main () {

	void *pbuffer;
    variaveis *op;


	op = pbuffer;

	pbuffer = malloc(sizeof(int));

	while (op->i != 5) {

		printf("[>1<] Inserir\n[>2<] Excluir\n[>3<] Buscar\n[>4<] Mostrar \n[>5<] Sair\n");
		scanf("%d", op->i);

		if (op->i == 1) {
			insere();
		} else if (op->i == 2) {
			exclui();
		} else if (op->i == 3) {
			busca();
		} else {
			mostra();
		}
	};


}
void insere() {

}
void exclui() {

}
void busca() {

}
void mostra() {

}



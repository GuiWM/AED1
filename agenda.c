#include <stdio.h>
#include <stdlib.h>

typedef struct P {
	char nome[20];
} pessoa;

void insere();
void exclui();
void busca();
void mostra();

int main () {

	pessoa *pbuffer;
	char *resposta;
	int *op;
	*resposta = 'S'; 
	
	pbuffer = (pessoa *) malloc(sizeof(pessoa));
	
	while (*resposta != 'N') {
	
		printf("[ 1 ] Inserir\n [ 2 ] Excluir\n [ 3 ] Buscar\n [ 4 ] Mostrar");
		scanf("%d", op);
		
		if (*op == 1) {
			insere();
		} else if (*op == 2) {
			exclui();
		} else if (*op == 3) {
			busca();
		} else {
			mostra();
		}				
	
		scanf("%c", resposta);
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
	
	

	#include <stdio.h>
	#include <string.h>
	#include <stdbool.h>
	#include <stdlib.h>
	
	// Para salvar o tamanho e soluções.
	typedef struct {
	    int tamanho;
	    int solucoes;
	} Rainha;
	
	// Tabuleiro com as posições, coluna x linha.
	void tabuleiro01(Rainha *rainha, int *posicoes) {
	    for(int i = 0; i < rainha->tamanho; ++i) {
	        printf("%d ", posicoes[i]);
	    }
	    printf("\n");
	}
	
	// Tabuleiro.
	void tabuleiro02(Rainha *rainha, int *posicoes) {
	    for(int linha = 0; linha < rainha->tamanho; ++linha) {
	        for(int coluna = 0; coluna < rainha->tamanho; ++coluna) {
	            if(posicoes[linha] == coluna) {
	                printf("R ");
	            } else {
	                printf(". ");
	            }
	        }
	        printf("\n");
	    }
	    printf("\n");
	}
	
	// Verifica se uma rainha está no campo da outra.
	bool verificar(int *posicoes, int linha_ocupada, int coluna) {
	    for(int i = 0; i < linha_ocupada; ++i) {
	        if(posicoes[i] == coluna || posicoes[i] - i == coluna - linha_ocupada || posicoes[i] + i == coluna + linha_ocupada) {
	            return false;
	        }
	    }
	    return true;
	}
	
	// Coloca a rainha verificando todos os casos, se tiver lugar diponivel, tenta colocar a proxima até acabar as rainhas.
	void acrescentar_rainha(Rainha *rainha, int *posicoes, int linha_alvo) {
	    // Break se todos as linhas estiverem ocupadas.
	    if(linha_alvo == rainha->tamanho) {
	        // Acrescenta + 1 para solução.
	        tabuleiro02(rainha, posicoes);
	        rainha->solucoes++;
	    } else {
	        // Rainha na coluna
	        for(int coluna = 0; coluna < rainha->tamanho; ++coluna) {
	            // verificar e rejeitar posições não validas.
	            if(verificar(posicoes, linha_alvo, coluna)) {
	                posicoes[linha_alvo] = coluna;
	                acrescentar_rainha(rainha, posicoes, linha_alvo + 1);
	            }
	        }
	    }
	}
	
	// Resolve e imprime as soluções (quantas).
	void resolver(Rainha *rainha) {
	    int *posicoes = malloc(rainha->tamanho * sizeof(int));
	    memset(posicoes, ~0, rainha->tamanho * sizeof(int));
	    acrescentar_rainha(rainha, posicoes, 0);
	    printf("   %d Solucoes Encontradas\n", rainha->solucoes);
	    free(posicoes);
	}
	
	int main(void) {
	    Rainha rainha = {.tamanho = 8};
	    resolver(&rainha);
	    printf("\nTecle ENTER para finalizar");
	    getchar();
	    return 0;
	}

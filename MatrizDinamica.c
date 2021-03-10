#include "MatrizDinamica.h"
#include <stdlib.h>
#include <stdio.h>

void inicializa_matriz( MatrizDinamica *p, int l, int c ){
	p->linhas = l;
	p->colunas = c;
	
	p->dados = malloc( sizeof(int*) * l );
	int i, j;
	for( i = 0 ; i < l ; i++ ){
            p->dados[i] = malloc( sizeof(int) * c );
            for( j = 0 ; j < c ; j++)
		p->dados[i][j] = 0;
	}
}

void mostra_matriz( MatrizDinamica m ){
	int i, j;
	
	printf("Dados da matriz (%dx%d):\n", m.linhas, m.colunas);
	for( i = 0 ; i < m.linhas; i++ ){
		for( j = 0; j < m.colunas ; j++ )
			printf("%4d ", m.dados[i][j]);
		printf("\n");
	}
	printf("\n");
}

void desaloca_matriz( MatrizDinamica *p ){
	int i;
	for( i = 0 ; i < p->linhas ; i++ )
		free( p->dados[i] );
		
	free( p->dados );
}

int modifica_matriz( MatrizDinamica *p, int lin, int col, int valor){
	if( lin >= p->linhas || col > p->colunas )
		return ERRO_COORDENADA_INVALIDA;
		
	p->dados[lin][col] = valor;
	return 1; // Sucesso.
}

int compara_matrizes( MatrizDinamica a, MatrizDinamica b ){
	if( a.linhas != b.linhas || a.colunas != b.colunas )
		return 0; // Falso, pois t�m dimens�es diferentes.
	
	int i, j;
	for( i = 0 ; i < a.linhas; i++ )
		for( j = 0; j < a.colunas ; j++ )
			if( a.dados[i][j] != b.dados[i][j] )
				return 0; // Falso, pois h� pelo menos um valor diferente.
	
	return 1; // Verdadeiro, pois � tudo igual (dimens�es e valores)
}


int get_valor(MatrizDinamica *a, int lin, int col){ ////////NAO ACUSA COORDENADA INVALIDA
    if( lin >= a->linhas || lin < 0 || col >= a->colunas || col < 0 )
		return ERRO_COORDENADA_INVALIDA;
    
    return (a->dados[lin][col]);
}


#define ERRO_COORDENADA_INVALIDA -1

typedef struct{
	int **dados;
	int linhas, colunas;
} MatrizDinamica;

void inicializa_matriz( MatrizDinamica *p, int l, int c );
void mostra_matriz( MatrizDinamica m );
void desaloca_matriz( MatrizDinamica *p );
int modifica_matriz( MatrizDinamica *p, int lin, int col, int valor);
int compara_matrizes( MatrizDinamica a, MatrizDinamica b );
int get_valor(MatrizDinamica *a, int lin, int col);


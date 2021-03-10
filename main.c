/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: joaol
 *
 * Created on 9 de Março de 2021, 18:27
 */

#include <stdio.h>
#include <stdlib.h>


#include "MatrizDinamica.h"
#include "FilaGenerica.h"

/*
 * 
 */
int mostra(void *x){
    printf("%d\n", *(int *)x);
}


int main(int argc, char** argv) {
    
    typedef struct{
        int x,y,dist;
    }coordenadas;
    
    int i,j,input;
    int linhas = 7;
    int colunas = 6;
    
    
    
    //int inicio[2];
    //int fim[2];
    
    MatrizDinamica M1;
    inicializa_matriz(&M1,linhas,colunas);
    
    MatrizDinamica MStatus;
    inicializa_matriz(&MStatus,linhas,colunas);
    
    FilaGenerica F1;
    inicializa_fila(&F1,(linhas*colunas),sizeof(coordenadas));
    
   
    coordenadas A;
    coordenadas B;
    coordenadas C;
   
    A.x = 1;
    A.y = 0;
    A.dist = 0;
    
    B.x = 6;
    B.y = 5;
    
    for(i = 0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            scanf("%d", &input);
            modifica_matriz(&M1,i,j,input);
            /*if(i == 0 && j == 0){
                modifica_matriz(&M1,i,j,1);
            }else if(i == 0 && j == 1){
                modifica_matriz(&M1,i,j,1);
            }
            else if(i == 0 && j == 2){
                modifica_matriz(&M1,i,j,1);
            }
            else if(i == 1 && j == 2){
                modifica_matriz(&M1,i,j,1);
            }
            else if(i == 2 && j == 2){
                modifica_matriz(&M1,i,j,1);
            }
            else{
                modifica_matriz(&M1,i,j,0);
            }*/
        }
    }
    
    modifica_matriz(&MStatus,A.x,A.y,1);
    mostra_matriz(M1);
    
    inserir(&F1, &A);
    int achou = 0;
    
    while(!(fila_vazia(F1)) && (achou == 0)){
        
        remover(&F1,&C);
        if(C.x == B.x && C.y == B.y){
            achou = 1;
        }
        else{
            for (i = 0; i < 4; i++){
                switch (i){
                    case 0:
                        //Cima
                        if((get_valor(&MStatus,C.x-1,C.y) == 0) && (get_valor(&M1,C.x-1,C.y) == 1)){
                            modifica_matriz(&MStatus,C.x+1,C.y,1);
                            C.x -= 1;
                            C.dist += 1;
                            inserir(&F1, &C);
                        }
                        break;
                        
                    case 1:
                        //Direita
                        if((get_valor(&MStatus,C.x,C.y+1) == 0) && (get_valor(&M1,C.x,C.y+1) == 1)){
                            modifica_matriz(&MStatus,C.x,C.y+1,1);
                            C.y += 1;
                            C.dist += 1;
                            inserir(&F1, &C);
                        }
                        break;
                        
                    case 2:
                        //Baixo
                        if((get_valor(&MStatus,C.x+1,C.y) == 0) && (get_valor(&M1,C.x+1,C.y) == 1)){
                            modifica_matriz(&MStatus,C.x-1,C.y,1);
                            C.x += 1;
                            C.dist += 1;
                            inserir(&F1, &C);
                        }
                        break;
                        
                    case 3:
                        //Esquerda
                        if((get_valor(&MStatus,C.x,C.y-1) == 0) && (get_valor(&M1,C.x,C.y-1) == 1)){
                            modifica_matriz(&MStatus,C.x,C.y-1,1);
                            C.y -= 1;
                            C.dist += 1;
                            inserir(&F1, &C);
                        }
                        break;
                }
            }
        }
    }
    if(achou){
        printf("Caminho encontrado!\n");
        printf("A distancia percorrida foi: %d\n",C.dist);
    }
    else{
        printf("Não há caminho possível entre [%d,%d] e [%d,%d]\n",A.x,A.y,B.x,B.y);
    }
    mostra_matriz(MStatus);
    mostra_fila(F1,mostra);
    
    
    desaloca_fila(&F1);
    desaloca_matriz(&M1);
    desaloca_matriz(&MStatus);
    
    return (EXIT_SUCCESS);
}


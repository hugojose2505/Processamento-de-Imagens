/*-------------------------------------------------------------------------
 *               UNIFAL- UNIVERSIDADE FEDERAL DE ALFENAS
 *                BACHARELADO EM CIENCIA DA COMPUTACAO
 *  TRABALHO: IMAGEM ASCII
 *  DISCIPLINA: PROCESSAMENTO DE IMAGENS
 *  ALUNO: HUGO JOSE TEODORO TERRA
 *  DATA: 26/04/2023
 *-------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagelib.h"

void ascii(image In, image Out, int nr, int nc, char* chars) {
    int linhascii = nr /(int)strlen(chars);
    FILE *saida;
    saida = fopen("result.txt","w");

    int colunascii = nc / (int)strlen(chars);
    int converte_ascii = 255 / strlen(chars);
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            int indice_in =+ In[i*nc + j];
            int transforma_ascii = indice_in / converte_ascii;
            Out[i*nc + j] = (char)chars[transforma_ascii];
            fprintf(saida,"%c", Out[i*nc+j]);
        }
        fprintf(saida,"\n");
    }


    
}

int main(int argc, char *argv[])
{
    char *caractere = argv[4]; 
    int nc, nr, ml, tp;
    char *p, nameIn[100], nameOut[100], cmd[110];
    image In, Out;
    

    tp = atoi(argv[2]);
    //-- define input/output file name
    img_name(argv[1], nameIn, nameOut, 2);
    //-- read image
    In = img_get(nameIn, &nr, &nc, &ml, 2);
    //-- create output image
    Out = img_alloc(nr, nc);
    ascii(In,Out, nr, nc, caractere);
    //-- save image
    img_put(Out, nameOut, nr, nc, ml, 2);
    //-- show image
    //sprintf(cmd, "%s %s &", VIEW, nameOut);
    system(cmd);
    img_free(In);
    img_free(Out);
    return 0;
}

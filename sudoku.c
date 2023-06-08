/*fazendo o sudoku*/
#include <stdio.h>
#include <stdlib.h>
int tabuleiro[9][9];

void funcao_zerando_tabuleiro(){

    int linha,coluna;

    for(linha = 0; linha < 9; linha++){
        for(coluna = 0; coluna < 9; coluna++){
            tabuleiro[linha][coluna] = 0;
        }
    }
}

void bot_criacao_tabuleiro(int valor,int posicao_i_valor,int posicao_j_valor){
    int j = 0;
    int verificador=0;
    for(int i = 0; i < 9; i++){
        if(i == posicao_i_valor){
            while(j < 9){
                if(valor == tabuleiro[i][j]){
                   verificador++;
                   break;
                }
                j++;
            }
        }
        if(valor == tabuleiro[i][posicao_j_valor]){
            verificador++;
        }
    }
    if(verificador == 0){
        tabuleiro[posicao_i_valor][posicao_j_valor] = valor;
    }
}
void funcao_exibicao_tabuleiro(){
    int contador_i = 0;
    int contador_j = 0;

    for(int linha = 0; linha< 9; linha++){
        for(int j = 0; j< 9; j++){
            printf(" [%d] ",tabuleiro[linha][j]);

        }
        printf("\n\n");
    }
}

int funcao_jogando_tabuleiro(int valor, int posicao_i_valor, int posicao_j_valor){
    int j = 0;
    int verificador=0;

    for(int i = 0; i < 9; i++){
        if(i == posicao_i_valor){
            while(j < 9){
                if(valor == tabuleiro[i][j]){
                   verificador++;
                   break;
                }
                j++;
            }
        }
        if(valor == tabuleiro[i][posicao_j_valor]){
            verificador++;
        }
    }
    if(tabuleiro[posicao_i_valor][posicao_j_valor] == 0 && verificador == 0){
        return 1;
    }
    else{
        return 0;
    }
}
int funcao_verificacao_vitoria(){
    int verificacao= 0;
    for(int linha = 0; linha< 9; linha++){
        for(int j = 0; j< 9; j++){
            if(tabuleiro[linha][j] == 0){
                verificacao++;
            }
        }
    }
    return verificacao;

}

int main(){

    int valor, posicao_i_valor, posicao_j_valor, resultado=0;
    int posicao_i, posicao_j, vitoria;
    int vidas, opcao;

    printf("*bem vindo ao jogo de SUDOKU!!*\nVOCE TEM COMEÇA COM 3 VIDAS, USE COM SABEDORIA\n");
    printf("*APENAS SAO ACEITOS VALORES MENORES QUE 10 E POSITIVOS*\n");
    int quantidade_de_valores;

    while(1){
        quantidade_de_valores= 0;
        funcao_zerando_tabuleiro();
        while(quantidade_de_valores < 150){
            valor = rand()%10;//sorteando 10 valores que cairao em lugares aleatorios
            posicao_i_valor = rand()%9; //do meu tabuleiro 5x5 == 25...
            posicao_j_valor = rand()%9;

            bot_criacao_tabuleiro(valor,posicao_i_valor,posicao_j_valor);
            quantidade_de_valores++;

        }
        vidas=3;
        vitoria=0;
        while(1){
            if(!vidas){
                printf("GAME OVER\n");
                break;
            }
            funcao_exibicao_tabuleiro();
            printf("\ninforme a posicao que vais colocar o valor em coordenadas\n");/*jogando o jogo finalmente*/
            scanf("%d%d",&posicao_i,&posicao_j);
            printf("informe o valor");
            scanf("%d",&valor);

            resultado = funcao_jogando_tabuleiro(valor, posicao_i, posicao_j);
            if(resultado && valor < 10 && valor > 0){
                tabuleiro[posicao_i][posicao_j] = valor;
            }
            else{
                vidas--;
            }
            vitoria = funcao_verificacao_vitoria();
            if(vitoria == 0){
                printf("PARABENS, VENCEU O JOGO!!!\n");
                break;
            }

        }
        printf("para jogar novamente, digite:1 , caso queira parar digite: 2 ");
        scanf("%d",&opcao);
            switch(opcao){
                case 1:
                    continue;
                case 2:
                printf("\nobrigado por jogar");
                break;
            }
    }
    return 0;
}

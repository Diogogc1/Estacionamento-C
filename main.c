/*
Nome: Diogo Gomes Castro
Professor: Ernani Claúdio Borges
Data: 12/12/2022
Turma: 1° Período - ADS
CPF: 127.250.206-62
E-mail: diogo.castro@estudante.iftm.edu.br
*/

#incIude <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

#define M 5
#define N 5

//==========================PROTÓTIPOS==========================
void funcao_menu (int *menu);
//==========================FUNÇÕES==========================
void inicializar(char mat[][N])
{
    int i, j;

    for(i=0; i<M; i++)
        for(j=0; j<N; j++)
            mat[i][j] = '0';
}
//=================================================================
void funcao_m(int *menu, float preco)
{
    system("cls");
    printf("\n\n Preco do estacionamento: %.2f reais", preco);
    printf("\n\n ======================= MENU ======================= \n");
    printf("\n 1: Entrada de veiculo");
    printf("\n 2: Saida de veiculo.");
    printf("\n 3: Consultar vagas quantidade de vagas livres e ocupadas.");
    printf("\n 4: Situacao do estacionamento");
    printf("\n 5: Relatorio diario");
    printf("\n 6: Sair do sistema");
    printf("\n\n Escolha uma opcao: ");

    do
    {
        fflush(stdin);
        scanf("%d", &*menu);
        if(*menu < 1 || *menu > 6)
            printf("\n Opção Invalida! Digite Outra: ");
    }while(*menu < 1 || *menu > 6);
}
//=================================================================
float entrada(char mat[][N], float qtd_entrada)
{
    int m, n;

    printf("\n\n Digite o numero do corredor: ");

    do
    {
        fflush(stdin);
        scanf("%d", &m);

        if(m < 0 || m > M-1)
            printf("\n Numero Invalido! Digite outro: ");
    }while(m < 0 || m > M-1);

    printf("\n Digite o numero da vaga: ");

    do
    {
        fflush(stdin);
        scanf("%d", &n);

        if(n < 0 || n>N-1)
            printf("\n Numero Invalido! Digite outro: ");
    }while(n < 0 || n>N-1);


    if(mat[m][n] == '0')
    {
        mat[m][n] = 'X';
        printf("\n\n Vaga ocupada com sucesso!");
        qtd_entrada++;
    }
    else
    {
        printf("\n\n Vaga ja esta ocupada");
    }

    printf("\n\n\n Pressione qualquer tecla para voltar ao menu");
    getch();

    return qtd_entrada;
}

//=================================================================
float saida(char mat[][N], float qtd_saida)
{
    int m, n;

    printf("\n\n Digite o numero do corredor: ");

    do
    {
        fflush(stdin);
        scanf("%d", &m);

        if(m < 0 || m > M-1)
            printf("\n Numero Invalido! Digite outro: ");
    }while(m < 0 || m > M-1);

    printf("\n Digite o numero da vaga: ");

    do
    {
        fflush(stdin);
        scanf("%d", &n);

        if(n < 0 || n>N-1)
            printf("\n Numero Invalido! Digite outro: ");
    }while(n < 0 || n>N-1);


    if(mat[m][n] == 'X')
    {
        mat[m][n] = '0';
        printf("\n\n Vaga desocupada com sucesso!");
        qtd_saida++;
    }
    else
    {
        printf("\n\n Esta vaga ja esta desocupada");
    }

    printf("\n\n\n Pressione qualquer tecla para voltar ao menu");
    getch();

    return qtd_saida;
}

void consulta(char mat[][N])
{
    int contl, conto;
    int i, j;

    contl = conto = 0;

    for(i=0; i<M; i++)
        for(j=0; j<N; j++)
        {
            if(mat[i][j] == 'X')
                conto++;
            else
                if(mat[i][j] == '0')
                    contl++;
        }

    printf("\n\n O numero de vagas ocupadas e %d.", conto);
    printf("\n\n O numero de vagas livres e %d.", contl);

    printf("\n\n\n Pressione qualquer tecla para voltar ao menu");
    getch();
}

//=================================================================
 void situacao(char mat[][N])
 {
    int i, j;

    printf("\n\n ============= SITUACAO DO ESTACIONAMENTO ============= \n\n");

    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
            printf("\t%c", mat[i][j]);
        printf("\n");
    }
    printf("\n\n Pressione qualquer tecla para voltar ao menu");
    getch();
 }

//=================================================================
void relatorio(char mat[][N], float qtd_entrada, float qtd_saida, float preco)
{
    float vl_recebido, vl_areceber;
    float estacionados;
    float percent;
    float m, n;

    m = M;
    n = N;

    //ENTRADA
    printf("\n\n A quantidade de veiculos que entraram durante todo o dia foi %.0f.", qtd_entrada);

    //SAIDA
    printf("\n\n A quantidade de veiculos que sairam durante todo o dia foi %.0f.", qtd_saida);

    //VALOR RECEBIDO
    vl_recebido = preco * qtd_saida;
    printf("\n\n O valor total recebido foi %.2f reais, %.0f clientes pagaram.", vl_recebido, qtd_saida);

    //VALOR A RECEBER
    vl_areceber = preco * (qtd_entrada - qtd_saida);
    estacionados = qtd_entrada - qtd_saida;

    printf("\n\n O valor total que falta para receber e %.2f reais, a quantidade de carros que ainda estao estacionados e %.0f.", vl_areceber, estacionados);

    //PORCENTAGEM DE VAGAS OCUPADAS
    percent = (estacionados / (m*n)) * 100;

    printf("\n\n O percentual de utilizacao de vagas no momento atual em relacao ao total de vagas do estacionamento e %.0f porcento.", percent);

    printf("\n\n\n Pressione qualquer tecla para voltar ao menu");
    getch();
}


//=================================================================
int main()
{
    //CRIAR VARIÁVEIS
    int menu=0;
    char mat[M][N];
    float preco;
    float qtd_entrada=0, qtd_saida=0;

    //PREÇO DO ESTACIONAMENTO
    preco = 20.50;

    //INICIALIZAR
    inicializar(mat);

    //MENU
    while(menu != 6)
    {
        funcao_m(&menu, preco);

        if(menu == 6)
        {
            printf("\n\n Finalizando o programa! \n\n");
        }
        else
            if(menu == 1)
                qtd_entrada = entrada(mat, qtd_entrada);
            else
                if(menu == 2)
                    qtd_saida = saida(mat, qtd_saida);
                else
                    if(menu == 3)
                        consulta(mat);
                    else
                        if(menu == 4)
                            situacao(mat);
                        else
                            if(menu == 5)
                                relatorio(mat, qtd_entrada, qtd_saida, preco);
    }
}

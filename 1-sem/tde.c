#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lerIdade()
{
    int idade;
    printf("\n");
    printf("FAIXA ETARIA A SER ANALISADA:\n");
    printf("1 - A PARTIR DE 15 ANOS\n");
    printf("2 - DE 15 A 24\n");
    printf("3 - DE 25 A 64\n");
    printf("4 - A PARTIR DE 65 ANOS\n");
    printf("\n");
    do
    {
        scanf("%i", &idade);
        if(idade<1 || idade>4)
        {
            printf("DIGITE UM DOS NUMEROS ACIMA\n");
        }
    }
    while(idade<1 || idade>4);
    return idade;
}

int lerReg()
{
    int reg;
    printf("\n");
    printf("REGIAO A SER ANALISADA:\n");
    printf("1 - BRASIL\n");
    printf("2 - NORTE\n");
    printf("3 - NORDESTE\n");
    printf("4 - SUDESTE\n");
    printf("5 - SUL\n");
    printf("6 - CENTRO-OESTE\n");
    printf("\n");
    do
    {
        scanf("%i", &reg);
        if(reg<1 || reg>6)
        {
            printf("DIGITE UM DOS NUMEROS ACIMA\n");
        }
    }
    while(reg<1 || reg>6);
    return reg;
}

int retornar()
{
    int op_retorno = 0;
    printf("\n");
    printf("O QUE DESEJA FAZER:\n");
    printf("1 - RETORNAR AO MENU\n");
    printf("2 - ENCERRAR\n");
    printf("\n");
    do
    {
        scanf("%i", &op_retorno);
        if(op_retorno!=1 && op_retorno!=2)
        {
            printf("DIGITE UM DOS NUMEROS ACIMA\n");
        }
    }
    while(op_retorno!=1 && op_retorno!=2);
    system("cls");
    return op_retorno;
}

int main()
{

    FILE *arquivo;

    char reg[23][15];
    float dados[23][7];
    arquivo = fopen("/TDE-1-SEM/tde.csv", "r");

    if(arquivo == NULL)
    {
        printf("Erro! Não consegui abrir o arquivo de leitura");
        return 1;
    }

    char linha[120];
    fgets(linha,120, arquivo);

    char desc_col[8][50];
    char *token;
    token = strtok(linha, ",");
    strcpy(desc_col[0], token);
    token = strtok(NULL, ",");
    strcpy(desc_col[1], token);
    token = strtok(NULL, ",");
    strcpy(desc_col[2], token);
    token = strtok(NULL, ",");
    strcpy(desc_col[3], token);
    token = strtok(NULL, ",");
    strcpy(desc_col[4], token);
    token = strtok(NULL, ",");
    strcpy(desc_col[5], token);
    token = strtok(NULL, ",");
    strcpy(desc_col[6], token);
    token = strtok(NULL, ",");
    token[strcspn(token, "\n")] = '\0';
    strcpy(desc_col[7], token);

    int i=0, j=0;

    while(fgets(linha,100, arquivo) != NULL)
    {
        token = strtok(linha, ",");
        strcpy(reg[i], token);
        token = strtok(NULL,",");
        dados[i][0] = strtod(token,NULL);
        token = strtok(NULL,",");
        dados[i][1] = strtod(token, NULL);
        token = strtok(NULL,",");
        dados[i][2] = strtod(token,NULL);
        token = strtok(NULL,",");
        dados[i][3] = strtod(token, NULL);
        token = strtok(NULL,",");
        dados[i][4] = strtod(token,NULL);
        token = strtok(NULL,",");
        dados[i][5] = strtod(token, NULL);
        token = strtok(NULL,",");
        dados[i][6] = strtod(token, NULL);
        i++;
    }

    fclose(arquivo);

    char faixa_etaria[4][30];
    strcpy(faixa_etaria[0], "A PARTIR DE 15 ANOS");
    strcpy(faixa_etaria[1], "ENTRE 15 E 24 ANOS");
    strcpy(faixa_etaria[2], "ENTRE 25 E 64 ANOS");
    strcpy(faixa_etaria[3], "A PARTIR DE 65 ANOS");

    char nome[20];

    printf("x--------------------------x\n");

    printf("| DIGITE SEU NOME: ");
    do
    {
        scanf("%s", &nome);
        if(strlen(nome)<4 || strlen(nome)>20)
        {
            printf("Digite um nome com minimo de 4 caracteres e maximo de 20\n");
        }
    }
    while(strlen(nome)<4 || strlen(nome)>20);

    printf("| OLA %s! BEM VINDO(A)! \n", nome);
    printf("x--------------------------x\n");
    printf("\n");
    int encerrar;
    do
    {

        printf("ESTE PROGRAMA FAZ A LEITURA DE DADOS SOBRE A TAXA DA ALFABETIZACAO DA POPULACAO BRASILEIRA EM 2019 SEPARADO POR REGIOES E GRUPOS DE FAIXA ETARIA, GENERO E COR/RACA.\n");
        printf("COMO VOCE DESEJA VISUALIZAR OS DADOS?\n");
        printf("\n");
        printf("1- PESQUISA POR FAIXA ETARIA\n");
        printf("2- PESQUISA POR REGIOES\n");
        printf("3- PESQUISA POR FAIXA ETARIA E REGIOES\n");
        int op_divisao;
        do
        {
            scanf("%i", &op_divisao);
            if(op_divisao<1 || op_divisao>3)
            {
                printf("DIGITE UM DOS NUMEROS ACIMA\n");
            }
        }
        while(op_divisao<1 || op_divisao>3);

        system("cls");

        switch (op_divisao)
        {
            int idade_main;
            int reg_main;

        case 1:

            idade_main = lerIdade();
            system("cls");
            int cont_reg = 0, id_maior, id_menor, inicio;
            float maior=0, menor=0;

            printf("TAXA DE ALFABETIZACAO BRASILEIRA DA POPULACAO %s\n", faixa_etaria[idade_main-1]);
            printf("\n");
            for(i=(idade_main-1)*6; i<=((idade_main-1)*6)+5; i++)
            {
                puts(reg[cont_reg+6]);
                for(j=0; j<=6; j++)
                {
                    if(j == 0) menor = dados[i][j];
                    printf("%s: %.1lf%%\n", desc_col[j+1], dados[i][j]);
                    if(j == 2 || j == 3 || j == 5 || j == 6)
                    {
                        if (dados[i][j] > maior)
                        {
                            maior = dados[i][j];
                            id_maior = j+1;
                        }
                        if (dados[i][j] < menor)
                        {
                            menor = dados[i][j];
                            id_menor = j+1;
                        }
                    }
                }
                printf("Maior taxa de alfabetizacao na regiao %s: ", reg[cont_reg+6]);
                printf("%.1lf%% (%s)\n", maior, desc_col[id_maior]);
                printf("Menor taxa de alfabetizacao na regiao %s: ", reg[cont_reg+6]);
                printf("%.1lf%% (%s)\n", menor, desc_col[id_menor]);
                printf("\n");
                maior = 0;
                id_maior = 0;
                id_menor = 0;
                cont_reg = 0;
                cont_reg++;
            }
            cont_reg = 0;
            printf("\n");
            encerrar = retornar();
            break;

        case 2:

            reg_main = lerReg();
            system("cls");
            printf("TAXA DE ALFABETIZACAO DA REGIAO %s\n", reg[reg_main-1+6]);
            printf("\n");
            int cont = 0;
            for(i=reg_main-1; i<=23; i=i+6)
            {
                printf("POPULACAO %s\n", faixa_etaria[cont]);
                for(j=0; j<=6; j++)
                {
                    if(j == 0) menor = dados[i][j];
                    printf("%s: %.1lf%%\n", desc_col[j+1], dados[i][j]);
                    if(j == 2 || j == 3 || j == 5 || j == 6)
                    {
                        if (dados[i][j] > maior)
                        {
                            maior = dados[i][j];
                            id_maior = j+1;
                        }
                        if (dados[i][j] < menor)
                        {
                            menor = dados[i][j];
                            id_menor = j+1;
                        }
                    }
                }
                printf("Maior taxa de alfabetizacao da populacao %s: ", faixa_etaria[cont]);
                printf("%.1lf%% (%s)\n", maior, desc_col[id_maior]);
                printf("Menor taxa de alfabetizacao da populacao %s: ", faixa_etaria[cont]);
                printf("%.1lf%% (%s)\n", menor, desc_col[id_menor]);
                maior = 0;
                id_maior = 0;
                id_menor = 0;
                cont++;
            }
            printf("\n");
            encerrar = retornar();
            break;

        case 3:

            reg_main = lerReg();
            idade_main = lerIdade();
            system("cls");

            printf("TAXA DE ALFABETIZACAO DA POPULACAO DO %s %s\n", reg[reg_main-1+6], faixa_etaria[idade_main-1]);
            printf("\n");
            int k = reg_main-1 + (idade_main-1) * 6;
            for(j=0; j<=6; j++)
            {
                if(j == 0) menor = dados[k][j];
                printf("%s: %.1lf%%\n", desc_col[j+1], dados[k][j]);
                if(j == 2 || j == 3 || j == 5 || j == 6)
                {
                    if (dados[k][j] > maior)
                    {
                        maior = dados[k][j];
                        id_maior = j+1;
                    }
                    if (dados[k][j] < menor)
                    {
                        menor = dados[k][j];
                        id_menor = j+1;
                    }
                }
            }
            printf("Maior taxa de alfabetizacao da populacao da regiao %s %s: ", reg[reg_main-1+6], faixa_etaria[idade_main-1]);
            printf("%.1lf%% (%s)\n", maior, desc_col[id_maior]);
            printf("Menor taxa de alfabetizacao da populacao da regiao %s %s: ", reg[reg_main-1+6], faixa_etaria[idade_main-1]);
            printf("%.1lf%% (%s)\n", menor, desc_col[id_menor]);
            printf("\n");
            maior = 0;
            id_maior = 0;
            id_menor = 0;
            cont = 0;
            printf("\n");
            encerrar = retornar();
        }
    }
    while (encerrar != 2);
}

//Biblioteca com operac�es de entrada e sa�da de dados
//Autor: Ramon Giovane Dias
//Data: Setembro/2017 - Atualizado em: Setembro/2018

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<errno.h>
#include "io.h"

/**Le uma string digitada pelo usuario. Tem como varaveis:
-var: variavel que guarda a string a ser lida.
-tamanho: n�mero de caracteres do vetor da string
-message: texto exibido ao usuario indicando o que deve digitar
*/
void readString(char var[], int tamanho, const char message[]){
    printf("%s", message);
    setbuf(stdin, NULL);
    fgets(var, tamanho, stdin);
    setbuf(stdin, NULL);
}
/**Le um numero inteiro digitado pelo usuario. Tem como varaveis:
-var: variavel que guarda o n�mero a ser lido.
-message: texto exibido ao usuario indicando o que deve digitar
*/
void readInteger(int * var, const char message[]){
    char buffer[256];
    printf("%s", message);
    setbuf(stdin, NULL);
    fgets(buffer, 256, stdin);
    setbuf(stdin, NULL);
    *var = atoi(buffer);

}

/**Le um numero inteiro positivo do tipo long digitado pelo usuario. Tem como varaveis:
-var: variavel que guarda o n�mero a ser lido.
-message: texto exibido ao usuario indicando o que deve digitar
*/
void readULong(unsigned long int * var, const char message[]){
    char buffer[256];
    printf("%s", message);
    setbuf(stdin, NULL);
    fgets(buffer, 256, stdin);
    setbuf(stdin, NULL);
    *var = strtoul(buffer, NULL, 0);
}

/**Le um numero real(float) digitado pelo usuario. Tem como varaveis:
-var: variavel que guarda o n�mero a ser lido.
-message: texto exibido ao usuario indicando o que deve digitar
*/
void readFloat(float * var, const char message[]){
    char buffer[256];
    printf("%s", message);
    setbuf(stdin, NULL);
    fgets(buffer, 256, stdin);
    setbuf(stdin, NULL);
    *var = atof(buffer);

}


/**Funcao que le do usuario uma data e verifica se a mesma e valida, recebendo como par�metro dia(int), mes(int) e ano(int).
Retorna 1 se a data e valida e 0 caso contrario
*/
int readDate(int *dia, int *mes, int *ano){
    readInteger(&*dia, "Dia: ");
    readInteger(&*mes, "Mes: ");
    readInteger(&*ano, "Ano: ");
    return validarData(*dia, *mes, *ano);
}


/**Funcao que converte tres inteiros(dia, mes e ano) em uma string de data formatada (dd/MM/yyyy).
Requer como parametros:
- data: um vetor de char que ira receber por referencia a data formatada.
- dia:  um inteiro que guarda o valor de um dia do mes.
- mes:  um inteiro que guarda o valor de um mes do ano.
- ano:  um inteiro que guarda o valor de um ano
AVISO: Letras e s�mbolos passados na leitura de dados serao convertidas em n�meros de acordo com a tabela ASCII.*/
void parseDate(char data[],int dia, int mes, int ano){
     if(dia<10 && mes<10)
        sprintf(data, "0%d/0%d/%d", dia, mes, ano);
        else if(dia<10)
            sprintf(data, "0%d/%d/%d", dia, mes, ano);
            else if(mes<10)
                sprintf(data, "%d/0%d/%d", dia, mes, ano);
                else
                    sprintf(data, "%d/%d/%d", dia, mes, ano);
    }



/**Funcao que obtem o dia, mes e ano atuais, por meio da funcao da biblioteca time.
Requer como par�metros:
-dia: ponteiro para inteiro que armazenara o dia atual.
-mes: ponteiro para inteiro que armazenara o mes atual
-ano: ponteiro para inteiro que armazenara o ano atual*/
void getCurrentDate(int *dia, int *mes, int *ano){
    struct tm *local;
    time_t t;
    t= time(NULL);
    local=localtime(&t);

    *dia=local->tm_mday;
    *mes=local->tm_mon+1;
    *ano=local->tm_year+1900;
}



/**Funcao que verifica se a data passada e posterior a data atual.
Requer como par�metros:
-dia: inteiro que armazenara o dia.
-mes: inteiro que armazenara o mes.
-ano: inteiro que armazenara o ano.
Retorna 1 se a data for posterior, caso contrario, retorna 0.
*/
int isAfterToday(int dia, int mes, int ano){
    int diaA, mesA, anoA;
    getCurrentDate(&diaA, &mesA, &anoA);

    if(ano < anoA)
        return 0;
        else if(ano ==  anoA){
            if(mes <= mesA)
                if(dia<= diaA)
                    return 0;
        }

    return 1;

}


/**Funcao que paralisa a tela de prompt ate que o usuario pressione a tecla ENTER*/
void pauseScreen(){
    char buffer[256];
    readString(buffer, 256, "\nPressione ENTER para continuar...");
    return;
}

/**Funcao que limpa a tela de prompt do usuario*/
void clearScreen(){
    system("clear || cls");
}
/**Funcao que identifica se ha ocorrencias de n�meros inteiros em um vetor de caracteres.
Requer como par�metros:
- var: vetor a ser inspecionado.
- tam: tamanho do vetor.
Retorna um n�mero inteiro positivo, sendo esse o n�mero de ocorrencias de inteiros nas posic�es do vetor.
A funcao deve retornar 0 caso nenhuma posicao contenha n�meros.
*/
int apenasInteiros(const char var[], int tam){
    int i=0, status = 0;
    do{
        if(boundsCheck(var[i], '0', '9')) {
           status ++;
           }
           i++;
    }while(i<tam);

    return status;
}

/**Verifica se um numero inteiro esta entre um limite determinado, onde:
-var: e o n�mero a ser validado
-limite1: e o menor valor deste limite
-limite2: e o maior valor deste limite
Se var estiver entre os valores de limite, a funcao retorna verdadeiro.
Caso contrario, retorna falso.
*/
int boundsCheck(const int var, int limite1, int limite2){
    if(var < limite1 || var > limite2)
        return 0;
    return 1;
}
/**Funcao que valida um codigo. Recebe os parametros:
    - codigo: string com o codigo a ser analisado
    - tamanho: int com o numero de digitos que o codigo deve ter
    - apenasNumeros: boleano, quando true admite apenas n�meros*/
int validarCodigo(char codigo[], int tamanho, int apenasNumeros){
    int tam = strlen(codigo);
    if(codigo[tam-1] == '\n')
        codigo[tam-1] = '\0';

    else if(codigo[tam] == '\n')
        codigo[tam] = '\0';
    tam = strlen(codigo);

    if(apenasNumeros)
        if(apenasInteiros(codigo, tam)!=tamanho){
            printf("\nC�digo invalido! Digite apenas os %d caracteres.", tamanho);
            return 0;
        }

    if(!boundsCheck(tam, 0, tamanho)){
        printf("\nC�digo invalido! Nao pode conter letras ou s�mbolos.");
        return 0;
    }
    return 1;
}
/**Funcao que valida um cpf. Retorna 1 se o cpf for valido.
Caso o mesmo contenha algo a mais que os 11 n�meros, a funcao retorna 0*/
int validarCPF(char cpf[]){
     int tam = strlen(cpf);
     if(apenasInteiros(cpf, tam)!=11){
        printf("\nCPF invalido! Digite apenas os 11 n�meros!");
        return 0;
    }
    if(!boundsCheck(tam, 0, 11)){
        printf("\nCPF invalido! Digite apenas os 11 n�meros!");
        return 0;
    }
    if(!validarIntegridadeCPF(cpf)){
        printf("\nCPF invalido! Nao e um cadastro �ntegro. Tente novamente");
        return 0;
    }
    return 1;

}

/**Valida e formata um telefone.
Retorna 1 se o telefone e valido. Caso contrario, retorna 0.*/
int validarTelefone(char telefone[]){
    char buffer[256];
    int i, tam = strlen(telefone);
    if(boundsCheck(tam, 10, 11))
        if(apenasInteiros(telefone, tam)){
            buffer[0] = '(';
            buffer[1] =  telefone[0];
            buffer[2] =  telefone[1];
            buffer[3] =  ')';

            for(i=4; buffer[i]!='\0'; i++)
                buffer[i] = telefone[i-2];
            removerNullString(telefone, tam);
            return 1;
        }

    printf("\nO telefone de contato deve conter apenas o n�mero incluindo o DDD.\n");
    return  0;
}

/**Funcao que verifica a integridade de um cpf*/
int validarIntegridadeCPF(char cpf[]){
    int i, j, digito1 = 0, digito2 = 0;
    if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return 0; //Se o CPF tiver todos os n�meros iguais ele e invalido.

    else{

        //Digito 1
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os n�meros de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; //Se o digito 1 nao for o mesmo que o da validacao CPF e invalido

        //Digito 2
        else{
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--){
                //Multiplica os n�meros de 11 a 2 e soma os resultados dentro de digito2
                digito2 += (cpf[i]-48) * j;
            }

        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; //Se o digito 2 nao for o mesmo que o da validacao CPF e invalido
        }
    }
    return 1;

}


/**Funcao que valida um nome. Recebe como paramentros:
    - nome:  variavel string com o nome
    - min:  inteiro com o valor minimo que a string deve ter
    - max: valor maximo da string
    - sujeito: varivale string que serve para completar as mensagens de erro. Exemplos: 'A rua', 'O nome'.
    Retorna 0 se o nome esta em branco, e um valor negativo caso nao possua caracteres suficintes ou se
    satisfazer as duas situac�es.
    Caso contrario, retorna 1, indicando que o nome e valido*/
int validarNome(char nome[], int min, int max, char sujeito[]){
    int tam = strlen(nome);

    int status = validarString(nome, min+1, max);
    if(status == -1){
        printf("\n%s deve possuir apenas letras e espacamento.", sujeito);
        return 0;
    }
    if(status == -2){
        printf("\n%s deve possuir no m�nimo %d e no maximo %d letras.", sujeito, min, max);
        return 0;
    }
    if(status == -3){
        printf("\n%s deve comecar com uma letra.", sujeito);
        return 0;
    }
    if(temSimbolos(nome, tam)){
        printf("\n%s nao pode conter s�mbolos", sujeito);
        return 0;
    }
    return 1;
}
/**Valida uma sigla (uf). Retorna 1 se a sigla existiver e estiver em caixa alta. Do contrario, retorna 0.*/
int validarUFBrasileira(char uf[]){

    if(strlen(uf) != 3){
        printf("\nA sigla(UF) deve possuir apenas duas letras e nada mais!");
        return 0;
    }
    //Retirando a quebra de linha
    uf[2] = '\0';
    uf[0] = toupper(uf[0]);
    uf[1] = toupper(uf[1]);
    if( strcmp("AC", uf) == 0  || strcmp("AL", uf) == 0  || strcmp("AP", uf) == 0  || strcmp("AM", uf) == 0  || strcmp("BA", uf) == 0  ||
        strcmp("CE", uf) == 0  || strcmp("DF", uf) == 0  || strcmp("ES", uf) == 0  || strcmp("GO", uf) == 0  || strcmp("MA", uf) == 0  ||
        strcmp("MT", uf) == 0  || strcmp("MS", uf) == 0  || strcmp("MG", uf) == 0  || strcmp("PA", uf) == 0  || strcmp("PB", uf) == 0  ||
        strcmp("PR", uf) == 0  || strcmp("PE", uf) == 0  || strcmp("PI", uf) == 0  || strcmp("RJ", uf) == 0  || strcmp("RN", uf) == 0  ||
        strcmp("RS", uf) == 0  || strcmp("RO", uf) == 0  || strcmp("RR", uf) == 0  || strcmp("SC", uf) == 0  ||
                             strcmp("SP", uf) == 0  || strcmp("SE", uf) == 0  || strcmp("TO", uf) == 0 ){

        return 1;
    }
    printf("\nSigla invalida! Tente novamente.");
    return 0;
}

int validarRG(char rg[]){
    int tam = strlen(rg);
    removerNullString(rg, tam);
    if(tam < 9 || tam > 14){
        printf("\nRG invalido!Digite todos/apenas os n�meros.");
        return 0;
    }
    if(temSimbolos(rg, tam) == 1){
        printf("\nRG invalido! Digite apenas os n�meros do registros.");
        return 0;
    }
    return 1;

}

/**Verifica se um numero real esta entre um limite determinado, onde:
-var: e o n�mero a ser validado
-limite1: e o menor valor deste limite
-limite2: e o maior valor deste limite
Se var estiver entre os valores de limite, a funcao retorna verdadeiro.
Caso contrario, retorna falso.
*/
int validarFloat(const float var, float limite1, float limite2){
    if(var < limite1 || var > limite2)
        return 0;
    return 1;
}


/**Funcao que valida uma data, recebendo como par�metro dia(int), mes(int) e ano(int).
Retorna 1 se e valida e 0 caso contrario*/
int validarData(int dia, int mes, int ano){
    if(boundsCheck(mes, 1, 12) && boundsCheck(ano, 1700, 2020) && dia>0){
        /// Verifica se o dia e valido para um ano e bissexto
        if(mes == 2){
            if(ano%4 == 0){
                if(dia > 29)
                    return 0;
            }
            else if(dia>28)
                return 0;
        }
        /// Verifica se o mes tem trinta dias
        else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
            if(dia>30)
              return 0;
        }
        else if(dia>31)
            return 0;

        return 1;
    }
    return 0;
}

/**Funcao que verifica se uma string e vazia, se tem apenas letras, se comeca com espacamento e se tem um n�mero determinado
n�mero de caracteres. Deve receber:
-var:     uma cadeia de caracteres qualquer
-tam:     o tamanho da string
-min: m�nimo de caracteres que a string deve ter
-max: maximo de caracteres que a string pode ter
Retorna:  -1 se possui n�meros; -2 se a string nao esta entre os limites pre-definidos; -3 se comeca com um caractere vazio.
Retorna 0 se a string for valida.
 */
int validarString(char var[], int min, int max){
     int tam = strlen(var);
     if(apenasInteiros(var, tam))
        return -1;

    if(!boundsCheck(tam, min, max))
        return -2;

    if(var[0]==' ')
        return -3;

    removerNullString(var, tam);
    removerNullString(var, tam);
    return 0;
}

int validarCEP(char cep[]){
    char aux[5], aux2[4];
    int i, tam = strlen(cep);
    if(tam != 10){
        printf("\nO CEP fornecido e invalido, pois o mesmo deve ter 9 d�gitos");
        return 0;
    }
    cep[9] = '\0';
    if(cep[5] != '-'){
        printf("!%s!", cep);
        printf("O CEP fornecido e invalido! Digite conforme o exemplo");
        return 0;
    }
    aux[5] = '\0'; aux[4] = '\0';
    for(i =0; i<5; i++)
        aux[i] = cep[i];
    for (i=6; i<9; i++)
        aux2[i-6] = cep[i];

    if(temSimbolos(aux, strlen(aux))|| temSimbolos(aux2, strlen(aux2))){
        printf("O CEP fornecido e invalido, pois possui letras.");
        return 0;
    }
    return 1;
}

/**Funcao que identifica se ha s�mbolos em um vetor de caracteres.
Requer como par�metros:
- var: vetor a ser inspecionado.
- tam: tamanho do vetor.
Retorna 1 se ha ocorrencia de s�mbolos no vetor. Caso nao exista, retorna 0;
**/
int temSimbolos(const char var[], int tam){
    int i;

    for(i=0; i<tam; i++){
        if ( boundsCheck(var[i], 33, 45)   || boundsCheck(var[i], 58, 64) || boundsCheck(var[i], 123, 126)   ||
             boundsCheck(var[i], 155, 159) || boundsCheck(var[i], 166, 197) || boundsCheck(var[i], 200, 209 )||
             boundsCheck(var[i], 227, 223) || var[i] == '&' || boundsCheck(var[i], 238, 255)|| var[i] == 47    ||
             var[i] == 128)
           return 1;
    }

           return 0;
}

/**Funcao que identifica e remove o caractere '\n' do final de um c string**/
void removerNullString(char var[], int tam){
    int i;
    for(i=0; i<tam; i++)
        if(var[i]=='\n')
            var[i] ='\0';

}

/**Funcao que adiciona um separador de linha no texto*/
void quebraDeLinha(){
    printf("\n--------------\n");
}

/**Funcao que limpa e pausa a tela*/
void pausarELimparTela(){
    pauseScreen();
    clearScreen();
}


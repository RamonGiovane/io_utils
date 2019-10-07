#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

/**Esta biblioteca inclui fun��es de interface do usu�rio, envolvendo entrada e sa�da de dados*/
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
void readString(char var[], int tamanho, const char message[]);

/**Le um numero inteiro digitado pelo usuario. Tem como varaveis:
-var: variavel que guarda o n�mero a ser lido.
-message: texto exibido ao usuario indicando o que deve digitar
*/
void readInteger(int * var, const char message[]);

/**Le um numero inteiro positivo do tipo long digitado pelo usuario. Tem como varaveis:
-var: variavel que guarda o n�mero a ser lido.
-message: texto exibido ao usuario indicando o que deve digitar
*/
void readULong(unsigned long int * var, const char message[]);

/**Le um numero real(float) digitado pelo usuario. Tem como varaveis:
-var: variavel que guarda o n�mero a ser lido.
-message: texto exibido ao usuario indicando o que deve digitar
*/
void readFloat(float * var, const char message[]);

/**Funcao que le do usuario uma data e verifica se a mesma e valida, recebendo como par�metro dia(int), mes(int) e ano(int).
Retorna 1 se a data e valida e 0 caso contrario
*/
int readDate(int *dia, int *mes, int *ano);

/**Funcao que converte tres inteiros(dia, mes e ano) em uma string de data formatada (dd/MM/yyyy).
Requer como parametros:
- data: um vetor de char que ira receber por referencia a data formatada.
- dia:  um inteiro que guarda o valor de um dia do mes.
- mes:  um inteiro que guarda o valor de um mes do ano.
- ano:  um inteiro que guarda o valor de um ano
AVISO: Letras e s�mbolos passados na leitura de dados serao convertidas em n�meros de acordo com a tabela ASCII.*/
void parseDate(char data[],int dia, int mes, int ano);

/**Funcao que obtem o dia, mes e ano atuais, por meio da funcao da biblioteca time.
Requer como par�metros:
-dia: ponteiro para inteiro que armazenara o dia atual.
-mes: ponteiro para inteiro que armazenara o mes atual
-ano: ponteiro para inteiro que armazenara o ano atual*/
void getCurrentDate(int *dia, int *mes, int *ano);

/**Funcao que verifica se a data passada e posterior a data atual.
Requer como par�metros:
-dia: inteiro que armazenara o dia.
-mes: inteiro que armazenara o mes.
-ano: inteiro que armazenara o ano.
Retorna 1 se a data for posterior, caso contrario, retorna 0.
*/
int isAfterToday(int dia, int mes, int ano);

/**Funcao que paralisa a tela de prompt ate que o usuario pressione a tecla ENTER*/
inline void pauseScreen(){
    char buffer[256];
    readString(buffer, 256, "\nPressione ENTER para continuar...");
    return;
}

/**Funcao que limpa a tela de prompt do usuario*/
inline void clearScreen(){
    system("clear || cls");
}
/**Funcao que identifica se ha ocorrencias de n�meros inteiros em um vetor de caracteres.
Requer como par�metros:
- var: vetor a ser inspecionado.
- tam: tamanho do vetor.
Retorna um n�mero inteiro positivo, sendo esse o n�mero de ocorrencias de inteiros nas posic�es do vetor.
A funcao deve retornar 0 caso nenhuma posicao contenha n�meros.
*/
int apenasInteiros(const char var[], int tam);

/**Verifica se um numero inteiro esta entre um limite determinado, onde:
-var: e o n�mero a ser validado
-limite1: e o menor valor deste limite
-limite2: e o maior valor deste limite
Se var estiver entre os valores de limite, a funcao retorna verdadeiro.
Caso contrario, retorna falso.
*/
int boundsCheck(const int var, int limite1, int limite2);

/**Funcao que valida um codigo. Recebe os parametros:
    - codigo: string com o codigo a ser analisado
    - tamanho: int com o numero de digitos que o codigo deve ter
    - apenasNumeros: boleano, quando true admite apenas n�meros*/
int validarCodigo(char codigo[], int tamanho, int apenasNumeros);

/**Funcao que valida um cpf. Retorna 1 se o cpf for valido.
Caso o mesmo contenha algo a mais que os 11 n�meros, a funcao retorna 0*/
int validarCPF(char cpf[]);

/**Valida e formata um telefone.
Retorna 1 se o telefone e valido. Caso contrario, retorna 0.*/
int validarTelefone(char telefone[]);

/**Funcao que verifica a integridade de um cpf*/
int validarIntegridadeCPF(char cpf[]);

/**Funcao que valida um nome. Recebe como paramentros:
    - nome:  variavel string com o nome
    - min:  inteiro com o valor minimo que a string deve ter
    - max: valor maximo da string
    - sujeito: varivale string que serve para completar as mensagens de erro. Exemplos: 'A rua', 'O nome'.
    Retorna 0 se o nome esta em branco, e um valor negativo caso nao possua caracteres suficintes ou se
    satisfazer as duas situac�es.
    Caso contrario, retorna 1, indicando que o nome e valido*/
int validarNome(char nome[], int min, int max, char sujeito[]);

/**Valida uma sigla (uf). Retorna 1 se a sigla existiver e estiver em caixa alta. Do contrario, retorna 0.*/
int validarUFBrasileira(char uf[]);

int validarRG(char rg[]);

/**Verifica se um numero real esta entre um limite determinado, onde:
-var: e o n�mero a ser validado
-limite1: e o menor valor deste limite
-limite2: e o maior valor deste limite
Se var estiver entre os valores de limite, a funcao retorna verdadeiro.
Caso contrario, retorna falso.
*/
int validarFloat(const float var, float limite1, float limite2);

/**Funcao que valida uma data, recebendo como par�metro dia(int), mes(int) e ano(int).
Retorna 1 se e valida e 0 caso contrario*/
int validarData(int dia, int mes, int ano);

/**Funcao que verifica se uma string e vazia, se tem apenas letras, se comeca com espacamento e se tem um n�mero determinado
n�mero de caracteres. Deve receber:
-var:     uma cadeia de caracteres qualquer
-tam:     o tamanho da string
-min: m�nimo de caracteres que a string deve ter
-max: maximo de caracteres que a string pode ter
Retorna:  -1 se possui n�meros; -2 se a string nao esta entre os limites pre-definidos; -3 se comeca com um caractere vazio.
Retorna 0 se a string for valida.
 */
int validarString(char var[], int min, int max);

int validarCEP(char cep[]);

/**Funcao que identifica se ha s�mbolos em um vetor de caracteres.
Requer como par�metros:
- var: vetor a ser inspecionado.
- tam: tamanho do vetor.
Retorna 1 se ha ocorrencia de s�mbolos no vetor. Caso nao exista, retorna 0;
**/
int temSimbolos(const char var[], int tam);

/**Funcao que identifica e remove o caractere '\n' do final de um c string**/
void removerNullString(char var[], int tam);

/**Funcao que adiciona um separador de linha no texto*/
void quebraDeLinha();

/**Funcao que limpa e pausa a tela*/
void pausarELimparTela();
#endif // IO_H_INCLUDED

#include <iostream> // Entrada e saída de dados, exemplo de usos: ''cin'' , ''cout''
#include <locale.h> // Idioma, uso: ''setlocale''
#include <stdlib.h> // Funções e constantes básicas, usos: conversão de variáveis,''void''
#include<stdio.h>   // Entrada e saída de dados, uso: ''snprintf''
#include <math.h>   // Para uso de Exponenciação


using namespace std; // Para não ter que especificar os name space da biblioteca ''iostream''


int main(void) // Void para não exigir returno
{

 setlocale(LC_ALL, "Portuguese"); // Definindo idioma
 ios::sync_with_stdio(false); // Desativando a sincronização para ganho de performance nas entradas(cin) e saídas(cout)
  /* DECLARANDO VARIÁVEIS */
  int numBin[32]; // [32] declara o número de arrays que a variável pode ter
  int i, contagem, length, positionBin, resultado, potencia, multi;
  long long int numDec, bin, opcao; // ''long long'' para aumentar a capacidade de alocação
  bool valido;
  char* string;

    do{ // Repete loop até a opção ''0'' ser escolhida
      /* CABEÇALHO */
      cout << "\n---==========CALCULADORA==========---\n";
      cout << "\n Escolha uma das opções de conversão:\n";
      cout << "\n 1 - Binário para Decimal\n";
      cout << " 2 - Decimal para Binário\n";
      cout << " 3 - Créditos\n";
      cout << " 0 - Sair\n";
      cout << "\n Opção: ";
      cin >> opcao; // Lendo valor da ''opcao'' para uso em switch

        switch(opcao){ // Switch/Cases para seleção da opção escolhida pelo usuário
          case 1:
            /* CABEÇALHO OPÇÃO 1*/
            system("clear||cls"); // Limpa console
            cout << "\n---==========CALCULADORA==========---\n";
            cout << "Você escolheu Binário para Decimal!\n";
            cout << "\nDigite o Número Binário: ";
            cin >> bin; // Lendo o que foi digitado pelo usuário
            cout << "Número Binário digitado: " << bin << "\n"; // Mostrando o que foi digitado
            /* DECLARANDO VALORES DAS VARIÁVEIS */
            length = snprintf( NULL, 0, "%lld", bin); // Colocando a quantidade de bits de ''bin'' em ''length''
            string = (char*)malloc( length + 1); // Alocando espaço  // ''length+1'' atribuindo valor inicial a ''length''
            valido = true;  // Atribuindo valor verdadeiro a variável Booleans
            snprintf(string, length + 1, "%lld", bin); // Mudando ''int bin'' para ser um char ''string'' 
            resultado = 0;
            positionBin = 0;
                /* Conversão de binário para decimal */
                for (contagem=length-1; contagem>=0; contagem --) { // ''contagem'' corresponde ao numero de bits de ''bin'' ; ''contagem'' sendo maior ou igual a 0 ; contagem -1
                  if (string[contagem] != '1' && string[contagem] != '0'){ // ''if'' para valores diferentes de 1 e 0 quebrar o loop
                   valido = false; // Sendo diferentes de 1 e 0, booleans terá valor falso
                   break; // Quebra do loop ''for''
                  }
            
                potencia=pow(2,positionBin); // Variável que acumula resultado da exponenciação entre 2(que é a base de conversões para valores binários) elevado a posição dos números de bin
                multi= (string[contagem] - '0') * potencia; // Variável que acumula o número de ''bin''(como ''char'' menos '0' porque todo numero na tabela ASCII está ele mesmo de diferença do 0) vezes o número da exponenciação
                resultado =  resultado+multi ;
                positionBin++;  // Atualizando a posição para proxima casa, sempre que o loop reiniciar
                }

            valido ?  cout << "\nDecimal correspondente = " << resultado: cout << ("Resultado invalido, insere os numeros binários corretamente! \n"); // ''?''e '':'' são operadores ternários que são uma versão do ''if'' e ''else'', e que nesse caso se ''valido'' for verdadeiro realiza a primeira operação, se ''valido'' for falso realiza a operação depois dos '':''
            cout << endl; // Pulando linha para próxima operação não ficar grudada no final dessa
            free(string); // Liberando a memória alocada com ''malloc''
          break; // Quebra da opção 1

          case 2:
            /* CABEÇALHO OPÇÃO 2*/
            system("clear||cls");
            cout << "\n---==========CALCULADORA==========---\n";
            cout << "Você escolheu Decimal para Binário!\n";
            cout<<"\nDigite o Número Decimal: ";
            cin>>numDec;
            cout <<"Número Decimal digitado: " << numDec << "\n";
                    /* Convertendo Decimal para Binário*/
                    for(i=0; numDec>0; i++){
                      numBin[i]=numDec%2; // Separando o que resta da divisão de ''numDec'' e armazenando no array ''numBin'' mudando as posição do array com a contagem ''[i]''
                      numDec /= 2; // Dividindo ''numDec''
                    }
            cout<<"\nBinário correspondente = ";
                        for(i=i-1 ;i>=0 ;i--){ // ''For'' para imprimir os valores dos array(numBin) que corresponde ao número decimal
                          cout<<numBin[i];
                        }
            cout<<endl;
          break; // Quebra da opção 2

          case 3:
            /* CABEÇALHO OPÇÃO 3*/
            system("clear||cls");
            cout << "\n---==========CALCULADORA==========---\n" << endl;
            cout << "           .-=CRIADORES=-.           \n          Alexsander Faria\n          Andreas Grudtner\n           Herik Maurício\n       Maria Fernanda Sabino\n           Pedro Pacheco\n       Willian César Fagundes\n";
                  break; // Quebra da opção 3
          case 0:
            system("clear||cls");
            cout << "Bye, bye!"<< endl; 
          break; // Quebra da opção 0
                  
          default:
            system("clear||cls");
            cout << "Opção inválida!" << endl;     
        }
    }
          while(opcao!=0);  // While para opção ''0'' quebrar o loop
} // Chaves fechando na mesma linha de suas respectivas funções
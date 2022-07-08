#include <iostream>

using namespace std;

int main()
{
   setlocale(LC_ALL, "Portuguese");
  long long int codigo;
  int d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, soma, soma2, divisao, multi, digito;
  cout << "Trabalho de Algoritimos e Programação."<<endl<< "Alunos: Agnês Rusche, Erick Andrew, Julia Amaral, Vinicius José."<<endl;
  cout << "\n-------------Leitor de Codigos em Barras-------------\n\n";
  cout << "Insira aqui o seu codigo em barras para a avaliaçao do digito verificador : \n";
    cin >> codigo;
  if (codigo<=9999999999999 || codigo>=1000000000000){
    d0=codigo%10;
    d1=codigo/10%10;
    d2=codigo/100%10;
    d3=codigo/1000%10;
    d4=codigo/10000%10;
    d5=codigo/100000%10;
    d6=codigo/1000000%10;
    d7=codigo/10000000%10;
    d8=codigo/100000000%10;
    d9=codigo/1000000000%10;
    d10=codigo/10000000000%10;
    d11=codigo/100000000000%10;
    d12=codigo/1000000000000%10;
    soma =(d12+( d11 * 3 )+d10+( d9 * 3 )+d8+( d7 * 3 )+d6+( d5 * 3 )+d4+( d3 * 3 )+d2+( d1 * 3 ) );

    divisao = soma / 10;

    soma2 = divisao + 1;

    multi = soma2 * 10;

    digito = multi - soma;

    digito = digito % 10;

   }
  if( digito == d0 ){
       cout << "\ndDgoto de barras correto.\n";
       cout << endl;
       cout << endl;
  }
   else{
    cout << "\nDigito verificador inconsistente.\n";
    cout << endl;
    cout << endl;

  }


return 0;

}

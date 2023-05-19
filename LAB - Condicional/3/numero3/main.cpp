#include <iostream>
#include <cmath>

int main()
{

int numero = 0;

std::cout<<"Insira um numero de 4 digitos"<<"\n";
std::cin>>numero;

int quociente = numero / 100;
int resto = numero % 100;

int conta = quociente + resto;

int resultado = std::pow(conta,2);

if(resultado == numero) std::cout<<"o numero "<<numero<<"Está igual "<<"n";
if(resultado != numero) std::cout<<"o numero "<<numero<<"Está incorreto "<<"n";

}

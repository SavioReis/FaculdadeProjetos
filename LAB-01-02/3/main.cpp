#include <iostream>
#include <cmath>
#include <iomanip>
int main()
{

float numero = 0;

std::cout<<"Digite um numero de 3 digitos"<<"\n";
std::cin>>numero;

float unidade = numero%4;

//int dezena = (numero%100) / 10;

//int centena = numero / 100;

std::cout<<"\n"<<"Numero invertido : "<<unidade<<"\n";

}


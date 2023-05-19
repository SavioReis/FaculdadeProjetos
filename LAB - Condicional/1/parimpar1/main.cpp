#include <iostream>

int main()
{

int numero = 0;

std::cout<<"Insira um numero inteiro"<<"\n";
std::cin>>numero;

int resto = numero % 2;

if(resto == 0 ){
std::cout<<"\n O numero : "<<numero<<" é par ";

}

if(resto == 1 ){
std::cout<<"\n O numero : "<<numero<<" é impar ";

}

}

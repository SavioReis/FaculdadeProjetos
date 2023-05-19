#include <iostream>

int main()
{

float salarioAtual = 0;
float salarioReajustado = 0;

std::cout<<"Insira seu salario Atual"<<"\n";
std::cin>>salarioAtual;

if(salarioAtual<= 1050) salarioReajustado = salarioAtual*1.5;

if(salarioAtual > 1050)salarioReajustado = salarioAtual *1.3;

std::cout<<"\n Seu salario reajustado é : "<<salarioReajustado<<"\n";


}

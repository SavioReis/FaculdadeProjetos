#include <iostream>
#include <cmath>
#include <iomanip>
int main()
{

float custoFabrica = 0;

std::cout<<"Informe o preço de fábrica"<<"\n";
std::cin>>custoFabrica;


float distribuidor = custoFabrica + (custoFabrica * 12 / 100 );

float impostos = custoFabrica + (custoFabrica * 30 / 100);

float consumi = custoFabrica + distribuidor + impostos ;

std::cout<<"O preço a pagar é de : "<<consumi<<"\n";





}

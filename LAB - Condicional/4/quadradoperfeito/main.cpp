#include <iostream>
#include <cmath>

int main()
{

int inteiro = 0;

std::cout<<"Insira um numero positivo inteiro"<<"\n";
std::cin>>inteiro;

int raiz = std::sqrt(inteiro);
int quadrado = std::pow(raiz,2);

if(quadrado == inteiro) std::cout<<"Esse numero é quadrado perfeito"<<"\n";
if(quadrado != inteiro) std::cout<<"Esse numero não é quadrado perfeito"<<"\n";

}

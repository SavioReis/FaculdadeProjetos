#include <iostream>
#include <cmath>

int main()
{
int A = 0;
int B = 0;
int C = 0;

std::cout<<"Insira o valor de A : "<<"\n";
std::cin>>A;

std::cout<<"Insira o valor de B : "<<"\n";
std::cin>>B;

std::cout<<"Insira o valor de C : "<<"\n";
std::cin>>C;


int segGrau = std::pow(B,2)-4*A*C;
int xUmaLinha = (-B + std::sqrt(segGrau)) / (2 * A);
int xDuasLinha = (-B - std::sqrt(segGrau)) / (2 * A);

if(segGrau < 0)
std::cout<<"A raiz : "<<segGrau<<" É RAIZ IMAGINARIA"<<"\n";

if(segGrau == 0)
std::cout<<"A raiz : "<<segGrau<<" É RAIZ ÚNICA "<<"X1 : "<<xUmaLinha<<" e X2 : "<<xDuasLinha<<"\n";

if(segGrau > 0)
std::cout<<"A raiz : "<<segGrau<<" É RAIZ DISTINTA"<<" X1 : "<<xUmaLinha<<" e X2 : "<<xDuasLinha<<"\n";



}

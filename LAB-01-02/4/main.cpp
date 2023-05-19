#include <iostream>
#include <cmath>
#include <iomanip>
int main()
{

int numeroA;
int numeroB;

std::cout<<"Insira o valor de A : "<<"\n";
std::cin>>numeroA;

std::cout<<"Insira o valor de B : "<<"\n";
std::cin>>numeroB;

int numeroAA = numeroA;
numeroA = numeroB;
numeroB = numeroAA;

std::cout<<"O valor de A é : "<<numeroA<<"\n";
std::cout<<"O valor de B é : "<<numeroB<<"\n";

}


#include <iostream>

int main()
{

int A = 0;
int B = 0;
int C = 0;

std::cout<<"Insira o Valor de A : "<<"\n";
std::cin>>A;

std::cout<<"Insira o Valor de B : "<<"\n";
std::cin>>B;

std::cout<<"Insira o Valor de C : "<<"\n";
std::cin>>C;

if(A != B && A != C && B != C)
std::cout<<"Triangulo Escaleno"<<"\n";

if (A == B && A == C)
std::cout<<"Triangulo Equilatero"<<"\n";

if (A == B || A == C || B == C)
std::cout<<"Triangulo Isoceles"<<"\n";

if (C > A + B || A > B + C || B > A + C)
std::cout<<"Isso não é um triangulo";

}

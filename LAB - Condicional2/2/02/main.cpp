#include <iostream>

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

    if(A<B+C && B<A+C && C<A+B)
    std::cout<<"Sim os valores A : "<<A<<" B : "<<B<<" e C : "<<C<<" É um triangulo"<<"\n";

    if(A>B+C || B>A+C || C>A+B)
    std::cout<<"Os valores : "<<A<<" , "<<B<<" e : "<<C<<" Não é um triangulo"<<"\n";

}

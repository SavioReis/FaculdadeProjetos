#include <iostream>

int main()
{

    int idade = 0;

    std::cout<<"Insira sua idade : "<<"\n";
    std::cin>>idade;

    if(idade < 16 )
    std::cout<<"Você não é eleitor , pois você ainda não tem 16 anos"<<"\n";

    if(idade >= 18 && 65 )
    std::cout<<"Você é um eleitor"<<"\n";

    if(idade >= 16 && 18 || idade > 65)
    std::cout<<"Você é um eleitor facultativo"<<"\n";

}

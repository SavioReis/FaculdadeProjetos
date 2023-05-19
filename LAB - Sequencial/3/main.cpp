#include <iostream>
#include <cmath>
int main()
{
    int taxa = 0;
    int aplicacao = 0;
    int meses = 0;
	
	std::cout<<"insira a taxa : "<<"\n";
	std::cin>>taxa;
	std::cout<<"insira a aplicação mensal : "<<"\n";
	std::cin>>aplicacao;
	std::cout<<"insira os meses : "<<"\n";
	std::cin>>meses;
	
	int valoracomulado = (std::pow(1+taxa,meses)*aplicacao)/taxa;
	
	std::cout<<"Seu rendimento  : "<<valoracomulado<<"\n";

}
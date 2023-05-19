#include <iostream>
#include <cmath>
#include <iomanip>
int main()
{
   int prestacao = 0;
   int juros = 0;
   int atraso = 0;
   
   std::cout<<"Insira o valor da prestação : "<<"\n";
   std::cin>>prestacao;
   
   std::cout<<"Insira o valor da taxa de juros : "<<"\n";
   std::cin>>juros;
   
   std::cout<<"Insira o tempo de atraso : "<<"\n";
   std::cin>>atraso;
   
   int prestacaoconta = prestacao + (prestacao*(juros/100)*atraso);
   
   std::cout<<"Valor da prestação : "<<prestacaoconta<<"\n";


}
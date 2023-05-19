#include <iostream>
int main()
{
   float quantiLitros = 0;
   float conta1 = 0;
   std::string opcao = "";
   //Repita com estrutura condicional simples
   for(int repetir = 0; repetir < 3 ; repetir++){
       std::cout<<"\nDigitar a quantidade de litros : ";
       std::cin>>quantiLitros;
       std::cout<<"OPÇÕES: \n";
       std::cout<<"a – Alcool R$ 4.805\n";
       std::cout<<"d – Diesel R$ 5.953\n";
       std::cout<<"g – Gasolona R$ 6.565\n";
       std::cout<<"Digite a Opção: ";
       std::cin>>opcao;
       if(opcao == "a"){
           conta1 = quantiLitros*4.805;
           std::cout<<"Valor em Reais R$"<<conta1<<"\n";
       }
       if(opcao == "d"){
           conta1 = quantiLitros*5.593;
           std::cout<<"Valor em Reais R$"<<conta1<<"\n";
       }
       if(opcao == "g"){
           conta1 = quantiLitros*6.565;
           std::cout<<"Valor em Reais R$"<<conta1<<"\n";
       }
       if(opcao != "a" && opcao != "d" && opcao != "g"){
           std::cout<<"\n OPCAO ERRADA \n";
       }
   }
}

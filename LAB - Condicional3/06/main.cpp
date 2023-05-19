#include <iostream>
#include <cmath>
int main()
{
   int nota1 = 0;
   int nota2 = 0;
   int nota3 = 0;
   int conta1 = 0;
   int opcao = 0;
   //Repita com estrutura condicional simples
   for(int repetir = 0; repetir < 6 ; repetir++){
       std::cout<<"Insira a Nota 1 : "<<"\n";
       std::cin>>nota1;
       std::cout<<"Insira a Nota 2 : "<<"\n";
       std::cin>>nota2;
       std::cout<<"Insira a Nota 3 : "<<"\n";
       std::cin>>nota3;
       std::cout<<"OPÇÕES: \n";
       std::cout<<"1 – Aritimetica\n";
       std::cout<<"2 – Ponderada\n";
       std::cout<<"3 – Harmônica\n";
       std::cout<<"4 – geométrica\n";
       std::cout<<"5 – quadrática\n";
       std::cout<<"Digite a Opção: ";
       std::cin>>opcao;
       if(opcao == 1){
           conta1 = (nota1 + nota2 + nota3) / 3;
           std::cout<<"Media : "<<conta1<<"\n";
       }else{
           if(opcao == 2){
               conta1 = (( nota1 * 3 ) + (nota2 * 3) + (nota3 * 4)) /10;
               std::cout<<"Media : "<<conta1<<"\n";
           }else{
               if(opcao == 3){
                   conta1 =  3/(1/nota1 + 1/nota2 +1/nota3);
                   std::cout<<"Media : "<<conta1<<"\n";
               }else{
                   if(opcao == 4){
                       conta1 = std::pow(nota1+nota2+nota3,1.0/3.0);
                       std::cout<<"Media : "<<conta1<<"\n";
                   }
                       if(opcao == 5){
                          conta1 = std::sqrt((nota1*nota1)+(nota2*nota2)+(nota3*nota3));
                       std::cout<<"Media : "<<conta1<<"\n";

                       } else{
                          std::cout<<"\n OPCAO ERRADA \n";
                   }
               }
           }
       }
   }
}

#include <iostream>
#include <cmath>
int main()
{
   int raio = 0;
   int altura = 0;
   int area = 0;
   int volume = 0;
   int opcao = 0;
   //Repita com estrutura condicional simples
   for(int repetir = 0; repetir < 3 ; repetir++){
       std::cout<<"Insira o raio : "<<"\n";
       std::cin>>raio;
       std::cout<<"Insira a altura : "<<"\n";
       std::cin>>altura;
       std::cout<<"OPÇÕES: \n";
       std::cout<<"1 – Cone Reto\n";
       std::cout<<"2 – Cilindro\n";
       std::cout<<"3 – Esfera\n";
       std::cout<<"Digite a Opção: ";
       std::cin>>opcao;
       if(opcao == 1){
           volume = 3.1415*(raio*raio)+altura;
           area = 3.1415*raio*std::pow((raio*raio)+(altura*altura),1.0/3.0);
           std::cout<<"Volume : "<<volume<<"\n";
           std::cout<<"Area : "<<area<<"\n";
       }else{
           if(opcao == 2){
               volume = 3.1415*(raio*raio)*altura;
               area = 2*3.1415*raio*altura;
               std::cout<<"Volume : "<<volume<<"\n";
               std::cout<<"Area : "<<area<<"\n";
           }else{
               if(opcao == 3){
                  volume = (4/3)*3.1415*std::pow(raio,3);
                  area = 4*3.1415*raio*raio;
                  std::cout<<"Volume : "<<volume<<"\n";
                  std::cout<<"Area : "<<area<<"\n";
               }else{
                   std::cout<<"\n OPCAO ERRADA \n";
                   }
               }
           }
       }
   }
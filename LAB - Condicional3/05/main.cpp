#include <iostream>
int main()
{
   float area = 0;
   float total = 0;
   std::string nome = "";
   std::string opcao = "";
   //Repita com estrutura condicional simples
   for(int repetir = 0; repetir < 3 ; repetir++){
       std::cout<<"\nDigite o nome do fazendeiro :";
       std::cin>>nome;        
       std::cout<<"\nDigitar a area :";
       std::cin>>area;     
       std::cout<<"OPÇÕES: \n";
       std::cout<<"1 – pulverização contra ervas daninhas, R$ 50,00 por acre;\n";
       std::cout<<"2 – pulverização contra gafanhotos, R$ 100,00 por acre\n";
       std::cout<<"3 – pulverização contra broca, R$ 150,00 por acre\n";
       std::cout<<"4 – pulverização contra tudo acima, R$ 250,00 por acre\n";
       std::cout<<"Digite a Opção: ";
       std::cin>>opcao;
       if(opcao == "1"){
           total = area*50 ;
       }
       if(opcao == "2"){
           total = area*100;
       }
       if(opcao == "3"){
           total = area*150;
       }
       if(opcao == "4"){
           total = area*250;
       }
       if(opcao != "1" && opcao != "2" && opcao != "3" && opcao != "4"){
           std::cout<<"\n OPCAO ERRADA \n";
       }
   }
   if(area>300){
        total = total*0.05;
   }
   if(total>10.750){
        total = total*0.1;
   }
    std::cout<<"Fazendeiro : "<<nome<<" , Tipo de pulverização : "<<opcao<<" , Area : "<<total;
}
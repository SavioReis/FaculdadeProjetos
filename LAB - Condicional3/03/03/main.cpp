#include <iostream>
int main()
{
    int inteiro1 = 0;
    int inteiro2 = 0;
    float conta1 = 0;
    int opcao = 0;
   //Repita com estrutura condicional simples
   for(int repetir = 0; repetir < 4 ; repetir++){
       std::cout<<"\nDigitar o primeiro numero inteiro: ";
       std::cin>>inteiro1;
       std::cout<<"Digite o segundo numero inteiro";
       std::cin>>inteiro2;
       std::cout<<"OPÇÕES: \n";
       std::cout<<"1 –Adição\n";
       std::cout<<"2 – Subtração\n";
       std::cout<<"3 – Multiplicação\n";
       std::cout<<"4 – Divisão \n";
       std::cout<<"Digite a Opção: ";
       std::cin>>opcao;
       switch (opcao) {
            case 1:
                conta1 = inteiro1+inteiro2;
                std::cout<<"R :"<<conta1<<"\n";
                break;
            case 2:
                conta1 = inteiro1-inteiro2;
                std::cout<<"R :"<<conta1<<"\n";
                break;
            case 3:
               conta1 = inteiro1*inteiro2;
               std::cout<<"R : "<<conta1<<"\n";
                break;
            case 4:
                conta1 = inteiro1/inteiro2;
                std::cout<<"R :"<<conta1<<"\n";
                break;
            default:
                std::cout<<"\n OPCAO ERRADA \n";
       }
   }
}

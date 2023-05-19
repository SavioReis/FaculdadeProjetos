#include <iostream>
int main()
{
    float contaporcento = 0;
    float valorPago = 0;
    float conta1 = 0;
    int opcao = 0;
   //Repita com estrutura condicional simples
   for(int repetir = 0; repetir < 4 ; repetir++){
       std::cout<<"\nDigitar o valor pago em Reais: ";
       std::cin>>valorPago;
       std::cout<<"OPÇÕES: \n";
       std::cout<<"1 – À vista, dinheiro ou cheque, 10% de desconto\n";
       std::cout<<"2 – À vista, cartão de credito, 5% de desconto\n";
       std::cout<<"3 – Em 2 vezes, preço normal da etiqueta sem juros \n";
       std::cout<<"4 – Em 3 vezes, preço normal da etiqueta + 10% de juros \n";
       std::cout<<"Digite a Opção: ";
       std::cin>>opcao;
       switch (opcao) {
            case 1:
            	contaporcento =valorPago*0.1;
                conta1 = valorPago-contaporcento;
                std::cout<<"Valor a pagar em Reais R$"<<conta1<<"\n";
                break;
            case 2:
            	contaporcento =valorPago*0.05;
                conta1 = valorPago-contaporcento;
                std::cout<<"Valor a pagar em Reais R$"<<conta1<<"\n";
                break;
            case 3:
               conta1 = valorPago;
               std::cout<<"Valor a pagar em Reais R$"<<conta1<<"\n";
                break;
            case 4:
            	contaporcento =valorPago*0.1;
                conta1 = valorPago+contaporcento;
                std::cout<<"Valor a pagar em Reais R$"<<conta1<<"\n";
                break;
            default:
                std::cout<<"\n OPCAO ERRADA \n";
       }
   }
}

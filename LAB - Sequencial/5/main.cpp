#include <iostream>
#include <cmath>
int main()
{
   int numero;

   std::cout<<"Insira o numero"<<"\n";
   std::cin>>numero;
   
   int exib1= numero%10;
   int exib2= (numero/10)%10;
   int exib3= numero/100;
   int soma= numero+((exib1*100)+(10*exib2)+exib3);
   int soma1= soma%100;
   int soma2= (soma/10)%100;
   int soma3= soma/100;
   int verificador = (soma3*3)+(soma2*2)+soma1;
   int digito= verificador%10;
   
   std::cout<<"O digito verificador : "<<digito<<"\n";
}
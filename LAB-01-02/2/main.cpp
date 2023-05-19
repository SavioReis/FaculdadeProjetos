#include <iostream>
#include <cmath>
#include <iomanip>
int main()
{

int salarioFixo = 0;
int unidadeVendidaLCD = 0;
int unidadeVendidaLED = 0;
int unidadeVendidaPLASMA = 0;

std::cout<<"Insira o salario fixo"<<"\n";
std::cin>>salarioFixo;

std::cout<<"Unidades da tv LCD vendida"<<"\n";
std::cin>>unidadeVendidaLCD;

std::cout<<"Unidades da tv LED vendida"<<"\n";
std::cin>>unidadeVendidaLED;

std::cout<<"Unidades da tv PLASMA vendida"<<"\n";
std::cin>>unidadeVendidaPLASMA;

int comissao = (unidadeVendidaLCD*50) + (unidadeVendidaLED*60) +(unidadeVendidaPLASMA*55)+salarioFixo;

std::cout<<"O salario do empregado é de :"<<comissao<<"\n";

}

#include <iostream>

int main()
{

std::string nome = 0;
int numeroConta = 0;
float saldoBancario = 0;

std::cout<<"Insira o Nome da pessoa :"<<"\n";
std::cin>>nome;

std::cout<<"Insira o numero da sua conta bancaria : "<<"\n";
std::cin>>numeroConta;

std::cout<<"Insira seu saldo bancario"<<"\n";
std::cin>>saldoBancario;

int tarifaBasica = saldoBancario - 25;
int tarifaPrata = saldoBancario - 20;
int tarifaOuro = saldoBancario - 13;
int tarifaPremio = saldoBancario - 0;


if(saldoBancario < 1.000)
std::cout<<"Nome : "<<nome<<" , Conta Basica , "<<"Tarifa : "<<tarifaBasica;

if(saldoBancario== 1.000 && 2.000)
std::cout<<"Nome : "<<nome<<" , Conta Prata , "<<"Tarifa : "<<tarifaPrata;

if(saldoBancario== 2.000 && 3.500)
std::cout<<"Nome : "<<nome<<" , Conta Ouro , "<<"Tarifa : "<<tarifaOuro;

if(saldoBancario> 3.500)
std::cout<<"Nome : "<<nome<<" , Conta Premio , "<<"Tarifa : "<<tarifaPremio;






}

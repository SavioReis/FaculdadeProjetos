#include <iostream>
#include <cmath>
int main()
{
int publicototal = 0;

std::cout<<"Digite o publico total"<<"\n";
std::cin>>publicototal;

float total = (10*0.1)+(10*0.5)+(20*0.3)+(40*10);
float total2 = publicototal * total;

std::cout<<"Renda : "<<total2<<"\n";

}

#include <iostream>
#include <cmath>
int main()
{
 int M = 0;
 int N = 0;
 std::cout<<"\n Digite o valor de M";
 std::cin>>M;
 
 std::cout<<"\n Digite o valor de N";
 std::cin>>N;

 int L1 = (M*M)-(N*N);
 int L2 = 2*M*N;
 int hipotenusa = (M*M)+(N*N);

 std::cout<<"L1 : "<<L1<<"\n";
 std::cout<<"L2 : "<<L2<<"\n";
 std::cout<<"Hipotenusa: "<<hipotenusa<<"\n";

}

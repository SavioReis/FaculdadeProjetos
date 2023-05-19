#include <iostream>
#include <cmath>
#include <unistd.h>
#include <bits/stdc++.h>

int main(void) {
	int linha = 0;
	int coluna = 0;
	int tam = 3;
	int A[tam][tam];
	int B[tam][tam];
	int C[tam][tam];
	int opcao = 0;
	
	for(linha = 0; linha < tam; linha++){
		for(coluna = 0; coluna < tam; coluna++){
			std::cout<<"MatrizA]"<<linha<<"]["<<coluna<<"] = ";
			std::cin>>A[linha][coluna];
		}
	}
	for(linha = 0; linha < tam; linha++){
		for(coluna = 0; coluna < tam; coluna++){
			std::cout<<"MatrizB]"<<linha<<"]["<<coluna<<"] = ";
			std::cin>>B[linha][coluna];
		}
	}  
 
 	std::cout<<"Escolha uma opção : "<<"\n";
	std::cout<<"1 - Adição"<<"\n";
	std::cout<<"2 - Subtração"<<"\n";
	std::cout<<"3 - Multiplicação"<<"\n";
	std::cout<<"4 - divisão"<<"\n";
	std::cin>>opcao;
 
 	if(opcao == 1){
 		for(linha = 0; linha < tam; linha++){ 
		    for(coluna = 0; coluna < tam; coluna++){
		    	C[linha][coluna] = A[linha][coluna] + B[linha][coluna];
			}
	   }
 		for(linha = 0; linha < tam; linha++){
		    std::cout<<"\n {"; 
		    for(coluna = 0; coluna < tam; coluna++){
		    	std::cout<<C[linha][coluna];
			}
	   }  
	   std::cout<<"}";
    }
	if(opcao == 2){
 		for(linha = 0; linha < tam; linha++){ 
		    for(coluna = 0; coluna < tam; coluna++){
		    	C[linha][coluna] = A[linha][coluna] - B[linha][coluna];
			}
	   }
 		for(linha = 0; linha < tam; linha++){
		    std::cout<<"\n {"; 
		    for(coluna = 0; coluna < tam; coluna++){
		    	std::cout<<C[linha][coluna];
			}
	   }  
	   std::cout<<"}";
	}
    if(opcao == 3){
 		for(linha = 0; linha < tam; linha++){ 
		    for(coluna = 0; coluna < tam; coluna++){
		    	C[linha][coluna] = A[linha][coluna] * B[linha][coluna];
			}
	   }
 		for(linha = 0; linha < tam; linha++){
		    std::cout<<"\n {"; 
		    for(coluna = 0; coluna < tam; coluna++){
		    	std::cout<<C[linha][coluna];
			}
	   }  
	   std::cout<<"}"; 
	}
    if(opcao == 4){
 		for(linha = 0; linha < tam; linha++){ 
		    for(coluna = 0; coluna < tam; coluna++){
		    	C[linha][coluna] = A[linha][coluna] / B[linha][coluna];
			}
	   }
 		for(linha = 0; linha < tam; linha++){
		    std::cout<<"\n {"; 
		    for(coluna = 0; coluna < tam; coluna++){
		    	std::cout<<C[linha][coluna];
			}
	   }  
	   std::cout<<"}";    
	} 
    if(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4){
    	std::cout<<"Opção Errada"<<"\n";
	}
}
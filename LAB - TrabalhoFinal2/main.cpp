#include <iostream>
#include <cmath>
#include <unistd.h>
#include <bits/stdc++.h>

int main(void) {
int numeropositivo = 0;
int binario[8];
int octal[8];
int opcao = 0;
    while(numeropositivo<= 0){
    	std::cout<<"Insira um numero inteiro positivo"<<"\n";
    	std::cin>>numeropositivo;
    	if(numeropositivo < 0 ){
    		std::cout<<"Esse programa não aceita numero negativo"<<"\n";
		}
	}
	if(numeropositivo > 0){
		std::cout<<"Escolha uma opção : "<<"\n";
		std::cout<<"1 - Base 2"<<"\n";
		std::cout<<"2 - Base 8"<<"\n";
		std::cout<<"3 - Base 16"<<"\n";
		std::cout<<"4 - Sair do programa"<<"\n";
		std::cin>>opcao;
	}	
	if(opcao == 1){
	    for(int i = 0; i < 8; i++){
	    	binario[i] = numeropositivo % 2;
	    	numeropositivo /= 2;
		}
		std::cout<<"Numero em binario é : "<<"\n";
		for(int i = 7; i>=0; i--){
			std::cout<<binario[i];
		}
    }
	if(opcao == 2){
	    for(int i = 0; i < 8; i++){
	    	octal[i] = numeropositivo % 8;
	    	numeropositivo /= 8;
		}
		std::cout<<"Numero Octal é : "<<"\n";
		for(int i = 7; i>=0; i--){
			std::cout<<octal[i];
		}	
	}
    if(opcao == 3){
        std::stringstream ss;
        ss << std::hex << numeropositivo;
        std::string res = ss.str();
        std::cout << " " << res;
	}
    if(opcao == 4){
        exit(1);  
	} 
    if(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4){
    	std::cout<<"Opção Errada"<<"\n";
	}
}
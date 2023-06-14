#include <iostream>
#include <iomanip>
#include <math.h>

//Alunos : Gustavo Lucas , Augusto Santos , Sávio Reis e Gustavo Henrique Kermes

using namespace std;
class Fracao
{
	private:
		int num, den, a, b,r, aux,d1,d2,intn;	//atributos
	public:  //constructor
		Fracao(int numP=0, int denP=1)
{
	num=numP;
	den=denP;//São os metodos de funções-membros
}
	void setNum(int numP)// parametro formal
{
		num=numP;
}
	void setDen(int denP)// parametro formal
{
		den=denP;
}
	int getNum()
{
		return num;
}
	int getDen()
{
		return den;
}

	void multiplica (Fracao fracao1P , Fracao fracao2P)
{

		num = fracao1P.num*fracao2P.num;
		den = fracao1P.den*fracao2P.den;
//return aux;

}
	void divisao (Fracao fracao1P,Fracao fracao2P)
{

		num = fracao1P.num*fracao2P.den;
		den = fracao1P.den*fracao2P.num;
	//return aux;
}
double mdc(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    
    return a;


}
//Algoritmo do MMC
	double mmc(Fracao fracao1P, Fracao fracao2P){
    		return fracao1P.den * (fracao2P.den / mdc(fracao1P.den, fracao2P.den));
}
    double soma(Fracao fracao1P, Fracao fracao2P){
	num = mmc( fracao1P,fracao2P)/fracao1P.den*fracao1P.num + mmc (fracao1P,fracao2P)/fracao2P.den*fracao2P.num;
	den = mmc(fracao1P,fracao2P);
	
//    den=d1/1000000;
}
double subtracao(Fracao fracao1P,Fracao fracao2P){
	num = mmc( fracao1P,fracao2P)/fracao1P.den*fracao1P.num - mmc (fracao1P,fracao2P)/fracao2P.den*fracao2P.num;
	den = mmc(fracao1P,fracao2P);
}


double inteiro (Fracao fracao2P){
	den = fracao2P.den;
}
double inverter (Fracao fracao1P){
	num = fracao1P.num;
	den = fracao1P.den;
}
double inverter1 (Fracao fracao2P){
	num = fracao2P.num;
	den = fracao2P.den;
}
//~Fracao(){//destrutor
//cout<<"fim\n";
//}

};
int main(){
	Fracao fracao1,fracao2,fracao3,fracao4,fracao5,fracao6,fracao7,fracao8;//Objeto
	int n1,n2,d1,d2,opcao,intn;
	setlocale (LC_ALL,"");
			cout<<"\nEscreva duas frações";
			cout<<"\nnumerador 1: ";
					cin>>n1;
			cout<<"\ndenominador 1: ";
					cin>>d1;
			cout<<"\nnumerador 2: ";
					cin>>n2;
			cout<<"\ndenominador 2: ";
					cin>>d2;
	
	fracao1.setNum(n1);//parametro real ou argumento
	fracao1.setDen(d1);
	fracao2.setNum(n2);
	fracao2.setDen(d2);

	cout<<fracao1.getNum()<<"/"<<fracao1.getDen()<<"\n"<<endl;
	cout<<fracao2.getNum()<<"/"<<fracao2.getDen()<<"\n"<<endl;
	
	
	
	cout<<"Escolha um metodo para usar as frações\n";
	cout<<"\n1.soma";
	cout<<"\n2.subtracao";
	cout<<"\n3.multiplicação";
	cout<<"\n4.inverter";
	cout<<"\n5.multiplicar por um inteiro";
	cout<<"\n6.divisão\n";
			cin>>opcao;
	system("cls");
while(opcao >0 && opcao<7){

	

		if(opcao==3){
	
			fracao3.multiplica(fracao1, fracao2);
				cout<<fracao3.getNum()<<"/"<<fracao3.getDen()<<" multiplicação \n"<<endl;
				break;
	}
		else if(opcao==6){
			fracao4.divisao(fracao1, fracao2);
				cout<<fracao4.getNum()<<"/"<<fracao4.getDen()<<" divisao\n"<<endl;
				cout<<fracao4.getNum()/fracao4.getDen();
				cout<<"/";cout<<fracao4.getDen();cout<<" divisao\n"<<endl;
				cout<<"Resto: ";cout<<fracao4.getNum()%fracao4.getDen();
				break;
	}
		else if(opcao==1){
			fracao5.soma(fracao1, fracao2);
				cout<<fracao5.getNum()<<"/"<<fracao5.getDen()<<" soma com mdc\n"<<endl;
				break;
	}
		else		if(opcao==2){
			fracao8.subtracao(fracao1, fracao2);
				cout<<fracao8.getNum()<<"/"<<fracao8.getDen()<<" subtracao com mmc\n"<<endl;
				break;
	}
	else	if(opcao==4){
			fracao6.inverter(fracao1);
				cout<<fracao1.getDen()<<"/"<<fracao1.getNum()<<" invertida\n"<<endl;
			fracao6.inverter1(fracao2);
				cout<<fracao2.getDen()<<"/"<<fracao2.getNum()<<" invertida\n"<<endl;	
				break;
				
	}	
	else	if(opcao==5){
			cout<<"Qual valor será multiplicado: ";
			cin>>intn;
			fracao7.inteiro(fracao2);
				cout<<n2*intn<<"/"<<fracao7.getDen()<<" fração*inteiro\n "<<endl;
				break;
	}
}
while(opcao<1 || opcao>6){
	cout<< "opção invalida";
	
	break;
}


}


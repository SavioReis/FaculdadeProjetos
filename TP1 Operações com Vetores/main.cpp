#include <iostream>
#include <iomanip>
using namespace std;
class Vetor
{
	private:
	int tam,Nbusca;
		int*vet;
		public:
	Vetor (int tamP)
	{
		tam=tamP;
		vet=new int[tam];
			for(int i=0;i<tam;i++){
			vet[i]=0;
		}
	}
	
	int setVet(int valorP, int iP)
	{

		if(iP<0 || iP>tam-1)
	{

		return 0;

		}else{

		vet[iP]=valorP;
	
		return 1;

		}

	}
			int getVet(int iP)
	{
		if(iP<0 || iP>tam-1){
		return-1;
		}else{

		return vet[iP];
	}
		}


	double busca(Vetor vet1P,int n){
		int i;
	for(i=0;i<vet1P.tam;i++)
	{

	if(vet1P.vet[i]==n)

		return 1;		
	
	}
	}
	
	double verificar(Vetor vet1P,Vetor vet2P){
		int i;
		int v=0;
			for(i=0;i<vet1P.tam;i++)

		{

		if(vet1P.vet[i]==vet2P.vet[i])
		v=v+1;
}
		
			if(v==vet2P.tam )	
			
			return 1; 
	}
	
	void uniao(Vetor vet1P,Vetor vet2P){
		int n;
		int i=0;
		int k=0;
	n=vet1P.tam + vet2P.tam ;
		
		for(i=0;i<vet1P.tam;i++){
		
		vet[i] = vet1P.vet[i];
	}
		for(i=vet1P.tam; i<n;i++){
		
		vet[i] = vet2P.vet[k];
		k++;
	}
		
	}
	
	void lista(Vetor vet1P){
		
	int i;
	
	for(i=0;i<vet1P.tam;i++)
	{
		cout<<"\n"<<vet1P.vet[i];
	}
	
	}
	
	int tamanhoVetor(Vetor vet1P){
		int n;
		n=vet1P.tam;
		return 0;
	}
	
	double disjunto(Vetor vet1P,Vetor vet2P){
			int i;
			int v=0;
	for(i=0;i<vet1P.tam;i++)

	{

		if(vet1P.vet[i]!=vet2P.vet[i])
		v=v+1;
	}
		
			if(v==vet2P.tam )	
			
			return 1; 
	}

	void intercecao(Vetor vet1P,Vetor vet2P){
		int n;
		int i;
		int k;
        for(n=0;n<vet1P.tam;n++){
            if(vet1P.vet[n] == vet2P.vet[n]) 
			vet[n]=vet1P.vet[n];
        }k=n+1;
        for(n=0;n<vet2P.tam;n++){
            if(vet2P.vet[n] == vet1P.vet[n]){
            vet[k] = vet2P.vet[n];
            k=k+1;
            }
        }
	}
	
	int multiplica(Vetor vet1P,Vetor vet2P){

	int i;

		if(vet1P.tam !=vet2P.tam)

	return -1;
 
		else{

	for(i=0;i<vet1P.tam;i++)

		vet[i]=vet1P.vet[i] * vet2P.vet[i];
	}
		return 0;

		}

	float multiplica(Vetor vet1P,int escalarP){
	int i;
		for(i=0;i<vet1P.tam;i++)
			vet[i]=vet1P.vet[i]*escalarP;
		return 0;

		}

	double soma(Vetor vet1P,Vetor vet2P)	{

		int i;
		if(vet1P.tam !=vet2P.tam)

		return -1;
 
			else
		for(i=0;i<vet1P.tam;i++)

	{

		vet[i]=vet1P.vet[i] + vet2P.vet[i];
	}

	}
	double subtracao(Vetor vet1P,Vetor vet2P)
	{

int i;

if(vet1P.tam !=vet2P.tam)

return -1;
 
else
for(i=0;i<vet1P.tam;i++)


{
	
vet[i]=vet1P.vet[i] - vet2P.vet[i];

}

}

	
	};
		
		
		int main(){
		
			setlocale (LC_ALL,"");
	Vetor vetor1(3),vetor2(3),vetor3(3),vetor4(6),vetor5(6);
	vetor1.setVet(100,0);
	vetor1.setVet(200,1);
	vetor1.setVet(300,2);

	vetor2.setVet(10,0);
	vetor2.setVet(20,1);
	vetor2.setVet(30,2);
	
	string repetir="sim";
	int opcao;
	while (repetir =="sim"||repetir =="SIM" ){

	int Nbusca;
	
	setlocale (LC_ALL,"");
	
	
	cout<<"Escolha uma opção para usar os vetor\n";
	cout<<"\n1 > multiplicação";
	cout<<"\n2 > multiplicação por inteiro";
	cout<<"\n3 > soma";
	cout<<"\n4 > subtração";
	cout<<"\n5 > união";
	cout<<"\n6 > busca";
	cout<<"\n7 > verificador";
	cout<<"\n8 > disjunto";
	cout<<"\n9 > interceção";
	cout<<"\n\nEscolha uma opção: ";
			cin>>opcao;
	system("cls");
	
	
			if(opcao==1){
	if(vetor3.multiplica(vetor1,vetor2)==0){
		cout<<"\nmultiplica\n";
		vetor3.lista(vetor3);
	}else{
	cout<<"\nERRO NA MULTIPLICAÇÂO";
	}
}else
	
		if(opcao==2){
	vetor3.multiplica(vetor2,2);
		cout<<"\nmultiplica por real\n";
	vetor3.lista(vetor3);
	
}else
	
		if(opcao==3){
	if(vetor3.soma(vetor1,vetor2)==0){
			cout<<"\nsoma\n";
		vetor3.lista(vetor3);
	}else{
	cout<<"\nERRO NA MULTIPLICAÇÂO";
	};
	
}else
	
		if(opcao==4){
	if(vetor3.subtracao(vetor1,vetor2)==0){
			cout<<"\nsubtração\n";
		vetor3.lista(vetor3);
	}else{
	cout<<"\nERRO NA MULTIPLICAÇÂO";
	};
}else
	
		if(opcao==5){
		vetor4.uniao(vetor1,vetor2);
		cout<<"\nuniao\n";
	vetor4.lista(vetor4);
		
}else
		
			if(opcao==6){
	cout<<"\nDigite o numero a ser buscado:";
	cin>>Nbusca;
	
		if(vetor1.busca(vetor1,Nbusca)==1){
		
	cout<<"\nvalor "<<Nbusca<<" encontrado\n";
	vetor1.lista(vetor1);
	}else{
	cout<<"\nvalor não encontrado";
	};
}else
	
	
		if(opcao==7){
	if(vetor3.verificar(vetor1,vetor2)==1){
			cout<<"\nvetores são iguais\n";
			
	}else{
	cout<<"\nVetores não sao iguais";
	
	};
}else
	
		if(opcao==8){
		if(vetor3.disjunto(vetor1,vetor2)==1){
			cout<<"\nvetores são disjuntos\n";
			
	}else{
	cout<<"\nVetores não sao disjuntos";
	};
}else
	
		if(opcao==9){
		vetor5.intercecao(vetor1,vetor2);{
		cout<<"\ninterseção\n";
		vetor5.lista(vetor5);
	};
}
else cout<<"\nerror \n";
	cout<<"\n\nSe dejesa continuar digite sim: ";
	cin>>repetir;
}
}



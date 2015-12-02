#include <iostream>
#include "class_mapa.cpp"


using namespace std;

class Juego{
public:
       
    Mapa mapa1;
       
    int juego(){
           mapa1.mapa();
           mapa1.mostrar();
           
	
    int pos_ingresada;
	int pos_real = 0;
	int lleno = 0;
	bool gano = false;
	char player = 15;
	while(!gano){
		if(pos_real != -1){//comprobar si hay una error al momento de caer
			if(player == 15){
				cout<<"player 1 sonde quieres poner tu ficha?";
				player = 254;
			}
			else{
				cout<<"";
				player = 15;
			}
		}
		while(true){
			if(lleno == 42) break;
			cin>>pos_ingresada;
			pos_ingresada--;
			if(pos_ingresada <=6 && pos_ingresada>= 0) break;
			else cout<<endl<< "Ingrese un numero entre 1 y 7: ";
			if (cin.fail())	
			{						
				cin.clear();		
				char c;			
				cin>>c;			
			}						

		}
		if(lleno == 42) break;
		pos_real = mapa1.caida(pos_ingresada,player);
		if(pos_real == -1){
                    cout<<"Columna esta llena"<< endl;
                    cout<<"Ingrese un numero entre 1 y 7:";
		}else{
			gano = mapa1.comprobar(pos_real,pos_ingresada);
			lleno ++;
			system("cls");
			mapa1.mostrar();
		}
	}
	
 
                       
	system("cls");
	if(lleno == 42){
		cout<<"No hay ganador,hay un empate";
		system("pausa");
		return 0;
	}
	
		
     
	if(player == 15)
		cout<<"El jugador 2 ha ganado"<<endl;
	    
    else cout<<"El jugador 1 ha ganado"<< endl;
	    
	}
	
	
	
	
};

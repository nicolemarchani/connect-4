#include <iostream>
using namespace std;

//Typename <T>
class Mapa{
      
public:
       
  char pos[6][7];    //poner antes del pos el t ev vez del char
  void mapa(){
      for(int a =0;a <= 5; a++){	
		for(int b = 0; b<=6; b++)	
			pos[a][b] = ' ';		
 	  }
  }					
      
  void mostrar(){
	cout<<" 1   2   3   4   5   6   7\n";
	for(int a = 0; a<= 5; a++)
	{
		for(int b =0; b <= 6; b++) cout<<char(218)<<char(196)<<char(191)<<" ";
		cout<<endl;
		for(int b =0; b <= 6; b++) cout<<char(179)<<pos[a][b]<<char(179)<<" ";
		cout<<endl;
		for(int b =0; b <= 6; b++) cout<<char(192)<<char(196)<<char(217)<<" ";
		cout<<endl;
	}}
	
	int caida(int b, char player){
	if(b >=0 && b<= 6)
	{
		if(pos[0][b] == ' '){
			int i;
			for(i = 0;pos[i][b] == ' ';i++)
				if(i == 5){pos[i][b] = player;
			return i;}
			i--;
			pos[i][b] =player;
			return i;

		}
		else{
			return -1;
		}

	}
	else{
		return -1;
	}

}

bool comprobar(int a, int b){
	int vertical = 1;
	int horizontal = 1;
	int diagonal1 = 1;
	int diagonal2 = 1;
	char player = pos[a][b];
	int i;//vertical
	int ii;//horizontal
	
    //comprobar en vertical
	for(i = a +1;pos[i][b] == player && i <= 5;i++,vertical++);         
	for(i = a -1;pos[i][b] == player && i >= 0;i--,vertical++);
	if(vertical >= 4)return true;
	
    //comprobar en horizontal
	for(ii = b -1;pos[a][ii] == player && ii >= 0;ii--,horizontal++);
	for(ii = b +1;pos[a][ii] == player && ii <= 6;ii++,horizontal++);
	if(horizontal >= 4) return true;
	
    //comprobar en diagonal-izq
	for(i = a -1, ii= b -1;pos[i][ii] == player && i>=0 && ii >=0; diagonal1 ++, i --, ii --);
	for(i = a +1, ii = b+1;pos[i][ii] == player && i<=5 && ii <=6;diagonal1 ++, i ++, ii ++);
	
    //comprobar en diagonal-der
	for(i = a -1, ii= b +1;pos[i][ii] == player && i>=0 && ii <= 6; diagonal2 ++, i --, ii ++);
	for(i = a +1, ii= b -1;pos[i][ii] == player && i<=5 && ii >=0; diagonal2 ++, i ++, ii --);
	if(diagonal2 >= 4) return true;
	return false;
}
};

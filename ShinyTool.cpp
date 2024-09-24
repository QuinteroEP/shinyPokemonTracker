#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <unistd.h>
#include <ctime>

using namespace std;

void setup();
int hunt();
void writePokeData(string, string, string, time_t);
void writeHuntData(int);

int main ()
{
	int op;
	
	cout<<"\t ||WELCOME TRAINER|| \n\n";
	cout<<"1.start a new hunt\n\n";
	
	do{
		cout<<"Please pick an option...\n";
		cin>>op;
		switch(op)
		{
			case 1:
				setup();
				
				cout<<"Ready to start...";
				//sleep(2);
				
				hunt();
				break;
			default:
				cout<<"Error: invalid option.\n";
				sleep(1);
				break;
		}
	}while(op != 1);
}

void setup()
{
	time_t tiempoInicio;
	time(&tiempoInicio);
	
	string pokemon, game, meth;
	
	system("cls");
	cout<<"\t ||STARTING A NEW HUNT|| \n\n";
	
	cout<<"Pokemon: ";
	cin>>pokemon;
	cout<<"Game: ";
	cin>>game;
	cout<<"Method: ";
	cin>>meth;
	
	writePokeData(pokemon, game, meth, tiempoInicio);
	cout<<"\n\n";
}

int hunt()
{
	system("cls");
	int count;
	
	cout<<"||Press Space bar to increase the counter, press left arrow to decrease the counter, press R to finish the hunt||\n\n";
	
	cout << "Encounters: "<<count<<endl;
	while (true) 
	{
        while (true) 
		{
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) 
			{
                count++;
                break;
            } 
			
			else if (GetAsyncKeyState(VK_LEFT) & 0x8000) 
			{
                count--;
                break;
            } 
			
			else if (GetAsyncKeyState(0x52) & 0x8000) 
			{
				writeHuntData(count);
				
				cout<<"\nHunt finished, data exported\n";
            	return 0;
            }
        }
        sleep(1);
        system("cls");
        cout<<"||Press Space bar to increase the counter, press left arrow to decrease the counter, press R to finish the hunt||\n\n";
	
		cout << "Encounters: "<<count<<endl;
    }
}

void writePokeData(string pokemon, string game, string meth, time_t tiempo)
{
	ofstream archivo("caza.txt");
	if(archivo.is_open())
	{
		archivo<<"||HUNT REPORT|\n\n";
		archivo<<"Date: "<<ctime(&tiempo)<<endl;
		archivo<<"Pokemon: "<<pokemon<<endl;
		archivo<<"Game: "<<game<<endl;
		archivo<<"Method: "<<meth<<endl;
	}
}

void writeHuntData(int count)
{
	
}

//Lab 10: 3D Tic-Tac-Toe in C++
//Dane Copple
//11/10/2014
//Section 1

#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>

using namespace std;

class TicTacToe 
{
	protected:
    	char Board[3][3];

    	
  	public:
    	void CreateBoard ();
    	void DisplayBoard ();
    	void Turn();
    	bool CheckPlayer();
    	bool CheckAI();
    	bool CheckDraw();
};//end class TicTacToe

void TicTacToe::CreateBoard () //used to create values in regions
{
	Board[0][0] = '1';
	Board[0][1] = '2';
	Board[0][2] = '3';
	Board[1][0] = '4';
	Board[1][1] = '5';
	Board[1][2] = '6';
	Board[2][0] = '7';
	Board[2][1] = '8';
	Board[2][2] = '9';
	
	
}//end CreateBoard

void TicTacToe::DisplayBoard()//used to print values in said regions
{
	cout<<"\n\t   "<<"|"<<"   "<<"|"<<"   \n\t ";
	cout<<Board[0][0]<<" | "<<Board[0][1]<<" | "<<Board[0][2]<<" \n";
	cout<<"\t   "<<"|"<<"   "<<"|"<<"   \n\t";
	cout<<"-----------\n";
	cout<<"\t   "<<"|"<<"   "<<"|"<<"   \n\t ";
	cout<<Board[1][0]<<" | "<<Board[1][1]<<" | "<<Board[1][2]<<" \n";
	cout<<"\t   "<<"|"<<"   "<<"|"<<"   \n\t";
	cout<<"-----------\n";
	cout<<"\t   "<<"|"<<"   "<<"|"<<"   \n\t ";
	cout<<Board[2][0]<<" | "<<Board[2][1]<<" | "<<Board[2][2];	
	cout<<"\n\t   "<<"|"<<"   "<<"|"<<"   \n\t";
}//end DisplayBoard

bool TicTacToe::CheckPlayer()//checks to see if the player has a winning line
{

        if(Board[0][0] == 'X' && Board[0][1] == 'X' && Board[0][2] == 'X') return 1;
        if(Board[1][0] == 'X' && Board[1][1] == 'X' && Board[1][2] == 'X') return 1;
        if(Board[2][0] == 'X' && Board[2][1] == 'X' && Board[2][2] == 'X') return 1;
        if(Board[0][0] == 'X' && Board[1][0] == 'X' && Board[2][0] == 'X') return 1;
        if(Board[0][1] == 'X' && Board[1][1] == 'X' && Board[2][1] == 'X') return 1;
        if(Board[0][2] == 'X' && Board[1][2] == 'X' && Board[2][2] == 'X') return 1;
        if(Board[0][0] == 'X' && Board[1][1] == 'X' && Board[2][2] == 'X') return 1;
        if(Board[2][0] == 'X' && Board[1][1] == 'X' && Board[0][2] == 'X') return 1;

}//end CheckPlayer

bool TicTacToe::CheckAI()//checks to see if the AI has a winning line
{
        if(Board[0][0] == '0' && Board[0][1] == '0' && Board[0][2] == '0') return 1;
        if(Board[1][0] == '0' && Board[1][1] == '0' && Board[1][2] == '0') return 1;
        if(Board[2][0] == '0' && Board[2][1] == '0' && Board[2][2] == '0') return 1;
        if(Board[0][0] == '0' && Board[1][0] == '0' && Board[2][0] == '0') return 1;
        if(Board[0][1] == '0' && Board[1][1] == '0' && Board[2][1] == '0') return 1;
        if(Board[0][2] == '0' && Board[1][2] == '0' && Board[2][2] == '0') return 1;
        if(Board[0][0] == '0' && Board[1][1] == '0' && Board[2][2] == '0') return 1;
        if(Board[2][0] == '0' && Board[1][1] == '0' && Board[0][2] == '0') return 1;
}//end CheckAll

bool TicTacToe::CheckDraw()//checks to see if the board is filled
{
	 if((Board[0][0]=='X' || Board[0][0]=='0')&&
		(Board[0][1]=='X' || Board[0][1]=='0')&&
		(Board[0][2]=='X' || Board[0][2]=='0')&&
		(Board[1][0]=='X' || Board[1][0]=='0')&&
		(Board[1][1]=='X' || Board[1][1]=='0')&&
		(Board[1][2]=='X' || Board[1][2]=='0')&&
		(Board[2][0]=='X' || Board[2][0]=='0')&&
		(Board[2][1]=='X' || Board[2][1]=='0')&&
		(Board[2][2]=='X' || Board[2][2]=='0'))
			return 1;
	
}//end CheckDraw

void TicTacToe::Turn()//used for the player and AI turns
{
	int TurnCounter;
	int PlayerInput;
	int Turn=0;
	int Temp = 0;
	srand(time(NULL));
	TurnCounter = rand()%2;
	int i;
	int j;
	int x;

	if(TurnCounter == 0)
		{
			cout<<"\nYou will go first.\n\n";
			system("Pause");
		}//end if
		
	if(TurnCounter == 1)
		{
			cout<<"\nThe AI will go first.\n\n";
			system("Pause");
		}//end if
		
	while((CheckPlayer()==0) && (CheckAI()==0) && (CheckDraw()==0))//while all game-ending statements are false
	{

		
		DisplayBoard();
	    if (TurnCounter == 0)  //Player Turn
        	{
        		cout<<"\nPlease enter an open space.\n";
        		cin>>PlayerInput;
            	bool found = false;
            	while (found == false)
            		{
						//The following ifs are used to represent the region the player selects
						if(PlayerInput == 1)
							{
            					if(Board[0][0] !='X' && Board[0][0] != '0')
           					 		{
            							Board[0][0] = 'X';
            							found = true;
            							TurnCounter++;  // sets it to be the AI's turn
            							system("cls");
           							}//end inner if
           					 
           						if(Board[0][0] =='X' || Board[0][0] == '0')
           					 		{
										cout<<"\nInvalid move. Please try again.";
										found = true;
           							}//end inner if	
           			 		}//end if
           			 		
           				if(PlayerInput == 2)
							{
            					if(Board[0][1] !='X' && Board[0][1] != '0')
           					 		{
            							Board[0][1] = 'X';
            							found = true;
            							TurnCounter++;  // sets it to be the AI's turn;
            							system("cls");
           							}//end inner if
           					 
           						if(Board[0][1] =='X' || Board[0][1] == '0')
           					 		{
										cout<<"\nInvalid move. Please try again.";
										found = true;
           							}//end inner if	
           			 		}//end if
           			 		
						if(PlayerInput == 3)
							{
            					if(Board[0][2] !='X' && Board[0][2] != '0')
           					 		{
            							Board[0][2] = 'X';
            							found = true;
            							TurnCounter++;  // sets it to be the AI's turn
            							system("cls");
           							}//end inner if
           					 
           						if(Board[0][2] =='X' || Board[0][2] == '0')
           					 		{
										cout<<"\nInvalid move. Please try again.";
										found = true;
           							}//end inner if	
           			 		}//end if
           			 		
						if(PlayerInput == 4)
							{
            					if(Board[1][0] !='X' && Board[1][0] != '0')
           					 		{
            							Board[1][0] = 'X';
            							found = true;
            							TurnCounter++;  // sets it to be the AI's turn;
            							system("cls");
           							}//end inner if
           					 
           						if(Board[1][0] =='X' || Board[1][0] == '0')
           					 		{
										cout<<"\nInvalid move. Please try again.";
										found = true;
           							}//end inner if	
           			 		}//end if           			 		
           			 		
						if(PlayerInput == 5)
							{
            					if(Board[1][1] !='X' && Board[1][1] != '0')
           					 		{
            							Board[1][1] = 'X';
            							found = true;
            							TurnCounter++;  // sets it to be the AI's turn
            							system("cls");
           							}//end inner if
           					 
           						if(Board[1][1] =='X' || Board[1][1] == '0')
           					 		{
										cout<<"\nInvalid move. Please try again.";
										found = true;
           							}//end inner if	
           			 		}//end if           			 		
           			 		
						if(PlayerInput == 6)
							{
            					if(Board[1][2] !='X' && Board[1][2] != '0')
           					 		{
            							Board[1][2] = 'X';
            							found = true;
            							TurnCounter++;  // sets it to be the AI's turn
            							system("cls");
           							}//end inner if
           					 
           						if(Board[1][2] =='X' || Board[1][2] == '0')
           					 		{
										cout<<"\nInvalid move. Please try again.";
										found = true;
           							}//end inner if	
           			 		}//end if           			 		
           			 		
						if(PlayerInput == 7)
							{
            					if(Board[2][0] !='X' && Board[2][0] != '0')
           					 		{
            							Board[2][0] = 'X';
            							found = true;
            							TurnCounter++;  // sets it to be the AI's turn
            							system("cls");
           							}//end inner if
           					 
           						if(Board[2][0] =='X' || Board[2][0] == '0')
           					 		{
										cout<<"\nInvalid move. Please try again.";
										found = true;
           							}//end inner if	
           			 		}//end if   
								\
						if(PlayerInput == 8)
							{
            					if(Board[2][1] !='X' && Board[2][1] != '0')
           					 		{
            							Board[2][1] = 'X';
            							found = true;
            							TurnCounter++;  // sets it to be the AI's turn
            							system("cls");
           							}//end inner if
           					 
           						if(Board[2][1] =='X' || Board[2][1] == '0')
           					 		{
										cout<<"\nInvalid move. Please try again.";
										found = true;
           							}//end inner if	
           			 		}//end if						        			 		
           			 		
						if(PlayerInput == 9)
							{
            					if(Board[2][2] !='X' && Board[2][2] != '0')
           					 		{
            							Board[2][2] = 'X';
            							found = true;
            							TurnCounter++;  // sets it to be the AI's turn
            							system("cls");
           							}//end inner if
           					 
           						if(Board[2][2] =='X' || Board[2][2] == '0')
           					 		{
										cout<<"\nInvalid move. Please try again.";
										found = true;
           							}//end inner if	
           							
           			 		}//end if
           			 	
           			 	else
           			 		{
           			 			cout<<"\nInvalid move. Please try again.";
           			 			found = true;
           			 		}
           			}//end while
    		}//end if
    		
		x = CheckPlayer();
		if(x == 1)
			{
				break;
			}//end if
			//done to prevent the AI from going after the player wins
			
	    if (TurnCounter == 1)  //AI turn
        	{

            	bool found = false;
            	while (found == false)
            		{
            			i = rand() % 3;
            			j = rand() % 3;
           				if(Board[i][j] !='X' && Board[i][j] != '0')
            				{
            					system("cls");            					
								cout<<"AI move: "<<Board[i][j];
            					Board[i][j] = '0';
            					found = true;
            					TurnCounter--;  //sets it to be the player's turn
            				}//end inner if
           			}//end while
    		}//end if
	}
}//end Turn Function


int main () 
{
	int exit = 0;
	int Test;
	int Test2;
	int Test3;
	TicTacToe myGame;
	myGame.CreateBoard();
	
	cout<<"Hello! Welcome to a game of Tic-Tac-Toe!\nGet three in a line to win!\n\n";
	system("Pause");
	
	myGame.Turn();
	system("cls");
	
	Test = myGame.CheckPlayer();
	Test2 = myGame.CheckAI();
	Test3 = myGame.CheckDraw();
	myGame.DisplayBoard();
	
	if(Test ==1)
		{
		cout<<"\nPlayer wins!";
		return 1;
		}//end if
	
	if(Test2==1)
		{
		cout<<"\nAI wins!";
		return 1;
		}//end if
	
	if(Test!=1 && Test2!=1 && Test3==1)
		{
			cout<<"\nIt's a draw.";
			return 1;
		}//end if
}//end main

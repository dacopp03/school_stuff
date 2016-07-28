//Lab 11: AI vs. AI 3D Tic-Tac-Toe in C++
//Dane Copple & Geordie Ayers
//11/27/2014
//Section 1

#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>

using namespace std;

class TicTacToe 
{
	private:
    	char Board[3][3];
	
  	public:
    	void CreateBoard();
    	void DisplayBoard ();
    	void Turn();
    	void CheckDane(int *);
    	void CheckGeordie(int *);
    	bool CheckDraw();
};//end class TicTacToe

class _3DTicTacToe: public TicTacToe
{
	private:
		char Board[9][3];
		
};

void TicTacToe::CreateBoard() //used to create values in regions
{
	int x=0;
	int y=0;
	
	for(y = 0;y < 3;y++)
	{
		Board[x][0] = '1';
		Board[x][1] = '2';
		Board[x][2] = '3';
		Board[x+1][0] = '4';
		Board[x+1][1] = '5';
		Board[x+1][2] = '6';
		Board[x+2][0] = '7';
		Board[x+2][1] = '8';
		Board[x+2][2] = '9';
		
		x = (x+3);
	};
	
}//end CreateBoard

void TicTacToe::DisplayBoard()//used to print values in 3-Dimensional regions
{
	//Start of Top Board
	cout<<"\n\n\t   "<<"|"<<"   "<<"|"<<"   \n\t ";
	cout<<Board[0][0]<<" | "<<Board[0][1]<<" | "<<Board[0][2]<<" \n";
	cout<<"\t   "<<"|"<<"   "<<"|"<<"   \n\t";
	cout<<"-----------\n";
	cout<<"\t   "<<"|"<<"   "<<"|";
	cout<<"\t   "<<"|"<<"   "<<"|"<<"   \n\t ";
	cout<<Board[1][0]<<" | "<<Board[1][1]<<" | "<<Board[1][2]<<" \t ";
	cout<<Board[3][0]<<" | "<<Board[3][1]<<" | "<<Board[3][2]<<" \n";
	//Start of the Middle board
	cout<<"\t   "<<"|"<<"   "<<"|";
	cout<<"\t   "<<"|"<<"   "<<"|"<<"\n\t-----------";
	cout<<"\t-----------\n";
	cout<<"\t   "<<"|"<<"   "<<"|";
	cout<<"\t   "<<"|"<<"   "<<"|";
	cout<<"\t   "<<"|"<<"   "<<"|"<<"   \n\t ";
	cout<<Board[2][0]<<" | "<<Board[2][1]<<" | "<<Board[2][2]<<" \t ";
	cout<<Board[4][0]<<" | "<<Board[4][1]<<" | "<<Board[4][2]<<" \t ";
	cout<<Board[6][0]<<" | "<<Board[6][1]<<" | "<<Board[6][2]<<" \n ";
	//End of the Top board and start of the Bottom board	
	cout<<"\t   "<<"|"<<"   "<<"|";
	cout<<"\t   "<<"|"<<"   "<<"|";
	cout<<"\t   "<<"|"<<"   "<<"|"<<"   \n\t ";
	cout<<"\t\t-----------";
	cout<<"\t-----------\n";
	cout<<"\t\t\t   "<<"|"<<"   "<<"|";
	cout<<"\t   "<<"|"<<"   "<<"|\n \t\t\t ";
	cout<<Board[5][0]<<" | "<<Board[5][1]<<" | "<<Board[5][2]<<" \t ";
	cout<<Board[7][0]<<" | "<<Board[7][1]<<" | "<<Board[7][2]<<" \n ";
	//End of the Middle board
	cout<<"\t\t\t   "<<"|"<<"   "<<"|";
	cout<<"\t   "<<"|"<<"   "<<"|"<<"   \n";
	cout<<"\t\t\t\t\t-----------\n";
	cout<<"\t\t\t\t\t   "<<"|"<<"   "<<"|\n\t\t\t\t\t ";
	cout<<Board[8][0]<<" | "<<Board[8][1]<<" | "<<Board[8][2]<<" \n ";
	cout<<"\t\t\t\t\t   "<<"|"<<"   "<<"|\n";
	//End of the Bottom board
	cout<<"\t    Top\t\t  Middle\t   Bottom\n";
	
	
}//end DisplayBoard

void TicTacToe::CheckDane(int *PlayerScore)//checks to see how many lines the player has
{
	int x = 0;//used for the total number of line groupings
	int y = 0;//used for "for" functions
	int z = 0;//used in tandem with temp
	int temp = 0;//used to show statistics
	
	for(y = 0; y < 9; y++)
		{
        	if(Board[y][0] == 'X' && Board[y][1] == 'X' && Board[y][2] == 'X') x++;
    	}//end for
    	//done to check horitontally across single planes
    	
    cout<<"\nDane's horizontal lines: "<<x;
    z = x;
    
	for(y = 0; y < 9; y += 3)    
		{
	    	if(Board[y][0] == 'X' && Board[y+1][0] == 'X' && Board[y+2][0] == 'X') x++;
	    	if(Board[y][1] == 'X' && Board[y+1][1] == 'X' && Board[y+2][1] == 'X') x++;
	       	if(Board[y][2] == 'X' && Board[y+1][2] == 'X' && Board[y+2][2] == 'X') x++;
        }//end for
        //done to check vertically across single planes 
		  
    temp = (x-z);
    z = x;
    cout<<"\nDane's vertical lines: "<<temp;
    
	for(y = 0; y < 9; y += 3)
		{
        	if(Board[y][0] == 'X' && Board[y+1][1] == 'X' && Board[y+2][2] == 'X') x++;
        	if(Board[y+2][0] == 'X' && Board[y+1][1] == 'X' && Board[y][2] == 'X') x++;
		}//end for
		//done to check diagonally across single planes
		
	temp = (x-z);
	z = x;
	cout<<"\nDane's diagonal lines: "<<temp;
	
	for(y = 0; y < 3; y++)
		{
			if(Board[y][0] == 'X' && Board[y+3][0] == 'X' && Board[y+6][0] == 'X') x++;
			if(Board[y][1] == 'X' && Board[y+3][1] == 'X' && Board[y+6][1] == 'X') x++;
			if(Board[y][2] == 'X' && Board[y+3][2] == 'X' && Board[y+6][2] == 'X') x++;
		}//end for
		//done to check vertically across all planes
		
	temp = (x-z);
	cout<<"\nDane's vertical lines across planes: "<<temp;
	
	cout<<"\nDane's total score: "<<x;
	*PlayerScore = x;
}//end CheckPlayer

void TicTacToe::CheckGeordie(int *AIScore)//checks to see how many lines the AI has
{
	int x = 0;//used for the total number of line groupings
	int y = 0;//used for "for" functions
	int z = 0;//used in tandem with temp
	int temp = 0;//used to show statistics
	
	for(y = 0; y < 9; y++)
		{
        	if(Board[y][0] == '0' && Board[y][1] == '0' && Board[y][2] == '0') x++;
    	}//end for
    	//done to check horitontally across single planes
    	
    cout<<"\n\nGeordie's horizontal lines: "<<x;
    z = x;
    
	for(y = 0; y < 9; y += 3)    
		{
	    	if(Board[y][0] == '0' && Board[y+1][0] == '0' && Board[y+2][0] == '0') x++;
	    	if(Board[y][1] == '0' && Board[y+1][1] == '0' && Board[y+2][1] == '0') x++;
	       	if(Board[y][2] == '0' && Board[y+1][2] == '0' && Board[y+2][2] == '0') x++;
        }//end for
        //done to check vertically across single planes 
		  
    temp = (x-z);
    z = x;
    cout<<"\nGeordie's vertical lines: "<<temp;
    
	for(y = 0; y < 9; y += 3)
		{
        	if(Board[y][0] == '0' && Board[y+1][1] == '0' && Board[y+2][2] == '0') x++;
        	if(Board[y+2][0] == '0' && Board[y+1][1] == '0' && Board[y][2] == '0') x++;
		}//end for
		//done to check diagonally across single planes
		
	temp = (x-z);
	z = x;
	cout<<"\nGeordie's diagonal lines: "<<temp;
	
	for(y = 0; y < 3; y++)
		{
			if(Board[y][0] == '0' && Board[y+3][0] == '0' && Board[y+6][0] == '0') x++;
			if(Board[y][1] == '0' && Board[y+3][1] == '0' && Board[y+6][1] == '0') x++;
			if(Board[y][2] == '0' && Board[y+3][2] == '0' && Board[y+6][2] == '0') x++;
		}//end for
		//done to check vertically across all planes
		
	temp = (x-z);
	cout<<"\nGeordie's vertical lines across planes: "<<temp;
	
	cout<<"\nGeordie's total score: "<<x;
	*AIScore = x;
}//end CheckAl

void TicTacToe::Turn()//used for the player and AI turns
{
	int TurnCounter;//decides whether the Dane's Ai or Geordie's AI goesfirst
	int Turn = 0;//counts up until 27 turns have passed
	srand(time(NULL));
	TurnCounter = rand()%2;
	int i;//for Both AI use
	int j;//for Both AI use
	int x;//for Dane's AI use
	
	
	
	if(TurnCounter == 0)
		{
			cout<<"\nDane will go first this round.\n\n";
			system("Pause");
		}//end if
		
	if(TurnCounter == 1)
		{
			cout<<"\nGeordie will go first this round.\n\n";
			system("Pause");
			Turn = 0;
		}//end if
		
	while(Turn != 27)//while all tiles have not been filled
	{

	    if (TurnCounter == 0)  //Dane's Turn
        	{
        		bool found = false;
            	while (found == false)
            		{
            			i = rand() % 9;
            			j = rand() % 3;
           				if(Board[i][j] !='X' && Board[i][j] != '0')
            				{
            					if(i < 3)
            						{
            							system("cls");
            							Board[i][j] = 'X';
            							found = true;
            							Turn++;
            							TurnCounter++;//sets it to be the Geordie's turn  
            						}//end inner inner if
            						
            					if(i > 2 && i < 6)
            						{
            							system("cls");
            							Board[i][j] = 'X';
            							found = true;
            							Turn++; 
            							TurnCounter++;//sets it to be the Geordie's turn 
            						}//end inner inner if
            					
            					if(i > 5 && i < 9)
            						{
            							system("cls");
            							Board[i][j] = 'X';
            							found = true;
            							Turn++; 
            							TurnCounter++;//sets it to be the Geordie's turn
            						}//end inner inner if
            				}//end inner if
           			}//end inner while		
    		}//end Dane-Turn if
    	
		if(Turn == 27)
			break;
			
	    if (TurnCounter == 1)  //Geordie's AI 
        	{
        		
        		bool found = false;
        		
        		// The spaces will be chosen in sequence until the game ends.
				// Center Squares
				if(found != true && Board[4][1] !='X' && Board[4][1] != '0'){ 
					Board[4][1] = '0';
					found = true;
					Turn++; 
					TurnCounter--;	// sets do Dane's Turn
								
				};
				if(found != true && Board[1][1] !='X' && Board[1][1] != '0'){ 
					Board[1][1] = '0';
					found = true;
					Turn++; 
					TurnCounter--;	
								
				};
				if(found != true && Board[7][1] !='X' && Board[7][1] != '0'){ 
					Board[7][1] = '0';
					found = true;
					Turn++; 
					TurnCounter--;				
				};
				// Top Right Corners
				if(found != true && Board[3][2] !='X' && Board[3][2] != '0'){ 
					Board[3][2] = '0';
					found = true;
					Turn++; 
					TurnCounter--;
				};
				if(found != true && Board[0][2] !='X' && Board[0][2] != '0'){ 
					Board[0][2] = '0';
					found = true;
					Turn++; 
					TurnCounter--;	
								
				};
				if(found != true && Board[6][2] !='X' && Board[6][2] != '0'){ 
					Board[6][2] = '0';
					found = true;
					Turn++; 
					TurnCounter--;	
								
				};
				//Bottom Left Corners
				if(found != true && Board[5][0] !='X' && Board[5][0] != '0'){ 
					Board[5][0] = '0';
					found = true;
					Turn++; 
					TurnCounter--;
				};
				if(found != true && Board[2][0] !='X' && Board[2][0] != '0'){ 
					Board[2][0] = '0';
					found = true;
					Turn++; 
					TurnCounter--;	
								
				};
				if(found != true && Board[8][0] !='X' && Board[8][0] != '0'){ 
					Board[8][0] = '0';
					found = true;
					Turn++; 
					TurnCounter--;	
								
				};
				//Bottom Right Corners
				if(found != true && Board[5][2] !='X' && Board[5][2] != '0'){ 
					Board[5][2] = '0';
					found = true;
					Turn++; 
					TurnCounter--;
				};
				if(found != true && Board[2][2] !='X' && Board[2][2] != '0'){ 
					Board[2][2] = '0';
					found = true;
					Turn++; 
					TurnCounter--;	
								
				};
				if(found != true && Board[8][2] !='X' && Board[8][2] != '0'){ 
					Board[8][2] = '0';
					found = true;
					Turn++; 
					TurnCounter--;	
								
				};
				//Top Left Corners
				if(found != true && Board[3][0] !='X' && Board[3][0] != '0'){ 
					Board[3][0] = '0';
					found = true;
					Turn++; 
					TurnCounter--;
				};
				if(found != true && Board[0][0] !='X' && Board[0][0] != '0'){ 
					Board[0][0] = '0';
					found = true;
					Turn++; 
					TurnCounter--;	
								
				};
				if(found != true && Board[6][0] !='X' && Board[6][0] != '0'){ 
					Board[6][0] = '0';
					found = true;
					Turn++; 
					TurnCounter--;	
								
				};
				//Top Middle Squares
				if(found != true && Board[3][1] !='X' && Board[3][1] != '0'){ 
					Board[3][1] = '0';
					found = true;
					Turn++; 
					TurnCounter--;
				};
				if(found != true && Board[0][1] !='X' && Board[0][1] != '0'){ 
					Board[0][1] = '0';
					found = true;
					Turn++; 
					TurnCounter--;	
								
				};
				if(found != true && Board[6][1] !='X' && Board[6][1] != '0'){ 
					Board[6][1] = '0';
					found = true;
					Turn++; 
					TurnCounter--;	
			};
				//Bottom Middle Squares
				if(found != true && Board[5][1] !='X' && Board[5][1] != '0'){ 
					Board[5][1] = '0';
					found = true;
					Turn++; 
					TurnCounter--;
				};
				if(found != true && Board[2][1] !='X' && Board[2][1] != '0'){ 
					Board[2][1] = '0';
					found = true;
					Turn++; 
					TurnCounter--;	
								
				};
				if(found != true && Board[8][1] !='X' && Board[8][1] != '0'){ 
					Board[8][1] = '0';
					found = true;
					Turn++; 
					TurnCounter--;
				};
				
					//Right Middle
				if(found != true && Board[4][1] !='X' && Board[4][1] != '0'){ 
					Board[4][1] = '0';
					found = true;
					Turn++; 
					TurnCounter--;	
								
				};
				if(found != true && Board[1][1] !='X' && Board[1][1] != '0'){ 
					Board[1][1] = '0';
					found = true;
					Turn++; 
					TurnCounter--;	
								
				};
				if(found != true && Board[7][1] !='X' && Board[7][1] != '0'){ 
					Board[7][1] = '0';
					found = true;
					Turn++; 
					TurnCounter--;				
				};
				//Left Middle
				if(found != true && Board[4][2] !='X' && Board[4][2] != '0'){ 
					Board[4][2] = '0';
					found = true;
					Turn++; 
					TurnCounter--;
								
				};
				if(found != true && Board[1][2] !='X' && Board[1][2] != '0'){ 
					Board[1][2] = '0';
					found = true;
					Turn++; 
					TurnCounter--;	
								
				};
				if(found != true && Board[7][2] !='X' && Board[7][2] != '0'){ 
					Board[7][2] = '0';
					found = true;
					Turn++; 
					TurnCounter--;				
				};
				//Right Middle
				if(found != true && Board[4][0] !='X' && Board[4][0] != '0'){ 
					Board[4][0] = '0';
					found = true;
					Turn++; 
					TurnCounter--;	
								
				};
				if(found != true && Board[1][0] !='X' && Board[1][0] != '0'){ 
					Board[1][0] = '0';
					found = true;
					Turn++; 
					TurnCounter--;	
								
				};
				if(found != true && Board[7][0] !='X' && Board[7][0] != '0'){ 
					Board[7][0] = '0';
					found = true;
					Turn++; 
					TurnCounter--;				
				};
				
    		}		
	}
}

int main () 
{
	int DaneScore;//done for victory comparisons
	int GeordieScore;
	int Round = 0;//used to count the number of rounds out of 10
	int DaneWins = 0;//used for number of win comparisons
	int GeordieWins = 0;
	
	_3DTicTacToe myGame;
	
	cout<<"\nHello! Welcome to a game of 3D-Tic-Tac-Toe!\nThis version of Tic-Tac-Toe is unique, however.\n\n";
	cout<<"Here, two AI's, one made by Dane Copple and the other made by Geordie Ayers,\nwill be";
	cout<<" pitted against each other in a best of 10 match. You don't have to do \nanything but watch and hit a key when prompted!\n\n";
	cout<<"\tScoring:\n\t\t-horizontal line of 3\n\t\t-vertical line of 3 on same plane\n";
	cout<<"\t\t-diagonal line of 3\n\t\t-vertical line of 3 across planes\n\n";
	cout<<"Before you get started, I recommend you maximize the window.\n\n";
	system("pause");
	
	for(Round = 1; Round <= 10; Round++)
		{
			myGame.CreateBoard();
			myGame.Turn();
			system("cls");
	
			cout<<"\nGame "<<Round<<" results.";
	
			myGame.DisplayBoard();
			myGame.CheckDane(&DaneScore);
			myGame.CheckGeordie(&GeordieScore);

			if(DaneScore > GeordieScore)
				{
					cout<<"\n\nDane wins round "<<Round<<".\n\n";
					DaneWins++;
				}//end if
		
			if(DaneScore < GeordieScore)
				{
					cout<<"\n\nGeordie wins round "<<Round<<".\n\n";
					GeordieWins++;
				}//end if
		
			if(DaneScore == GeordieScore)
				cout<<"\n\nIt's a draw this round (Round "<<Round<<").\n\n";
			
			cout<<"Dane's wins: "<<DaneWins;
			cout<<"\nGeordie's wins: "<<GeordieWins<<"\n\n";
			system("pause");
		}//end for
		
	system("cls");
	if(DaneWins > GeordieWins)
		cout<<"\nDane wins the match!\n";

		
	if(DaneWins < GeordieWins)
		cout<<"\nGeordie wins the match!\n";

	if(DaneWins == GeordieWins)
		cout<<"\nThe match was a draw.\n";

}//end main

//Lab 8: Phone Book v3
//Dane Copple
//10/25/2014
//Section 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Phonebook_Contacts
{
	
	char fName[20];
	char lName[20];
	char uNum[20];
	
} book; //end structure, "book" is now a data type

//Following are 3 function prototypes for the main to use
void AddContact(book *, FILE *, char *);
void DeleteContact(book *, FILE *, char *);
void ViewContacts(FILE *,char *);
void SortContacts(book *, FILE *, char *);
void SearchContacts(book *, FILE *, char *);
void RandomContact(book *, FILE *File,char *);
void DelAllContacts(FILE *, char *);

main()
{
	int iUserInt;

	FILE *File;
	
	char FileName[50];

	book *phonebook;
	phonebook = (book*) malloc(sizeof(book)*100); //memory for contacts
	
	if (phonebook == NULL)
		{
			printf("No memory left. Program will now terminate.");
			return 1;
		}//end if
	
	printf("\nHello! Welcome to Dane's Phonebook Application.\n");
	
	printf("\nBefore you get started, I need to know if you are a new or existing user.\n");
	printf("\n\tNew (1)");
	printf("\n\tExisting (0)\n");
	scanf("%d", &iUserInt);
	
	if(iUserInt == 1)
		{
			system("cls");
			printf("\nIn that case, I am going to need to make a file for you to save your stuff in.\n");
			printf("\nOf course, said file will need a name. Would you like to name it yourself?\n");
			printf("\n\tYes (1)");
			printf("\n\tNo (2)\n");
			scanf("%d", &iUserInt);
			
			if(iUserInt == 1)
				{
					printf("\n\nWhat would you like to name it?\n");
					printf("\tNOTE: Do NOT put any extensions (like .txt) on your file name.\n\n");
					scanf("%s", FileName);
		
					strcat(FileName, ".txt");
					
					File = fopen(("%s", FileName), "w");
					fclose(File);//This creates the new user-named file 
					
					printf("\n\nYour file name is ""%s"".\n", FileName);
					printf("\nThis is the name you will use if you want to reopen your contacts after closing this program.\n");
				}//end inner if
				
			if(iUserInt == 2)
				{
					strcpy(FileName, "Contacts.txt");
					
					File = fopen(("%s", FileName), "w");
					fclose(File);//This creates the new system-named file 
					
					printf("\n\nAlright. I'll just name your file ""%s"".\n", FileName);
					printf("\nThis is the name you will use if you want to reopen your contacts after closing this program.\n");
				}//end other inner if
		}//end if
		
	if(iUserInt == 0)
		{
			system("cls");
			printf("What is the name of your file with the "".txt"" extension included?\n");
			scanf("%s", FileName);
			
			File = fopen(("%s", FileName), "r+");
				if(File == NULL)
				{
					printf("\nFile does not exist. Program will exit.");
					return 1;
				}//end inner if
				
			else
			{
				fclose(File);//This checks to see if the file exists
				printf("\nFile successfully opened.\n");
			}//end inner else
			
		}//end outer if
		
	do
		{
			printf("\n________________________________________\n");
			printf("\nPhonebook Menu:\n");
			printf("\n\tAdd a Contact (1)\n");
			printf("\tDelete a Contact (2)\n");
			printf("\tView Contacts (3)\n");
			printf("\tSort Contacts (4)\n");
			printf("\tSearch for a Contact (5)\n");
			printf("\tGet a Random Contact (6)\n");
			printf("\tDelete All Contacts (7)\n");
			printf("\tQuit (0)\n");
			
			printf("\nPlease choose an operation:\t");
			scanf("%d", &iUserInt);
			system("cls");
		
			switch(iUserInt)
			{
				case 1:
					AddContact(phonebook, File, FileName);
					break;
				case 2:
					DeleteContact(phonebook, File, FileName);
					break;
				case 3:
					ViewContacts(File, FileName);
					break;
				case 4:
					SortContacts(phonebook, File, FileName);
					break;
				case 5: 
					SearchContacts(phonebook, File, FileName);
					break;
				case 6:
					RandomContact(phonebook, File, FileName);
					break;
				case 7:
					DelAllContacts(File, FileName);
					break;
				case 0:
					printf("\nThank you!\n");
					return 0;
				default:
					printf("Not a valid option.\n");
					break;
			}//end switch
		}while (iUserInt != 0);//end do while
}//end main

void AddContact(book *phonebook,FILE *File, char *FileName)//function definition
{

	printf("\nPlease enter the first name of the individual.\n");
	scanf("%s", phonebook[0].fName);
	
	printf("\nPlease enter the last name of the individual.\n");
	scanf("%s", phonebook[0].lName);
	
	printf("\nPlease enter the individual's number (XXX-XXX-XXXX)\nPlease use spaces if there is no area code\n");
	scanf("%s", phonebook[0].uNum);
	
	printf("\nContact was added to the phonebook.\n");
	
	File = fopen(("%s", FileName), "a");//appends new contacts to the file
	
	if(File == NULL)
		{
			printf("\nFile didn't open correctly.");
			return;
		}//end if
				
	else
		{
			fprintf(File, "%s %s %s\n", phonebook[0].fName, phonebook[0].lName, phonebook[0].uNum);
			fclose(File);
		}//end else
		
}//end AddContact

void DeleteContact(book * phonebook, FILE *File, char *FileName)//function definition
{
	int x = 0;
	int y = 0;
	int Comp = sizeof(File);
	char delfName[20];
	char dellName[20];
	char Name1[20];
	char Name2[20];
	char Num[20];

			printf("\nPlease enter the first name of the person you want to delete.\n");
			scanf("%s",delfName);
	
			printf("Please enter the last name of the person you want to delete.\n");
			scanf("%s",dellName);
	
								
			File = fopen(("%s", FileName), "r");
				if(File == NULL)
					{
						printf("\nFile didn't open correctly.");
						return;
					}//end if
				
				else
					{
						
						while( !feof(File) )
							{
								fscanf(File, "%s %s %s", Name1, Name2, Num);
								
								if((strcmp(delfName, Name1)==0) && (strcmp(dellName, Name2)== 0))
									{
									y = 1;
									continue;
									}//end if
									
								strcpy(phonebook[x].fName, Name1);
								strcpy(phonebook[x].lName, Name2);
								strcpy(phonebook[x].uNum, Num);
								
								x++;
								
								/*the contacts are copied over from a string to a 
								corresponding string array, while ommitting the
								desired string*/

							}//end while
							
						if(y == 0)
							{
								printf("\nContact was not found.\n");
								return;
							}
					}//end else
					fclose(File);
				
		  		File = fopen(("%s", FileName), "w");//clears the original file for usage

				if(File == NULL)
					{
						printf("\nFile didn't open correctly.");
						return;
					}//end if
				
				else
					{
						for(y = 0; y <= x; y++)
							fprintf(File, "%s %s %s\n", phonebook[y].fName, phonebook[y].lName, phonebook[y].uNum);
							/*copies all of the remaining strings onto the new file*/
					
					}//end else
					fclose(File);
					
				printf("\nContact deleted.\n");

}//end DeleteContact

void ViewContacts(FILE *File, char *FileName)//function definition
{
	char Name1[20];
	char Name2[20];
	char Num[20];

	File = fopen(("%s", FileName), "r");
	
	if(File == NULL)
		{
			printf("\nFile didn't open correctly.");
			return;
		}//end if
				
	else
		{
			printf("\nUserContacts\n\n");
			fscanf(File, "%s %s %s", Name1, Name2, Num);
			
			while( !feof(File))
				{
					printf("\t%s %s\n\t%s\n\n", Name1, Name2, Num);
					fscanf(File, "%s %s %s", Name1, Name2, Num);
				}//end while
		}//end else
		
	fclose(File);
}//end ViewContacts

void SortContacts(book * phonebook, FILE *File, char *FileName)//function definition
{
		
	int i=0;
	int x=0;
	int y=0;
	int swap;
	char UserRes[6];
	char First[6] = "first";
	char Last[5] = "last";
	char Name1[20];
	char Name2[20];
	char Num[20];
	book Temp;
	
	printf("\nWould you like to sort by first or last name?\n");
	scanf("%s", UserRes);
	
	if(strcmp(UserRes, First) == 0)
		{
		File = fopen(("%s", FileName), "r");
			if(File == NULL)
				{
					printf("\nFile didn't open correctly.");
					return;
				}//end if
				
			else
				{		
					while( !feof(File) )
						{
							fscanf(File, "%s %s %s", Name1, Name2, Num);
									
							strcpy(phonebook[x].fName, Name1);
							strcpy(phonebook[x].lName, Name2);
							strcpy(phonebook[x].uNum, Num);
								
							x++;
						}//end while
				}//end else
				fclose(File);
			
		int TempCounter = (x-1);
	
		do
		{
			swap = 0;
			for(i = 1; i< TempCounter; i++)
			{
				if(strcmp(phonebook[i-1].fName, phonebook[i].fName) > 0)
				{
					Temp = phonebook[i];
					phonebook[i] = phonebook[i-1];
					phonebook[i-1] = Temp;
				
					strcpy(Temp.fName, phonebook[i].fName);
					strcpy(Temp.lName, phonebook[i].lName);
					strcpy(Temp.uNum, phonebook[i].uNum);
				
				
					swap = 1;
				}//end if
			}//end for
			TempCounter--;
		}while(swap);//end while
	
		File = fopen(("%s", FileName), "w");//clears the original file for usage

			if(File == NULL)
				{
					printf("\nFile didn't open correctly.");
					return;
				}//end if
				
			else
				{
					for(y = 0; y < (x-1); y++)
						fprintf(File, "%s %s %s\n", phonebook[y].fName, phonebook[y].lName, phonebook[y].uNum);
				}//end else
				fclose(File);
	
			printf("\n Contacts have been alphbatized by first name.\n\n" ); 
		}//end if
	
	if(strcmp(UserRes, Last) == 0)
		{
		File = fopen(("%s", FileName), "r");
			if(File == NULL)
				{
					printf("\nFile didn't open correctly.");
					return;
				}//end if
				
			else
				{		
					while( !feof(File) )
						{
							fscanf(File, "%s %s %s", Name1, Name2, Num);
									
							strcpy(phonebook[x].fName, Name1);
							strcpy(phonebook[x].lName, Name2);
							strcpy(phonebook[x].uNum, Num);
								
							x++;
						}//end while
				}//end else
				fclose(File);
			
		int TempCounter = (x-1);
	
		do
		{
			swap = 0;
			for(i = 1; i< TempCounter; i++)
			{
				if(strcmp(phonebook[i-1].lName, phonebook[i].lName) > 0)
				{
					Temp = phonebook[i];
					phonebook[i] = phonebook[i-1];
					phonebook[i-1] = Temp;
				
					strcpy(Temp.fName, phonebook[i].fName);
					strcpy(Temp.lName, phonebook[i].lName);
					strcpy(Temp.uNum, phonebook[i].uNum);
				
				
					swap = 1;
				}//end if
			}//end for
			TempCounter--;
		}while(swap);//end while
	
		File = fopen(("%s", FileName), "w");//clears the original file for usage

			if(File == NULL)
				{
					printf("\nFile didn't open correctly.");
					return;
				}//end if
				
			else
				{
					for(y = 0; y < (x-1); y++)
						fprintf(File, "%s %s %s\n", phonebook[y].fName, phonebook[y].lName, phonebook[y].uNum);
				}//end else
				fclose(File);
	
			printf("\n Contacts have been alphbatized by last name.\n\n" ); 
		}//end if
}//end Sort function

void SearchContacts(book * phonebook, FILE *File, char *FileName)//function definition 
{
	int x = 0;
	char Searchf[20];
	char Searchl[20];
	
	printf("\nEnter the first name of whom you'd like to search for.\n");
	scanf("%s", Searchf);
	
	printf("\nEnter the last name of whom you'd like to search for.\n");
	scanf("%s", Searchl);
	
	File = fopen(("%s", FileName), "r");//opens the file to find a contact
	
	if(File == NULL)
		{
			printf("\nFile didn't open correctly.");
			return;
		}//end if
				
	else
		{
			while(!feof(File))
				{
					x++;
					
					fscanf(File, "%s %s %s", phonebook[x].fName, phonebook[x].lName, phonebook[x].uNum);
						if((strcmp(phonebook[x].fName, Searchf) == 0) &&  (strcmp(phonebook[x].lName, Searchl) == 0))
							{
								printf("\n\nContact found.\n");
								printf("\t%s %s\n\t%s", phonebook[x].fName, phonebook[x].lName, phonebook[x].uNum);
								fclose(File);
								return;
							}//end if
				}//end while
			printf("\n\nContact not found.\n");
			fclose(File);
		}//end else
	

	
}//end Search function

void RandomContact(book * phonebook, FILE *File, char *FileName)//function definition
{
	int iRandom;
	void srand();
	int x=0;
	char Name1[20];
	char Name2[20];
	char Num[20];
	
			File = fopen(("%s", FileName), "r");//the file is opened for copying contacts
				if(File == NULL)
					{
						printf("\nFile didn't open correctly.");
						return;
					}//end if
				
				else
					{
						
						while( !feof(File) )
							{
								fscanf(File, "%s %s %s", Name1, Name2, Num);
								
								strcpy(phonebook[x].fName, Name1);
								strcpy(phonebook[x].lName, Name2);
								strcpy(phonebook[x].uNum, Num);
								/*all of the strings in the file are copied into string arrays,
								which are then assigned values by their repecive arrays.*/
								
								x++;
								
							}//end while
							iRandom = rand()%x;
							printf("\nYour random contact:\n");
							printf("\t%s %s\n\t%s\n\n", phonebook[iRandom].fName, phonebook[iRandom].lName, phonebook[iRandom].uNum);
							/*a random number is chosen based off of the iterations of the file,
							which is subbed into the string array to get a random value*/
							
					}//end else
					fclose(File);
}//end Random function

void DelAllContacts(FILE *File, char *FileName)//function definition
{
	int x;
	char iUserResponse[4];
	char Yes[4] = "yes";
	char No[3] = "no";
	
	printf("\nAre you sure you want to delete all contacts (yes or no)?\n");
	scanf("%s", iUserResponse);
	
	if(strcmp(iUserResponse, Yes) == 0)
		{
			File = fopen(("%s", FileName), "w");//opens a new file to "wipe" all contacts
				if(File == NULL)
					{
						printf("\nFile didn't open correctly.");
						return;
					}//end if
				
				else
					{
						fclose(File);
					}//end else
			printf("\nAll contacts have been deleted.");
		}
		
	if(strcmp(iUserResponse, No) == 0)
		{
			printf("\nRequest cancelled.");
			return;
		}//end if
}//end Nuke function

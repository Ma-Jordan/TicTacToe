//Jordan Ma 	
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
	int row, col,px,px2,po,po2,count=0,count2=0;
	bool end = false, go=true,X=false,O=false,tie=false;
	char arr[3][3] = { {'*','*','*'},{'*','*','*'},{'*','*','*'} };
	
	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			cout << setw(5) << arr[row][col];
		}
		cout << endl;
	}
	while (end != true)
	{
		while (go == true)
		{
			cout << "Player X input row#: ";
			cin >> px;
			cout << "\nPlayer X input column#: ";
			cin >> px2;
			if (arr[px - 1][px2 - 1] == '*' && px>0 && px<4)
			{
				arr[px - 1][px2 - 1] = 'X';
				cout << endl << endl;
				go = false;
				for (row = 0; row < 3; row++)
				{
					for (col = 0; col < 3; col++)
					{
						cout << setw(5) << arr[row][col];
					}
					cout << endl;
				}

			}
			else
			{
				cout << "That is an incorrect entry, retry.\n\n";
			}
		}
		go = true;
		//SINCE X ALWAYS GOES FIRST I CHECK HERE IF A TIE CONDITION HAS OCCURED
		for (row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
			{
				if (arr[row][col] == '*')
				{
					tie = false;
					break;
				}
				else
				{
					tie = true;
				}
			}
			if (tie == false)
			{
				break;
			}
		}
		if (tie == true)
		{
			cout << "\nA tie has occured. New Game.\n\n";
			end = true;
			break;
		}
		for (row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
			{
				if (arr[row][col] == 'X')
				{
					count++;
				}
				if (count == 3 && O == false)
				{
					cout << "\nPlayer X wins!\n\n";
					X = true;
					end = true;
					break;
				}
			}
			count = 0;
		}
		for (row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
			{
				if (arr[col][row] == 'X')
				{
					count++;
				}
				if (count == 3 && O == false)
				{
					cout << "\nPlayer X wins!\n\n";
					X = true;
					end = true;
					break;
				}
			}
			count = 0;
		}
		if (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X')
		{
			cout << "\nPlayer X wins!\n\n";
			end = true;
			X = true;
			break;
		}
		if (arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X')
		{
			cout << "\nPlayer X wins!\n\n";
			end = true;
			X = true;
			break;
		}
		
		//THIS WILL CONSTANTLY UPDATE DISPLAY IN PROMPT
		//YOU CAN TURN THIS ON FOR CONSTANT DISPLAY UPDATES
		/*for (row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
			{
				cout << setw(5) << arr[row][col];
			}
			cout << endl;
		}*/
		if (X == true)
		{
			go = false;
		}
		
		while (go == true)
		{
			cout << "Player O input row#: ";
			cin >> po;
			cout << "\nPlayer O input column#: ";
			cin >> po2;
			if (arr[po - 1][po2 - 1] == '*' && po > 0 && po < 4)
			{
				arr[po - 1][po2 - 1] = 'O';
				cout << endl << endl;
				go = false;
				for (row = 0; row < 3; row++)
				{
					for (col = 0; col < 3; col++)
					{
						cout << setw(5) << arr[row][col];
					}
					cout << endl;
				}
			}
			else
			{
				cout << "That is an incorrect entry, retry.\n\n";
			}
		}
		go = true;
		

		/*for (row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
			{
				cout << setw(5) << arr[row][col];
			}
			cout << endl;
		}*/
		// ALL OF THESE LOOPS AND CONDITIONAL STATEMENTS ARE TO CHECK WIN CONDITIONS
		
		for (row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
			{
				if (arr[row][col] == 'O')
				{
					count2++;
				}
				if (count2 == 3 && X==false)
				{
					cout << "\nPlayer O wins!\n\n";
					O = true;
					end = true;
					break;
				}
			}
			count2 = 0;
		}
		for (row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
			{
				if (arr[col][row] == 'O')
				{
					count2++;
				}
				if (count2 == 3 && X == false)
				{
					cout << "\nPlayer O wins!\n\n";
					O = true;
					end = true;
					break;
				}
			}
			count2 = 0;
		}
		
		if (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O')
		{
			cout << "\nPlayer O wins!\n\n";
			end = true;
			O = true;
			break;
		}
		if (arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O')
		{
			cout << "\nPlayer O wins!\n\n";
			end = true;
			O = true;
			break;
		}
	}
	return 0;
}

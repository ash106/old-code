#include<iostream>
#include<fstream>
#include<set>
#include<vector>
#include<iterator>
using namespace std;

bool userInput(set<int> row, set<int> col, set<int> grid, int userNum);
bool solve(int i, int j);

set<int> permgrid[9];
set<int> permrow[9];
set<int> permcol[9];
vector< vector<int> > boardVector(9, vector<int>(0,0));

int main()
{
	int temp, userRow, userCol, userNum;
	bool valid, solveBool;
	int choice = 1;
        int k = 0;
	
	ifstream inFile ("sudoku1.dat");

	for(int i=0; i<9; i++)
        {
		for(int j=0; j<9; j++)
		{
			inFile >> temp;
			boardVector[i].push_back(temp);
			permrow[i].insert(temp);
			permcol[j].insert(temp);
                        k = (i/3) * 3 + j/3;
			permgrid[k].insert(temp);
		}

	}
	
	cout << "Welcome to Sudoku! If you need the rules of the game, use Google." << endl;

	while(choice)
	{
		cout << endl;
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				cout << boardVector[i][j] << " ";
				if(j%3 == 2)
					cout << "| ";
			}
			if(i%3 == 2)
				cout << "\n-----------------------";
			cout << endl;
		}
                for(k=0; k<9; k++)
                {
                        //copy(permrow[k].begin(), permrow[k].end(), ostream_iterator<int>(cout, " "));
 
                        //cout << permrow[k] << " "; 
                        //cout << permcol[k] << " "; 
                        //cout << permgrid[k] << " "; 
	        }	
		cout << endl << "1. Enter a number" << endl;
		cout << "2. Solve puzzle"   << endl;
		cout << "3. Quit" << endl;
		cout << "Please choose: ";
		cin >> choice;

		if(choice == 1)
		{
                        cout << endl << "Please enter the row number, column number, and number" << endl << "you wish to insert into the slot:" << endl;
			cout << "Row number:     ";
			cin >> userRow;
			cout << "Column number:  ";
			cin >> userCol;
			cout << "Number:         ";
			cin >> userNum;

			if(boardVector[userRow-1][userCol-1])
				cout << endl << "There is already a number in that position." << endl;
			else {	
                                k = (userRow/3) * 3 + userCol/3;
		                valid = userInput(permrow[userRow], permcol[userCol], permgrid[k], userNum);
			}
			
			if(!valid)
				cout << endl << "The number you entered is not valid in that position." << endl;
			else
				boardVector[userRow-1][userCol-1] = userNum;
		}

		if(choice == 2)
		{
			cout << "before" << endl;
			for(int i = 0; i < 9; i++)
			{
				for(int j = 0; j < 9; j++)
				{
					if(!boardVector[i][j])
						cout << i << " " << j << endl;
						//solveBool = solve(i,j);
				}
			}
			cout << "after" << endl;

			if(solveBool)
			{
				cout << "The puzzle has been solved!" << endl;
				cout << endl;
				for(int i = 0; i < 9; i++)
				{
					for(int j = 0; j < 9; j++)
					{
						cout << boardVector[i][j] << " ";
						if(j%3 == 2)
							cout << "| ";
					}
					if(i%3 == 2)
						cout << "\n-----------------------";
					cout << endl;
				}
				cout << endl;
				choice = 0;
			}
			else
			{
				cout << "You screwed it up somehow!" << endl;
				choice = 0;
			}
			
		}

		
        if(choice == 3)
		{
			cout << endl << "Thanks for playing!" << endl << endl;
			choice = 0;
		}	
	
	
	
	}

	return 0;
}

bool userInput(set<int> row, set<int> col, set<int> grid, int userNum)
{
	set<int>::iterator rowCount;
	set<int>::iterator colCount;
	set<int>::iterator gridCount;
	int valid, valid2, valid3;
	
	valid = row.count(userNum);
	valid2 = col.count(userNum);
	valid3 = grid.count(userNum);
	
	for(rowCount=row.begin(); rowCount!=row.end();rowCount++)
	{
		cout << *rowCount << " ";
    }
	cout << endl;
	for(colCount=col.begin(); colCount!=col.end();colCount++)
	{
		cout << *colCount << " ";
    }
	cout << endl;
	for(gridCount=grid.begin(); gridCount!=grid.end();gridCount++)
	{
		cout << *gridCount << " ";
    }
	cout << endl;

	if(!valid && !valid2 && !valid3)
	{
		row.insert(userNum);
		col.insert(userNum);
		grid.insert(userNum);
		return true;
	}
	else
		return false;
}
bool solve(int i, int j)
{
	set<int> row, col, grid;
	bool solveBool;
	int k = 1;

	//set<int>::iterator rowCount;
	//set<int>::iterator colCount;
	//set<int>::iterator gridCount;
	
	int l, valid, valid2, valid3;
        l = (i/3)*3+j/3;

	while(k <= 9)
	{
		valid = permrow[i].count(k);
		valid2 = permcol[j].count(k);
		valid3 = permgrid[l].count(k);
	
		if(!valid && !valid2 && !valid3)
		{
			permrow[i].insert(k);
			permcol[j].insert(k);
			permgrid[l].insert(k);
			boardVector[i][j] = k;
			i = 0;
			j = 0;
			while(i <= 8)
			{
				while(j < 8)
				{
					if(!boardVector[i][j+1])
						solveBool = solve(i,j+1);
					
					if(solveBool)
						return solveBool;
					else
					{
						permrow[i].erase(k);
						permcol[j].erase(k);
                                                l = (i/3)*3+j/3;
						permgrid[l].erase(k);
					}
					j++;
				}
				i++;
			}
		}
		k++;
	}
	return false;
}

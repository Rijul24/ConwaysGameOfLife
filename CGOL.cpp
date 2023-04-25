//CONWAY'S GAME OF LIFE - MY VERSION
//CODE BELONGS TO RIJUL
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gridSize = 14;

void PrintGrid(vector<vector<int>> x)
{
    for(int r = 1 ; r < x.size()-1 ; r++)
    {
        for(int c = 1 ; c < x[r].size()-1 ; c++ )
        {
            cout << x[r][c] << " ";
        }
        cout << endl;
    }

        cout << endl;
        cout << endl;
        cout << endl;


}

int countNeighbours(vector<vector<int>> x , int r , int c)
{
    return x[r-1][c-1] + x[r-1][c]+ x[r-1][c+1]+ x[r][c-1]+ x[r][c+1]+ x[r+1][c-1]+ x[r+1][c]+ x[r+1][c+1];

}

vector<vector<int>> CGOL(vector<vector<int>>* x , vector<vector<int>> x_copy )
{

    for(int r = 1 ; r < x_copy.size()-1 ; r++)
    {
        for(int c = 1 ; c < x_copy[r].size()-1 ; c++ )
        {
        
            int a = countNeighbours(x_copy , r , c);
            int isAlive= x_copy[r][c];    


            if((isAlive && a==2) || (isAlive && a==3)) isAlive = 1;
            else if (!isAlive && a==3) isAlive = 1;
            else isAlive = 0;

            (*x)[r][c] = isAlive;
        
        }
        
    }

   PrintGrid(*x);
   
    return (*x);


}

int main()
{
    //gridSize*gridSize grid
    vector<vector<int>> x(gridSize , vector<int> (gridSize , 0));

    //MAKING A GLIDER
    x[1][2] =1;
    x[2][3]=1;
    x[3][1]=1;
    x[3][2]=1;
    x[3][3]=1;
    
    //Intial Grid
    PrintGrid(x);


    int iteration = 1;
    cout << "Enter number of iterations : " << endl;
    cin >> iteration;

    while(iteration)
    {
        x = CGOL(&x , x);

        iteration--;
    }


    return 0;
}

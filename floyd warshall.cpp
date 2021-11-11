#include <iostream>

using namespace std;

#define INF 999
int n;
int graph[100][100];
int matrix[100][100];

void printMatrix()
{
    cout << "The shortest path matrix is :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << "The shortest path between each pair are : " << endl;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != INF && i!= j)
                cout << "<" <<i+1 << "," << j+1 << "> = " << matrix[i][j] <<endl;
        }
    }

    for (int i = 0; i < n; i++)
        if (matrix[i][i] < 0){
            cout << "Negative cycle detected";
            break;
        }

}

void floydWarshall()
{
    int i, j, k;
    int D[10][10][10];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            matrix[i][j] = graph[i][j];

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];

                D[k][i][j] = matrix[i][j];
            }
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cout << D[k][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }

    printMatrix();
}

int main()
{
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter the matrix for " << n << " nodes." << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    floydWarshall();
}

/*

4
0 3 999 7
8 0 2 999
5 999 0 1
2 999 999 0



4
{0   , 1   , 999, 999},
{999 , 0   , -1  , 999},
{999, 999, 0   ,  -1},
{-1  , 999, 999,   0}};

*/



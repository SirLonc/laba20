#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
#define SIZE 7

int** read()
{
    ifstream fin("matrix.txt");
    int** a = new int* [SIZE];
    for (int count = 0; count < SIZE; count++) {
        a[count] = new int[SIZE];
    }
    int k = 0;
    while (k++ < 1)
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                fin >> a[i][j];
            }
        }
    }
    fin.close();
    return a;
}

int main(){
    int** b = new int* [SIZE];
    for (int count = 0; count < SIZE; count++) {
        b[count] = new int[SIZE];
    }
    b = read();
    


    queue<int> Queue;
    int nodes[7]; 
    for (int i = 0; i < SIZE; i++)
        nodes[i] = 0; 
    Queue.push(0); 
    while (!Queue.empty())
    { 
        int node = Queue.front();
        Queue.pop();
        nodes[node] = 2;
        for (int j = 0; j < 7; j++)
        { 
            if (b[node][j] == 1 && nodes[j] == 0)
            { 
                Queue.push(j);
                nodes[j] = 1;
            }
        }
        cout << node + 1 << endl;
    }
    
}

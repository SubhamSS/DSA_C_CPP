#include<iostream>
#include<cstdio>

using namespace std;

class Node
{
public:
    int col;
    int val;
    Node *next;
};

class sparse_matrix
{
private:
    Node** sp_point;

public:
    sparse_matrix(int rows, int cols, int A[][]); //constructor to create LL
    ~sparse_matrix(); //destructor
};

sparse_matrix::sparse_matrix(int rows, int cols, int A[rows][cols]){

}

int main()
{
    int mat[5][6] = {{0,0,0,0,4,0},
                    {1,0,6,0,0,0},
                    {0,0,9,0,0,0},
                    {2,3,0,0,6,0},
                    {0,0,7,0,0,9}};
    sparse_matrix l(5,6,mat);


    l.Display();
    printf("Mid element:%d\n",l.mid());

    l.Insert(3,10);

    l.Display();
    printf("Mid element:%d\n",l.mid());

    printf("Length:%d\n",l.Length());

    return 0;
}
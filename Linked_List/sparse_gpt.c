#include <stdio.h>
#include <stdlib.h>

struct Node {
    int col;
    int val;
    struct Node *next;
};

struct Node **create_sparse(int rows, int cols, int arr[rows][cols]) {
    struct Node **sp_point = (struct Node **)malloc(rows * sizeof(struct Node *));

    for (int i = 0; i < rows; i++) {
        sp_point[i] = NULL;
        struct Node *last = NULL;

        for (int j = 0; j < cols; j++) {
            if (arr[i][j] != 0) {
                struct Node *t = (struct Node *)malloc(sizeof(struct Node));
                t->col = j;
                t->val = arr[i][j];
                t->next = NULL;

                if (last == NULL) {
                    sp_point[i] = t;
                    last = t;
                } else {
                    last->next = t;
                    last = t;
                }
            }
        }
    }

    return sp_point;
}

int main() {
    int mat[5][6] = {{0, 0, 0, 0, 4, 0},
                     {1, 0, 6, 0, 0, 0},
                     {0, 0, 9, 0, 0, 0},
                     {2, 3, 0, 0, 6, 0},
                     {0, 0, 7, 0, 0, 9}};

    struct Node **sp_mat = create_sparse(5, 6, mat);

    return 0;
}

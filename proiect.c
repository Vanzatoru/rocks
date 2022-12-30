#include<stdio.h>
#include<stdlib.h>
#define T 8

int attacked(int a) {
    if (a == 0)
        return 1;
    else
        return 0;
}
void attack_l(int t[T][T], int l) {
    int k;
    for (k = 0; k < T; k++) {
        if (t[l][k] != 5)
            t[l][k] = -1;
    }

}

void attack_c(int t[T][T], int c) {
    int k;
    for (k = 0; k < T; k++) {
        if (t[k][c] != 5)
            t[k][c] = -1;
    }

}

void create_table(int t[T][T]) {
    int i, j;
    for (i = 0; i < T; i++)
        for (j = 0; j < T; j++)
            t[i][j] = 0;
}

void print_table(int t[T][T]) {
    int i, j;
    for (i = 0; i < T; i++)
    {
        printf("----------------------------------------\n");
        for (j = 0; j < T; j++)
        {
            if (t[i][j] == 5)
                printf("R  |");
            else
                printf("   |");
        }
        printf("\n");
    }
}

void rock(int t[T][T], int x, int y) {
    int i, j;


    t[x][y] = 5;


    for (i = 0; i < T; i++)
    {
        for (j = 0; j < T; j++)
        {
            if (i != x && j != y)
                if (attacked(t[i][j]))
                {
                    t[i][j] = 5;
                    attack_l(t, i);
                    attack_c(t, j);

                }
        }

    }
    print_table(t);
    printf("\n\n\n");
    if (y < T)
        y++;
    if (y == T)
    {
        y = 0;
        x++;
    }
    if (x == 8)
    {

        getchar();
        exit(0);
    }
    create_table(t);

    rock(t, x, y);

}


int main() {
    int x, y;
    x = y = 0;
    int table[T][T];
    create_table(table);
    rock(table, x, y);



    return 0;
}
//骑士周游(qishizhouyou），with method of trace back
//Note:This program can list all probable ways , but costs a lot of time.
//Compiled in Code::Blocks on Ubuntu platform

//move[8][2]  eight probable directions
//chess[N][N] the order of points/grids
//pro in function trace(int ,int ,int) means pro steps jumped

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 8

int chess[N][N];
int move[8][2] = {
    { 2,  1},
    { 1,  2},
    {-1,  2},
    {-2,  1},
    {-2, -1},
    {-1, -2},
    { 1, -2},
    { 2, -1}
}; //counter-clockwise direction

inline void init() //initialize
{
    memset(chess, 0, sizeof(chess));
}

inline int canjump(int x,int y)
{
    return (x >= 0 && x < N &&
            y >= 0 && y < N &&
            !chess[x][y]);
}

inline void print()
{
    int i,j;
    for(i = 0;i < N; ++i) {
        for(j = 0; j < N; ++j)
            printf("%3d", chess[i][j]);
        printf("\n");
    }
    printf("\n");
}

void trace(int pro,int x,int y)
{
    int i;
    if(pro >= N*N)
        print();
    else {
        for(i = 0;i < 8; ++i) {
            if(canjump(x + move[i][0], y + move[i][1])) {
                chess[x += move[i][0]][y += move[i][1]] = pro+1;
                trace(pro + 1, x, y);//after finish this step,try next step
                chess[x][y] = 0;//trace back
                x -= move[i][0];
                y -= move[i][1];
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int x = 0;
    int y = 0;
    if (argc == 3) {
        x = atoi(argv[1]);
        y = atoi(argv[2]);
    }

    if (x < 0 || x >= N || y < 0 || y >= N) {
        printf("invalid number\n");
        return 1;
    }

    printf("starting from (%d, %d)\n", x, y);

    chess[x][y] = 1;
    trace(1,x,y);
    return 0;
}

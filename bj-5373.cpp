#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    for(int it = 0; it < t; it++)
    {
        cin >> n;
        char operation[3];
        char U[3][4] = {{'w', 'w', 'w', 0}, {'w', 'w', 'w', 0}, {'w', 'w', 'w', 0}};
        char D[3][4] = {{'y', 'y', 'y', 0}, {'y', 'y', 'y', 0}, {'y', 'y', 'y', 0}};
        char L[3][4] = {{'g', 'g', 'g', 0}, {'g', 'g', 'g', 0}, {'g', 'g', 'g', 0}};
        char R[3][4] = {{'b', 'b', 'b', 0}, {'b', 'b', 'b', 0}, {'b', 'b', 'b', 0}};
        char F[3][4] = {{'r', 'r', 'r', 0}, {'r', 'r', 'r', 0}, {'r', 'r', 'r', 0}};
        char B[3][4] = {{'o', 'o', 'o', 0}, {'o', 'o', 'o', 0}, {'o', 'o', 'o', 0}};

        for(int i = 0; i < n; i++)
        {
            scanf("%s", operation);
            if(operation[0] == 'U')
            {
                char c1[4] = {U[0][0], U[1][0], U[2][0], 0};
                char c2[4] = {U[0][1], U[1][1], U[2][1], 0};
                char c3[4] = {U[0][2], U[1][2], U[2][2], 0};

                // L의 r1
                char tmp1[4] = {L[0][0], L[0][1], L[0][2], 0};
                // F의 r1
                char tmp2[4] = {F[0][0], F[0][1], F[0][2], 0};
                // R의 r1
                char tmp3[4] = {R[0][0], R[0][1], R[0][2], 0};
                // B의 r1
                char tmp4[4] = {B[0][0], B[0][1], B[0][2], 0};
                // 반시계방향 회전
                if(operation[1] == '-')
                {
                    memcpy(U[0], c3, sizeof(c3));
                    memcpy(U[1], c2, sizeof(c2));
                    memcpy(U[2], c1, sizeof(c1));

                    memcpy(L[0], tmp4, sizeof(tmp1));
                    memcpy(F[0], tmp1, sizeof(tmp1));
                    memcpy(R[0], tmp2, sizeof(tmp1));
                    memcpy(B[0], tmp3, sizeof(tmp1));
                } 
                else // 시계방향 회전
                {
                    U[0][0] = c1[2];
                    U[0][1] = c1[1];
                    U[0][2] = c1[0];

                    U[1][0] = c2[2];
                    U[1][1] = c2[1];
                    U[1][2] = c2[0];

                    U[2][0] = c3[2];
                    U[2][1] = c3[1];
                    U[2][2] = c3[0];

                    memcpy(L[0], tmp2, sizeof(tmp1));
                    memcpy(F[0], tmp3, sizeof(tmp1));
                    memcpy(R[0], tmp4, sizeof(tmp1));
                    memcpy(B[0], tmp1, sizeof(tmp1));
                }
            }
            if(operation[0] == 'D')
            {
                char c1[4] = {D[0][0], D[1][0], D[2][0], 0};
                char c2[4] = {D[0][1], D[1][1], D[2][1], 0};
                char c3[4] = {D[0][2], D[1][2], D[2][2], 0};

                // F의 r3
                char tmp1[4] = {F[2][0], F[2][1], F[2][2], 0};
                // L의 r3
                char tmp2[4] = {L[2][0], L[2][1], L[2][2], 0};
                // B의 r3
                char tmp3[4] = {B[2][0], B[2][1], B[2][2], 0};
                // R의 r3
                char tmp4[4] = {R[2][0], R[2][1], R[2][2], 0};

                // 반시계방향 회전
                if(operation[1] == '-')
                {
                    memcpy(D[0], c3, sizeof(c3));
                    memcpy(D[1], c2, sizeof(c2));
                    memcpy(D[2], c1, sizeof(c1));

                    memcpy(F[2], tmp4, sizeof(tmp1));
                    memcpy(L[2], tmp1, sizeof(tmp1));
                    memcpy(B[2], tmp2, sizeof(tmp1));
                    memcpy(R[2], tmp3, sizeof(tmp1));
                } 
                else // 시계방향 회전
                {
                    D[0][0] = c1[2];
                    D[0][1] = c1[1];
                    D[0][2] = c1[0];

                    D[1][0] = c2[2];
                    D[1][1] = c2[1];
                    D[1][2] = c2[0];

                    D[2][0] = c3[2];
                    D[2][1] = c3[1];
                    D[2][2] = c3[0];


                    memcpy(F[2], tmp2, sizeof(tmp1));
                    memcpy(L[2], tmp3, sizeof(tmp1));
                    memcpy(B[2], tmp4, sizeof(tmp1));
                    memcpy(R[2], tmp1, sizeof(tmp1));
                }
            }

            if(operation[0] == 'F')
            {
                char c1[4] = {F[0][0], F[1][0], F[2][0], 0};
                char c2[4] = {F[0][1], F[1][1], F[2][1], 0};
                char c3[4] = {F[0][2], F[1][2], F[2][2], 0};

                // U의 r3
                char tmp1[4] = {U[2][0], U[2][1], U[2][2], 0};
                // L의 c3
                char tmp2[4] = {L[0][2], L[1][2], L[2][2], 0};
                // D의 r1
                char tmp3[4] = {D[0][0], D[0][1], D[0][2], 0};
                // R의 c1
                char tmp4[4] = {R[0][0], R[1][0], R[2][0], 0};

                // 반시계방향 회전
                if(operation[1] == '-')
                {
                    memcpy(F[0], c3, sizeof(c3));
                    memcpy(F[1], c2, sizeof(c2));
                    memcpy(F[2], c1, sizeof(c1));

                    memcpy(U[2], tmp4, sizeof(tmp4));
                    memcpy(D[0], tmp2, sizeof(tmp2));

                    L[0][2] = tmp1[2];
                    L[1][2] = tmp1[1];
                    L[2][2] = tmp1[0];

                    R[0][0] = tmp3[2];
                    R[1][0] = tmp3[1];
                    R[2][0] = tmp3[0];
                } 
                else // 시계방향 회전
                {
                    F[0][0] = c1[2];
                    F[0][1] = c1[1];
                    F[0][2] = c1[0];

                    F[1][0] = c2[2];
                    F[1][1] = c2[1];
                    F[1][2] = c2[0];

                    F[2][0] = c3[2];
                    F[2][1] = c3[1];
                    F[2][2] = c3[0];

                    U[2][0] = tmp2[2];
                    U[2][1] = tmp2[1];
                    U[2][2] = tmp2[0];

                    D[0][0] = tmp4[2];
                    D[0][1] = tmp4[1];
                    D[0][2] = tmp4[0];

                    L[0][2] = tmp3[0];
                    L[1][2] = tmp3[1];
                    L[2][2] = tmp3[2];

                    R[0][0] = tmp1[0];
                    R[1][0] = tmp1[1];
                    R[2][0] = tmp1[2];
                }
            }

            if(operation[0] == 'L')
            {
                char c1[4] = {L[0][0], L[1][0], L[2][0], 0};
                char c2[4] = {L[0][1], L[1][1], L[2][1], 0};
                char c3[4] = {L[0][2], L[1][2], L[2][2], 0};

                // U의 c1
                char tmp1[4] = {U[0][0], U[1][0], U[2][0], 0};
                // B의 c3
                char tmp2[4] = {B[2][2], B[1][2], B[0][2], 0};
                // D의 c1
                char tmp3[4] = {D[0][0], D[1][0], D[2][0], 0};
                // F의 c1
                char tmp4[4] = {F[0][0], F[1][0], F[2][0], 0};

                // 반시계방향 회전
                if(operation[1] == '-')
                {
                    memcpy(L[0], c3, sizeof(c3));
                    memcpy(L[1], c2, sizeof(c2));
                    memcpy(L[2], c1, sizeof(c1));

                    U[0][0] = tmp4[0];
                    U[1][0] = tmp4[1];
                    U[2][0] = tmp4[2];

                    B[0][2] = tmp1[2];
                    B[1][2] = tmp1[1];
                    B[2][2] = tmp1[0];

                    D[0][0] = tmp2[0];
                    D[1][0] = tmp2[1];
                    D[2][0] = tmp2[2];

                    F[0][0] = tmp3[0];
                    F[1][0] = tmp3[1];
                    F[2][0] = tmp3[2];
                } 
                else // 시계방향 회전
                {
                    L[0][0] = c1[2];
                    L[0][1] = c1[1];
                    L[0][2] = c1[0];

                    L[1][0] = c2[2];
                    L[1][1] = c2[1];
                    L[1][2] = c2[0];

                    L[2][0] = c3[2];
                    L[2][1] = c3[1];
                    L[2][2] = c3[0];

                    U[0][0] = tmp2[0];
                    U[1][0] = tmp2[1];
                    U[2][0] = tmp2[2];

                    B[0][2] = tmp3[2];
                    B[1][2] = tmp3[1];
                    B[2][2] = tmp3[0];

                    D[0][0] = tmp4[0];
                    D[1][0] = tmp4[1];
                    D[2][0] = tmp4[2];

                    F[0][0] = tmp1[0];
                    F[1][0] = tmp1[1];
                    F[2][0] = tmp1[2];
                }
            }

            if(operation[0] == 'R')
            {
                char c1[4] = {R[0][0], R[1][0], R[2][0], 0};
                char c2[4] = {R[0][1], R[1][1], R[2][1], 0};
                char c3[4] = {R[0][2], R[1][2], R[2][2], 0};

                // U의 c3
                char tmp1[4] = {U[0][2], U[1][2], U[2][2], 0};
                // F의 c3
                char tmp2[4] = {F[0][2], F[1][2], F[2][2], 0};
                // D의 c3
                char tmp3[4] = {D[0][2], D[1][2], D[2][2], 0};
                // B의 c1
                char tmp4[4] = {B[2][0], B[1][0], B[0][0], 0};

                // 반시계방향 회전
                if(operation[1] == '-')
                {
                    memcpy(R[0], c3, sizeof(c3));
                    memcpy(R[1], c2, sizeof(c2));
                    memcpy(R[2], c1, sizeof(c1));

                    U[0][2] = tmp4[0];
                    U[1][2] = tmp4[1];
                    U[2][2] = tmp4[2];

                    F[0][2] = tmp1[0];
                    F[1][2] = tmp1[1];
                    F[2][2] = tmp1[2];

                    D[0][2] = tmp2[0];
                    D[1][2] = tmp2[1];
                    D[2][2] = tmp2[2];

                    B[0][0] = tmp3[2];
                    B[1][0] = tmp3[1];
                    B[2][0] = tmp3[0];
                } 
                else // 시계방향 회전
                {
                    R[0][0] = c1[2];
                    R[0][1] = c1[1];
                    R[0][2] = c1[0];

                    R[1][0] = c2[2];
                    R[1][1] = c2[1];
                    R[1][2] = c2[0];

                    R[2][0] = c3[2];
                    R[2][1] = c3[1];
                    R[2][2] = c3[0];

                    U[0][2] = tmp2[0];
                    U[1][2] = tmp2[1];
                    U[2][2] = tmp2[2];

                    F[0][2] = tmp3[0];
                    F[1][2] = tmp3[1];
                    F[2][2] = tmp3[2];

                    D[0][2] = tmp4[0];
                    D[1][2] = tmp4[1];
                    D[2][2] = tmp4[2];

                    B[0][0] = tmp1[2];
                    B[1][0] = tmp1[1];
                    B[2][0] = tmp1[0];
                }
            }

            if(operation[0] == 'B')
            {
                char c1[4] = {B[0][0], B[1][0], B[2][0], 0};
                char c2[4] = {B[0][1], B[1][1], B[2][1], 0};
                char c3[4] = {B[0][2], B[1][2], B[2][2], 0};

                // D의 r3
                char tmp1[4] = {D[2][0], D[2][1], D[2][2], 0};
                // L의 c1
                char tmp2[4] = {L[0][0], L[1][0], L[2][0], 0};
                // U의 r1
                char tmp3[4] = {U[0][0], U[0][1], U[0][2], 0};
                // R의 c3
                char tmp4[4] = {R[0][2], R[1][2], R[2][2], 0};
                

                // 반시계방향 회전
                if(operation[1] == '-')
                {
                    memcpy(B[0], c3, sizeof(c3));
                    memcpy(B[1], c2, sizeof(c2));
                    memcpy(B[2], c1, sizeof(c1));

                    D[2][0] = tmp4[2];
                    D[2][1] = tmp4[1];
                    D[2][2] = tmp4[0];

                    U[0][0] = tmp2[2];
                    U[0][1] = tmp2[1];
                    U[0][2] = tmp2[0];

                    L[0][0] = tmp1[0];
                    L[1][0] = tmp1[1];
                    L[2][0] = tmp1[2];

                    R[0][2] = tmp3[0];
                    R[1][2] = tmp3[1];
                    R[2][2] = tmp3[2];
                } 
                else // 시계방향 회전
                {
                    B[0][0] = c1[2];
                    B[0][1] = c1[1];
                    B[0][2] = c1[0];

                    B[1][0] = c2[2];
                    B[1][1] = c2[1];
                    B[1][2] = c2[0];

                    B[2][0] = c3[2];
                    B[2][1] = c3[1];
                    B[2][2] = c3[0];

                    memcpy(D[2], tmp2, sizeof(tmp2));
                    memcpy(U[0], tmp4, sizeof(tmp4));

                    L[0][0] = tmp3[2];
                    L[1][0] = tmp3[1];
                    L[2][0] = tmp3[0];

                    R[0][2] = tmp1[2];
                    R[1][2] = tmp1[1];
                    R[2][2] = tmp1[0];
                }
            }
        }
        printf("%s\n%s\n%s\n", U[0], U[1], U[2]);

    }
    return 0;
}

/*
https://rubiks-cube-solver.com/fr/
*/
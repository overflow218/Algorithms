#include <iostream>
#include <vector>
using namespace std;

char program[4400];
char input[4400];

const int mod = 256;
int main()
{
    int t, m, c, s;
    cin >> t;
    for(int it = 0; it < t; it++)
    {
        // m은 메모리 배열 크기
        // c는 프로그램 코드 크기
        // s는 입력의 크기
        scanf("%d %d %d", &m, &c, &s);
        scanf("%s %s", program, input);

        vector<int> vec(m, 0);
        int loop[2] = {0};
        int pointer = 0, counter = 0, pc = 0, ic = 0;
        while(pc < c && counter <= 50000000)
        {
            counter++;
            switch (program[pc])
            {
                case '-':
                    // vec[pointer] = (vec[pointer] - 1 + mod) % mod;
                    vec[pointer] = (vec[pointer] - 1) % mod;
                    pc++;
                    break;
                case '+':
                    // vec[pointer] = (vec[pointer] + 1 + mod) % mod;
                    vec[pointer] = (vec[pointer] + 1) % mod;
                    pc++;
                    break;
                case '<':
                    pointer = (pointer - 1 + m) % m;
                    pc++;
                    break;
                case '>':
                    pointer = (pointer + 1 + m) % m;
                    pc++;
                    break;
                case '[':
                    // ] 다음명령으로 이동, 루프탈출
                    if(vec[pointer] == 0)
                    {
                        do {
                            pc++;
                        } while(program[pc] != ']');
                    }
                    pc++;
                    break;
                case ']':
                    // 다시 루프 안으로
                    loop[1] = pc;
                    if(vec[pointer] != 0)
                    {
                        do {
                            pc--;
                        } while(program[pc] != '[');
                        loop[0] = pc;
                    }
                    pc++;
                    break;
                case ',':
                    if(ic == s)
                    {
                        vec[pointer] = 255;
                    } else 
                    {
                        vec[pointer] = input[ic++];
                    }
                default:
                    pc++;
                    break;
            }
        }
        if(pc == c)
        {
            printf("Terminates\n");
        } else 
        {
            printf("Loops %d %d\n", loop[0], loop[1]);
        }
    }

    return 0;
}

/*
1
20 257 1
+[>>>>>>>++++++>>>+>>>>+[-<<<<>+<[-<<<<<<<<+<[>>>>>>>>>>>>+<<<<<<<<<<<-]>[->>>>>>>>+<<<<<<<]<<->>>>>>>>>>-]>[->]<<>+<[-<<<<<+<[>>>>>>>>>+<<<<<<<<-]>[->>>>>+<<<<]<<->>>>>>>-]>[->]<<>+<[-<<+<[>>>>>>+<<<<<-]>[->>+<]<<->>>>-]>[->]<<+>>>[[-]>+<]>]<<<<<<<<<<<<<<]
a
*/
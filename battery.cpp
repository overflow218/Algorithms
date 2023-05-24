#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <fstream>
using namespace std;

set<int> s;

void find(int x)
{
    if(x == 1) return;
    int mid = x / 2;
    s.insert(x);
    if(x % 2 != 0) find(mid + 1);
    find(mid);
}

int main()
{
    int t, n, c;
    scanf("%d %d", &t, &n);

    FILE* file = fopen("output_003.txt", "w");

    if (file != NULL) {
        // 파일에 데이터 쓰기
        for(int test = 0; test < t; test++)
        {
            scanf("%d", &c);
            s.clear();
            find(c);
            // printf("%d\n", s.size());
            fprintf(file, "%d\n", (int)s.size());

            auto it = s.begin();
            for(auto x:s)
            {
                int left = x / 2;
                int right = x % 2 == 0 ? left : left + 1;
                // printf("%d %d\n", right, left);
                fprintf(file, "%d %d\n", right, left);
            }
            printf("Ci: %d, result: %d\n", c, s.size());
        }
        fclose(file);
    } else {
        // 파일 열기 실패 시 처리
        std::cout << "파일을 열 수 없습니다." << std::endl;
    }

    // for(int test = 0; test < t; test++)
    // {
    //     scanf("%d", &c);
    //     s.clear();
    //     find(c);
    //     printf("%d\n", s.size());

    //     auto it = s.begin();
    //     for(auto x:s)
    //     {
    //         int left = x / 2;
    //         int right = x % 2 == 0 ? left : left + 1;
    //         printf("%d %d\n", right, left);
    //     }
    // }

    return 0;
}

/*
5 1
1 2 3 4 5

10 2
6 7 8 9 10 11 12 13 14 15

10 3
39908183 46444543 100000000 51637660 58394864 66580672 67108863 89209343 67172424 67108864

100 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100

250 5
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122 123 124 125 126 127 128 129 130 131 132 133 134 135 136 137 138 139 140 141 142 143 144 145 146 147 148 149 150 151 152 153 154 155 156 157 158 159 160 161 162 163 164 165 166 167 168 169 170 171 172 173 174 175 176 177 178 179 180 181 182 183 184 185 186 187 188 189 190 191 192 193 194 195 196 197 198 199 200 201 202 203 204 205 206 207 208 209 210 211 212 213 214 215 216 217 218 219 220 221 222 223 224 225 226 227 228 229 230 231 232 233 234 235 236 237 238 239 240 241 242 243 244 245 246 247 248 249 250

10 6
524288 25384 524287 599357 300028 1000000 281351 29910 685951 357887

10 7
39908183 46444543 100000000 51637660 58394864 66580672 67108863 89209343 67172424 67108864


5를 만든다고 했을떄
1 1
1 2
2 3
5 5
5 10
-> ans: 5가 나와야함.

1 14
7 7
1 6 
3 3
1 2
1 1


이거 여러가지 생각해봤는데 쉬운문제 아니래
addition chain exponential 이라고 불리는 암호학에서 엄청나게 중요한
NP 문제라고 하네요... 교수님이 원하셨던건 이걸 푸는게 아니라 굉장히 어려운 문제를 만났을떄
완벽한 답을 구하는것이 아닌 당장 문제 해결에 필요한 만큼의 결과를 검색하고 찾아내는 능력을 기르는 것이었다고 하심
그런 면에서 보았을때 지피티를 이런곳에다가 활용하는건 좋은 부분인거 같음
*/
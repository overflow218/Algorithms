#include <iostream>
#include <vector>
using namespace std;

int inOrder[100000] = {0};
int postOrder[100000] = {0};

void preOrder(int iS, int iE, int pS, int pE)
{
    if(iS == iE)
    {
        printf("%d ", inOrder[iS]);
        return;
    }

    for(int i = iS; i <= iE; i++)
    {
        if(inOrder[i] == postOrder[pE])
        {
            printf("%d ", postOrder[pE]);
            preOrder(iS, i - 1, pS, pS + i - iS - 1);
            return preOrder(i + 1, iE, pS + i - iS, pE - 1);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &inOrder[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &postOrder[i]);
    }

    preOrder(0, n -1, 0, n - 1);
    printf("\n");
    return 0;
}
#include "bridge.h"

void find_bridges(int N)
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(count_crosses(i, j) == -1)
                report_bridge(i, j);
        }
    }
}
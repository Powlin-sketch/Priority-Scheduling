
#include <stdio.h>

int main()
{
    int n, i, j, time = 0, k;
    int at[10], bt[10], p[10];
    int ct[10], tat[10], wt[10];
    int done[10] = {0};

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter AT, BT and Priority: ");
        scanf("%d%d%d", &at[i], &bt[i], &p[i]);
    }

    for(i = 0; i < n; i++)
    {
        k = -1;

        for(j = 0; j < n; j++)
        {
            if(!done[j] && at[j] <= time &&
              (k == -1 || p[j] < p[k]))
                k = j;
        }

        if(k == -1)
        {
            time++;
            i--;
            continue;
        }

        time += bt[k];
        ct[k] = time;
        tat[k] = ct[k] - at[k];
        wt[k] = tat[k] - bt[k];
        done[k] = 1;
    }

    printf("\nProcess\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\n",
        i+1, ct[i], tat[i], wt[i]);
    }

    return 0;
}

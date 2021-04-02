

#include "stdio.h"


double calculate(double weight[], double cost[], double capacity, int num)
{
    double temp[num], total_cost;
    int i, j;

    for (i = 0; i < num; i++)
    {
        if (weight[i] > capacity)
        {
            break;
        }

        temp[i] = 1.0;
        total_cost += cost[i];
        capacity -= weight[i];
    }

    if (i < num)
    {
        temp[i] = capacity / weight[i];
    }

    total_cost += temp[i] * cost[i];

    return total_cost;
}


void swap(double *a, double *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}


void sort(double *arr_1, double *arr_2, double *arr_3, int num)
{
    int i, j;

    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (*(arr_1 + i) < *(arr_1 + j))
            {
                swap((arr_1 + i), (arr_1 + j));
                swap((arr_2 + i), (arr_2 + j));
                swap((arr_3 + i), (arr_3 + j));
            }
        }
    }
}


int main()
{
    int num, i;

    printf("\nEnter the number of items - ");
    scanf("%d", &num);

    double weight[num], cost[num], ratio[num], capacity;

    printf("\nEnter the capacity - ");
    scanf("%lf", &capacity);

    for (i = 0; i < num; i++)
    {
        printf("\nEnter the weight and cost of item %d respectively.\n", i + 1);
        scanf("%lf%lf", &weight[i], &cost[i]);

        ratio[i] = cost[i] / weight[i];
    }

    sort(ratio, weight, cost, num);
    printf("\nTotal profit will be - %lf\n", calculate(weight, cost, capacity, num));
}


/* OUTPUT

Enter the number of items - 3

Enter the capacity - 50

Enter the weight and cost of item 1 respectively.
10 60

Enter the weight and cost of item 2 respectively.
20 100

Enter the weight and cost of item 3 respectively.
30 120

Total profit will be - 240.000000

*/

#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int item_no; 
    int profit;
    int weight;
    float ratio;
};

void swap(struct Item *a, struct Item *b)
{
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct Item items[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && items[left].ratio < items[smallest].ratio)
        smallest = left;
    if (right < n && items[right].ratio < items[smallest].ratio)
        smallest = right;
    if (smallest != i)
    {
        swap(&items[i], &items[smallest]);
        minHeapify(items, n, smallest);
    }
}

void minHeapSort(struct Item items[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(items, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&items[0], &items[i]);
        minHeapify(items, i, 0);
    }
}

int main()
{
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item items[n];

    // Input items
    for (int i = 0; i < n; i++)
    {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
        items[i].item_no = i + 1; 
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    
    minHeapSort(items, n);

    float maxProfit = 0.0;
    printf("\nItemNo\t\tProfit\t\t\tWeight\t\t\tAmount to be taken\n");

    for (int i = 0; i < n; i++)
    {
        if (W <= 0)
        {
            break; 
        }

        float fraction = (float)W / items[i].weight;

        if (fraction > 1.0)
        {
            fraction = 1.0;
        }

        float itemProfit = fraction * items[i].profit;
        float itemWeight = fraction * items[i].weight;

        printf("%d\t\t%.6f\t\t%.6f\t\t%.6f\n", items[i].item_no, itemProfit, itemWeight, fraction);

        maxProfit += itemProfit;
        W -= (int)itemWeight;
    }

    printf("Maximum profit: %.6f\n", maxProfit);
    return 0;
}

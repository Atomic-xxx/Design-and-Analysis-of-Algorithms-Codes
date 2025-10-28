#include <stdio.h>

struct Item {
    int weight;
    int value;
    float ratio;
};

void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

float fractionalKnapsack(struct Item items[], int n, int capacity) {
    sortItems(items, n);
    float totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // take full item
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // take fractional part
            int remain = capacity - currentWeight;
            totalValue += items[i].ratio * remain;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    float maxValue = fractionalKnapsack(items, n, capacity);

    printf("\nMaximum value in knapsack = %.2f\n", maxValue);

    return 0;
}

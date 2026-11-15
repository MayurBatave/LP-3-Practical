
#include <iostream>
#include <algorithm>
using namespace std;

struct Item
{
    int profit, weight;
};

bool compare(Item a, Item b)
{
    return (double)a.profit / a.weight >
           (double)b.profit / b.weight;
}

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter profit and weight of items:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].profit >> items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(items, items + n, compare);

    double totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        if (capacity >= items[i].weight)
        {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        }
        else
        {
            totalProfit += (double)items[i].profit *
                           capacity / items[i].weight;
            break;
        }
    }

    cout << "Maximum Profit = " << totalProfit;

    return 0;
}

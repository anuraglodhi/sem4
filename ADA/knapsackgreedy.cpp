#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct Item {
    int index;
    int profit;
    int weight;
};

bool comparepw(Item i, Item j) {
    return (float)i.profit / i.weight > (float)j.profit / j.weight;
}

int main() {
    int m;
    cout << "Enter capacity: ";
    cin >> m;
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];
    for (int i = 0; i < n; i++) {
        items[i].index = i;
        cout << "Enter profit and weight of item#" << i+1 << ": ";
        cin >> items[i].profit;
        cin >> items[i].weight;
    }
    sort(items, items + n, comparepw);

    float x[n];
    for (int i = 0; i < n; i++) {
        x[i] = 0.0f;
    }

    int totalWeight = 0;
    int i = 0;
    for (Item item: items) {
        if (item.weight + totalWeight > m) {
            break;
        }
        x[item.index] = 1.0f;
        totalWeight += item.weight;
        i++;
    }
    x[items[i].index] = (float)(m - totalWeight) / items[i].weight;

    for (float f: x) {
        cout << f << " ";
    }
    cout << endl;
}
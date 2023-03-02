#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertUnique(vector<int>& vec, int x) {
    if(find(vec.begin(), vec.end(), x) == vec.end()) {
        vec.push_back(x);
    }
}

vector<int> setUnion(vector<int> set1, vector<int> set2) {
    vector<int> un;
    int one = 0, two = 0;
    while (one < set1.size() && two < set2.size()) {
        if (set1[one] <= set2[two]) {
            insertUnique(un, set1[one]);
            one++;
        }
        if (set1[one] > set2[two]) {
            insertUnique(un, set2[two]);
            two++;
        }
    }
    while (one < set1.size()) {
        insertUnique(un, set1[one]);
        one++;
    }
    while (two < set2.size()) {
        insertUnique(un, set2[two]);
        two++;
    }
    return un;
}

void print(const vector<int>& set) {
    for (int i = 0, n = set.size(); i < n ; i++) {
        cout << set[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> set1;
    vector<int> set2;
    set1.push_back(2);
    set1.push_back(4);
    set1.push_back(7);
    set2.push_back(3);
    set2.push_back(4);
    set2.push_back(8);
    sort(set1.begin(), set1.end());
    sort(set2.begin(), set2.end());

    vector<int> un = setUnion(set1, set2);

    print(un);

}
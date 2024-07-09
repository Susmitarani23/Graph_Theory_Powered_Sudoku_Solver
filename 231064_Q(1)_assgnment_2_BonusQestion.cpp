#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m, x;
        cin >> m >> x;

        vector<int> costs(m);
        for (int i = 0; i < m; ++i) {
            cin >> costs[i];
        }

        priority_queue<int, vector<int>, greater<int>> min_heap;
        long long max_happiness = 0;
        long long saved_money = 0;

        for (int i = 0; i < m; ++i) {
            int ci = costs[i];

            // Add current month's cost to the min heap
            min_heap.push(ci);

            // Add current month's salary to saved_money
            saved_money += x;

            // While we have enough money to buy happiness units
            while (!min_heap.empty() && saved_money >= min_heap.top()) {
                saved_money -= min_heap.top();
                min_heap.pop();
                max_happiness++;
            }
        }

        cout << max_happiness << "\n";
    }

    return 0;
}
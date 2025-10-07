#include <bits/stdc++.h>

bool comp(const pair<int, int> item1, pair<int, int> item2)
{
    double r1 = (double)item1.second/item1.first;
    double r2 = (double)item2.second/item2.first;
    return r1>r2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    int totalWeight=0;
    double maxVal=0;
    sort(items.begin(), items.end(), comp);
    for(int i=0; i<n; i++) {
        if(totalWeight+items[i].first < w) {
            totalWeight += items[i].first;
            maxVal += items[i].second;
        } else {
            int leftWeight = w-totalWeight;
            double leftVal = ((double)items[i].second/items[i].first) * leftWeight;
            maxVal += leftVal;
            break;
        }
    }

    return maxVal;
}
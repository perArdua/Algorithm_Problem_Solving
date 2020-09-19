#include <iostream>

#define endl "\n"

using namespace std;
int n, k;
int weight[100], value[100];
int cache[100][1001];

inline int max(int a, int b){
    if(a > b) return a;
    return b;
}
/*
knapsack(item, capacity) = knapsack(item + 1, capacity + weight[item]) + value[item]
                        + knapsack(item + 1, capacity)
*/
int knapsack(int item, int weights){
    if(item == n) return 0;
    int& ret = cache[item][weights];
    if(ret != 0) return ret;
    ret = knapsack(item + 1, weights);
    if(weights + weight[item] <= k){
        ret = max(ret, knapsack(item + 1, weights + weight[item]) + value[item]);
    }
    // for(int nextItem = item + 1; nextItem < n; ++nextItem){
    //     ret = max(ret, knapsack(nextItem, weights));
    //     if(weights + weight[item] <= k){
    //         ret = max(ret, knapsack(nextItem, weights + weight[item]) + value[item]);
    //     }    
    // }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> weight[i] >> value[i];
    }
    cout << knapsack(0, 0);
    return 0;
}
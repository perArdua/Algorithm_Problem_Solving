#include <iostream>
#include <cstring>
#define endl "\n"

using namespace std;
int n, k;
int weight[100], value[100];
int cache[100][100001];

int max(int a, int b){
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
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(cache, 0, sizeof(cache));
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> weight[i] >> value[i];
    }
    cout << knapsack(0, 0);
    return 0;
}
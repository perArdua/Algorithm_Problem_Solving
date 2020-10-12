#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    
    cin >> n;
    
    vector<int> src(n);
    for(int i = 0; i < n; ++i){
        cin >> src[i];
    }

    cin >> m;
    
    vector<int> dest(m);
    for(int i = 0; i < m; ++i){
        cin >> dest[i];
    }
    sort(src.begin(), src.end());
    for(auto e : dest){
        if(find(src.begin(), src.end(), e) != src.end()){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }


    return 0;
}
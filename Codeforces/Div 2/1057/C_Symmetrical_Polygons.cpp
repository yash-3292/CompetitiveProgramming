#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> mpp;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            mpp[x]++;
        }
        int pair = 0;
        ll perimeter = 0;
        vector<int> arr;
        for(auto it : mpp){
            pair += it.second/2;
            if((it.second&1)){
                perimeter += (ll)(it.first) * (ll)(it.second - 1);
                it.second = 1;
                arr.push_back(it.first);
            } else{
                perimeter += (ll)(it.first) * (ll)(it.second);
                it.second = 0;
            }
        }
        if(pair == 0){
            cout << 0 << endl;
            continue;
        }
        int x = -1;
        int sz = arr.size();

        if((!arr.empty()) && perimeter > arr[0]) x = 0;

        for(int i=sz-1; i>=1; i--){
            if(perimeter+(ll)arr[i-1] > (ll)arr[i]){
                x = i;
                break;
            }
        }
        if((pair == 1) && (x == -1)){
            cout << 0 << endl;
            continue;
        }
        if(x != -1){
            if(x == 0) perimeter += (ll)(arr[x]);
            else perimeter += (ll)(arr[x] + arr[x-1]);
        } 
        cout << perimeter << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,vector<int>> mpp;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            mpp[x].push_back(i);
        }
        int aans = -1;
        int lans = -1;
        int rans = -1;
        int maxi = -1;
        for(auto it : mpp){
            int sum = 0;
            int m = it.second.size();
            int l = it.second[0];
            for(int i=0; i<m; i++){
                if(i != 0) sum -= it.second[i] - it.second[i-1] - 1;
                if(sum < 0){
                    sum = 0;
                    l = it.second[i];
                }
                sum++;
                if(sum > maxi){
                    maxi = sum;
                    aans = it.first;
                    lans = l;
                    rans = it.second[i];
                }
            }
        }
        lans++; rans++;
        cout << aans << " " << lans << " " << rans << endl;
    }
    return 0;
}
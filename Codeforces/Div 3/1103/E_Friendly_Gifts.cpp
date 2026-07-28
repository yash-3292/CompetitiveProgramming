#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> mpp(n+1, 0);
    for(int len=n/2; len>=1; len--){
        int cnt = 0;
        int mini;
        int maxi;
        deque<int> dq1;
        deque<int> dq2;
        map<int,int> vis;
        int i = 0;
        int j = 0;
        while(j < n){
            mpp[arr[j]]++;
            if(mpp[arr[j]] == 1) cnt++;
            while(!dq1.empty() && arr[dq1.back()] >= arr[j]) dq1.pop_back();
            dq1.push_back(j); 
            while(!dq2.empty() && arr[dq2.back()] <= arr[j]) dq2.pop_back();
            dq2.push_back(j); 
            if(j-i+1 > len){
                mpp[arr[i]]--;
                if(mpp[arr[i]] == 0){
                    cnt--;
                }
                while(!dq1.empty() && dq1.front() <= i) dq1.pop_front();
                while(!dq2.empty() && dq2.front() <= i) dq2.pop_front();
                i++;
            }
            if(j-i+1 == len){
                int mini = arr[dq1.front()];
                int maxi = arr[dq2.front()];
                if(cnt == len && maxi - mini + 1 == len){
                    vis[mini] = 1;
                }
            }
            j++;
        }
        while(i < j){
            mpp[arr[i]]--;
            i++;
        }
        for(auto it : vis){
            if(vis.find(it.first+len) != vis.end()){
                cout << len << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
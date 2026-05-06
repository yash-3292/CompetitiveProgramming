#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
bool canDone(vector<int> tasks, int minute, int n, int m){
    vector<int> arr(n+1, minute);
    int workleft = m;
    for(int i=0; i<m; i++){
        if(arr[tasks[i]] > 0){
            arr[tasks[i]]--;
            workleft--;
        }
    }
    int workPossible = 0;
    for(int i=1; i<=n; i++){
        workPossible += arr[i]/2;
        if(workPossible >= workleft){
            return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> tasks(m);
        for(int i=0; i<m; i++) cin >> tasks[i];
        int low = 1;
        int high = 1e6;
        int ans = 1e6;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(canDone(tasks, mid, n, m)){
                ans = mid;
                high = mid-1;
            } else{
                low = mid+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
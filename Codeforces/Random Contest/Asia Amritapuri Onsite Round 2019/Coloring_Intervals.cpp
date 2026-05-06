#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(3));
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            cin >> arr[i][0] >> arr[i][1];
            arr[i][2] = i;
        }
        sort(arr.begin(), arr.end());
        int color = 1;
        int thres = 0;
        for(int i=0; i<n; i++){
            int l = arr[i][0];
            int r = arr[i][1];
            int ind = arr[i][2];
            int c = !color;
            ans[ind] = c;
            if(r > thres){
                color = c;
                thres = r;
            } 
        }
        for(auto it : ans) cout << it;
        cout << endl;
    }
    return 0;
}
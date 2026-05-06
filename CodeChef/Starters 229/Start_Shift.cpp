#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(2*n);
        for(int i=0; i<2*n; i++) cin >> arr[i];
        vector<int> ind(n+1);
        for(int i=2*n-1; i>=0; i--) ind[arr[i]] = i;
        vector<int> vis(2*n, 0);
        int thres = 2*n;
        for(int i=2*n-1; i>=0; i--){
            if(vis[i]) continue;
            int prev = ind[arr[i]];
            if(thres < prev) break;
            thres = prev;
            vis[i] = 1;
            vis[prev] = 1;
        }
        vector<int> temp;
        for(int i=0; i<2*n; i++) if(!vis[i]) temp.push_back(arr[i]);
        int flag = 1;
        int i = 0;
        int j = temp.size()-1;
        while(i < j){
            if(temp[i] != temp[j]){
                flag = 0;
                break;
            }
            i++;
            j--;
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> arr(m);
        for(int i=0; i<m; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        if(m == 1){
            cout << 2 << endl;
            continue;
        }
        vector<int> gap(m);
        gap[0] = n - arr[m-1] + arr[0] - 1;
        for(int i=1; i<m; i++){
            gap[i] = arr[i] - arr[i-1]-1;
        }
        sort(gap.begin(), gap.end(), greater<int>());
        int notInf = 0;
        int cnt = 0;
        for(int i=0; i<m; i++){
            if(cnt >= gap[i]) break;
            int num = gap[i] - cnt;
            if(num > 1) num--;
            notInf += num;
            cnt += 4;
        }
        int inf = n - notInf;
        cout << inf << endl;
    }
    return 0;
}
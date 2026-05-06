#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        int cnt = 0;
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=n-1; i>=0; i--){
            int j = i-1;
            int mini = arr[i];
            while(j != -1){
                if(mini == 0) break;
                int val = arr[j] / 2;
                if(arr[j] % 2 == 0) val--;
                if(arr[j] < mini) mini = arr[j];
                else mini = min(mini-1, val);
                j--;
            }
            cnt += i - j;
        }
        cout << cnt << endl;
    }
    return 0;
}
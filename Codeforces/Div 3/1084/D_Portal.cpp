#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int mini = INT_MAX;
        int minInd = -1;
        for(int i=x; i<y; i++){
            if(arr[i] < mini){
                mini = arr[i];
                minInd = i;
            }
        }
        int i=0;
        if(i == x) i = y;
        while(i < n && arr[i] < mini){
            cout << arr[i] << " ";
            i++;
            if(i == x) i = y;
        }
        int j = minInd;
        int cnt = y - x;
        while(cnt--){
            cout << arr[j] << " ";
            j++;
            if(j == y) j = x;
        }
        while(i < n){
            cout << arr[i] << " ";
            i++;
            if(i == x) i = y;
        }
        cout << endl;
    }
    return 0;
}
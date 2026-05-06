#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int mini = 100;
        for(int i=0; i<n; i++){
            int temp = arr[i] % k;
            if(temp != 0) temp = k - temp;
            mini = min(mini, temp);
        }
        if(k == 4){
            int even = 0;
            for(int i=0; i<n; i++){
                if(arr[i] % 2 == 0) even++;
            }
            if(even >= 2) mini = 0;
            else if(even == 1) mini = min(mini, 1);
            else mini = min(mini,2);
        }
        cout << mini << endl;
    }
    return 0;
}

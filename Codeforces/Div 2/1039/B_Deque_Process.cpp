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
        for(int i=0; i<n; i++) cin >> arr[i];
        int cnt = 0;
        int i = 0;
        int j = n-1;
        while(i < j){
            if(cnt&1){
                if(arr[i] > arr[j]){
                    cout << "LR";
                } else{
                    cout << "RL";
                }
            } else{
                if(arr[i] > arr[j]){
                    cout << "RL";
                } else{
                    cout << "LR";
                }
            }
            cnt++;
            i++;
            j--;
        }
        if(i == j){
            cout << "L";
        }
        cout << endl;
    }
    return 0;
}
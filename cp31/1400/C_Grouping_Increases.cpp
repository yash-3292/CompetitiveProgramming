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
        vector<int> a;
        vector<int> b;
        a.push_back(arr[0]);
        int ans = 0;
        for(int i=1; i<n; i++){
            if(b.empty()){
                if(arr[i] > a.back()){
                    b.push_back(arr[i]);
                } else{
                    a.push_back(arr[i]);
                }
            } else{
                if(arr[i] > a.back() && arr[i] > b.back()){
                    ans++;
                    if(a.back() <= b.back()){
                        a.push_back(arr[i]);
                    } else{
                        b.push_back(arr[i]);
                    }
                } else if(arr[i] > a.back()){
                    b.push_back(arr[i]);
                } else if(arr[i] > b.back()){
                    a.push_back(arr[i]);
                } else{
                    if(a.back() <= b.back()){
                        a.push_back(arr[i]);
                    } else{
                        b.push_back(arr[i]);
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
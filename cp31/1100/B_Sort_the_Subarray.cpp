#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr0(n);
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr0[i];
        for(int i=0; i<n; i++) cin >> arr[i];
        int flag = 1;
        for(int i=0; i<n; i++){
            if(arr0[i] != arr[i]){
                flag = 0;
                break;
            } 
        }
        int l;
        int r;
        if(flag == 1){
            int cnt = 1;
            int maxi = 1;
            l = 1;
            r = 1;
            int templ = 1;
            for(int i=1; i<n; i++){
                if(arr[i] >= arr[i-1]) cnt++;
                else{
                    if(cnt > maxi){
                        maxi = cnt;
                        l = templ;
                        r = templ + cnt - 1;
                    }
                    cnt = 1;
                    templ = i+1;
                }
            }
            if(cnt > maxi){
                maxi = cnt;
                l = templ;
                r = templ + cnt - 1;
            }
        } else{
            l = 1;
            for(int i=1; i<n; i++){
                if(arr[i] < arr[i-1]) l = i + 1;
                if(arr[i] != arr0[i]) break;
            }
            r = n;
            for(int i=n-2; i>=0; i--){
                if(arr[i] > arr[i+1]) r = i + 1;
                if(arr[i] != arr0[i]) break;
            }
        }
        cout << l << " " << r << endl;
    }
    return 0;
}
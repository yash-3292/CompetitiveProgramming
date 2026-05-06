#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int maxi = 0;
        int blank = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                blank++;
            } else{
                blank = 0;
            }
            maxi = max(maxi, blank);
        }
        cout << maxi << endl;
    }
    return 0;
}
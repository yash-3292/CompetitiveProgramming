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
        vector<int> sumMod3(3);
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sumMod3[arr[i]%3]++;
        }
        if(sumMod3[0] > 0){
            cout << "Yes" << endl;
        } else if(sumMod3[1] >= 3 || sumMod3[2] >= 3){
            cout << "Yes" << endl;
        } else if(sumMod3[1] > 0 && sumMod3[2] > 0){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(k&1){
            for(int i=0; i<k; i++) cout << n << " ";
            cout << endl;
            continue;
        }
        int rem = 0;
        vector<int> arr;
        int flag = 0;
        int msb = -1;
        for(int i=30; i>=0; i--){
            if(n&(1<<i)){
                if(flag) arr.push_back(i);
                else{
                    msb = i;
                    flag = 1;
                } 
            }
        }
        vector<int> ans;
        if(!arr.empty()){
            int ind = arr[0];
            int val = (((1<<ind)-1) | (1<<msb));
            rem = (n ^ val);
            ans.push_back(val);
        }
        int i = 1;
        while(i+1<arr.size()){
            if(ans.size() >= k-2) break;
            int ind1 = arr[i];
            int ind2 = arr[i+1];
            rem = (rem | (1<<ind1));
            rem = (rem | (1<<ind2));
            int val1 = (n ^ (1<<ind1));
            int val2 = (n ^ (1<<ind2));
            val1 = (val1 | ((1<<ind2)-1));
            val2 = (val2 | ((1<<ind2)-1));
            ans.push_back(val1);
            ans.push_back(val2);
            i += 2;
        }
        ans.push_back(rem);
        while(ans.size() < k){
            ans.push_back(n);
        }
        for(auto it : ans){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
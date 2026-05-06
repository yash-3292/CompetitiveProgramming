#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        ll pos;
        cin >> pos;
        ll total = ((ll)(n)*(ll)(n+1))/2;
        ll oppPos = total-pos+1;
        int x;
        int lo = 1;
        int hi = n;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            ll val = ((ll)(mid-1)*(ll)(mid))/2;
            if(oppPos > val){
                x = mid;
                lo = mid+1;
            } else{
                hi = mid-1;
            }
        }
        int ind = (int)((ll)x - (oppPos - ((ll)(x-1)*(ll)(x))/2) + 1);
        string temp;
        int chance = n - x;
        for(int i=0; i<n; i++){
            while(!temp.empty() && chance>0 && s[i]<temp.back()){
                temp.pop_back();
                chance--;
            }
            temp.push_back(s[i]);
        }
        while(chance > 0){
            temp.pop_back();
            chance--;
        }
        char ch = temp[ind-1];
        cout << ch;
    }
    return 0;
}
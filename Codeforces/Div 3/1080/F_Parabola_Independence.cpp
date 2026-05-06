#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void sortf(vector<vector<int>>& group, vector<int>& c){
    for(auto &arr : group){
        vector<pair<int,int>> temp;
        for(auto it : arr){
            temp.push_back({c[it], it});
        }
        
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for(int i=0; i<n; i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        vector<int> gpNum(n, -1);
        int gpsz = 0;
        for(int i=0; i<n; i++){
            int gcd1 = __gcd(a[i], b[i]);
            int a1 = a[i] / gcd1;
            int b1 = b[i] / gcd1;
            for(int j=i-1; j>=0; j--){
                int gcd2 = __gcd(a[j], b[j]);
                int a2 = a[j] / gcd2;
                int b2 = b[j] / gcd2;
                if(a1 == a2 && b1 == b2){
                    gpNum[i] = gpNum[j];
                    break;
                } 
            }
            if(gpNum[i] == -1){
                gpNum[i] = gpsz++;
            }
        }
        vector<vector<int>> group1(gpsz), group2(gpsz);
        for(int i=0; i<n; i++){
            if(a[i] > 0){
                group1[gpNum[i]].push_back(i);
            } else{
                group2[gpNum[i]].push_back(i);
            }
        }
        sortf(group1, c);
        sortf(group2, c);

    }
    return 0;
}
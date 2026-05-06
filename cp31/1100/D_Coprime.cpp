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
        map<int,int> place;
        vector<int> array;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(place[arr[i]] == 0){
                array.push_back(arr[i]);
            }
            place[arr[i]] = i + 1;
        }
        int maxi = -1;
        sort(array.begin(),array.end());
        for(int i=0; i<array.size(); i++){
            for(int j=i; j<array.size(); j++){
                if(__gcd(array[i], array[j]) == 1){
                    maxi = max(maxi, place[array[i]] + place[array[j]]);
                }
            }
        }
        cout << maxi << endl;
    }
    return 0;
}
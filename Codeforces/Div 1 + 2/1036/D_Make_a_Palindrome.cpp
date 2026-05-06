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
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        } 
        if(k == 1){
            cout << "YES" << endl;
            continue;
        }
        for(int i=0; i<n; i++){
            if(pq.size() == k-1){
                if(pq.top() > arr[i]){
                    pq.pop();
                    pq.push(arr[i]);
                }
            } else{
                pq.push(arr[i]);
            }
        } 
        vector<int> temp;
        for(int i=0; i<n; i++){
            if(arr[i] <= pq.top()){
                temp.push_back(arr[i]);
            }
        }
        int size = temp.size();
        int limit = size - k + 1;
        int i = 0;
        int j = size-1;
        int flag = 1;
        while(i <= j){
            if(temp[i] == temp[j]){
                i++;
                j--;
            } else{
                if(temp[i] == pq.top() && limit > 0){
                    limit--;
                    i++;
                } else if(temp[j] == pq.top() && limit > 0){
                    limit--;
                    j--;
                } else{
                    flag = 0;
                    break;
                }
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
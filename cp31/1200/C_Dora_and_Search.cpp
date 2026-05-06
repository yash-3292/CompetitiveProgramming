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
        int i = 0;
        int j = n-1;
        int mini = 1;
        int maxi = n;
        int flag = 0;
        while(j - i + 1 > 3){
            if(arr[i] != mini && arr[i] != maxi && arr[j] != mini && arr[j] != maxi){
                flag = 1;
                break;
            }
            if(arr[i] == mini){
                mini++;
                i++;
            } else if(arr[i] == maxi){
                maxi--;
                i++;
            }
            if(arr[j] == mini){
                mini++;
                j--;
            } else if(arr[j] == maxi){
                maxi--;
                j--;
            }
        }
        if(!flag){
            cout << -1 << endl;
            continue;
        } 
        i++;
        j++;
        cout << i << " " << j << endl;
    }
    return 0;
}
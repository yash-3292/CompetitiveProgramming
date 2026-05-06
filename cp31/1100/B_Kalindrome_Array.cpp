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
        int isPal = 1;
        int i = 0;
        int j = n-1;
        while(i <= j){
            if(arr[i] != arr[j]){
                isPal = 0;
                break;
            }
            i++;
            j--;
        }
        if(isPal){
            cout << "YES" << endl;
            continue;
        }
        int x = arr[i];
        int y = arr[j];
        int flag = 1;
        i = 0;
        j = n-1;
        while(i <= j){
            if(arr[i] != arr[j]){
                if(arr[i] == x) i++;
                else if(arr[j] == x) j--;
                else{
                    flag = 0;
                    break;
                }
            }
            else{
                i++;
                j--;
            }
        }
        if(flag){
            cout << "YES" << endl;
            continue;
        }
        flag = 1;
        i = 0;
        j = n-1;
        while(i <= j){
            if(arr[i] != arr[j]){
                if(arr[i] == y) i++;
                else if(arr[j] == y) j--;
                else{
                    flag = 0;
                    break;
                }
            }
            else{
                i++;
                j--;
            }
        }
        if(flag){
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}
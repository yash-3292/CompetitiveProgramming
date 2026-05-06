#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll merge(vector<int>& arr, int l, int mid, int r){
    vector<int> temp;
    int i = l;
    int j = mid+1;
    ll inversion = 0;
    while(i <= mid && j <= r){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        } else{
            inversion += (ll)(mid-i+1);
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= r){
        temp.push_back(arr[j]);
        j++;
    }
    for(int k=l; k<=r; k++){
        arr[k] = temp[k-l];
    }
    return inversion;
}

ll mergeSort(vector<int>& arr, int l, int r){
    if(l >= r) return 0;
    ll inversion = 0;
    int mid = l + (r-l)/2;
    inversion += mergeSort(arr, l, mid);
    inversion += mergeSort(arr, mid+1, r);
    inversion += merge(arr, l, mid, r);
    return inversion;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        ll inv1 = mergeSort(a, 0, n-1);
        ll inv2 = mergeSort(b, 0, n-1);
        if(a != b){
            cout << "NO" << endl;
            continue;
        }
        ll val = abs(inv1-inv2);
        if(val&1){
            cout << "NO" << endl;
        } else{
            cout << "YES" << endl;
        }
    }
}
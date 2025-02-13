#include<iostream>
#include<vector>
#include<utility>

using namespace std;

void result(vector<int>& v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

// worst case, average case T.C = O(n*n)

// best case T.C = O(n)

void bubbleSort(vector<int> &v){
    int n = v.size();

    for(int i = n-1; i >= 0; i--){

        int didSwap = 0;

        for(int j = 0; j < i; j++){
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
                didSwap = 1;
            }
        }

        if(didSwap == 0) break;
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    bubbleSort(v);

    result(v);

    return 0;
}
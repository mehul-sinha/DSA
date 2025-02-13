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

void insertionSort(vector<int> &v){
    int n = v.size();

    for(int i = 0; i < n; i++){
        int j = i;
        while(j>0 && v[j-1] > v[j]){
            swap(v[j-1], v[j]);
            j--;
        }
    }
}


int main(){
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    insertionSort(v);

    result(v);

    return 0;
}
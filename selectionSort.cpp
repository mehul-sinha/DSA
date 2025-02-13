#include<iostream>
#include<vector>
// #include<utility>

using namespace std;

void swap(vector<int> &v, int i, int min){
    int temp = v[i];
    v[i] = v[min];
    v[min] = temp;
}

void result(vector<int>& v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void selectionSort(vector<int>& v){
    
    int n = v.size();

    for(int i = 0; i < n-1; i++){
        int min = i;

        for(int j = i+1; j < n; j++){
            if(v[j] < v[min]) min = j;
        }
        swap(v, i , min);
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    selectionSort(v);

    result(v);

    return 0;
}




#include<iostream>
#include<vector>
#include<utility>

using namespace std;

void output(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void selectionSort(vector<int> &v){
    int n = v.size();

    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(v[j] <v[min]){
                min = j;
            }
        }
        swap(v[i], v[min]);
    }
}

void bubbleSort(vector<int> &v){
    int n = v.size();

    for(int i = n-1; i > 0; i--){
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

void insertionSort(vector<int>& v){
    int n = v.size();

    for(int i = 1; i < n; i++){
        int j = i-1;
        while(j >= 0 && v[j] > v[j+1]){
            swap(v[j], v[j+1]);
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

    // selectionSort(v);

    // bubbleSort(v);

    insertionSort(v);


    output(v);

    return 0;
    
}
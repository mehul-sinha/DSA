#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &v, int low, int mid, int high){
    vector<int> temp;
    int right = low;
    int left = mid+1;

    while(right<=mid && left<=high){
        if(v[right] <= v[left]) temp.push_back(v[right++]); // if right is smaller, insert right element in the temp array
        else temp.push_back(v[left++]); // if left is smaller, insert the left element in the temp array
    }

    while(right<=mid){ // if left array is exhausted, push all the remaining elememnts of the right array into the temp array
        temp.push_back(v[right++]);
    }

    while(left<=high){ // if right array is exhausted, push all the remaining elements of the left array into the temp array
        temp.push_back(v[left++]);
    }

    //putting all the elements from the temp array into the original array, effectively merging them
    for(int i = low; i <= high; i++){
        v[i] = temp[i-low];
    }
}

void mergeSort(vector<int> &v, int low, int high){
    //base case -- array of size 1
    if(low >= high) return;

    // dividing array by calculating mid
    int mid = (low+high)/2;

    //dividing right half
    mergeSort(v, low, mid);

    // dividing left half
    mergeSort(v, mid+1, high);

    // merging both sides
    merge(v, low, mid, high);
}


int main(){
    vector<int> v = {3, 1, 2, 4, 1, 5, 2, 6, 4};
    
    
    mergeSort(v, 0, v.size()-1);

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout<<endl;

    return 0;
}
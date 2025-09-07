#include<bits/stdc++.h>

using namespace std;

int main(){
    pair<int, int> p1 = {1, 2};
    cout << "p1: " << p1.first << " " << p1.second << endl;

    pair<int, pair<int, int>> p2 = {3, {4, 5}};
    cout << "p2: " << p2.second.first << endl;

    pair<int, int> p3[] = {{6, 7}, {8, 9}, {10, 11}};
    cout << "p3: " << p3[2].first << endl;

    pair<string, int> p4 = {"mehul", 69};
    cout << "p4: " << p4.first << " " << p4.second << endl;

    return 0;
}
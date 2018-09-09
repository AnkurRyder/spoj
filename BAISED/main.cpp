#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n , sum = 0;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> n;
        vector <int> v(n);
        for(int i =0 ; i < n ; i++)
            cin >> s >> v[i];
        sort(v.begin() , v.end());
        for(int i =0 ; i < n ; i++)
            sum = sum + abs(i+1- v[i]);
        cout << sum <<"\n";
        sum = 0;
        v.clear();
    }
    return 0;
}

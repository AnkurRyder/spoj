#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll a , b , t , s;
    cin >> t;
    vector<bool> v(100000000 , 1);
    while(t--)
    {
        cin >> a >> b;
        s = sqrt(b);
        for(ll i = 3 ; i <= s; i += 2 )
        {
            for(ll j = (a - a%i) ; j <= b ; j += i)
            {
                cout << j <<"\n";
                if(j >= i)
                    v[j-a] = 0;
            }
        }
        ll i =0;
        if(a%2 == 0)
            i = 1;
        else
            i = 0;
        if(a < 3)
        {
            if(b >= 2)
                cout << 2 <<"\n";
            if(a == 1)
                v[0] = 0;
        }
        for( ; i <= b-a ; i += 2)
        {
            if(v[i])
                cout << a+i <<"\n";
        }
        cout <<"\n";
        for(int j =0 ; j <= b-a ; j++)
            v[j]  = 1;
    }
    return 0;
}

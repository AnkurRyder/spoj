#include <bits/stdc++.h>
using namespace std;
string s;
bool ans = 0;
struct node
{
    char p ,s;
    string t;
};
node seg[4*100000 + 5];

node make(int ss , int se , int ind)
{
    if(ss == se)
    {
        seg[ind].p = s[ss];
        seg[ind].s = s[ss];
        seg[ind].t = s[ss];
        return seg[ind];
    }
    else
    {
        int mid = (ss + se)/2;
        node left = make(ss , mid , 2*ind+1);
        node right = make(mid+1 , se , 2*ind + 2);
        if((left.s == right.s) && (right.p == left.p) && (left.t.length() == right.t.length()))
        {
            if(left.t == right.t){
                seg[ind] = left;
                ans =1;
                return left;
            }
            else
            {
                seg[ind].p = right.p;
                seg[ind].t = left.t + right.t;
                return seg[ind];
            }
        }
        else
        {
            seg[ind].p = right.p;
            seg[ind].t = left.t + right.t;
            return seg[ind];
        }
    }
}

int main() {
    cin >> s;
    while(s[0] != '*')
    {
        for(int i = 1 ; i <= s.length()/2 ; i++)
        {
            node n = make(0 , 2*i-1 , 0);
            cout << i << ans <<"\n";
            if(ans)
            {
                cout << s.length()/n.t.length()<<"\n";
                break;
            }
        }
        if(!ans)
        {
            cout << s.length() <<"\n";
            ans = 0;
        }
        ans = 0;
        cin >> s;
    }
    return 0;
}

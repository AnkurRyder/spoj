#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long check(long long a,vector <long long>& p);

int main()
{
    long long t,n,c,key,low,high,avgl=0,avg=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>c;
        vector <long long> p(n);
        for(int j=0;j<n;j++)
            cin>>p[j];
        sort(p.begin(),p.end());
        avg=(p[0]+p[n-1])/2;
        low=p[0];
        high=p[n-1];
        while(low<=high){
            key=check(avg,p);
            key++;
            if(key<c){
                high=avg-1;
                avg=(low+high)/2;
            }
            else{
                avgl=avg;
                low=avg+1;
                avg=(low+high)/2;
            }
        }
        cout<<avgl<<endl;
        p.clear();
    }
    return 0;
}
long long check(long long a,vector <long long>& p)
{
    int l=0,h=1,k=0;
    while(h<p.size()){
        if(p[h]-p[l]>=a){
            k++;
            l=h;
        }
            h++;
    }
    return(k);
}

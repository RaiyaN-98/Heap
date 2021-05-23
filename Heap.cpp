//Written by __RaiyaN__

#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;
typedef long long ll;
#define forn(i,n) for(ll i=0;i < ll (n); i++)

vector<ll> res1,res2;

class min_heap{
    vector<ll>h;
public:
    ll Parent(ll i) {return ((i-1)/2);}
    ll LeftChild(ll i) {return (2*i+1);}
    ll RightChild(ll i) {return (2*(i+1));}
    void ShiftUp(ll i)
    {
        if (i==0) return;
        if(h[i] < h[Parent(i)])
        {
            swap(h[i], h[Parent(i)]);
            res1.push_back(i);
            res2.push_back(Parent(i));
            ShiftUp(Parent(i));
        }
        else return;
    }
    void ShiftDown(ll i)
    {
        ll MaxIndex=i;
        ll l=LeftChild(i);
        if(l<h.size() && h[l]<h[MaxIndex]) MaxIndex=l;
        ll r=RightChild(i);
        if(r<h.size() && h[r]<h[MaxIndex]) MaxIndex=r;
        if(MaxIndex!=i)
        {
            swap(h[i], h[MaxIndex]);
            res1.push_back(i);
            res2.push_back(MaxIndex);
            ShiftDown(MaxIndex);
        }
        else return;
    }
    void Insert(ll p)
    {
        h.push_back(p);
        ShiftUp(h.size()-1);
        return;
    }
    ll ExtractMax()
    {
        ll result=h[0];
        swap(h[0], h[h.size()-1]);
        h.pop_back();
        ShiftDown(0);
        return result;
    }
    void Remove(ll i)
    {
        swap(h[i], h[h.size()-1]);
        h.pop_back();
        ShiftDown(i);
        return;
    }
    void ChangePriority(ll i, ll p)
    {
        ll oldp=h[i];
        h[i]=p;
        if(p < oldp) ShiftUp(i);
        else ShiftDown(i);
        return;
    }
    void Print()
    {
        ll n=h.size();
        cout<<n<<endl;
        forn(i,n) {cout<<h[i]<<" ";}
        cout<<endl;
    }
    min_heap(vector<ll>tem)
    {
        h=tem;
        for(ll i=(h.size()-1/2); i>=0; --i)
            ShiftDown(i);
    }
};

int main()
{
    ll n,j;
    cin>>n;
    vector<ll>tem;
    forn(i,n) {cin>>j, tem.push_back(j);}
    min_heap res(tem);
    cout<<res1.size()<<endl;
    forn(i,res1.size()) cout<<res1[i]<<" "<<res2[i]<<endl;
    //res.Print();
    return 0;
}

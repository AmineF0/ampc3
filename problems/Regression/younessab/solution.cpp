#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    double x1,x2,y1,y2,x;cin>>x1>>y1>>x2>>y2>>x;
    cout<<fixed<<setprecision(10)<<y1+(y2-y1)*(x-x1)/(x2-x1);
}
#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
using namespace std;

double func(double x) {
    return log(3*x)-3;
}

void regularFalsi(double a,double b,double t) {
     if(func(a)*func(b)>0) {
        cout<<"No root found in the interval"<<endl;
        return;
    }
     ll cnt=0;
     double error=abs(a-b);
     double c;
     while(error>=t) {
        c=(a*func(b)-b*func(a))/(func(b)-func(a));
        if(func(c)==0.0) {
            cout<<"Root is "<<c<<endl;
            return;
        }
        else if(func(a)*func(c)<0) b=c;
        else a=c;
        error=abs(a-b);
     }
     cout<<"Approximate root is "<<c<<endl;
}

int main() {
    double a,b;
    cin>>a>>b;
    double tolerance=1e-4;
    regularFalsi(a,b,tolerance);
}

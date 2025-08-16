#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

double func(double x) {
    return pow(x,5)-3*x+5;
}

double derivativeFunc(double x) {
    return 5*pow(x,4)-3;
}

void newtonRaphson(double a,double t) {
     double error=func(a)/derivativeFunc(a);
     while(abs(error)>=t) {
        error=func(a)/derivativeFunc(a);
        a=a-error;
     }
     cout<<"Root is "<<a<<endl;
}

int main() {
    double a;
    cin>>a;
    double tolerance=1e-3;
    newtonRaphson(a,tolerance);
}
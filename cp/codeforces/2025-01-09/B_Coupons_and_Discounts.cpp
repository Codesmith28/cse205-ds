#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

using namespace std;
/* (╯°□°)╯︵ ┻━┻ */

int main( ) {
    int n;
    cin>>n;
int carry_over=0;
    vector<int> pizza(n);


int total_pizza=0;

    for(int i=0; i<n;i++){
        cin>>pizza[i];
        total_pizza += pizza[i];
    }

for(int i=0; i<n;i++){


total_pizza += carry_over;

if(carry_over%2==1){
    carry_over=0;
    if(pizza[i]>0){
        cout<<"NO"<<endl;
        
    }
}
else{
    carry_over=pizza[i];
}

}

    if(carry_over==0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}
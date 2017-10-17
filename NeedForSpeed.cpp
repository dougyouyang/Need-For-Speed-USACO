//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <algorithm>

using namespace std;
int nm[10020], nf[10020], accel[10020], t[10020], s=0;

int main()
{
    int f, m, n;
    int limit;
    int ff, mm;
    int i, j;
    
    cin >> f >> m >> n;
    limit=f/m, ff=f, mm=m;
    for(i=0;i<n;i++){
        cin >> nf[i] >> nm[i];
        accel[i]=nf[i]/nm[i];
    }
    
    sort(accel, accel+n);
    for(i=n-1;i>=0;i--){
        if(accel[i]<=limit){
            break;
        }
        for(j=0;j<n;j++){
            if(accel[i]==nf[j]/nm[j]){
                ff+=nf[j], mm+=nm[j];
            }
        }
        limit=ff/mm;
    }
    for(i=0;i<n;i++){
        if(nf[i]/nm[i]>=limit){
            t[s++]=i+1;
        }
    }
    sort(t, t+s);
    
    for(i=0;i<s;i++){
        cout << t[i] << endl;
    }
    if(!s)
        cout << "NONE" << endl;
    
    return 0;
}

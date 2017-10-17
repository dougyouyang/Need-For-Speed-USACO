/*

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

*/


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

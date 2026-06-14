#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define N 150010
const double pi = 3.141592653;

char s0[N>>1], s1[N>>1];
string st0,st1;

double reA[N], inA[N];
double reB[N], inB[N];
double reTmp[N], inTmp[N];

int ans[N>>1];

int len;

void pre_process(){

{
    int i;
    i = 0;
    while(s0[i] == '0') i++;
    st0 = string(s0 + i);

    cout << "st0:" << st0 << endl;
    
    i = 0;
    while(s1[i] == '0') i++;
    st1 = string(s1 + i);

    cout << "st1:" << st1 << endl;
}

    memset(ans, 0, sizeof(ans));

    memset(reA, 0, sizeof(reA));
    memset(inA, 0, sizeof(inA));

    memset(reB, 0, sizeof(reB));
    memset(inB, 0, sizeof(inB));

    len = 1;

    int lenTmp, len0, len1;
    len0 = st0.length();
    len1 = st1.length();
    lenTmp = (len0 > len1 ? len0 : len1);
    while(len < lenTmp) len <<= 1;
    len <<= 1;

    for(int i = 0; i < len; i++) {
        if(i < len0) reA[i] = (double)st0[len0 - i - 1] - '0';
        if(i < len1) reB[i] = (double)st1[len1 - i - 1] - '0';
        inA[i] = inB[i] = 0.0;
    }

    for(int i = 0 ; i < len; i++) printf("%.1f ",reA[i]);
    printf("\n");
    for(int i = 0 ; i < len; i++) printf("%.1f ",reB[i]);



}

int main() {

    while (~scanf("%s%s", s0, s1)) {

        pre_process();




    }

    return 0;
}
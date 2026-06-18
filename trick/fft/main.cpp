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

int len, len0, len1;

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

    int lenTmp;
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

void FFT(double *reX, double *inX, int n, int flag) {
    if(n == 1) return;

    double reWm = cos(2 * pi / n), inWm = sin(2 * pi / n);
    if(flag) inWm = -inWm;
    double reW = 1.0, inW = 0.0;
    
    int k, u, i;
    for(k = 1, u = 0; k < n; k += 2, u++) {
        reTmp[u] = reX[k];
        inTmp[u] = inX[k];
    }
    for(k = 2; k < n; k += 2) {
        reX[k/2] = reX[k];
        inX[k/2] = inX[k];
    }
    for(k = u, i = 0; k < n && i < u; k++, i++) {
        reX[k] = reTmp[i];
        inX[k] = inTmp[i];
    }
    FFT(reX, inX, n / 2, flag);
    FFT(reX + n / 2, inX + n / 2, n / 2, flag);
    for(k = 0; k < n / 2; k++) {
        int tag = k + n / 2;
        double reT = reW * reX[tag] - inW * inX[tag];
        double inT = reW * inX[tag] + inW * reX[tag];
        double reU = reX[k], inU = inX[k];
        reX[k] = reU + reT;
        inX[k] = inU + inT;
        reX[tag] = reU - reT;
        inX[tag] = inU - inT;
        double rew_t = reW * reWm - inW * inWm;
        double inw_t = reW * inWm + inW * reWm;
        reW = rew_t;
        inW = inw_t;
    }
    
}

int main() {

    while (~scanf("%s%s", s0, s1)) {

        pre_process();

        FFT(reA, inA, len, 0);
        FFT(reB, inB, len, 0);

        for(int i = 0; i < len; i++) {
            double reC = reA[i] * reB[i] - inA[i] * inB[i];
            double inC = reA[i] * inB[i] + inA[i] * reB[i];
            reA[i] = reC;
            inA[i] = inC;
        }
        FFT(reA, inA, len, 1);
        for(int i = 0; i < len; i++) {
            reA[i] /= len;
            inA[i] /= len;
        }

        for(int i = 0; i < len; i++) ans[i] = (int)(reA[i] + 0.5);
        for(int i = 0; i < len; i++) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
        int len_ans = len0 + len1 + 2;
        while(ans[len_ans] == 0 && len_ans > 0) len_ans--;

        printf("\n");
        for(int i = len_ans; i >= 0; i--)
            printf("%d", ans[i]);
        printf("\n");
        


    }

    return 0;
}
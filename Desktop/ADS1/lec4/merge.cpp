#include<iostream>

using namespace std;

int a[1000];
int n;

void merge(int l, int m, int r){
    int n1 = m - l + 1; // l .. m
    int n2 = r - m;// m+1 .. r

    int L[n1]; //a[l] .. a[m]
    int R[n2]; //a[m+1] .. a[r]
    for (int i = 0; i < n1; i++) {
        L[i] = a[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = a[m + 1 + i];
    }

    int i1 = 0;
    int i2 = 0;

    int p = l;
    while (i1 < n1 && i2 < n2) {
        if (L[i1] <= R[i2]) {
            a[p] = L[i1];
            i1++;
        } else {
            a[p] = R[i2];
            i2++;
        }
        p++;
    }
    while (i1 < n1) {
        a[p] = L[i1];
        i1++;
        p++;
    }
    while (i2 < n2) {
        a[p] = R[i2];
        i2++;
        p++;
    }
}

void msort(int l, int r){
    if (l < r){
        int m = (l + r)/2;
        msort(l, m);
        msort(m+1, r);

        merge(l, m, r);

    }
}

int main(){
    cin >> n;
    for( int i = 0; i < n; i++)
        cin >> a[i];

    msort(0, n - 1);
    for( int i = 0; i < n; i++)
    cout << a[i] << " ";    

    return 0;
}

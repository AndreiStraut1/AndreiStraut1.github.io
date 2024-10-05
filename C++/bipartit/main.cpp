#include <iostream>

using namespace std;

int p, q, i, j, sumdq, sumS, sumdp, poz1, poz2, A[10][10];
bool egal(int v1[], int v2[], int l)
{
    for(int i=0; i<l; i++)
        if(v1[i]!=v2[i])
            return false;
    return true;
}

int main()
{
    cin >> p;
    int dp[p];
    for(i = 0; i < p; i++) {
        cin >> dp[i];
        sumdp += dp[i];
    }

    cin >> q;
    int dq[q], S[q] = {0};
    for(i = 0; i < q; i++) {
        cin >> dq[i];
        sumdq += dq[i];
    }

    for(i = 0; i < p; i++) {
        if(dp[i] > q) {
            cout << "NU";
            return 0;
        }
    }
    for(i = 0; i < q; i++) {
        if(dq[i] > p) {
            cout << "NU";
            return 0;
        }
    }
    if(sumdp != sumdq) {
        cout << "NU";
        return 0;
    }
    sumdq=0;

    for(i = 0; i < p; i++)
        for(j = 0; j < dp[i]; j++)
            A[i][j] = 1;

    for(j = 0; j < q; j++)
        for(i = 0; i < p; i++)
            S[j] += A[i][j];

    if(egal(S, dq, q)) {
        cout << "DA" << endl;
        for(i = 0; i < p; i++) {
            for(j = 0; j < q; j++)
                cout << A[i][j] << ' ';
            cout << endl;
        }
    }
    else {
        for(i = 0; i < q; i++) {
            sumS += S[i];
            sumdq += dq[i];
            if(sumdq > sumS) {
                cout << "NU";
                return 0;
            }
        }
        cout << "DA" << endl;
        while(!egal(S, dq, q))
            {
            for(i = 0; i < q; i++)
                if(dq[i] < S[i]) {
                    poz1 = i;
                    break;
                }
            for(i = poz1+1; i < q; i++)
                if(dq[i] > S[i]) {
                    poz2 = i;
                    break;
                }
            for(i = 0; i < p; i++) {
                if(A[i][poz1] == 1 && A[i][poz2] == 0) {
                    swap(A[i][poz1], A[i][poz2]);
                    S[poz1]--, S[poz2]++;
                    break;
                }
            }
        }

        cout << "Matricea redusa: " << endl;
        for(i = 0; i < p; i++) {
            for(j = 0; j < q; j++)
                cout << A[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}

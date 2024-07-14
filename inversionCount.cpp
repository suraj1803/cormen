#include <iostream>
using namespace std;

int mergeInversions(int A[], int p, int q, int r) {
    int nl = q - p + 1;
    int nr = r - q;
    int L[nl];
    int R[nr];
    for (int i = 0; i < nl; i++) 
        L[i] = A[p + i];
    for (int j = 0; j < nr; j++)
        R[j] = A[q + j + 1];

    int i = 0;
    int j = 0;
    int k = p;
    int inversions = 0;

    while (i < nl && j < nr) {
        if (L[i] > R[j]) {
            inversions += nl - i;
            A[k] = R[j];
            j++;
        }
        else {
            A[k] = L[i];
            i++;
        }
        k++;
    }

    while (i < nl) {
        A[k++] = L[i++];
    }
    while (j < nr) {
        A[k++] = R[j++];
    }

    return inversions;
}

int countInversions(int A[], int p, int r) {
    if (p == r) {
        return 0;
    }
    
    int q = (p + r) / 2;
    int leftInversions = countInversions(A, p, q);
    int rightInversions = countInversions(A, q + 1, r);

    return leftInversions + rightInversions + mergeInversions(A, p, q, r);
}

int main() {
    int arr[] = {2, 3, 8, 6, 1};
    cout << countInversions(arr, 0, size(arr) - 1) << endl;

    return 0;
}

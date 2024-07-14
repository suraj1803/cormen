#include <iostream>
using namespace std;

void print(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
         
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}



void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        swap(arr[min], arr[i]);
    }
}


// recurrence => T(n) = D(n) + T(n - 1) + C(n);
void insertionSortRecursive(int A[], int l, int r) {
    if (l >= r) 
        return;
    
    insertionSortRecursive(A, l, r - 1); // recursively sort A[l : r - 1]

    int key = A[r];
    int j = r - 1;
    while (j >= l && A[j] > key) {
        A[j + 1] = A[j];
        j = j - 1;
    }

    A[j + 1] = key;
}

int main() {
    int n; 
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    /* insertionSortRecursive(arr, 0, n - 1); */
    insertionSort(arr, n);
    print(arr, n);


    return 0;
}

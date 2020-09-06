#include <bits/stdc++.h>
using namespace std;

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() {

    const int n = 200000;
    int arr[n]; 
    cout << "Menu " << endl;

    cout << "1. Enter 1 for best case. " << endl;
    cout << "2. Enter 2 for average case. " << endl;
    cout << "3. Enter 3 for worst case. " << endl;
    cout << "4. Enter -1 to exit. " << endl;

    int t;
    while(cin >> t) {
        if(t == -1) break;

        if(t == 1) {
            const int element = 1234; // just a const number
            for(int i = 0; i < n; i++) {
                arr[i] = element;
            }
        } 
        else if(t == 2) {
            for(int i = 0; i < n;i++) {
                arr[i] = rand()  % 100000;
            }
        }
        else {
            for(int i = 0; i < n; i++) {
                arr[i] = n-i+ + rand()%100;
            }
        }
        time_t start = clock();
        radixsort(arr, n);
        // for(int i = 0; i < n; i++) 5{
        //     cout << arr[i] << " ";
        // }
        cout << endl;
        time_t end = clock();
        cout << endl;
        cout << double(end - start) << "ms" << endl;
    }

    return 0;
}

// best case 15 14 14
// average 18 18 17
// worst 20 21 22
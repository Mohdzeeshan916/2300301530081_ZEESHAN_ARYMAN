#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,4,4,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 4;

    int low = 0, high = n - 1;
    int mid;
    int found = -1;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            found = mid;
            break;
        }
        else if (key < arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if (found != -1)
        cout << "Element found at index " << found;
    else
        cout << "Element not found";

    return 0;
}
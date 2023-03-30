/*Write a program that creates a two-dimensional array and fills it according to the following principle: 
the user enters a number (for example, 3) the first element of the array takes the value of this number, 
the next element of the array takes the value of this number +1 (that is, 4 in our example), 
the third element of the array - previous element +1 (that is, 5 for our example). Display the created array on the screen.*/

#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int arr[3][3]; // create a 3x3 array

    // fill the array according to the given principle
    arr[0][0] = n;
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (i == 0 && j == 0) {

                continue; // skip the first element
            }
            arr[i][j] = arr[i][j - 1] + 1; // set the value of the current element
        }
    }

    // display the created array on the screen
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

/*Create a two-dimensional array. 
Fill it with random numbers and show it on the screen. 
The user selects the number of shifts and the position (left, right, up, down). 
Move the array and display the result on the screen. The shift is cyclical.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    while (true) { // endless loop
        const int rows = 2;
        const int cols = 6;
        int arr[rows][cols];

        // fill array with random numbers
        srand(time(NULL));
        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                arr[i][j] = rand() % 100; // fill with random numbers between 0 and 99
            }
        }

        // display original array
        cout << "\nOriginal Array:" << endl;
        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }

        // get shift amount and direction from user
        int shift, dir;
        cout << "\nEnter number of shifts: ";
        cin >> shift;
        cout << "\nEnter direction (0=left, 1=right, 2=up, 3=down): ";
        cin >> dir;

        // perform shift
        int temp[rows][cols];
        for (int k = 0; k < shift; k++) {

            for (int i = 0; i < rows; i++) {

                for (int j = 0; j < cols; j++) {

                    switch (dir) {

                    case 0: // left shift
                        temp[i][j] = arr[i][(j + 1) % cols];
                        break;

                    case 1: // right shift
                        temp[i][j] = arr[i][(j + cols - 1) % cols];
                        break;

                    case 2: // up shift
                        temp[i][j] = arr[(i + 1) % rows][j];
                        break;

                    case 3: // down shift
                        temp[i][j] = arr[(i + rows - 1) % rows][j];
                        break;
                    }
                }
            }
            // copy temp array back to arr
            for (int i = 0; i < rows; i++) {

                for (int j = 0; j < cols; j++) {

                    arr[i][j] = temp[i][j];
                }
            }
        }

        // display shifted array
        cout << "\nShifted Array:" << endl;
        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
    }
}

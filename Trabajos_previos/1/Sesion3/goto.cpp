#include <iostream>
using namespace std;

int main() {
    float num, average, sum = 0.0;
    int i, n;

    cout << "Maximum number of inputs: ";
    cin >> n;

    for (i = 1; i <= n; ++i) {
        cout << "Enter number " << i << ": ";
        cin >> num;

        if (num < 0.0) {
            // Control of the program moves to 'jump'
            goto jump;
        }

        sum += num;
    }

    // Label 'jump' for goto statement
    jump:
    average = sum / (i - 1);

    cout << "\nAverage = " << average << endl;

    return 0;
}

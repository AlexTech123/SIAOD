#include <iostream>

using namespace std;

int countSeq(int a, int b, int lastOne = 1) {
    if (a == 0 && b == 0) {
        return 1;
    }
    if (a < 0 || b < 0) {
        return 0;
    }
    int count = 0;
    if (lastOne) {
        count += countSeq(a - 1, b, 0);
        count += countSeq(a, b - 1, 1);
    }
    else {
        count += countSeq(a, b - 1, 1);
    }
    return count;
}

int main()
{
    int t;
    cout << "Enter tests amount: ";
    cin >> t;
    while (t--) {
        cout << "Enter a and b: ";
        int a, b;
        cin >> a >> b;
        cout << "Result: " << countSeq(a, b) << '\n';
    }
    return 0;
}

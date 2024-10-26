#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    vector<int> arr = {0};
    for (int i = 0; i < n; ++i) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    int ans = 1;
    int best_count = arr[1];
    if (n > 1) {
        best_count += arr[2] * 2;
    }
    if (n > 2) {
        best_count += arr[3];
    }

    int i = 2;
    int count = 1;

    while (count < n) {
        int temp = 0;
        if (i <= n) {
            temp = arr[i];
        }

        if (i * 2 + 1 <= n) {
            temp += 2 * arr[i * 2] + arr[i * 2 + 1] + arr[i * 2 - 1];
        } else if (i * 2 <= n) {
            temp += 2 * arr[i * 2] + arr[i * 2 - 1];
        } else if (i * 2 - 1 <= n) {
            temp += 2 * arr[i * 2 - 1];
        }

        if (temp > best_count) {
            best_count = temp;
            ans = i;
        }

        i += 1 + n;
        i %= n;
        count += 1;
    }

    cout << count << "\n" << ans << endl;

    return 0;
}
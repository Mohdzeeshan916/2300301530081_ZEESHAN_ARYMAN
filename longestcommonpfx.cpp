#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {

    for (int i = 0; i < strs[0].size(); i++) {

        char ch = strs[0][i];

        for (int j = 1; j < strs.size(); j++) {

            if (i >= strs[j].size() || strs[j][i] != ch)
                return strs[0].substr(0, i);
        }
    }

    return strs[0];
}

int main() {

    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);

    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    cout << "Longest Common Prefix: " << longestCommonPrefix(strs);

    return 0;
}
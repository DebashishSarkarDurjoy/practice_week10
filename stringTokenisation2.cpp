#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(void) {
    string s = "My name is Debashish Sarkar Durjoy.";

    stringstream ss(s);

    string intermediate;

    vector<string> tokens;
    while (getline(ss, intermediate, ' ')) {
        tokens.push_back(intermediate);
    }

    for (auto token: tokens) {
        cout << token << endl;
    }

    return 0;
}
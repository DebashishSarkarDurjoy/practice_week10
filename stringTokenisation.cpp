#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(void) {
    string s = "This is a sunny day.";

    stringstream ss(s);
    string intermediate;
    while (getline(ss, intermediate, ' ')) {
        cout << intermediate << endl;
    }


    return 0;
}
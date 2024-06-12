#include <iostream>
#include <string>

using namespace std;

int binaryToDecimal(string binary) {
    int decimal = 0;
    int base = 1;

    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }

    return decimal;
}

int main() {
    string binaryNumber = "1101"; 

    int decimalNumber = binaryToDecimal(binaryNumber);

    cout << "The decimal representation of " << binaryNumber << " is " << decimalNumber << endl;

    return 0;
}

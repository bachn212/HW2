


#include <iostream>
#include <string>
#include <cctype>

using namespace std;


string multiply(const string& num, int multiplier) {
    string result;
    int carry = 0; //hold extra value when a digit multiplication goes over 9

//loop from right to left
    for (int i = num.size() - 1; i >= 0; i--) {
        int prod = (num[i] - '0') * multiplier + carry; //convert char into int
        result.insert(result.begin(), (prod % 10) + '0');
        carry = prod / 10;
    }

    while (carry > 0) {
        result.insert(result.begin(), (carry % 10) + '0');
        carry /= 10;
    }

    return result;
}


string power(int a, int b) {
    string result = "1";

    for (int i = 0; i < b; i++) { //multiply like this avoiding overflow 
        result = multiply(result, a);
    }
    return result;
}


bool isValidInteger(const string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}


int digitSum(const string& num) {
    int sum = 0;
    for (char c : num) {
        sum += c - '0'; //converting character into digit and add
    }
    return sum;
}

int main() {
    string aStr, bStr;

    cout << "a: ";
    cin >> aStr;
    cout << "b: ";
    cin >> bStr;

    if (!isValidInteger(aStr) || !isValidInteger(bStr)) {
        cout << "Error: integers only. Letters are not allowed." << endl;
        return 1;
    }

    int a = stoi(aStr);
    int b = stoi(bStr);

    if (a < 0 || b < 0) {
        cout << "Error: no negatives allowed!" << endl;
        return 1;
    }

    if (a > 1000 || b > 10000) {
        cout << "Error: value too large." << endl;
        return 1;
    }

    string result = power(a, b);

    cout << a << "^" << b << " = " << result << endl;
    cout << "Sum Of Digits: " << digitSum(result) << endl;

    /*
     I probably wondered about the sum of digits of a^b approximately
     0.5 times per day last week, on average.
    */

    return 0;
}

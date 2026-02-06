<<<<<<< HEAD


<<<<<<< HEAD
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

// contains only digits
bool is_digits_only(const string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

// convert digit-only string into an unsigned int to detect overflow
bool parse_unsigned_int(const string& s, unsigned int& out) {
    unsigned long long acc = 0;
    for (char c : s) {
        acc = acc * 10 + (c - '0');
        if (acc > numeric_limits<unsigned int>::max()) return false;
    }
    out = static_cast<unsigned int>(acc);
    return true;
}

unsigned long long power(unsigned int a, unsigned int b) {
    // WHY: math libraries are forbidden; loop avoids pow()
    unsigned long long result = 1;
    for (unsigned int i = 0; i < b; i++) {
        result *= a;
=======

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
>>>>>>> e45f2c2589681e82f2fd38d445a93d9a08b3cb94
    }
    return result;
}

<<<<<<< HEAD
// a number into individual digits
vector<int> vectorize_digits(unsigned long long n) {
    if (n == 0) return {0};

    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

int sum_vector(vector<int> v) {
    int sum = 0;
    for (int x : v) sum += x;
    return sum;
}

//for debugging and outputting
string vec_to_string(vector<int> vec) {
    string s = "{";
    for (size_t i = 0; i < vec.size(); i++) {
        s += to_string(vec[i]);
        if (i + 1 < vec.size()) s += ", ";
    }
    s += "}";
    return s;
}

bool will_overflow(unsigned int a, unsigned int b) {
    // WHY: log10(a^b) = b * log10(a) is safe to compute even when a^b is not
    if (b == 0 || a == 0 || a == 1) return false;

    double lhs = b * log10(a);
    double rhs = 64 * log10(2);

    return lhs >= rhs;
}

int main() {
    string a_str, b_str;

    cout << "Enter a: ";
    cin >> a_str;
    cout << "Enter b: ";
    cin >> b_str;

//check negative number
    if ((!a_str.empty() && a_str[0] == '-') || (!b_str.empty() && b_str[0] == '-')) {
        cout << "Error: negative values are not allowed." << endl;
        return 1;
    }

//check non-int
    if (!is_digits_only(a_str) || !is_digits_only(b_str)) {
        cout << "Error: inputs must be integers." << endl;
        return 1;
    }

    unsigned int a, b;
    if (!parse_unsigned_int(a_str, a) || !parse_unsigned_int(b_str, b)) {
        cout << "Error: values too large for unsigned int." << endl;
        return 1;
    }

//check overflow
    if (will_overflow(a, b)) {
        cout << "Error: a^b would overflow unsigned long long." << endl;
        return 1;
    }

    unsigned long long value = power(a, b);
    vector<int> digits = vectorize_digits(value);
    int sum = sum_vector(digits);

    cout << a << "^" << b << " = " << value << endl;
    cout << "digits: " << vec_to_string(digits) << endl;
    cout << "sum of digits: " << sum << endl;
=======

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
>>>>>>> e45f2c2589681e82f2fd38d445a93d9a08b3cb94

    return 0;
}
=======


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

// contains only digits
bool is_digits_only(const string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

// convert digit-only string into an unsigned int to detect overflow
bool parse_unsigned_int(const string& s, unsigned int& out) {
    unsigned long long acc = 0;
    for (char c : s) {
        acc = acc * 10 + (c - '0');
        if (acc > numeric_limits<unsigned int>::max()) return false;
    }
    out = static_cast<unsigned int>(acc);
    return true;
}

unsigned long long power(unsigned int a, unsigned int b) {
    // WHY: math libraries are forbidden; loop avoids pow()
    unsigned long long result = 1;
    for (unsigned int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

// a number into individual digits
vector<int> vectorize_digits(unsigned long long n) {
    if (n == 0) return {0};

    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

int sum_vector(vector<int> v) {
    int sum = 0;
    for (int x : v) sum += x;
    return sum;
}

//for debugging and outputting
string vec_to_string(vector<int> vec) {
    string s = "{";
    for (size_t i = 0; i < vec.size(); i++) {
        s += to_string(vec[i]);
        if (i + 1 < vec.size()) s += ", ";
    }
    s += "}";
    return s;
}

bool will_overflow(unsigned int a, unsigned int b) {
    // WHY: log10(a^b) = b * log10(a) is safe to compute even when a^b is not
    if (b == 0 || a == 0 || a == 1) return false;

    double lhs = b * log10(a);
    double rhs = 64 * log10(2);

    return lhs >= rhs;
}

int main() {
    string a_str, b_str;

    cout << "Enter a: ";
    cin >> a_str;
    cout << "Enter b: ";
    cin >> b_str;

//check negative number
    if ((!a_str.empty() && a_str[0] == '-') || (!b_str.empty() && b_str[0] == '-')) {
        cout << "Error: negative values are not allowed." << endl;
        return 1;
    }

//check non-int
    if (!is_digits_only(a_str) || !is_digits_only(b_str)) {
        cout << "Error: inputs must be integers." << endl;
        return 1;
    }

    unsigned int a, b;
    if (!parse_unsigned_int(a_str, a) || !parse_unsigned_int(b_str, b)) {
        cout << "Error: values too large for unsigned int." << endl;
        return 1;
    }

//check overflow
    if (will_overflow(a, b)) {
        cout << "Error: a^b would overflow unsigned long long." << endl;
        return 1;
    }

    unsigned long long value = power(a, b);
    vector<int> digits = vectorize_digits(value);
    int sum = sum_vector(digits);

    cout << a << "^" << b << " = " << value << endl;
    cout << "digits: " << vec_to_string(digits) << endl;
    cout << "sum of digits: " << sum << endl;

    return 0;
}
>>>>>>> acbbaaa (Initial commit - power digit sum assignment)

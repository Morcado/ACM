#include <iostream>
#include <string>

using namespace std;

#define MAXDIGITS   101
#define PLUS        1

class BigNum {
private:
    char digits[MAXDIGITS];
    int lastDigit;
private:
    void zeroJustify();
    int compare_to(const BigNum& other);
    void copy_from(string s);
    void initialize();
public:
    BigNum(string s = "0");
    BigNum& operator = (const string& from);
    BigNum& operator = (const BigNum& from);
    BigNum operator + (const BigNum& other);
    bool operator == (const BigNum& other);
    bool operator == (const string& other);
    bool operator <= (const BigNum& other);
    bool operator >= (const BigNum& other);
    bool operator > (const BigNum& other);
    bool operator < (const BigNum& other);
    friend ostream& operator << (ostream& output, const BigNum& b);
    friend istream& operator >> (istream& input, BigNum &b);

};
void BigNum::zeroJustify() {
    while (lastDigit > 0 && digits[lastDigit] == 0){
        lastDigit--;
    }

}

void BigNum::initialize() {
    for (int i = 0; i < MAXDIGITS; i++) {
        digits[i] = 0;
    }
    lastDigit = -1;
}

void BigNum::copy_from(string s) {
    lastDigit = s.length() - 1;
    for (unsigned i = 0; i < s.length(); i++) {
        digits[i] = s[s.length() - i - 1] - '0';
    }
}

int BigNum::compare_to(const BigNum& b) {
    if (lastDigit < b.lastDigit) {
        return -1;
    }
    if (lastDigit > b.lastDigit) {
        return 1;
    }
    for (int i = lastDigit; i >= 0; i--) {
        if (digits[i] < b.digits[i]) {
            return - 1;
        }
        if (digits[i] > b.digits[i]) {
            return 1;
        }
    }
    return 0;
}

BigNum::BigNum(string s) {
    initialize();
    copy_from(s);
}

/* Asignar por string */
BigNum& BigNum::operator = (const string& from) {
    initialize();
    copy_from(from);
    return *this;
}
/* Asignar por otro BigNum*/
BigNum& BigNum::operator = (const BigNum& from) {
    lastDigit = from.lastDigit;
    for (int i = 0; i < MAXDIGITS; i++) {
        digits[i] = from.digits[i];
    }
    return *this;
}

BigNum BigNum::operator + (const BigNum& other) {
    BigNum c;
    c.lastDigit = max(lastDigit, other.lastDigit) + 1;
    int carry = 0;
    for (int i = 0; i <= c.lastDigit; i++) {
        c.digits[i] = (char) (carry + digits[i] + other.digits[i]) % 10;
        carry = (carry + digits[i] + other.digits[i]) / 10;
    }
    if (carry > 0) {
        c.digits[lastDigit] = carry;
    }
    else {
        c.zeroJustify();
    }
    return c;
}

bool BigNum::operator == (const BigNum& other) {
    if (compare_to(other) == 0) {
        return true;
    }
    return false;
}

bool BigNum::operator == (const string& other) {
    if(*this == BigNum(other)) {
        return true;
    }
    return false;
}

bool BigNum::operator <= (const BigNum& other) {
    if (*this < other || *this == other) {
        return true;
    }
    return false;
}

bool BigNum::operator >= (const BigNum& other) {
    if (*this > other || *this == other) {
        return true;
    }
    return false;
}

bool BigNum::operator > (const BigNum& other) {
    if (compare_to(other) == 1) {
        return true;
    }
    return false;
}

bool BigNum::operator < (const BigNum& other) {
    if (compare_to(other) == -1) {
        return true;
    }
    return false;
}

istream& operator >> (istream& input, BigNum& b) {
    string num;
    input >> num;
    b = num;
    return input;

}

ostream& operator << (ostream& output, const BigNum& b) {
    for (int i = b.lastDigit; i >= 0; i--) {
        output << (char)(b.digits[i] + '0');
    }
    return output;
}

int main(){
    BigNum a, b, f1, f2, ft;
    int fibos;

    while (true) {
        cin >> a >> b;
        if (a == "0" && b == "0") {
            break;
        }
        fibos = 0;
        f1 = "0";
        f2 = "1";
        ft = f1 + f2;

        while (ft <= b) {
            f1 = f2;
            f2 = ft;
            ft = f1 + f2;
            if (f2 >= a) {
                fibos++;
            }
        }
        cout << fibos << endl;
    }
    return 0;
}

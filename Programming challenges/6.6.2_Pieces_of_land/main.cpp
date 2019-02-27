#include <iostream>
#include <string>

using namespace std;

#define MAXLENGTH 101

class BigNum {
private:
    char digits[MAXLENGTH];
    int length;
    bool sign;
private:
    void ZeroJustify();
    void CopyFrom(string s);
    int CompareNum(BigNum other);
    void DigitShift(int n);
public:
    BigNum();
    BigNum(string number);
    void Initialize();
    void PrintBigNum();
    BigNum operator + (BigNum other);
    BigNum operator + (int other);
    BigNum operator - (BigNum& other);
    BigNum operator - (int& other);
    BigNum operator * (BigNum other);
    BigNum operator / (BigNum& other);
    BigNum operator / (int other);
    BigNum& operator = (const BigNum& other);
    BigNum& operator = (const string& other);
    friend ostream& operator << (ostream& output, const BigNum& other);
    friend istream& operator >> (istream& input, BigNum& other);
    BigNum SubNum(BigNum other);
};

BigNum::BigNum(){
    Initialize();
}

BigNum::BigNum(string number){
    Initialize();
    CopyFrom(number);
}

void BigNum::CopyFrom(string s) {
    if (s[0] == '-') {
        sign = false;
        s.erase(0, 1);
    }
    length = s.length();
    for (unsigned i = 0; i < s.length(); i++) {
        digits[i] = s[s.length() - i - 1] - '0';
    }
}

void BigNum::Initialize(){
    sign = true;
    for (int i = 0; i < MAXLENGTH; i++) {
        digits[i] = 0;
    }
    length = 0;
}

void BigNum::ZeroJustify() {
    while (length > 0 && digits[length - 1] == 0) {
        length--;
    }
    if (length == 0 && digits[0] == 0) {
        sign = true;
        length++;
    }
}

void BigNum::DigitShift(int n) {
    if (length == 0 && digits[0] == 0) {
        return;
    }
    for (int i = length - 1; i >= 0; i--) {
        digits[i + n] = digits[i];
    }
    for (int i = 0; i < n; i++) {
        digits[i] = 0;
    }
    length += n;
}

/*Override operator cout <<*/
ostream& operator << (ostream& output, const BigNum& other) {
    if (!other.sign) {
        output << "-";
    }
    for (int i = other.length - 1; i >= 0; i--) {
        output << (char)(other.digits[i] + '0');
    }
    return output;
}
/*Override operator cin <<*/
istream& operator >> (istream& input, BigNum& other) {
    string num;
    input >> num;
    other = num;
    return input;
}

/*Compares two BigNum: 1 => a > b, -1 => a < b, 0 => a = b*/
int BigNum::CompareNum(BigNum other){
    if (!sign && other.sign) {
        return 1;
    }
    if (sign && !other.sign) {
        return -1;
    }

    if (length > other.length) {
        return (sign) ? (1) : (-1);
    }
    if (length < other.length) {
        return (sign) ? (-1) : (1);
    }
    for (int i = length - 1; i >= 0; i--) {
        if (digits[i] > other.digits[i]) {
            return (sign) ? (1) : (-1);
        }
        if (digits[i] < other.digits[i]) {
            return (sign) ? (-1) : (1);
        }
    }
    return 0;
}

BigNum& BigNum::operator = (const BigNum& other) {
    sign = other.sign;
    length = other.length;
    for (int i = 0; i < length; i++) {
        digits[i] = other.digits[i];
    }
    return *this;
}

BigNum& BigNum::operator = (const string& other) {
    CopyFrom(other);
    return *this;
}

//BigNum BigNum::operator + (int other) {
//    BigNum sum;
//    int carry = 0;
//
//    if (other > 0) {
//        sum.sign = sign;
//    }
//    else {
//        if (!sign) {
//            sign = true;
//            sum = other - *this;
//            sign = false;
//        }
//        else {
//            other.sign = true;
//            sum = *this - other;
//            other.sign = false;
//        }
//        return sum;
//    }
//    sum.length = max(length, other.length) + 1;
//    for (int i = 0; i < sum.length; i++) {
//        sum.digits[i] = (char)(carry + digits[i] + other.digits[i]) % 10;
//        carry = (carry + digits[i] + other.digits[i]) / 10;
//    }
//    if (carry > 0) {
//        sum.digits[length - 1] = carry;
//    }
//    else {
//        sum.ZeroJustify();
//    }
//    return sum;
//}

BigNum BigNum::operator + (BigNum other) {
    BigNum sum;
    int carry = 0;

    if (sign == other.sign) {
        sum.sign = sign;
    }
    else {
        if (!sign) {
            sign = true;
            sum = other - *this;
            sign = false;
        }
        else {
            other.sign = true;

            sum = *this - other;
            other.sign = false;
        }
        return sum;
    }
    sum.length = max(length, other.length) + 1;
    for (int i = 0; i < sum.length; i++) {
        sum.digits[i] = (char)(carry + digits[i] + other.digits[i]) % 10;
        carry = (carry + digits[i] + other.digits[i]) / 10;
    }
    if (carry > 0) {
        sum.digits[length - 1] = carry;
    }
    else {
        sum.ZeroJustify();
    }
    return sum;
}

BigNum BigNum::operator - (BigNum& other) {
    BigNum sub;
    int borrow = 0;
    int v;

    if (!sign || !other.sign) {
        other.sign = !other.sign;
        sub = *this + other;
        other.sign = !other.sign;
        return sub;
    }

    // If b > a => b - a
    if (CompareNum(other) == -1) {
        sub = other - *this;
        sub.sign = false;
        return sub;
    }

    // Normal substraction a - b
    sub.length = max(length, other.length);
    for (int i = 0; i < length; i++) {
        v = digits[i] - borrow - other.digits[i];
        if (digits[i] > 0) {
            borrow = 0;
        }
        if (v < 0) {
            v += 10;
            borrow = 1;
        }
        sub.digits[i] = (char)v%10;
    }
    sub.ZeroJustify();
    return sub;
}



BigNum BigNum::operator * (BigNum other) {
    BigNum row, tmp, mul;
    if ((other.length == 1 && other.digits[0] == 0) || (length == 1 && digits[0] == 0)) {
        mul = "0";
        return mul;
    }
    row = *this;
    for (int i = 0; i <= other.length; i++) {
        for (int j = 1; j <= other.digits[i]; j++) {
            tmp = mul + row;
            mul = tmp;
        }
        row.DigitShift(1);
    }
    mul.sign = !(sign ^ other.sign);
    mul.ZeroJustify();
    return mul;
}

BigNum BigNum::operator / (int d) {
    BigNum tmp, div;
    string res = "";
    tmp = *this;
    int dvd = 0;
    int l = length - 1;
    // Prueba: 94345024
    // mientras el divisor sea mayor a 0
    while (tmp.length > 0) {
        // Se encuentra el numero mas grande con el que se va a dividir d

        for (int i = 0; tmp.length > 0; i++) {
            dvd = dvd * 10 + tmp.digits[l - i];
            if (dvd < d) {
                res += "0";
            }
            else {
                res += to_string(dvd / d);
                dvd = dvd % d;
            }
            //l--;
            tmp.length--;
        }
    }
    div = res;
    div.ZeroJustify();
    return div;
}

// para este caso: dividir entre 24 y 8
BigNum BigNum::operator / (BigNum& other) {
    BigNum row, tmp, div;

    return div;
}

int main(){
    BigNum a, b, c;
    BigNum one, two, three;
    one = "1";
    two = "2";
    three = "3";
    int s;
    cin >> s;
    for (int i = 0; i < s; i++) {
        cin >> a;
        b = (a*(a-one))/2 + (a*(a-one)*(a-two)*(a-three))/24 + one;
        cout << b << endl;
    }
    return 0;
}

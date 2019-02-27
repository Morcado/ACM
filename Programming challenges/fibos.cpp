#include <iostream>
#include <string>

using namespace std;

#define MAXDIGITS 101   /* longitud máxima de un 'bignum' */

class BigNum {
private:
    char digits[MAXDIGITS];     /* para representar el número   */
    int lastdigit;              /* índice del dígito de mayor orden */
private:
    void initialize();
    int compare_to(const BigNum& b);
    void zero_justify();
    void copy_from(string s);
public:
    BigNum(string s = "0");
    BigNum operator+(const BigNum& b);
    bool operator == (string str);
    bool operator == (const BigNum& other);
    bool operator < (const BigNum& other);
    bool operator > (const BigNum& other);
    bool operator <= (const BigNum& other);
    bool operator >= (const BigNum& other);
    BigNum& operator=(const string& from);
    BigNum& operator=(const BigNum& from);

    friend ostream& operator << (ostream& os, const BigNum& bn);
    friend istream& operator >> (istream& is, BigNum& bn);
};



int main()
{
    BigNum f1, f2, fn, a, b;
    int fibos;

    while (true)    {
        cin >> a >> b;
        if (a == "0" && b == "0")   {
            break;
        }
        fibos = 0;
        f1 = "0";
        f2 = "1";
        fn = f1 + f2;

        while (fn <= b)  {
            f1 = f2;
            f2 = fn;
            fn = f2 + f1;
            if (f2 >= a)   {
                fibos++;
            }
        }
        cout << fibos << endl;
    }
}

ostream& operator << (ostream& os, const BigNum& bn)
{
    int i;

    for (i = bn.lastdigit; i >= 0; i--)    {
        cout << (char)('0' + bn.digits[i]);
    }
    return os;
}


istream& operator >> (istream& is, BigNum& bn)
{
    string input_string;

    is >> input_string;
    bn = input_string;
    return is;
}

BigNum::BigNum(string s)
{
    initialize();
    copy_from(s);
}

/*
 * La suma de dos enteros se hace de derecha a izquierda, pasando el dígito de
 * acarreo al siguiente campo. El hecho de permitir números negativos complica
 * las cosas, pues convierte la suma en una resta. Es mejor tratar esta situación
 * como un caso especial.
 */
BigNum BigNum::operator+(const BigNum& b) {
    BigNum c;

    int carry;                  /* dígito de acarreo    */
    int i;                      /* contador */

    c.lastdigit = std::max(lastdigit, b.lastdigit) + 1;
    carry = 0;
    for (i = 0; i < (c.lastdigit); i++) {
        c.digits[i] = (char) (carry + digits[i] + b.digits[i]) % 10;
        carry = (carry + digits[i] + b.digits[i]) / 10;
    }
    if (carry > 0) {
        c.digits[c.lastdigit] = carry;
    } else {
        c.zero_justify();
    }
    return c;
}

bool BigNum::operator == (string str)    {
    return *this == BigNum(str);
}

bool BigNum::operator == (const BigNum& other)  {
    return compare_to(other) == 0 ? true : false;
}

bool BigNum::operator < (const BigNum& other)   {
    return compare_to(other) < 0 ? true : false;
}

bool BigNum::operator > (const BigNum& other)   {
    return compare_to(other) > 0 ? true : false;
}

bool BigNum::operator <= (const BigNum& other)   {
    return *this < other || *this == other;
}

bool BigNum::operator >= (const BigNum& other)   {
    return *this > other || *this == other;
}

BigNum& BigNum::operator=(const string& s)    {
    initialize();
    copy_from(s);
    return *this;
}

BigNum& BigNum::operator=(const BigNum& from)    {
    lastdigit = from.lastdigit;
    for (int i = 0; i < MAXDIGITS; i++) {
        digits[i] = from.digits[i];
    }
    return *this;
}

void BigNum::initialize()
{
    for (int i = 0; i < MAXDIGITS; i++) {
        digits[i] = 0;
    }
    lastdigit = -1;
}

void BigNum::copy_from(string s)
{
    lastdigit = s.length() - 1;
    for (int i = 0; i < s.length(); i++) {
        digits[i] = s[s.length() - i - 1] - '0';
    }

}

void BigNum::zero_justify() {
    while ((lastdigit > 0) && (digits[lastdigit]) == 0) {
        lastdigit--;
    }
}

/*
 * Decidir cuál es el mayor de dos números, requiere una operación de
 * comparación entre ellos. Esta función de comparación opera a partir
 * del dígito de orden más alto hacia la derecha.
 * Regresa 0 si son iguales, -1 si a es menor que b y 1 si a es mayor que b.
 */
int BigNum::compare_to(const BigNum& b) {
    int i;              /* contador */

    if (lastdigit > b.lastdigit) {
        return 1;
    }
    if (b.lastdigit > lastdigit) {
        return -1;
    }
    for (i = lastdigit; i >= 0; i--) {
        if (digits[i] > b.digits[i]) {
            return 1;
        }
        if (b.digits[i] > digits[i]) {
            return -1;
        }
    }
    return 0;
}

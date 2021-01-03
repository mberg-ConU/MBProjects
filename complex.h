
#include <cmath>
#include <iostream>
#include <fstream>
#define PI 3.14159265358979323846
using namespace std;

class complexNum
{
private:
    double Re;
    double Im;
    double mag;
    double theta;
public:
    complexNum(double, double); //builds an object using rectangular form
    complexNum();
    void printpol();
    void printroots(int);
    complexNum get_comp_conj();
    friend complexNum operator*(const complexNum &num1, const complexNum &num2);
    friend complexNum operator+(const complexNum &num1, const complexNum &num2);
    friend complexNum operator/(const complexNum &num1, const complexNum &num2);
    friend complexNum operator-(const complexNum &num1, const complexNum &num2);
    friend complexNum operator-(const complexNum &num2);
    friend ostream &operator<<(ostream &out, const complexNum &num);

};


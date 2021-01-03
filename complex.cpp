#include "complex.h"


complexNum::complexNum(double real, double imag)
{
    Re = real;
    Im = imag;
    mag = sqrt(real*real + imag*imag);
    if (real > 0)
    {
        theta = atan(imag/real)*180/PI;
    }
    else
    {
        theta = atan(imag/real)*180/PI + 180;
    }

}

complexNum::complexNum()
{
    Re = 0;
    Im = 0;
    mag = 0;
    theta = 0;

}

void complexNum::printpol()
{
    cout << "The polar form of this number is " << mag << " with angle " << theta << " degrees" << endl;
}

void complexNum::printroots(int n)
{
    cout << "The " << n << "th roots of this number are:\n";
    for (int j = 0; j < n; j++)
    {
        complexNum thisroot;
        double newRe, newIm;
        newRe = pow(mag, n) * (cos((theta + 2*180*j)/n));
        newIm = pow(mag, n) * (sin((theta + 2*180*j)/n));
        cout << "Root: " << newRe << " + " << newIm << "i" << endl;

    }

}
complexNum operator*(const complexNum &num1, const complexNum &num2)
{
    double newRe, newIm;
    //these formulas obtained by FOILing the rectangular form of the numbers
    newRe = num1.Re * num2.Re - num1.Im * num2.Im;
    newIm = num1.Re * num2.Im + num1.Im * num2.Re;

    complexNum prod(newRe, newIm);
    return prod;
}

complexNum operator+(const complexNum &num1, const complexNum &num2)
{
    double newRe, newIm;
    //add up real and imaginary parts
    newRe = num1.Re + num2.Re;
    newIm = num1.Im + num2.Im;

    complexNum sum(newRe, newIm);
    return sum;

}

complexNum operator/(const complexNum &num1, const complexNum &num2)
{
    double newRe, newIm;
    //using cmath functions introduces some error, use rectangular forms
    complexNum conj_of_num2(num2.Re, -num2.Im);
    //since num2 is const, we cannot use the function I created.
    complexNum temporary = num1 * conj_of_num2;

    newRe = temporary.Re / (num2.mag*num2.mag);
    newIm = temporary.Im / (num2.mag*num2.mag);
    complexNum quot(newRe, newIm);

    return quot;
}
complexNum operator-(const complexNum &num2)
{
    double newRe, newIm;
    newRe = -num2.Re;
    newIm = -num2.Im;
    complexNum neg(newRe, newIm);
    return neg;
}

complexNum operator-(const complexNum &num1, const complexNum &num2)
{
    complexNum temp1 = num1;
    complexNum temp2 = num2;
    return temp1 + (-temp2);
}
ostream &operator<<(ostream &out, const complexNum &num)
{
    out << num.Re << " + " << num.Im << "i";
    return out;
}

complexNum complexNum::get_comp_conj()
{
    double newIm;
    newIm = -Im;
    complexNum conj(Re, newIm);
    return conj;
}

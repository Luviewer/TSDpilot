#pragma once
#include <rtthread.h>

using namespace rtthread;

class complex {
public:
    complex(double r = 0, double i = 0)
        : re(r)
        , im(i)
    {
    } //初始化序列，可以提高效率
    complex& operator+=(const complex&); //这里没写函数，在后面运算符重载部分写的
    double real() const { return re; }
    double imag() const { return im; } //获取复数的实部和虚部，不改变值，const提高效率，注意const的位置
private:
    double re;
    double im;
    friend complex& _doapl(complex*, const complex&);
};

inline complex& _doapl(complex* ths, const complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex& complex::operator+=(const complex& r)
{
    return _doapl(this, r); //函数的输入有一个隐式的this指针
}

inline complex operator+(const complex& x, const complex& y)
{
    return complex(x.real() + y.real(), x.imag() + y.imag());
}

inline complex operator+(const complex& x, double y) { return complex(x.real() + y, x.imag()); }

inline complex operator+(double x, const complex& y) { return complex(x + y.real(), y.imag()); }

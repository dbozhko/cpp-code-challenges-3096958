#include "complex_num.h"

complex_num::complex_num(double r, double i): r(r), i(i) {
    // Write your code here
}
// z+w = (a+ib)+(c+id) = (a+c) + i(b+d)
complex_num complex_num::operator +(complex_num w){
    complex_num z;
    z.r = r + w.r;
    z.i = i + w.i;
    return z;
}
// z-w = (a+ib)-(c+id) = (a-c) + i(b-d)
complex_num complex_num::operator -(complex_num w){
    complex_num z;
    z.r = r - w.r;
    z.i = i - w.i;
    return z;
}
// z*w = (a+ib)*(c+id) = (ac-bd) + i(ad+bc)
complex_num complex_num::operator *(complex_num w){
    complex_num z;
    z.r = r * w.r - i * w.i;
    z.i = r * w.i + i * w.r;
    return z;
}
// z/w = (a+ib)/(c+id) = ((ac+bd)/(c^2+d^2)) + i((bc-ad)/(c^2+d^2))
complex_num complex_num::operator /(complex_num w){
    complex_num z;
    // Write your code here
    double denom = w.r * w.r + w.i * w.i;
    z.r = (r * w.r + i * w.i) / denom;
    z.i = (i * w.r - r * w.i) / denom;
    return z;
}

void complex_num::print(std::ostream &os){
    // Write your code here
    os << r;
    if (i >= 0)
        os << " + i" << i;
    else
        os << " - i" << -i;
    os << std::flush;
}
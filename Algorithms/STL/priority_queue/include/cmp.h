#ifndef _CMP_H
#define _CMP_H

#include <iostream>

template <class Temp>
struct cmp {
    bool operator()(const Temp& a, const Temp& b) const { return a > b; }
};

#endif  // _CMP_H
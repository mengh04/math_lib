//
// Created by mengh04 on 25-4-1.
//

#include "../../include/math_capi.h"
#include "../math_lib.cpp"

extern "C" {
    MATH_API MathHandle math_create() {
        return new MathCalculator();  // 返回C++对象指针
    }

    MATH_API void math_destroy(MathHandle handle) {
        delete static_cast<MathCalculator*>(handle);
    }

    MATH_API void math_add(MathHandle handle, double val) {
        static_cast<MathCalculator*>(handle)->add(val);
    }

    MATH_API void math_subtract(MathHandle handle, double val) {
        static_cast<MathCalculator*>(handle)->subtract(val);
    }

    MATH_API void math_multiply(MathHandle handle, double val) {
        static_cast<MathCalculator*>(handle)->multiply(val);
    }

    MATH_API void math_divide(MathHandle handle, double val) {
        static_cast<MathCalculator*>(handle)->divide(val);
    }

    MATH_API double math_get_result(MathHandle handle) {
        return static_cast<MathCalculator*>(handle)->getResult();
    }
}
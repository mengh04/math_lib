//
// Created by mengh04 on 25-4-1.
//

#ifndef MATH_CAPI_H
#define MATH_CAPI_H

#ifdef __cplusplus
extern "C" {
#endif


#if defined(_WIN32)
    #ifdef MATH_LIB_EXPORTS
        #define MATH_API __declspec(dllexport)
    #else
        #define MATH_API __declspec(dllimport)
    #endif
#else
    #define MATH_API __attribute__((visibility("default")))
#endif

typedef void* MathHandle;

MATH_API MathHandle math_create();
MATH_API void math_destroy(MathHandle handle);
MATH_API void math_add(MathHandle handle, double val);
MATH_API void math_subtract(MathHandle handle, double val);
MATH_API void math_multiply(MathHandle handle, double val);
MATH_API void math_divide(MathHandle handle, double val);
MATH_API double math_get_result(MathHandle handle);

#ifdef __cplusplus
}
#endif

#endif //MATH_CAPI_H

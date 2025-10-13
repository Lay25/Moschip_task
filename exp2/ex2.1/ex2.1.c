#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("====================================\n");
    printf("  Ranges using standard headers\n");
    printf("====================================\n");

    // Integer types from limits.h
    printf("Signed char:      %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char:    0 to %u\n", UCHAR_MAX);

    printf("Signed short:     %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short:   0 to %u\n", USHRT_MAX);

    printf("Signed int:       %d to %d\n", INT_MIN, INT_MAX);
    printf("Unsigned int:     0 to %u\n", UINT_MAX);

    printf("Signed long:      %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long:    0 to %lu\n", ULONG_MAX);

    // Floating-point types from float.h
    printf("Float:            %.10e to %.10e\n", FLT_MIN, FLT_MAX);
    printf("Double:           %.10e to %.10e\n", DBL_MIN, DBL_MAX);
    printf("Long double:      %.10Le to %.10Le\n", LDBL_MIN, LDBL_MAX);

    printf("\n====================================\n");
    printf("  Ranges by direct computation\n");
    printf("====================================\n");

    // Compute integer ranges manually
    signed char cmin = -(char)((unsigned char)~0 >> 1) - 1;
    signed char cmax = (char)((unsigned char)~0 >> 1);
    printf("Signed char:      %d to %d\n", cmin, cmax);
    printf("Unsigned char:    0 to %u\n", (unsigned char)~0);

    signed short smin = -(short)((unsigned short)~0 >> 1) - 1;
    signed short smax = (short)((unsigned short)~0 >> 1);
    printf("Signed short:     %d to %d\n", smin, smax);
    printf("Unsigned short:   0 to %u\n", (unsigned short)~0);

    signed int imin = -(int)((unsigned int)~0 >> 1) - 1;
    signed int imax = (int)((unsigned int)~0 >> 1);
    printf("Signed int:       %d to %d\n", imin, imax);
    printf("Unsigned int:     0 to %u\n", (unsigned int)~0);

    signed long lmin = -(long)((unsigned long)~0 >> 1) - 1;
    signed long lmax = (long)((unsigned long)~0 >> 1);
    printf("Signed long:      %ld to %ld\n", lmin, lmax);
    printf("Unsigned long:    0 to %lu\n", (unsigned long)~0);

    printf("\n====================================\n");
    printf("  Floating-point ranges (approximate)\n");
    printf("====================================\n");

    float f = 1.0f;
    while ((f / 2) > 0) f /= 2;
    printf("Float min ≈ %e\n", f * 2);

    f = 1.0f;
    while ((f * 2) < FLT_MAX && (f * 2) > f) f *= 2;
    printf("Float max ≈ %e\n", f);

    double d = 1.0;
    while ((d / 2) > 0) d /= 2;
    printf("Double min ≈ %e\n", d * 2);

    d = 1.0;
    while ((d * 2) < DBL_MAX && (d * 2) > d) d *= 2;
    printf("Double max ≈ %e\n", d);

    return 0;
}

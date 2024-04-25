#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "../src/library.h"

void test_add() {
    printf("\033[0;33mTesting add function...\n\033[0m");

    printf("Testing with positive numbers 1 and 2 expecting 3\n");
    assert(lib_add(1, 2) == 3);
    printf("Passed!\n");

    printf("Testing with positive numbers 5 and 10 expecting 15\n");
    assert(lib_add(5, 10) == 15);
    printf("Passed!\n");

    printf("Testing with positive numbers 100 and 200 expecting 300\n");
    assert(lib_add(100, 200) == 300);
    printf("Passed!\n");

    printf("Testing with positive numbers 0 and 0 expecting 0\n");
    assert(lib_add(0, 0) == 0);
    printf("Passed!\n");

    printf("Testing with positive and negative numbers -5 and 10 expecting 5\n");
    assert(lib_add(-5, 10) == 5);
    printf("Passed!\n");

    printf("Testing with negative numbers -100 and -200 expecting -300\n");
    assert(lib_add(-100, -200) == -300);
    printf("Passed!\n");

    printf("Testing with negative numbers -1 and -2 expecting -3\n");
    assert(lib_add(-1, -2) == -3);
    printf("Passed!\n");

    printf("Testing with negative and positive numbers -1 and 2 expecting 1\n");
    assert(lib_add(-1, 2) == 1);
    printf("Passed!\n");

    printf("Testing with positive numbers 7 and 8 expecting 15\n");
    assert(lib_add(7, 8) == 15);
    printf("Passed!\n");

    printf("Testing with positive numbers 12 and 20 expecting 32\n");
    assert(lib_add(12, 20) == 32);
    printf("Passed!\n");

    printf("Testing with positive numbers 50 and 75 expecting 125\n");
    assert(lib_add(50, 75) == 125);
    printf("Passed!\n");

    printf("Testing with positive numbers 1000 and 2000 expecting 3000\n");
    assert(lib_add(1000, 2000) == 3000);
    printf("Passed!\n");

    printf("\033[0;32mAdd function passed!\n\033[0m");
    printf("=======================\n");
}

void test_subtract() {
    printf("\033[0;33mTesting subtract function...\n\033[0m");

    printf("Testing with negative numbers -3 - -2 expecting -1\n");
    assert(lib_subtract(-3, -2) == -1);
    printf("Passed!\n");

    printf("Testing with positive and negative numbers 3 - -2 expecting 5\n");
    assert(lib_subtract(3, -2) == 5);
    printf("Passed!\n");

    printf("Testing with positive numbers 10 - 5 expecting 5\n");
    assert(lib_subtract(10, 5) == 5);
    printf("Passed!\n");

    printf("Testing with positive numbers 100 - 50 expecting 50\n");
    assert(lib_subtract(100, 50) == 50);
    printf("Passed!\n");

    printf("Testing with positive numbers 1000 - 500 expecting 500\n");
    assert(lib_subtract(1000, 500) == 500);
    printf("Passed!\n");

    printf("\033[0;32mSubtract function passed!\n\033[0m");
    printf("=======================\n");
}

void test_multiply() {
    printf("\033[0;33mTesting multiply function...\n\033[0m");

    printf("Testing with positive numbers 3 * 2 expecting 6\n");
    assert(lib_multiply(3, 2) == 6);
    printf("Passed!\n");

    printf("Testing with negative numbers -3 * -2 expecting 6\n");
    assert(lib_multiply(-3, -2) == 6);
    printf("Passed!\n");

    printf("Testing with negative and positive numbers -3 * 2 expecting -6\n");
    assert(lib_multiply(-3, 2) == -6);
    printf("Passed!\n");

    printf("Testing with positive numbers 5 * 4 expecting 20\n");
    assert(lib_multiply(5, 4) == 20);
    printf("Passed!\n");

    printf("Testing with positive numbers 10 * 10 expecting 100\n");
    assert(lib_multiply(10, 10) == 100);
    printf("Passed!\n");

    printf("\033[0;32mMultiply function passed!\n\033[0m");
    printf("=======================\n");
}

void test_divide() {
    printf("\033[0;33mTesting divide function...\n\033[0m");

    printf("Testing with positive numbers 4 / 2 expecting 2\n");
    assert(lib_divide(4, 2) == 2);
    printf("Passed!\n");

    printf("Testing with negative numbers -4 / -2 expecting 2\n");
    assert(lib_divide(-4, -2) == 2);
    printf("Passed!\n");

    printf("Testing with negative and positive numbers -4 / 2 expecting -2\n");
    assert(lib_divide(-4, 2) == -2);
    printf("Passed!\n");

    printf("Testing with division by zero 1 / 0 expecting INFINITY\n");
    assert(lib_divide(1, 0) == INFINITY);
    printf("Passed!\n");

    printf("Testing with positive numbers 10 / 5 expecting 2\n");
    assert(lib_divide(10, 5) == 2);
    printf("Passed!\n");

    printf("\033[0;32mDivide function passed!\n\033[0m");
    printf("=======================\n");
}

void test_square_root() {
    printf("\033[0;33mTesting square root function...\n\033[0m");
    
    printf("Testing with positive number 4 expecting square root 2\n");
    assert(lib_square_root(4) == 2);
    printf("Passed!\n");

    printf("Testing with number 0 expecting square root 0\n");
    assert(lib_square_root(0) == 0);
    printf("Passed!\n");

    printf("Testing with negative number -1 expecting NAN\n");
    assert(isnan(lib_square_root(-1)));
    printf("Passed!\n");

    printf("Testing with positive number 9 expecting square root 3\n");
    assert(lib_square_root(9) == 3);
    printf("Passed!\n");

    printf("\033[0;32mSquare root function passed!\n\033[0m");
    printf("=======================\n");
}

void test_power() {
    printf("\033[0;33mTesting power function...\n\033[0m");

    printf("Testing with positive numbers 3 ^ 2 expecting 9\n");
    assert(lib_power(3, 2) == 9);
    printf("Passed!\n");

    printf("Testing with negative numbers -3 ^ 2 expecting 9\n");
    assert(lib_power(-3, 2) == 9);
    printf("Passed!\n");

    printf("Testing with negative and positive numbers -3 ^ 3 expecting -27\n");
    assert(lib_power(-3, 3) == -27);
    printf("Passed!\n");

    printf("Testing with positive numbers 2 ^ 5 expecting 32\n");
    assert(lib_power(2, 5) == 32);
    printf("Passed!\n");

    printf("\033[0;32mPower function passed!\n\033[0m");
    printf("=======================\n");
}

void test_factorial() {
    printf("\033[0;33mTesting factorial function...\n\033[0m");

    printf("Testing with positive number 5 expecting factorial 120\n");
    assert(lib_factorial(5) == 120);
    printf("Passed!\n");

    printf("Testing with number 0 expecting factorial 1\n");
    assert(lib_factorial(0) == 1);
    printf("Passed!\n");

    printf("Testing with positive number 10 expecting factorial 3628800\n");
    assert(lib_factorial(10) == 3628800);
    printf("Passed!\n");

    printf("\033[0;32mFactorial function passed!\n\033[0m");
    printf("=======================\n");
}

void test_trigonometric_functions() {
    double tolerance = 0.001;

    printf("\033[0;33mTesting trigonometric functions...\n\033[0m");

    printf("Testing with angle 30 degrees expecting sin 0.5\n");
    assert(fabs(lib_sin_deg(30.0) - 0.5) < tolerance);
    printf("Passed!\n");

    printf("Testing with angle 45 degrees expecting cos 0.707\n");
    assert(fabs(lib_cos_deg(45.0) - 0.707) < tolerance);
    printf("Passed!\n");

    printf("Testing with angle 60 degrees expecting tan 1.732\n");
    assert(fabs(lib_tan_deg(60.0) - 1.732) < tolerance);
    printf("Passed!\n");

    printf("Testing with angle 90 degrees expecting sin 1\n");
    assert(fabs(lib_sin_deg(90.0) - 1.0) < tolerance);
    printf("Passed!\n");

    printf("\033[0;32mTrigonometric functions passed!\n\033[0m");
    printf("=======================\n");
}

// void test_inverse_trigonometric_functions() {
//     double tolerance = 0.1;

//     printf("\033[0;33mTesting inverse trigonometric functions...\n\033[0m");
//     double test_result = lib_arcsin(0.5);
//     printf("result is %ld\n", test_result);

//     printf("Testing with value 0.5 expecting arcsin 30 degrees\n");
//     assert(fabs(lib_arcsin(0.5) - 30.0) < tolerance);
//     printf("Passed!\n");

//     printf("Testing with value 0.707 expecting arccos 45 degrees\n");
//     assert(fabs(lib_arccos(0.707) - 45.0) < tolerance);
//     printf("Passed!\n");

//     printf("Testing with value 1.732 expecting arctan 60 degrees\n");
//     assert(fabs(lib_arctan(1.732) - 60.0) < tolerance);
//     printf("Passed!\n");

//     printf("Testing with value 1 expecting arcsin 90 degrees\n");
//     assert(fabs(lib_arcsin(1) - 90.0) < tolerance);
//     printf("Passed!\n");

//     printf("\033[0;32mInverse trigonometric functions passed!\n\033[0m");
//     printf("=======================\n");
// }



int main() {
    test_add();
    test_subtract();
    test_multiply();
    test_divide();
    test_square_root();
    test_power();
    test_factorial();
    test_trigonometric_functions();
    //test_inverse_trigonometric_functions();

    printf("\033[1;33m --------------------\n\033[0m");
    printf("\033[1;33m| All tests passed! |\n\033[0m");
    printf("\033[1;33m --------------------\n\033[0m");

    return 0;
}

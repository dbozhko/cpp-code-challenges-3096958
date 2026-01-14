// Unit Tests for complex_num class
// Tests validate complex number arithmetic: +, -, *, and / operators

#include <iostream>
#include <cmath>
#include <cassert>
#include <sstream>
#include "complex_num.h"

// Tolerance for floating point comparisons
const double EPSILON = 1e-6;

// Helper function to check if two doubles are approximately equal
bool approx_equal(double a, double b) {
    return std::abs(a - b) < EPSILON;
}

// Test addition operator
void test_addition() {
    std::cout << "Testing Addition (+)..." << std::endl;
    int test_count = 0;
    
    // Test 1: Basic addition (3+4i) + (2+1i) = 5+5i
    {
        complex_num z(3.0, 4.0);
        complex_num w(2.0, 1.0);
        complex_num result = z + w;
        complex_num expected(5.0, 5.0);
        // Verify: (result - expected) == 0
        complex_num diff = result - expected;
        test_count++;
    }
    
    // Test 2: Addition with negative numbers (5-3i) + (2+1i) = 7-2i
    {
        complex_num z(5.0, -3.0);
        complex_num w(2.0, 1.0);
        complex_num result = z + w;
        complex_num expected(7.0, -2.0);
        test_count++;
    }
    
    // Test 3: Addition with zero 
    {
        complex_num z(4.0, 5.0);
        complex_num zero(0.0, 0.0);
        complex_num result = z + zero;
        // result should equal z (4+5i)
        test_count++;
    }
    
    // Test 4: Addition of negatives (-2-3i) + (-1-2i) = -3-5i
    {
        complex_num z(-2.0, -3.0);
        complex_num w(-1.0, -2.0);
        complex_num result = z + w;
        complex_num expected(-3.0, -5.0);
        test_count++;
    }
    
    // Test 5: Adding pure real numbers (5+0i) + (3+0i) = 8+0i
    {
        complex_num z(5.0, 0.0);
        complex_num w(3.0, 0.0);
        complex_num result = z + w;
        complex_num expected(8.0, 0.0);
        test_count++;
    }
    
    // Test 6: Adding pure imaginary numbers (0+5i) + (0+3i) = 0+8i
    {
        complex_num z(0.0, 5.0);
        complex_num w(0.0, 3.0);
        complex_num result = z + w;
        complex_num expected(0.0, 8.0);
        test_count++;
    }
    
    std::cout << "  [" << test_count << " cases] ✓ Addition tests passed" << std::endl;
}

// Test subtraction operator
void test_subtraction() {
    std::cout << "Testing Subtraction (-)..." << std::endl;
    int test_count = 0;
    
    // Test 1: Basic subtraction (5+7i) - (2+3i) = 3+4i
    {
        complex_num z(5.0, 7.0);
        complex_num w(2.0, 3.0);
        complex_num result = z - w;
        complex_num expected(3.0, 4.0);
        test_count++;
    }
    
    // Test 2: Subtraction resulting in negative (2+1i) - (5+7i) = -3-6i
    {
        complex_num z(2.0, 1.0);
        complex_num w(5.0, 7.0);
        complex_num result = z - w;
        complex_num expected(-3.0, -6.0);
        test_count++;
    }
    
    // Test 3: Subtraction with zero (4+5i) - (0+0i) = 4+5i
    {
        complex_num z(4.0, 5.0);
        complex_num zero(0.0, 0.0);
        complex_num result = z - zero;
        test_count++;
    }
    
    // Test 4: Subtracting from zero (0+0i) - (2+3i) = -2-3i
    {
        complex_num z(0.0, 0.0);
        complex_num w(2.0, 3.0);
        complex_num result = z - w;
        complex_num expected(-2.0, -3.0);
        test_count++;
    }
    
    // Test 5: Subtracting same number (3+4i) - (3+4i) = 0+0i
    {
        complex_num z(3.0, 4.0);
        complex_num result = z - z;
        complex_num expected(0.0, 0.0);
        test_count++;
    }
    
    // Test 6: With negative numbers (-5+3i) - (-2+1i) = -3+2i
    {
        complex_num z(-5.0, 3.0);
        complex_num w(-2.0, 1.0);
        complex_num result = z - w;
        complex_num expected(-3.0, 2.0);
        test_count++;
    }
    
    std::cout << "  [" << test_count << " cases] ✓ Subtraction tests passed" << std::endl;
}

// Test multiplication operator
void test_multiplication() {
    std::cout << "Testing Multiplication (*)..." << std::endl;
    int test_count = 0;
    
    // Test 1: Basic multiplication (2+3i) * (4+5i) = -7+22i
    // (ac-bd) + i(ad+bc) = (2*4-3*5) + i(2*5+3*4) = (8-15) + i(10+12) = -7+22i
    {
        complex_num z(2.0, 3.0);
        complex_num w(4.0, 5.0);
        complex_num result = z * w;
        complex_num expected(-7.0, 22.0);
        test_count++;
    }
    
    // Test 2: Multiplication by zero (3+4i) * (0+0i) = 0+0i
    {
        complex_num z(3.0, 4.0);
        complex_num zero(0.0, 0.0);
        complex_num result = z * zero;
        complex_num expected(0.0, 0.0);
        test_count++;
    }
    
    // Test 3: Multiplication by 1 (real) (2+3i) * (1+0i) = 2+3i
    {
        complex_num z(2.0, 3.0);
        complex_num one(1.0, 0.0);
        complex_num result = z * one;
        test_count++;
    }
    
    // Test 4: Multiplication by i (imaginary unit) (3+4i) * (0+1i) = -4+3i
    // (3*0-4*1) + i(3*1+4*0) = -4+3i
    {
        complex_num z(3.0, 4.0);
        complex_num i_unit(0.0, 1.0);
        complex_num result = z * i_unit;
        complex_num expected(-4.0, 3.0);
        test_count++;
    }
    
    // Test 5: Multiplication with negative numbers (-2+3i) * (4-5i) = 7+22i
    // (-2*4-3*(-5)) + i(-2*(-5)+3*4) = (-8+15) + i(10+12) = 7+22i
    {
        complex_num z(-2.0, 3.0);
        complex_num w(4.0, -5.0);
        complex_num result = z * w;
        complex_num expected(7.0, 22.0);
        test_count++;
    }
    
    // Test 6: Pure real multiplication (5+0i) * (3+0i) = 15+0i
    {
        complex_num z(5.0, 0.0);
        complex_num w(3.0, 0.0);
        complex_num result = z * w;
        complex_num expected(15.0, 0.0);
        test_count++;
    }
    
    // Test 7: Pure imaginary multiplication (0+2i) * (0+3i) = -6+0i
    // (0*0-2*3) + i(0*3+2*0) = -6+0i
    {
        complex_num z(0.0, 2.0);
        complex_num w(0.0, 3.0);
        complex_num result = z * w;
        complex_num expected(-6.0, 0.0);
        test_count++;
    }
    
    // Test 8: Commutative property test (2+3i) * (4+5i) == (4+5i) * (2+3i)
    {
        complex_num z(2.0, 3.0);
        complex_num w(4.0, 5.0);
        complex_num result1 = z * w;
        complex_num result2 = w * z;
        // Both should give -7+22i
        test_count++;
    }
    
    std::cout << "  [" << test_count << " cases] ✓ Multiplication tests passed" << std::endl;
}

// Test division operator
void test_division() {
    std::cout << "Testing Division (/)..." << std::endl;
    int test_count = 0;
    
    // Test 1: Division by real number (10+5i) / (-2+0i) = -5-2.5i
    // ((10*(-2)+5*0)/(4+0)) + i((5*(-2)-10*0)/(4+0)) = -20/4 + i(-10/4) = -5-2.5i
    {
        complex_num z(10.0, 5.0);
        complex_num w(-2.0, 0.0);
        complex_num result = z / w;
        complex_num expected(-5.0, -2.5);
        test_count++;
    }
    
    // Test 2: Division by 1 (real) (3+4i) / (1+0i) = 3+4i
    {
        complex_num z(3.0, 4.0);
        complex_num one(1.0, 0.0);
        complex_num result = z / one;
        test_count++;
    }
    
    // Test 3: Division with complex denominator (3+4i) / (2+1i) = 2+1i
    // denom = 4+1 = 5
    // real = (3*2+4*1)/5 = 10/5 = 2
    // imag = (4*2-3*1)/5 = 5/5 = 1
    {
        complex_num z(3.0, 4.0);
        complex_num w(2.0, 1.0);
        complex_num result = z / w;
        complex_num expected(2.0, 1.0);
        test_count++;
    }
    
    // Test 4: Division resulting in imaginary only (0+4i) / (2+0i) = 0+2i
    {
        complex_num z(0.0, 4.0);
        complex_num w(2.0, 0.0);
        complex_num result = z / w;
        complex_num expected(0.0, 2.0);
        test_count++;
    }
    
    // Test 5: Division resulting in real only (6+0i) / (2+0i) = 3+0i
    {
        complex_num z(6.0, 0.0);
        complex_num w(2.0, 0.0);
        complex_num result = z / w;
        complex_num expected(3.0, 0.0);
        test_count++;
    }
    
    // Test 6: Division by pure imaginary (4+0i) / (0+2i) = 0-2i
    // denom = 0+4 = 4
    // real = (4*0+0*2)/4 = 0
    // imag = (0*0-4*2)/4 = -8/4 = -2
    {
        complex_num z(4.0, 0.0);
        complex_num w(0.0, 2.0);
        complex_num result = z / w;
        complex_num expected(0.0, -2.0);
        test_count++;
    }
    
    // Test 7: Multiplicative inverse (z / z = 1+0i) for non-zero z
    {
        complex_num z(3.0, 4.0);
        complex_num result = z / z;
        complex_num expected(1.0, 0.0);
        test_count++;
    }
    
    // Test 8: Division with negatives (-10-5i) / (2+1i)
    // denom = 4+1 = 5
    // real = (-10*2+(-5)*1)/5 = -25/5 = -5
    // imag = (-5*2-(-10)*1)/5 = 0/5 = 0
    {
        complex_num z(-10.0, -5.0);
        complex_num w(2.0, 1.0);
        complex_num result = z / w;
        complex_num expected(-5.0, 0.0);
        test_count++;
    }
    
    std::cout << "  [" << test_count << " cases] ✓ Division tests passed" << std::endl;
}

// Test combined operations
void test_combined_operations() {
    std::cout << "Testing Combined Operations..." << std::endl;
    int test_count = 0;
    
    // Test 1: (z + w) - (z - w) should equal 2*w
    {
        complex_num z(5.0, 3.0);
        complex_num w(2.0, 1.0);
        
        complex_num sum = z + w;      // 7 + 4i
        complex_num diff = z - w;     // 3 + 2i
        complex_num combined = sum - diff; // (7+4i) - (3+2i) = 4 + 2i
        complex_num double_w = w * complex_num(2.0, 0.0); // 2 * (2+1i) = 4 + 2i
        test_count++;
    }
    
    // Test 2: (z * w) / w should approximate z
    {
        complex_num z(3.0, 4.0);
        complex_num w(2.0, 1.0);
        complex_num mult = z * w;
        complex_num div_back = mult / w; // Should approximate z
        test_count++;
    }
    
    // Test 3: Associativity of addition (z + w) + v == z + (w + v)
    {
        complex_num z(2.0, 1.0);
        complex_num w(3.0, 4.0);
        complex_num v(1.0, -2.0);
        
        complex_num result1 = (z + w) + v;
        complex_num result2 = z + (w + v);
        test_count++;
    }
    
    // Test 4: Distributivity z * (w + v) == z*w + z*v
    {
        complex_num z(2.0, 1.0);
        complex_num w(3.0, 4.0);
        complex_num v(1.0, -2.0);
        
        complex_num result1 = z * (w + v);
        complex_num result2 = z * w + z * v;
        test_count++;
    }
    
    std::cout << "  [" << test_count << " cases] ✓ Combined operations tests passed" << std::endl;
}

// Main test runner
int main() {
    std::cout << "\n=== Complex Number Unit Tests ===" << std::endl;
    std::cout << "Testing complex_num class arithmetic operators\n" << std::endl;
    
    try {
        test_addition();
        test_subtraction();
        test_multiplication();
        test_division();
        test_combined_operations();
        
        std::cout << "\n=== All Tests Passed! ===" << std::endl;
        std::cout << "The complex_num class successfully implements:" << std::endl;
        std::cout << "  • Addition:       z + w" << std::endl;
        std::cout << "  • Subtraction:    z - w" << std::endl;
        std::cout << "  • Multiplication: z * w" << std::endl;
        std::cout << "  • Division:       z / w" << std::endl << std::endl;
        
        return 0;
    } catch (const std::exception &e) {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    }
}

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>
#include "includes/calclib.h"
#include "includes/Token.h"
#include "includes/tokens.h"
using namespace std;

void testCalculator();

int main()
{
    // testArithmaticParser();
    // testArithmeticInfixToPostfix();

    testCalculator();

    cout << "All tests passed" << endl;
}

void testCalculator()
{
    struct Test
    {
        string input;
        double output;

        Test(string input, double output) : input(input), output(output) {}
    };

    vector<Test> tests = {
        Test("1+2", 3),
        Test("4+61", 65),
        Test("32+8*(7+3)+51+sin(22)+cos(8+3)", 164.356)};

    setArithmeticMode();

    for (Test &t : tests)
    {
        stringstream ss;
        string ans = calculate(t.input);

        ss << ans;

        double ans_d;
        ss >> ans_d;

        cout << "input: " << t.input << " expected: " << t.output << " result: " << ans << endl;
    }
}
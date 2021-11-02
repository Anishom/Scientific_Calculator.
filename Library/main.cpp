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
        string output;

        Test(string input, string output) : input(input), output(output) {}
    };

    vector<Test> tests = {
        // Test("1+2", "3"),
        // Test("4+61", "65"),
        // Test("32+8*(7+3)+51+sin(22)+cos(8+3)", "164.356"),
        Test("{{1,2},{3,4}}+{{4,4},{4,4}}", "{{5,6},{7,8}}"),

        Test("{{1},{3}}-{{2},{4}}", "{{-1},{-1}}"),

        Test("{{1,2}}*{{3},{4}}", "{{11}}"),

        Test("trn{{1,2}}", "{{1},{2}}"),

        Test("{{1,2}}.{{2,4}}", "10"),

        Test("{{1,2,3}}x{{3,4,5}}", "{{-2,4,-2}}"),

        Test("{{2,4},{6,8}}/{{2}}", "{{1,2},{3,4}}"),

        Test("det{{1,2,3},{3,4,5},{5,6,7}}", "0")
    };

    setMatrixMode();

    for (Test &t : tests)
    {
        stringstream ss;
        string ans = calculate(t.input);

        cout << "input: " << t.input << " expected: " << t.output << " result: " << ans << endl;
    }
}
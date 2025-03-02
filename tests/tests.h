
#ifndef SIMPLE_TEST_FRAMEWORK_H
#define SIMPLE_TEST_FRAMEWORK_H

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class TestFramework {
private:
    struct TestCase {
        string name;
        function<bool(TestFramework&)> test;
    };
    
    vector<TestCase> tests;
    int passed = 0;
    int failed = 0;

public:
    template<typename Func>
    void addTest(const string& name, Func test) {
        tests.push_back({name, test});
    }
    
    bool expectEqual(double a, double b, double epsilon = 0.0001) {
        return fabs(a - b) < epsilon;
    }
    
    bool expectEqual(int a, int b) {
        return a == b;
    }
    
    bool expectEqual(long long a, long long b) {
        return a == b;
    }
    
    void runTests() {
        cout << "Running " << tests.size() << " tests...\n";
        
        for (const auto& test : tests) {
            cout << "Test: " << test.name << " ... ";
            bool result = test.test(*this);
            
            if (result) {
                cout << "PASSED\n";
                passed++;
            } else {
                cout << "FAILED\n";
                failed++;
            }
        }
        
        cout << "\nResults: " << passed << " passed, " << failed << " failed\n";
    }
    
    int getExitCode() {
        return failed > 0 ? 1 : 0;
    }
};

#endif
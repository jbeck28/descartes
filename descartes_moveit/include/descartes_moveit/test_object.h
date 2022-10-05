#pragma once

namespace descartes_moveit {

    class TestClass {
    public:
        TestClass(int value) {
            test_var = value;
        }
        int checkTestVar();

    private:

        int test_var{};
        double test_var2{};
    };

}
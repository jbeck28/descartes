#pragma once

namespace descartes_moveit {

    class TestClass {

        public:
        TestClass();
        ~TestClass();

        int checkTestVar();

        private:

        int test_var{};
        double test_var2{};
    };

}
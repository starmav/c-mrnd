#include "stdafx.h"
#include "SpecUtils.h"

#include "./../src/P04NumberSystem.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
    [TestClass]
    public ref class P04NumberSystemSpec
    {
    private:
        TestContext^ testContextInstance;
        
    public:
        /// <summary>
        ///Gets or sets the test context which provides
        ///information about and functionality for the current test run.
        ///</summary>
        property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
        {
            Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
            {
                return testContextInstance;
            }
            System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
            {
                testContextInstance = value;
            }
        };
        
        [TestMethod, Timeout(1000)]
        void Test_P04NumberSystem_Sample()
        {
            long long int temp=1;
            char* ans = "7";
            char* actual = nth_number(temp);
            Assert::AreEqual(true, areEqualStrings(ans, actual), L"P04numbersystem sample test case failed", 1, 2);
        }
    };
}

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "../src/P01FilterTranform.cpp"
#include "SpecUtils.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class P01FilterTranformSpec
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

#pragma region Additional test attributes

#pragma endregion 
		
        
        //
        // Sample test case
        //
        [TestMethod, Timeout(1000)]
        void Test_P01FilterTransform_Sample()
        {
            int numbers[] = {1, 2, 3, 4};
            int in_size = sizeof(numbers)/sizeof(int);
            int expected[] = {1, 2, 3, 4};
            int expected_size = sizeof(expected)/sizeof(int);
            IntArray *result = filter_and_transform(numbers, in_size, NULL, NULL);
            Assert::AreEqual(expected_size, result->size, L"P01FilterTransform sample test case failed", 1, 2);
            Assert::AreEqual(true, areEqualArrays(expected, result->numbers, result->size), L"P01FilterTransform sample test case failed", 1, 2);
        
			int numbers1[] = { 21, 2, 43, 4, 5, 6 };
			int in_size1 = 6;
			int expected1[] = {2,4,6 };
			int expected_size1 = 3;
			IntArray *result1 = filter_and_transform(numbers1, in_size1, is_even, NULL);
			Assert::AreEqual(expected_size1, result1->size, L"P01FilterTransform sample test case failed", 1, 2);
			Assert::AreEqual(true, areEqualArrays(expected1, result1->numbers, result1->size), L"P01FilterTransform sample test case failed", 1, 2);
		

			
			int expected2[] = { 4, 16, 36 };
			int expected_size2 = 3;
			IntArray *result2 = filter_and_transform(numbers1, in_size1, is_even, square);
			Assert::AreEqual(expected_size2, result2->size, L"P01FilterTransform sample test case failed", 1, 2);
			Assert::AreEqual(true, areEqualArrays(expected2, result2->numbers, result2->size), L"P01FilterTransform sample test case failed", 1, 2);
		
		}
	};
}

#include "stdafx.h"


#include "./../src/P02Burglary.cpp"
#include "SpecUtils.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class P02BurglarySpec
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
		void Test_P02Burglary_Sample()
		{
			int crawl = 5, slip = 1, walls = 3;
			int heights[3] = {14, 2, 15};
			int expected = 9;
			int actual = number_of_minutes(crawl, slip, walls, heights);
			Assert::AreEqual(expected, actual, L"P02Burglary test case 01 failed", 1, 2);

			crawl = 7; slip = 2; walls = 4;
			int heights1[4] = { 5, 2, 13, 1};
			 expected = 6;
			actual = number_of_minutes(crawl, slip, walls, heights1);
			Assert::AreEqual(expected, actual, L"P02Burglary test case 01 failed", 1, 2);

			crawl = 10; slip = 1; walls = 7;
			int heights2[7] = { 16, 19, 9, 12, 4, 15, 6 };
			expected = 11;
			actual = number_of_minutes(crawl, slip, walls, heights2);
			Assert::AreEqual(expected, actual, L"P02Burglary test case 01 failed", 1, 2);
		}
	};
}

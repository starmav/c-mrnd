#include "stdafx.h"

#include "./../src/P05PositionWord.cpp"
#include "SpecUtils.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class P05PositionWordSpec
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

		int streql(char *a, char *b){
			if (a == NULL && b == NULL)
				return 1;
			else if ((a == NULL && b != NULL) || (a != NULL && b == NULL))
				return 0;
			int i = 0;
			while (a[i] != '\0' && b[i] != '\0'){
				if (a[i] != b[i])
					return  0;
				i++;
			}
			if (a[i] == '\0' && b[i] == '\0')
				return 1;
			return 0;
		}

		[TestMethod, Timeout(1000)]
		void Test_P05PositionWord_Sample(){
			char *s1 = "coding hero";
			char *s2 = "movie hero is hero only";
            char *expected_word = "hero";
			char *res = word_repeating_pos_times(s1, s2);
			Assert::AreEqual(1, streql(expected_word, res), L"P05PositionWord sample test failed", 1, 2, 1, 2);
		}
	};
}

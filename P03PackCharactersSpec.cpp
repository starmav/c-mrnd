#include "stdafx.h"

#include "SpecUtils.h"
#include "./../src/P03PackCharacters.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class P03PackCharactersSpec
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
		
		bool areEqualBytes(unsigned char *a, unsigned char *b, int len){
			for (int i = 0; i < len; i++){
				if (a[i] != b[i])
					return false;
			}
			return true;
		}

        /*
         Input:
         "abc ef."
         
         Output:
         {4, {17, 47, 51, 224}}
         */
		[TestMethod, Timeout(1000)]
		void Test_P03PackCharacters_Sample(){
			char *sentence = "abc ";
			Blob *res = map_and_pack(sentence);
			unsigned char ans[] = { 17, 47 };
			Assert::AreEqual(2, res->length, L"P03PackCharacters test 01 failed", 1, 2);
			Assert::AreEqual(true, areEqualBytes(ans, res->bytes, res->length), L"P03PackCharacters test 01 failed", 1, 2);
		}
	};
}

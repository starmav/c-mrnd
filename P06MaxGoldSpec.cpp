#include "stdafx.h"
#include "../src/P06MaxGold.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class P06MaxGoldSpec
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

		int charToInt(char bin){
			switch (bin){
			case '0':	return 0;
			case '1':	return 1;
			case '2':	return 2;
			case '3':	return 3;
			}
			return -1;
		}

		struct node* createNewNode(char bin){
			struct node* temp = (struct node*)malloc(sizeof(struct node));
			temp->bin = charToInt(bin);
			temp->first_node = NULL;
			temp->second_node = NULL;
			temp->third_node = NULL;
			return temp;
		}

		struct node* constructTree(char *binString){
			struct node* root = NULL;
			struct node* nodes[2005];
			int i = 0;
			while (binString[i] != '\0'){
				nodes[i] = createNewNode(binString[i]);
				i++;
			}
			int invalid = 3;
			int mid = (i / 3);
			for (int i = 0; i < mid; i++){
				struct node* curnode = nodes[i];
				struct node* firstnode = nodes[(i * 3) + 1];
				struct node* secondnode = nodes[(i * 3) + 2];
				struct node* thirdnode = nodes[(i * 3) + 3];
				if (curnode->bin != invalid){
					if (firstnode->bin != invalid){
						curnode->first_node = firstnode;
					}
					if (secondnode->bin != invalid){
						curnode->second_node = secondnode;
					}
					if (thirdnode->bin != invalid){
						curnode->third_node = thirdnode;
					}
				}
			}
			root = nodes[0];
			return root;
		}

#pragma endregion 

		[TestMethod, Timeout(1000)]
		void Test_P06MaxGold_Sample()
		{
			struct node* head = NULL;
			int expectedAnswer = -1;
			int actualAnswer = max_gold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"P06MaxGold Sample test failed", 1, 2, 1, 2);
		}

		[TestMethod, Timeout(1000)]
		void Test_P06MaxGold_Real02()
		{
			char *binString = "1133";
			struct node* head = constructTree(binString);
			int expectedAnswer = 4;
			int actualAnswer = max_gold(head);
			Assert::AreEqual(expectedAnswer, actualAnswer, L"maxGold Real test 01 failed", 1, 2, 1, 2);
		}
	};
}

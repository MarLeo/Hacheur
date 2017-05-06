#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Hacheur/Hacheur.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HacheurUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		std::string input = "grape";
		std::string verify = "0f78fcc486f5315418fbf095e71c0675ee07d318e5ac4d150050cd8e57966496";

		TEST_METHOD(Test_Hash_String)
		{
			std::string output = Hash::Hash::hash(input);
			Assert::AreEqual(verify, output);
		}

		TEST_METHOD(Test_Hash_Verify)
		{
			Assert::AreEqual(true, Hash::Hash::checkHash(input, verify));
		}

	};
}
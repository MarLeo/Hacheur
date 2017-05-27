#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Hacheur\Hacheur.h"
#include<iostream>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HacheurTest
{		
	TEST_CLASS(HacheurTest)
	{
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


	TEST_CLASS(HacheurTest2)
	{

		char tab[64] = { 's','o','s','h','h','a','s','h','h','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0','1','2','h','a','s','h','h','a','s','h','h','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','f','9','0','1','s' };
		TXI txi1 = *new TXI(3, 5, 7, tab);
		TXI txi2 = *new TXI(4, 6, 8, tab);
		TXI txi3 = *new TXI(5, 7, 9, tab);
		TXI txi4 = *new TXI(6, 8, 0, tab);

		TXI txi[4] = { txi1, txi2, txi3, txi4 };

		char tab3[64] = { 's','o','s','h','h','a','s','h','h','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0','1','2','h','a','s','h','h','a','s','h','h','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','f','9','0','1','s' };
		char tab2[64] = { 'a', 'b', 'c', 'd' };

		UTXO utxo1 = *new UTXO(100, tab2, tab3);
		UTXO utxo2 = *new UTXO(230, tab2, tab3);
		UTXO utxo[2] = { utxo1, utxo2 };

		TX tx = *new TX(txi, utxo);
		UTXO utxo3 = *new UTXO(1000, tab2, tab3);
		UTXO utxo4[1] = { utxo3 };
		TXM txm = *new TXM(utxo4);

		char tab4[64] = { 's','o','s','h','h','a','s','h','h','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0','1','2','h','a','s','h','h','a','s','h','h','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','f','9','0','1','s' };
		char tab5[64] = { 'z','o','s','h','h','a','s','h','h','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0','1','2','h','a','s','h','h','a','s','h','h','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','f','9','0','1','z' };

		unsigned int nonce = 2;

		Bloc bloc = *new Bloc(1, nonce, &tx, &txm, tab5, tab4);
		std::string verification = "c451caf43068ec6b8500c0e8227a4efc14956a70f801a5a58ba226fcd740dabc";

		std::string value_to_hash = Hash::Hash::blocToString(bloc);

		TEST_METHOD(Test_Hash_String_Bloc)
		{	
			std::string output = Hash::Hash::hash(value_to_hash);
			Assert::AreEqual(verification, output);
		}

		TEST_METHOD(Test_Hash_Verify_Bloc)
		{
			Assert::AreEqual(true, Hash::Hash::checkHash(value_to_hash, verification));
		}
	};
}
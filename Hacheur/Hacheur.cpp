// Hacheur.cpp : définit les fonctions exportées pour l'application DLL.
//

#include "stdafx.h"
#include "Hacheur.h"


namespace Hash 
{
	std::string Hash::hash(std::string chaine)
	{
		SHA256 sha256;
		return std::string(sha256(chaine));
	}

	bool Hash::checkHash(std::string chaine, std::string verify)
	{
		return bool(verify == hash(chaine));
	}

	std::string Hash::blocToString(Bloc bloc)
	{
		return std::string(
			"{ \n"
			"	" "previous_hash:" + charToString(bloc.previous_hash, 64) + ", \n" +
			"	" "nonce:" + std::to_string(bloc.nonce) + ", \n" +
			"	" "num:" + std::to_string(bloc.num) + ", \n" +
			"	" "tx1: { \n" +
			"		"	"txi[0]: \n" +
			"		" "{ \n" +
			"			"	"nBloc:" + std::to_string(bloc.tx1.txi[0].nBloc) + ", \n" +
			"			"	"nTx:" + std::to_string(bloc.tx1.txi[0].nTx) + ", \n" +
			"			"	"nUtxo:" + std::to_string(bloc.tx1.txi[0].nUtxo) + ", \n" +
			"			"	"signature:" + charToString(bloc.tx1.txi[0].signature, 64) + "\n" + "	        }, \n" +
			"		"	"txi[1]: \n" +
			"		" "{ \n" +
			"			"	"nBloc:" + std::to_string(bloc.tx1.txi[1].nBloc) + ", \n" +
			"			"	"nTx:" + std::to_string(bloc.tx1.txi[1].nTx) + ", \n" +
			"			"	"nUtxo:" + std::to_string(bloc.tx1.txi[1].nUtxo) + ", \n" +
			"			"	"signature:" + charToString(bloc.tx1.txi[1].signature, 64) + "\n" + "	        }, \n" +
			"		"	"txi[2]: \n" +
			"		" "{ \n" +
			"			"	"nBloc:" + std::to_string(bloc.tx1.txi[2].nBloc) + ", \n" +
			"			"	"nTx:" + std::to_string(bloc.tx1.txi[2].nTx) + ", \n" +
			"			"	"nUtxo:" + std::to_string(bloc.tx1.txi[2].nUtxo) + ", \n" +
			"			"	"signature:" + charToString(bloc.tx1.txi[2].signature, 64) + "\n" + "	        }, \n" +
			"		"	"txi[3]: \n" +
			"		" "{ \n" +
			"			"   "nBloc:" + std::to_string(bloc.tx1.txi[3].nBloc) + ", \n" +
			"			"	"nTx:" + std::to_string(bloc.tx1.txi[3].nTx) + ", \n" +
			"			"	"nUtxo:" + std::to_string(bloc.tx1.txi[3].nUtxo) + ", \n" +
			"			"	"signature:" + charToString(bloc.tx1.txi[3].signature, 64) + "\n" + "	        }, \n" +
			"		"	"utxo[0]: \n" +
			"		" "{ \n" +
			"			"  "montant:" + std::to_string(bloc.tx1.utxo[0].montant) + ", \n" +
			"			"  "dest:" + charToString(bloc.tx1.utxo[0].dest, 4) + ", \n" +
			"			"  "hash:" + charToString(bloc.tx1.utxo[0].hash, 64) + "\n" + "	        }, \n" +
			"		"	"utxo[1]: \n" +
			"		" "{ \n" +
			"			"  "montant:" + std::to_string(bloc.tx1.utxo[1].montant) + ", \n" +
			"			"  "dest:" + charToString(bloc.tx1.utxo[1].dest, 4) + ", \n" +
			"			"  "hash:" + charToString(bloc.tx1.utxo[1].hash, 64) + "\n" + "	        }, \n" +
			"	" "tx0: { \n" +
			"		"	"utxo[0]: \n" +
			"		" "{ \n" +
			"			"	"montant:" + std::to_string(bloc.tx0.utxo[0].montant) + ", \n" +
			"			"	"dest:" + charToString(bloc.tx0.utxo[0].dest, 4) + ", \n" +
			"			"	"hash:" + charToString(bloc.tx0.utxo[0].hash, 64) + "\n" + "	        }, \n" +
			"	   " " }" +
			"\n }"
		);
	}

	std::string Hash::charToString(unsigned char * tab, unsigned int size)
	{
		std::string output = "";

		for (unsigned int i = 0; i < size; i++) {
			output += tab[i];
		}
		return std::string(output);
	}

	std::string Hash::charToString(char tab[], unsigned int size)
	{
		std::string output;

		for (unsigned int i = 0; i < size; i++) {
			output += tab[i];
		}
		return std::string(output);
	}

}
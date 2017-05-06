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
			"previous_hash:" + charToString(bloc.previous_hash, 64) + "," +
			"nonce:" + std::to_string(bloc.nonce) + "," +
			"num:" + std::to_string(bloc.num) + "," +
			"tx1:{" +
			"txi[0]:{" +
			"nBloc:" + std::to_string(bloc.tx1.txi[0].nBloc) + "," +
			"nTx:" + std::to_string(bloc.tx1.txi[0].nTx) + "," +
			"nUtxo:" + std::to_string(bloc.tx1.txi[0].nUtxo) + "," +
			"signature:" + charToString(bloc.tx1.txi[0].signature, 64) + "}," +
			"txi[1]:{" +
			"nBloc:" + std::to_string(bloc.tx1.txi[1].nBloc) + "," +
			"nTx:" + std::to_string(bloc.tx1.txi[1].nTx) + "," +
			"nUtxo:" + std::to_string(bloc.tx1.txi[1].nUtxo) + "," +
			"signature:" + charToString(bloc.tx1.txi[1].signature, 64) + "}," +
			"txi[2]:{" +
			"nBloc:" + std::to_string(bloc.tx1.txi[2].nBloc) + "," +
			"nTx:" + std::to_string(bloc.tx1.txi[2].nTx) + "," +
			"nUtxo:" + std::to_string(bloc.tx1.txi[2].nUtxo) + "," +
			"signature:" + charToString(bloc.tx1.txi[2].signature, 64) + "}," +
			"txi[3]:{" +
			"nBloc:" + std::to_string(bloc.tx1.txi[3].nBloc) + "," +
			"nTx:" + std::to_string(bloc.tx1.txi[3].nTx) + "," +
			"nUtxo:" + std::to_string(bloc.tx1.txi[3].nUtxo) + "," +
			"signature:" + charToString(bloc.tx1.txi[3].signature, 64) + "}," +
			"utxo[0]:{" +
			"montant:" + std::to_string(bloc.tx1.utxo[0].montant) + "," +
			"dest:" + charToString(bloc.tx1.utxo[0].dest, 4) + "," +
			"hash:" + charToString(bloc.tx1.utxo[0].hash, 64) + "}," +
			"utxo[1]:{" +
			"montant:" + std::to_string(bloc.tx1.utxo[1].montant) + "," +
			"dest:" + charToString(bloc.tx1.utxo[1].dest, 4) + "," +
			"hash:" + charToString(bloc.tx1.utxo[1].hash, 64) + "}" +
			"}," +
			"tx0:{" +
			"utxo[0]:{" +
			"montant:" + std::to_string(bloc.tx0.utxo[0].montant) + "," +
			"dest:" + charToString(bloc.tx0.utxo[0].dest, 4) + "," +
			"hash:" + charToString(bloc.tx0.utxo[0].hash, 64) + "}" +
			"}" +
			"}"
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
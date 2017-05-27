#pragma once
#ifndef _BLOC_H

//
// bloc.h  version 1.0
//
// projet blockchain M2IF 2016
//

#define KEY_SIZE 4 // taille en byte des cle (publique, privee) a valider avec les groupes specifiant et developpant la signature
#define HASH_SIZE 64  // taille du hash, a valider avec les groupes specifiant et developpant le hacheur

#include<string>

class TXI // input d'une transaction
{
public:
	unsigned int nBloc;
	unsigned int nTx;   // hash of the previous transaction
	unsigned int nUtxo; // index of output ( la référence d'une transaction précédente)
	char signature[HASH_SIZE]; // signature de la transaction avec la clé privée

	TXI();
	TXI(unsigned int, unsigned int, unsigned int);
	TXI(unsigned int, unsigned int, unsigned int, char*);
	virtual ~TXI();
};

class UTXO // une sortie non dépensée
{
public:
	float montant;
	char dest[KEY_SIZE];  //	compte destinataire (clé publique)
	char hash[HASH_SIZE];    // hash(nBloc,nTx,nUTXO,montant,destinataire) pour securisation de l'UTXO

	UTXO();
	UTXO(float, char*);
	UTXO(float, char*, char*);
	virtual ~UTXO();
};

class TX { // transaction standard 
public:
	TXI txi[4]; // input d'une transaction
	UTXO utxo[2]; // sortie non dépensée

	TX();
	TX(TXI*, UTXO*);
	virtual ~TX();
};

class TXM { // transaction du mineur
public:
	UTXO utxo[1];

	TXM();
	TXM(UTXO*);
	~TXM();
};

class Bloc
{

public:
	char hash[64]; // hash des autres champs, hash of the entire bloc
	char previous_hash[HASH_SIZE]; // hash of the previous bloc
	unsigned int nonce;
	int num; // numero du bloc, commence a zero
	TX tx1; //  transaction du bloc
	TXM tx0; // transaction du mineur (coinbase)

	Bloc();
	~Bloc();
	Bloc(int, TX*, TXM*);
	Bloc(int, unsigned int, TX*, TXM*);
	Bloc(int, unsigned int, TX*, TXM*, char*);
	Bloc(int, unsigned int, TX*, TXM*, char*, char*);

};
#endif
#include "stdafx.h"

#include "Bloc.h"

TX::TX() {}
TX::~TX() {}


TX::TX(TXI* _txi, UTXO* _utxo) {
	*txi = *_txi;
	*utxo = *_utxo;
}

TXI::TXI() {}

TXI::TXI(unsigned int _nBloc, unsigned int _nTx, unsigned int _nUtxo) {
	nBloc = _nBloc;
	nTx = _nTx;
	nUtxo = _nUtxo;
}

TXI::TXI(unsigned int _nBloc, unsigned int _nTx, unsigned int _nUtxo, char* _signature) {
	nBloc = _nBloc;
	nTx = _nTx;
	nUtxo = _nUtxo;
	//strcpy(this->signature, signature);
	//std::strncpy(this->signature, _signature, sizeof(_signature));
	strncpy(signature, _signature, sizeof(_signature));
}

TXI::~TXI() {}

TXM::TXM() {}
TXM::TXM(UTXO* _utxo) {
	*utxo = *_utxo;
}
TXM::~TXM() {}

UTXO::UTXO() {}

UTXO::UTXO(float _montant, char* _dest) {
	montant = _montant;
	//strcpy(this->dest, dest);
	strncpy(dest, _dest, sizeof(_dest));
}

UTXO::UTXO(float _montant, char* _dest, char* _hash) {
	montant = _montant;
	strncpy(dest, _dest, sizeof(_dest));
	strncpy(hash, _hash, sizeof(_hash));
}

UTXO::~UTXO() {}


Bloc::Bloc() {}

Bloc::Bloc(int _num, TX* _tx1, TXM* _tx0) {
	num = _num;
	//this->nonce = nonce;
	tx1 = *_tx1;
	tx0 = *_tx0;
}

Bloc::Bloc(int _num, unsigned int _nonce, TX* _tx1, TXM* _tx0) {
	num = _num;
	nonce = _nonce;
	tx1 = *_tx1;
	tx0 = *_tx0;
}

Bloc::Bloc(int _num, unsigned int _nonce, TX* _tx1, TXM* _tx0, char* _previous_hash) {
	num = _num;
	nonce = _nonce;
	tx1 = *_tx1;
	tx0 = *_tx0;
	strncpy(this->previous_hash, _previous_hash, sizeof(_previous_hash));
}

Bloc::Bloc(int _num, unsigned int _nonce, TX* _tx1, TXM* _tx0, char* _previous_hash, char* _hash) {
	num = _num;
	nonce = _nonce;
	tx1 = *_tx1;
	tx0 = *_tx0;
	strncpy(this->previous_hash, _previous_hash, sizeof(_previous_hash));
	strncpy(this->hash, _hash, sizeof(_hash));
}

Bloc::~Bloc() {}
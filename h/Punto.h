#pragma once
#include "ofMain.h"
#include "Angolo.h"

class Punto : public Angolo
{
public:
	Punto(void);
	~Punto(void);

	void aggiornaDimPassoAngolo(float _dim, float _passo, float _angolo);
	void aggiungiPunto(ofVec2f _punto);
	void aggiungiPuntoAtDirezione();
	void eliminaUltimoPunto();
	void eliminaPrimoPunto();
	
	void avantiDestra();
	void avantiSinistra();
	void giroCompletoDestra();
	void giroCompletoSinistra();

	void disegnaPunto();
	void disegnaStoria();

private:
	deque <ofVec2f> contenitore;
	int dimensioneMassima;
	int dimensione;
	int contatore;
	bool elimina;
	float passo;

	
};


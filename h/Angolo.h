#pragma once
#include "ofMain.h"

class Angolo
{

public:
	Angolo(void);
	Angolo(ofVec2f _centro, float _raggio);	

	void aggiornaAngolo(float _angolo);
	void destra();
	void sinistra();
	void ingresso();
	void scelta();	
	void teorema();
	void giroDestra();
	void giroSinistra();
	bool rivoluzione();

	
	void disegna();


	ofVec2f centro;
	float raggio;
	ofVec2f dir;
	ofVec2f orientamento;

	float angolo;
	int sommaAngolo;
	
	float unAngolo;
	bool sonoPartito;

	float timer;
	bool tempo;

	bool girodestra;
	bool girosinistra;
	bool giro;
};



		
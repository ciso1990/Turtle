#include "src\Angolo.h"

Angolo::Angolo(void)
{
}

Angolo::Angolo(ofVec2f _centro, float _raggio)
{
	centro = _centro;
	raggio = _raggio;
	dir = ofVec2f(1, 0);
	angolo = 0;
	sommaAngolo = 0;
	sonoPartito = false;	

	tempo = false;
	timer = 50.f;

	girodestra = false;
	girosinistra = false;
	giro = false;
}

void Angolo::aggiornaAngolo(float _angolo)
{
	angolo = _angolo;
	orientamento = centro + raggio * dir;
}

void Angolo::destra()
{
	dir.rotate(angolo);
	sommaAngolo -= angolo;
	if(sommaAngolo<0){
		sommaAngolo +=360;
	}
}

void Angolo::sinistra()
{
	dir.rotate(-angolo);
	sommaAngolo += angolo;
	if(sommaAngolo >= 360){
		sommaAngolo = 0;
	}
}

void Angolo::ingresso()
{
	unAngolo = sommaAngolo;
	tempo = !tempo;
}

void Angolo::scelta()
{
	if(tempo){
		timer -= 1.f;
			if(timer <= 30.f){
				sonoPartito = !sonoPartito;
				tempo = false;
				timer = 50;
			}
	}
}

void Angolo::teorema()
{
	if(sonoPartito){
		if(unAngolo != sommaAngolo){
			giro = !giro;
	}else if(unAngolo == sommaAngolo){
			sonoPartito = !sonoPartito;
			giro = false; 
			girodestra = false;
			girosinistra = false;
		}
	}
}

bool Angolo::rivoluzione()
{
	return giro;
}

void Angolo::giroDestra()
{
	girodestra = !girodestra;
}

void Angolo::giroSinistra()
{
	girosinistra = !girosinistra;
}


void Angolo::disegna()
{
	
	ofSetCircleResolution(60);
	ofPushStyle();
		ofSetColor(ofColor::white);	
		ofNoFill();
		ofCircle(centro, raggio);
		ofLine(centro, orientamento);
		ofDrawBitmapString(ofToString(sommaAngolo), centro.x+raggio+30, 200);
	ofPopStyle();
	
	if(tempo || sonoPartito){
		ofPushMatrix();
			ofPushStyle();
			ofNoFill();
				ofSetColor(ofColor::red);
					ofVec2f tempDir = ofVec2f(1, 0);
					tempDir.rotate(-unAngolo);
					ofVec2f punto = centro + raggio * tempDir;	
					ofCircle(punto, 20);
					ofDrawBitmapString(ofToString(unAngolo), punto.x, punto.y+50);
			ofPopStyle();
		ofPopMatrix();
	}
	
	ofPushStyle();
		if(sonoPartito){
			ofSetColor(ofColor::red);
		}else {
			ofSetColor(ofColor::white);
		}
		string testo = "teorema dell'angolo giro";
		ofDrawBitmapString(testo, ofGetWidth()- 280, centro.y - raggio - 50, 0.f);
	ofPopStyle();
}

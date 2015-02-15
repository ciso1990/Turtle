#include "src\Punto.h"

//1720
Punto::Punto(void):Angolo(ofVec2f(600, 200), 100)
{
	contatore = 0;
	dimensioneMassima = 15;
	dimensione = contenitore.size();
	elimina = true;
	aggiungiPunto(ofVec2f(70, ofGetHeight()/2));
	passo = 50;
}

Punto::~Punto(void)
{
}

void Punto::aggiornaDimPassoAngolo(float _dim, float _passo, float _angolo)
{
	dimensioneMassima = _dim;
	passo = _passo;
	aggiornaAngolo(_angolo);
}

void Punto::aggiungiPunto(ofVec2f _punto)
{
	contenitore.resize(contenitore.size()+1);
	contenitore[contenitore.size()-1] = _punto;
}
void Punto::aggiungiPuntoAtDirezione()
{
	ofVec2f ultimoPunto =  contenitore[contenitore.size()-1];
	ofVec2f nuovoPunto = ofVec2f(ultimoPunto + passo * dir);
	aggiungiPunto(nuovoPunto);
}

void Punto::eliminaUltimoPunto()
{
	contenitore.erase(contenitore.end()-1);
	if(contatore > 1){contatore--;}
}

void Punto::eliminaPrimoPunto()
{
	int indice = contenitore.size()-1;
	if(indice > dimensioneMassima){
		contenitore.erase(contenitore.begin());
		elimina = false;
		contatore--;
		if(contatore <1){
			contatore = dimensioneMassima;
		}
	}
}

void Punto::giroCompletoDestra()
{ 
	if(rivoluzione()){
		if(girodestra){
			avantiDestra();
		}
	}else giro = false;
}

void Punto::giroCompletoSinistra()
{ 
	if(rivoluzione()){
		if(girosinistra){
			avantiSinistra();
		}
	}else giro = false;
}

void Punto::avantiDestra()
{
	destra();
	aggiungiPuntoAtDirezione();
}

void Punto::avantiSinistra()
{
	sinistra();
	aggiungiPuntoAtDirezione();
}

void Punto::disegnaPunto()
{
	disegna();

	int ultimoPunto = contenitore.size()-1;
	int r = 20;
	float angle = (float)atan2(-dir.y, dir.x);
    float theta =  -1.0*angle;
    float heading2D = ofRadToDeg(theta)+90;
	

    ofSetColor(0);
    ofFill();
    ofPushMatrix();
       ofTranslate(contenitore[ultimoPunto].x,  contenitore[ultimoPunto].y);
        ofRotate(heading2D);
            ofBeginShape();
			ofPushStyle();
			ofNoFill();
			ofSetColor(ofColor::white);
                ofVertex(0, -r*2);
                ofVertex(-r, r*2);
                ofVertex(r, r*2);
            ofEndShape(true);
			ofPopStyle();
    ofPopMatrix();

	if(contenitore.size() > 1){
		ofPushStyle();
			ofFill();
			ofSetColor(ofColor::blue);
			if(elimina){
			contatore = contenitore.size()-1;
			}
			ofCircle(contenitore[contatore].x, contenitore[contatore].y, 5);
			ofPopStyle();

		}
	
	disegnaStoria();
}

void Punto::disegnaStoria()
{
	for(int i=0; i<contenitore.size()-1; i++){
		ofPushStyle();
			ofNoFill();
			ofSetColor(ofColor::white);
			ofCircle(contenitore[i].x, contenitore[i].y, 5);
			ofSetColor(ofColor::red);
			ofLine(contenitore[i], contenitore[i+1]);
		ofPopStyle();
		}
}
/*


	void mondo(int _w, int _h)
	{
		int indice = contenitore.size()-1;
		int w = _w;
		int h = _h;
		int lato = 50;

		if( contenitore[indice].x > w+lato){ contenitore[indice].x = 1;}
		if(contenitore[indice].y > h+lato){ contenitore[indice].y = -lato;}
		if(contenitore[indice].x < -lato){ contenitore[indice].x = w + lato;}
		if(contenitore[indice].y < -lato) { contenitore[indice].y = h + lato;}
	}

*/
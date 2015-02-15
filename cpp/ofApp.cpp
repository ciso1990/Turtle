#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	b = Punto();
	gui.setColor();
	gui.setStateBotton();
	gui.setup();
//	ofToggleFullscreen();
}

//--------------------------------------------------------------
void ofApp::update(){
	b.aggiornaDimPassoAngolo(gui.dimVettore, gui.passo, gui.angolo);

	b.scelta();
	b.teorema();

	b.giroCompletoDestra();
	b.giroCompletoSinistra();
	
	b.eliminaPrimoPunto();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(0.f);
	b.disegnaPunto();

	
	gui.drawGui();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if(key == OF_KEY_LEFT){b.sinistra();}
	if(key == OF_KEY_RIGHT){b.destra();}
	if(key == OF_KEY_UP){b.aggiungiPuntoAtDirezione();}
	if(key == OF_KEY_DOWN){b.eliminaUltimoPunto();}

	
	if(key=='s'){b.ingresso();}

	if(key=='d'){b.giroDestra(); b.avantiDestra();}
	if(key=='a'){b.giroSinistra(); b.avantiSinistra();}



}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	gui.pannel.mouseDragged(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	gui.pannel.mousePressed(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

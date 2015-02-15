#pragma once

#include "ofMain.h"
#include "mrpGui\simpleButton.h"
#include "mrpGui\pagePanel.h"
#include "mrpGui\baseGui.h"
#include "mrpGui\floatSlider.h"


class Gui
{
public:

	void setColor()
	{
		 nero=ofColor(0.f,0.f,0.f,80.f);
		 rosso=ofColor(255.f, 0.f,0.f,200.f);
		 white = ofColor::white;
		 blu=ofColor(0.f,0.f,255.f,255.f);
		 giallo=ofColor(255.f,255.f,0.f,255.f);
		 bgd=ofColor(40.f, 40.f, 40.f, 255.f);
	}	

	void setStateBotton()
	{
		 dimVettore = 0;
		 passo = 30.f;
		 angolo = 10;
	}

	void setup()
	{	
	config cfg;
	cfg.area= ofRectangle(10, 10, 300, 0);
	cfg.cBack = &nero;
	cfg.cStroke= &blu;
	cfg.cString = &white;
	cfg.cOn = &rosso;
	cfg.cOff = &nero;
	cfg.cTitle = &blu;
	
	pannel.setBase(cfg);
	pannel.setGrid("controlli", 50, 20, 5);

  	pannel.addCell(&bDimVettore);
	pannel.addCell(&bPasso);
	pannel.addCell(&bAngolo);

	pannel.setCtrls();
	bDimVettore.setup("elementi", &dimVettore, 0, 100);
	bPasso.setup("passo", &passo, 0, 300);
	bAngolo.setup("ruota", &angolo, 0, 360);
	}


	void drawGui()
	{
		pannel.render();
	}

	pagePanel pannel;

	float passo;
	int dimVettore;
	int angolo;
	intSlider bAngolo;
	intSlider bDimVettore;
	floatSlider bPasso;

	ofColor nero;
	ofColor rosso;
	ofColor blu;
	ofColor giallo;
	ofColor white;
	ofColor bgd;
};




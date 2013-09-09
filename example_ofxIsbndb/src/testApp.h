#pragma once

#include "ofMain.h"

#include "ofxIsbndb.h"

// -------------------------------------------------------
// ISBN Numbers ------------------------------------------
// -------------------------------------------------------

// Programming interactivity - Joshua Noble
#define ISBN13_ProgrammingInteractivity 9780596154141
#define ISBN13_RaisonsEtSentiments      9782264058256
#define ISBN13_HyperionTome1            9782266111560
#define ISBN13_SlumDog                  9782264045531


class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofxIsbndb m_oIsbndb;
    
    
};

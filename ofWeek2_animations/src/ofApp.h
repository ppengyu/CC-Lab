#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofPoint from, to,newFrom,newTo,from3,to3,from4, to4;
        //make two point called "from" and "to", containing position x and y
    ofPoint circleCenter,newCircleCenter, circleCenter3, circleCenter4;
    
    float radius;
    float currentPercent;
};

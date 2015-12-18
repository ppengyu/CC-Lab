#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxFPSCamera.h"

class testApp : public ofBaseApp{

  public:
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);

	ofxFPSCamera camera;
    
    float distance;
    int theCylinder;
    
    
	

    ofCylinderPrimitive cylinders [80];
    
    ofCylinderPrimitive colorCylinder;
    int neighbourhood [10];
    
    ofImage bgImage;
};

#endif

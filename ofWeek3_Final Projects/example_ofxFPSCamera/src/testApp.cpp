#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
    
    
    
	camera.setup();
    
    
    /*****************************************************
    // ofxFPSCamera example
     
    // by Ivaylo Getov, 2014
    // Derived from ofxGameCamera, created by James George and FlightPhase
     
    // Methods: ////////////////////////
     
    camera.disableMove()                                // Disables both mouse and keyboard control
    camera.enableMove()                                 // Enables both mouse and keyboard control
     
    camera.disableStrafe()                              // Disables left/right strafe (A/D or left/right arrow)
    camera.enableStrafe()                               // Enables left/right strafe (on by default)
     
    camera.setCamHeight(float ch);                      // Sets camera y-height
     
    camera.target(ofVec3f v);                           // Sets look target as a vector from current camera position
    camera.getTarget();                                 // Returns current target as an ofVec3f
     
    camera.getPosition();                               // Returns ofVec3f of (X,Y,Z) position
    camera.setPosition(float px, float py, float pz);   // Sets camera position to (x,y,z)
    camera.setPosition(const ofVec3f &p);               // Sets camera position to ofVec3f
    camera.movedManually();                             // Call this whenever you update orientation or position manually (eg using camera.setPosition())
     
    camera.setMinMaxY(float angleDown, float angleUp);  // Set new limits for looking down and up
     
    camera.reset();                                     // Sets camera position to (0,0,0) and camHeight = 0.0
    camera.reset(float h);                              // Sets camera position to (0,0,0) and camHeight = h
    camera.reset(float x, float y, float z);            // Sets camera position to (x,y,z) and camHeight = 0.0
    camera.reset(float x, float y, float z, float h);   // Sets camera position to (x,y,z) and camHeight = h
    camera.reset(ofVec3f v);                            // Sets camera position to ofVec3f v and camHeight = 0.0
    camera.reset(ofVec3f v, float h);                   // Sets camera position to ofVec3f v and camHeight = h
     
    
    // Defaults: ///////////////////////
     
	camera.sensitivityX = 0.10f;            // Mouse Sensitivity
	camera.sensitivityY = 0.10f;
    
    
	camera.speed = 8.0f;                    // Movement speed
    
	camera.usemouse = true;
    camera.useArrowKeys = false;            // arrow keys instead of W A S D

	camera.autosavePosition = false;
    
    camera.camHeight = 0.0;                 // Camera will always move along a horizontal plane at this Y-value
    camera.upAngle = -30.0;                 // must be negative - limits angle looking UP
    camera.downAngle = 30.0;                // must be positive - limits angle looking DOWN
    
    camera.keepTurning = false;             // When mouse is at far left or right of screen, setting this to TRUE will
                                            // keep the camera rotating in that direction. The default setting of FALSE will
                                            // allow for an "infinite" mouse, repositioning the mouse to the middle when it reaches
                                            // the edge. This is tested on a Mac and SHOUD work on windows, but I haven't had
                                            // a chance to test it. Currently does not worl on Linux.
    
    camera.easeIn = true;                   // Camera movements speed up gradually until they reach value set as camera.speed.
    camera.accel = 0.3;                     // if easeIn is set to TRUE, this is the rate of acceleration.
    
    *****************************************************/
    
    camera.target(ofVec3f(1,0,0));

    //white ones
    for (int i = 0; i < 80; i++) { //the mac of i is the amount of cylinders
        cylinders[i].set(ofRandom(20,30),ofRandom(20,200));
        //the height and the radius of the cylinders
        cylinders[i].setPosition(ofRandom(0,ofGetWidth()), 0, ofRandom(-600,600));
        //the coordinate (x,y,z)of the cylinders
    }
    
    //red cylinder
    colorCylinder.set(30, 100);
    colorCylinder.setPosition(ofRandom(0, ofGetWidth()), 0, ofRandom(-600, 600));
    
    
    ofHideCursor();
    ofSetWindowPosition(ofGetScreenWidth()/2 - ofGetWidth()/2, ofGetScreenHeight()/2 - ofGetHeight()/2);
}

//--------------------------------------------------------------
void testApp::update(){

    ofVec3f v1 = colorCylinder.getPosition();
    ofVec3f v2 = camera.getPosition();
    
    distance = v1.distance(v2);
    
    if (distance <300)
    {
        colorCylinder.setPosition(ofRandom(0, ofGetWidth()), 0, ofRandom(-600, 600));
    }
    
}

    
 // cylinders[]


//--------------------------------------------------------------
void testApp::draw(){
    //bgImage.loadImage("data/bg.png");
   // ofBackground.loadimage
	//ofBackground(144,212,212);
   ofColor colorOne (4,51,106);
    ofColor colorTwo (0);//11,146
    ofBackgroundGradient(colorOne, colorTwo,OF_GRADIENT_LINEAR);
    
	camera.begin();
    

    ofSetColor(5,131,235,150);
    //the color of the grid of the floor 200
    int step = 30;
    for (int i = 0; i < step; i++) {
        ofLine(i*ofGetWidth()/step, -50, -ofGetWidth(), i*ofGetWidth()/step, -50, ofGetWidth());
        ofLine(0, -50, i*ofGetWidth()/step, ofGetWidth(), -50, i*ofGetWidth()/step);
        ofLine(0, -50, -i*ofGetWidth()/step, ofGetWidth(), -50, -i*ofGetWidth()/step);
    }
    
    ofSetColor(200,150);
    for (int i = 0; i < 80; i++)
    {
        cylinders[i].drawWireframe();
    }
    
    
    ofSetColor (255, 0, 0,100);
    colorCylinder.draw();
    ofSetColor(255);
    colorCylinder.drawWireframe();
    
    //ofSetColor(0, 0, ofRandom(0, 255));
  //  cylinders[]

    
	camera.end();
	
    
    if (camera.easeIn) {
        ofDrawBitmapString("easing is ON", ofPoint(30, ofGetHeight()-30));
    } else {
        ofDrawBitmapString("easing is OFF", ofPoint(30, ofGetHeight()-30));
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case ' ':
            camera.setPosition(0, 0, 0);
            camera.target(ofVec3f(1,0,0));
            break;
            
        case 'f':
            ofToggleFullscreen();
            break;
            
        case 'e':
            camera.easeIn = !camera.easeIn;
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

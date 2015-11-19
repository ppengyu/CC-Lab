#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(30);
    
    for (int i=0; i<20; i++) {
        balls[i].x = ofRandomWidth();
        balls[i].y = ofRandomHeight();
        balls[i].vx = ofRandom(-10,10);
        balls[i].vy = ofRandom(-10,10);
        balls[i].radius = ofRandom(10,40);
    }
    
}

//--------------------------------------------------------------
void testApp::update() {
    
    for (int i=0; i<20; i++) {
        
        balls[i].x = balls[i].x + balls[i].vx;
        balls[i].y = balls[i].y + balls[i].vy;
        
        if (balls[i].x<0 || balls[i].x > ofGetWidth()) {
            balls[i].vx = -balls[i].vx;
        }
        
        if (balls[i].y<0 || balls[i].y > ofGetHeight()) {
            balls[i].vy = -balls[i].vy;
        }
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i=0; i<20; i++) {
        ofSetColor(ofRandom(0,255), 255, 0);
        ofCircle(balls[i].x, balls[i].y, balls[i].radius);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
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
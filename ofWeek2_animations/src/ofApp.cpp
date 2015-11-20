#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    newFrom.set(ofGetWidth()/2, ofGetWindowHeight()/2);
    from3.set(0, ofGetWindowHeight());
    from4.set(ofGetWindowWidth(), ofGetWindowHeight());
    

}

//--------------------------------------------------------------
void ofApp::update(){
    from.set(mouseX, mouseY);
    
    currentPercent = ofMap(sin(ofGetElapsedTimef()),-1,1,0,1);
    //mapping
    
    circleCenter = from.getInterpolated(to, currentPercent);
    //set the circlecenter between "from" and "to", the exact position is the currentPercent;
    newCircleCenter = newFrom.getInterpolated(newTo, currentPercent);
    newTo.set(circleCenter);
    circleCenter3 = from3.getInterpolated(to3,currentPercent);
    to3.set(newCircleCenter);
    circleCenter4 = from4.getInterpolated(to4,currentPercent);
    to4.set(circleCenter3);

    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //EXAMPLE1 - circles
    ofSetColor(ofRandom(0,255), 255, ofRandom(0,255));
    ofCircle(circleCenter, 100*currentPercent);
    ofSetColor(ofRandom(0,255), 0, 255);
    ofLine(from,to);//making a line start from the point from to the point to.
    ofCircle(newCircleCenter, 100*currentPercent);
    ofLine(newFrom,newTo);
    ofSetColor(255, 0, ofRandom(0,255));
    ofCircle(circleCenter3, 100*currentPercent);
    ofLine(from3,to3);
    ofSetColor(ofRandom(0,255), 255, 0);
    ofCircle(circleCenter4, 100*currentPercent);
    ofLine(from4,to4);
    
    
    //EXAMPLE2 -noise
   // float temp= ofNoise(ofGetElapsedTimef())*255;
   // cout << temp<< endl;
   // ofBackground(temp);
    
    //EXAMPLE3 -tele noise
//    for (int i =0; i<ofGetWidth(); i++) {
//        for (int j=0; j<ofGetHeight();j+=2){
//            ofColor temp = 255* ofNoise(i,j,ofGetElapsedTimef()*mouseX);
//           // float temp= ofRandom(255);
//            ofSetColor(temp);
//            ofRect(i,j,2,2);
//            
//        }
//            }


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    //if I want to use the mouseReleased, i write down here
    to.set(x, y);

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

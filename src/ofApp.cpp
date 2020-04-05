#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
//    shader.load("shader");
    shaderFilter.load("shader.frag");
    shaderFilter.allocate(ofGetWidth(), ofGetHeight());
    buffer.resize(N, 0.0);
    soundStream.setup(this, 2 , 1, sampleRate, 512, 4);
}

//--------------------------------------------------------------
void ofApp::update(){
    //float red = sin( ofGetElapsedTimef() * 8) * 2.0;
    //float green = sin( ofGetElapsedTimef() * 8) * 2.0;
//    float time = sin(ofGetElapsedTimef() / 10000);
//    shaderFilter.setUniform1f("u_mouse.x", ofGetMouseX());
//    shaderFilter.setUniform1f("u_mouse.y", ofGetMouseY());
//    shaderFilter.setUniform1f("u_time", N);
    ofSoundUpdate();
    shaderFilter.setUniform1f("u_time", playPos);
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
//    shader.begin();
//    ofDrawRectangle(0,0, ofGetWidth(), ofGetHeight());
//    shader.end();
    shaderFilter.render();
    shaderFilter.draw(0, 0);
    
    
//    i = float(x) * N / w;
//    ofBackground(255, 255, 255);
    
    int w = ofGetWidth(); // width of the visualization picture
    
    //Graph of the sound buffer
//    ofSetColor(0, 0, 0);
//    for (int x = 0; x < w; x++) {
//        int i = float(x) * N / w; // Convert x to buffer's position
////        ofDrawLine(x, 100, x,  100 - buffer[i] * 100);
////        shaderFilter.render();
////        shaderFilter.draw(x, buffer[i] * 100);
//
//    }
    
    //Stripe image
//    for (int x = 0; x < w; x++) {
//        int i = float(x) * N / w; //Convert x to buffer's position
//        float v = buffer[i]; //Get buffer value
//
//        //Apply square-root transformation and also shift by 0.2 to make to picture brighter
//        v = ofSign(v) * sqrt(fabs(v)) + 0.2;
//
//        //Convert v to range [0,255]
//        float col = ofMap(v, -1, 1, 0, 255, true);
//
//        // Set color and draw vertical line
//        ofSetColor(col, col, col);
//        shaderFilter.render();
//        shaderFilter.draw(0, 0);
//    }
}
//--------------------------------------------------------------
void ofApp::audioReceived(float *input,int bufferSize, int nChannels){
    
    //If recording is enabled by the user, then store data received
    if (recordingEnabled) {
        for (int i =0; i < bufferSize; i++) {
            buffer[recPos] = input[i];
            recPos++;
            //When the end of buffer is reached, recPos sets to 0, so we record sound in a loop
            recPos %=N;
//            shaderFilter.setUniform1f("u_time", recPos);
        }
    }

}
//--------------------------------------------------------------
void ofApp::audioOut(float *output, int bufferSize, int nChannels){
    // If playing is enabled by the user, then do output sound
    if (playingEnabled) {
        for (int i = 0; i < bufferSize; i++) {
            output[ 2*i ] = output[ 2*i+1 ]
            =buffer[playPos];
            playPos++;
            //When the end of the buffer is reached, playPos sets to 0, so we hear looped sound
            playPos %= N;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    //Enable recording mode
    if (key == '1') {
        recordingEnabled = 1;
        playingEnabled = 0;
    }
    
    // Enable playing mode
    if (key == '2') {
        recordingEnabled = 0;
        playingEnabled = 1;
    }
    
    //Save screen image to the file
    if (key == 's') {
        ofImage grab;
        grab.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        grab.save("grab.png");
    }
    
    
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

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

    shaderFilter.allocate(w,h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

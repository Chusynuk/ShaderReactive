#pragma once

#include "ofMain.h"
//#include "ofxShader.h"
#include "ofxShaderFilter.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

//		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
//    void audioReceived(float *input, int bufferSize, int nChannels);
//    void audioOut(float *output, int bufferSize, int nChannels);
//
//    ofxShader shader;
    
    ofxShaderFilter shaderFilter;
    ofxPanel gui;
    
//    ofSoundStream soundStream;
//
//
//    const int sampleRate = 44100; //Sample rate of sound
//    const float duration = 5.0; // Suration of the recorded sound in seconds
//
//    const int N = duration * sampleRate; //Size of the PCM buffer
//
//    //Variables
//
//    vector<float> buffer; //PCM buffer of sound sample
//    int recPos = 0; //Current recording postion in the buffer.
//    int playPos = 0; //Current playing position in the buffer.
//
//    int recordingEnabled = 1; // //Is recording enabled
//    int playingEnabled = 0; // Is playing enabled.
    
    ofParameter<float> volume;
    ofParameter<float> decay;
    
    ofSoundPlayer sound;
		
    float *fft;
    float *soundSpectrum;
    int bands;
};

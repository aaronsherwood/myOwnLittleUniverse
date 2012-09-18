#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofParticle.h"

#define NPARTICLES 5


class testApp : public ofBaseApp {
public:
	
	void setup();
	void update();
	void draw();
    void keyPressed(int key);
	void exit();
	
	ofxKinect kinect;
    ofEasyCam easyCam;
    ofParticle particle[NPARTICLES];
    ofParticle particle2[NPARTICLES];
    ofParticle particle3[NPARTICLES];
};

#include "testApp.h"

ofVec3f trackedPoint;
ofVec3f trackedPoint2;
ofVec3f trackedPoint3;
bool show;




void testApp::setup() {
    
	kinect.init();
	kinect.setRegistration(true);
	kinect.setDepthClipping(50, 1500);
    ofEnableSmoothing();
	kinect.open();
}

void testApp::update() {
    
		//ofHideCursor();
        
	
	kinect.update();
	if(kinect.isFrameNew()) {
        int width = kinect.getWidth();
		int height = kinect.getHeight();
		float* distancePixels = kinect.getDistancePixels();
        float forePoint = 8000;
        for(int y = 0; y < height-1; y++) {
				for(int x = 0; x < width-1; x++) {
                    int i = y * width + x;
                    float z = distancePixels[i];
                    int trackedX;
                    int trackedY;
                    if (z >0 && z < forePoint) {
                        forePoint=z;
                        trackedX=x;
                        trackedY=y;
                        trackedPoint=kinect.getWorldCoordinateAt(x,y,z);
                        }
                    if (z >0 && z < forePoint+200 && z > forePoint && (x > trackedX+200 || x < trackedX -200) ){
                        trackedPoint2=kinect.getWorldCoordinateAt(x,y,z);
                        }
                    if (z >0 && z < forePoint+200 && z > forePoint && (y > trackedY+200 || y < trackedY -200) ){
                        trackedPoint3=kinect.getWorldCoordinateAt(x,y,z);
                    }
                    }
				}
        
        
        for (int i=0; i<NPARTICLES; i++) {
            particle[i].update(trackedPoint);
            particle2[i].update(trackedPoint2);
            particle3[i].update(trackedPoint3);
        
            }
        }
        
        
	}


void testApp::draw() {
    ofSetupScreen();
	ofBackground(245);
    easyCam.begin();
    ofScale(-1, -1, 1);
    ofTranslate(0, 0, -1000);
   
    for (int i=0; i<NPARTICLES; i++) {
        ofSetColor(255,0,0,150);
        particle[i].draw();
        ofSetColor(0,0,255,200);
        particle2[i].draw();
        ofSetColor(0,255,0,200);
        particle3[i].draw();
    }
    
    easyCam.end();
    if (show) {
        ofSetColor(255);
        //kinect.drawDepth(950, 300, 320, 240);
        kinect.drawDepth(1420, 650, -320, 240);
    }
    
	
} 

void testApp::keyPressed  (int key){ 
	if (key==114 || key==82){
        if (show) {
            show=false;
        } else {
            show=true;
        }
    }
    if (key==122 || key==90){
        for (int i=0; i<NPARTICLES; i++) {
            particle[i].reset();
            particle2[i].reset();
            particle3[i].reset();
    }
        
}
}

void testApp::exit() {
	kinect.close();
}


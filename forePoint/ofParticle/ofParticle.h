#ifndef _OF_PARTICLE 
#define _OF_PARTICLE 

#include "ofMain.h"

class ofParticle {
    
public: float drag;
        ofVec3f target;
    
    // methods
    void update(ofVec3f coords); 
    void draw();
    ofVec3f destination();
    void reset();
    
    // variables
    ofVec3f currentPoint;
    ofVec3f previousPoint;
    ofVec3f desired;
    ofVec3f vel;
    ofVec3f acc;
    ofVec3f steer;
    ofPolyline line;
    
    //constructor
    ofParticle();
    
}; 

#endif 
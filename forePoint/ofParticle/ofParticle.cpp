#include "ofParticle.h"

//--------------------------------------------------------------
ofParticle::ofParticle(){
    drag = .957;
    vel.set(ofRandom(-2,2),ofRandom(-2,2),ofRandom(-2,2));
}

//--------------------------------------------------------------
void ofParticle::update(ofVec3f coords){
    currentPoint.set(coords);
    desired = currentPoint-previousPoint;
    float magnitude= desired.length();
    if (magnitude>0){
        magnitude= 1.0f/magnitude * ofRandom(1);
        desired*=magnitude;
    }
    acc+=desired;
    vel+=acc;
    vel*=drag;
    previousPoint=target;
    target+=vel;
    acc.set(0,0,0);
}

void ofParticle::draw(){
    line.addVertex(target);
    line.draw();
    
}

ofVec3f ofParticle::destination (){
    
    return target;
}

void ofParticle::reset (){ 
        line.clear();
}


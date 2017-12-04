#pragma once

// auraglyph by clay@calarts.edu

#include "ofMain.h"

#define FRAME_DELAY_LENGTH 30

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

private:
    ofVideoGrabber webcam;
    ofTexture current_frame;
    
    ofShader anaglyph;
    
    int write_head;
    ofTexture delay[FRAME_DELAY_LENGTH];
};

#pragma once

// auraglyph by clay@calarts.edu

#include "ofMain.h"

#define MAX_FRAME_DELAY_LENGTH 60

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

    vector<string> arguments;

private:

    ofVideoGrabber webcam;
    ofTexture current_frame;
    
    ofShader anaglyph;

    int out_w, out_h;
    
    int write_head = 0;
    int opt_delay_amount;
    ofTexture delay[MAX_FRAME_DELAY_LENGTH];
};

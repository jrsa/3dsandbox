#include "ofApp.h"

void ofApp::setup()
{
    vector<ofVideoDevice> devices = webcam.listDevices();

    for (auto i = devices.begin(); i != devices.end(); ++i) {
        cout << i->id << ": " << i->deviceName;

        if (i->bAvailable) {
            cout << " - available" << endl;
        }
        else {
            cout << " - not available" << endl;
        }
    }

    int w = 640;
    int h = 480;
    int cam = 0; // if there is more than one camera, choose here (the id is printed)
    write_head = 0;

    webcam.setDeviceID(cam);
    webcam.setDesiredFrameRate(30);
    webcam.initGrabber(w, h);

    anaglyph.load("generic.vert", "anaglyph.frag");
    
    ofSetWindowShape(w, h);
    ofSetVerticalSync(true);
}

void ofApp::update()
{
    webcam.update();
    if (webcam.isFrameNew()) {
        write_head = (write_head + 1) % FRAME_DELAY_LENGTH;
        current_frame.loadData(webcam.getPixels());
        delay[write_head].loadData(webcam.getPixels());
    }
}

void ofApp::draw()
{
    int read_head = write_head - 10;

    if (read_head < 0) {
        read_head += FRAME_DELAY_LENGTH;
    }

    anaglyph.begin();
    anaglyph.setUniformTexture("tex1", delay[read_head], 1);
    current_frame.draw(0, 0);
    anaglyph.end();
}

void ofApp::keyPressed(int key)
{
}

void ofApp::keyReleased(int key)
{
    switch (key) {
        case 'r': {
            anaglyph.load("generic.vert", "anaglyph.frag");
            break;
        }
        default:
            break;
    }
}

void ofApp::mouseMoved(int x, int y)
{
}

void ofApp::mouseDragged(int x, int y, int button)
{
}

void ofApp::mousePressed(int x, int y, int button)
{
}

void ofApp::mouseReleased(int x, int y, int button)
{
}

void ofApp::mouseEntered(int x, int y)
{
}

void ofApp::mouseExited(int x, int y)
{
}

void ofApp::windowResized(int w, int h)
{
}

void ofApp::gotMessage(ofMessage msg)
{
}

void ofApp::dragEvent(ofDragInfo dragInfo)
{
}

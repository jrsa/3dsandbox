#include "ofApp.h"

void ofApp::setup()
{
    int serial_port = std::atoi(arguments[5].c_str());
    ser.listDevices();
    ser.setup(serial_port, 9600);

    flip = !!std::atoi(arguments[6].c_str());

    webcam.listDevices();
    
    int cam_w = std::atoi(arguments[2].c_str());
    int cam_h = std::atoi(arguments[3].c_str());
    out_w = cam_w;
    out_h = cam_h;
    
    int opt_cam_device = std::atoi(arguments[1].c_str());
    opt_delay_amount = std::atoi(arguments[4].c_str());

    webcam.setDeviceID(opt_cam_device);
    webcam.initGrabber(cam_w, cam_h);

    anaglyph.load("generic.vert", "anaglyph.frag");
    
    ofSetWindowShape(cam_w, cam_h);
    ofSetVerticalSync(true);

    cout << "waiting for camera (and first delay iteration)." << endl; 
}

void ofApp::update()
{
    webcam.update();
    if (webcam.isFrameNew()) {
        write_head = (write_head + 1) % MAX_FRAME_DELAY_LENGTH;
        current_frame.loadData(webcam.getPixels());
        delay[write_head].loadData(webcam.getPixels());
    }

    if(ser.available()) {
        serial_isright = ser.readByte();
        cout << (serial_isright ? "right" : "left") << endl;
    }
}

void ofApp::draw()
{
    int read_head = write_head - opt_delay_amount;

    if (read_head < 0) {
        read_head += MAX_FRAME_DELAY_LENGTH;
    }

    if (current_frame.isAllocated() && delay[read_head].isAllocated()){
        anaglyph.begin();
        anaglyph.setUniformTexture("tex1", delay[read_head], 1);
        anaglyph.setUniform1i("right", flip ? !serial_isright : serial_isright);
        current_frame.draw(0, 0, out_w, out_h);
        anaglyph.end();
    } else {
        ofClear(0.0, 0.0, 0.0, 1.0);
        cout << ".";
        cout.flush();
    }
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
    out_w = w;
    out_h = h;
}

void ofApp::gotMessage(ofMessage msg)
{
}

void ofApp::dragEvent(ofDragInfo dragInfo)
{
}

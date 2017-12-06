#include "ofMain.h"
#include "ofApp.h"

#define GL_MAJOR 3
#define GL_MINOR 3


int main(int argc, char* argv[]) {

    if(argc < 5) {
        cout << "usage: " << argv[0] << " <device> <width> <height> <delay>" << endl;
        exit(-1);
    }

    ofGLWindowSettings settings;
    settings.setGLVersion(GL_MAJOR, GL_MINOR);
    ofCreateWindow(settings);

    ofApp *app = new ofApp();
    app->arguments = vector<string>(argv, argv + argc);
    ofRunApp(app);
}

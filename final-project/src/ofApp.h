#pragma once

#include "ofMain.h"
#include "ofxMidi.h"

class ofApp :

public ofBaseApp,
public ofxMidiListener {
    const static int kMaxNotes = 1000;
    
    struct Note {
        ofPoint pos;
        int time_counter = 0;
        int pitch;
        int velocity;
    };
    
    Note notes[kMaxNotes]; //declare constant
    int background_color;
    ofxMidiIn midi_in;
    bool showing_instructions;

    public:
    
        void setup();
        void update();
        void draw();

        void keyPressed(int key);
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

        void newMidiMessage(ofxMidiMessage& event);
    
};

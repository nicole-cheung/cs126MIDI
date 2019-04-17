#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
const int kMaxNotes = 1000;

class ofApp :

public ofBaseApp,
public ofxMidiListener {
    
    struct Note {
        ofPoint pos;
        int time_counter;
        int note_num;
        int note_vel;
    };
    
    Note notes[kMaxNotes];
    int backgroundColor;
    ofxMidiIn midiIn;
    bool showingInstructions;

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

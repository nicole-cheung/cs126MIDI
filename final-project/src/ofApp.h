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
        void draw();

        void keyPressed(int key);
        void newMidiMessage(ofxMidiMessage& event);
    
};

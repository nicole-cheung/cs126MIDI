#pragma once

#include "ofxMidi.h"
#include "Note.hpp"

class ofApp :

public ofBaseApp,
public ofxMidiListener {
    const static int kMaxNotes = 1000;
    
    Note notes[kMaxNotes];
    int background_color;
    //a MIDI input that reads data from the port
    ofxMidiIn midi_in;
    bool showing_instructions;

    public:
    
        void setup();
        void draw();
        void keyPressed(int key);
        void newMidiMessage(ofxMidiMessage& event);
        void displayInstructions(int line);
    
};

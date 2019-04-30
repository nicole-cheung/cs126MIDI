//
//  Note.hpp
//  final-project
//
//  Created by Nicole Cheung on 4/30/19.
//

#ifndef Note_hpp
#define Note_hpp

#include "ofMain.h"
#include "ofxMidi.h"
#include <stdio.h>

struct Note {
    ofPoint pos;
    int time_counter = 0;
    int pitch;
    int velocity;
    
    void initializeNote(ofxMidiMessage& note);
};

#endif /* Note_hpp */

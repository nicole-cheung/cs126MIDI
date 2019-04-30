//
//  Note.hpp
//  final-project
//
//  Created by Nicole Cheung on 4/30/19.
//

#ifndef Note_hpp
#define Note_hpp

#include "ofxMidi.h"
#include "ofMain.h"
#include <stdio.h>

struct Note {
    ofPoint pos;
    int time_counter = 0;
    int pitch;
    int velocity;
    
    void initializeNote(ofxMidiMessage& note);
};

#endif /* Note_hpp */

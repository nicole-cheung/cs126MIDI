//
//  Note.cpp
//  final-project
//
//  Created by Nicole Cheung on 4/30/19.
//

#include "Note.hpp"


//Sets the timer to the top, randomizes the position in which the note graphic will appear, and sets the pitch/velocity
void Note::initializeNote(ofxMidiMessage& note) {
    this->pos.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    this->pitch = note.pitch;
    this->velocity = note.velocity;
    this->time_counter = 500;
}

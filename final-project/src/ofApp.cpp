#include "ofApp.h"

const int kMaxNotes = 1000;
//--------------------------------------------------------------
void ofApp::setup() {
    background_color = 0;
    showing_instructions = true;
    midi_in.openPort(0);
    midi_in.addListener(this);
    
    for (int i = 0; i < kMaxNotes; i++) {
        notes[i].time_counter = 0;
    }}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(0, background_color);
    
    for (int i = 0; i < kMaxNotes; i++) {
        if (notes[i].time_counter > 0) {
            
            //Sets the visual elements of the circle
            //newer notes will be more opaque to catch the eye
            int transparency = notes[i].time_counter;
            //TODO: fiddle with color value in case int converstion is ugly
            int color = notes[i].pitch;
            ofSetColor(255 - color, color, color, transparency);
            
            //draws the circle at the randomly generated position
            //TODO: fiddle with value of velocity to get smooth images
            ofDrawCircle(notes[i].pos, notes[i].velocity);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

void ofApp::newMidiMessage(ofxMidiMessage& note) {
    //if we have received a note-on message
    if (note.status == MIDI_NOTE_ON && note.velocity != 0) {
        for (int i = 0; i < kMaxNotes; i++) {
            //if found a member of noteData that is currently 'off'
            if (notes[i].time_counter == 0) {
                notes[i].time_counter = 255;
                
                //get a random point/position on the screen for the note/circle and stores note info
                notes[i].pos.set (ofRandom (ofGetWidth()), ofRandom (ofGetHeight()));
                notes[i].pitch = note.pitch;
                notes[i].velocity = note.velocity;
                
                break;
            }
        }
    } else if (note.status == MIDI_CONTROL_CHANGE && note.control == 1) {
        //Set the background colour based on the CC value
        background_color = note.value;
    }
}

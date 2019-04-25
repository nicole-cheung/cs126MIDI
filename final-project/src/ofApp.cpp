#include "ofApp.h"

const int kMaxNotes = 1000;
//--------------------------------------------------------------
void ofApp::setup() {
    ofSetVerticalSync(true);
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetFrameRate(60);
    
    background_color = 0;
    showing_instructions = true;
    
    //openPort will let the program look for the first MIDI input that the computer can recognize, openVirtualPort will let another program interact with the code as if it was a keyboard
    //midi_in.openPort(0);
    bool openVirtualPort(std::string portName="ofxMidi Virtual Input");
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
    
    if (showing_instructions) {
        //display text
        //display if there are no current inputs
        ofSetColor(255);
        
        //get and display MIDI inputs
        ofDrawBitmapString("MIDI inputs:", 10, 20);
        std::vector<string> midi_port_strings = midi_in.getInPortList();
        int last_line_pos = 44;
        for (int i = 0; i < midi_port_strings.size(); i++) {
            ofDrawBitmapString(ofToString(i) + ": " + midi_port_strings[i], 10, 44 + (10 * i));
            
            last_line_pos += (10 * i);
        }
        
        ofDrawBitmapString("Currently connected to MIDI input:", 10, last_line_pos + 40);
        
        //if we are currently connected to a MIDI input, display its name on the screen
        if (midi_in.getPort() != -1) {
            ofDrawBitmapString(midi_in.getName(), 10, last_line_pos + 50);
        //if we're not currently connected to a MIDI input, display that we're not connected to anything
        } else {
            ofDrawBitmapString("NOT CONNECTED", 10, last_line_pos + 50);
        
        ofDrawBitmapString("Press 0-9 on the keyboard to set the connected port number.", 10, last_line_pos + 100);
        ofDrawBitmapString("Press lowercase 's' on the keyboard to show/hide this text.", 10, last_line_pos + 120);
        }
    }
    
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
            
            notes[i].time_counter--;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    //toggle instructions
    //set preferred MIDI input
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
                notes[i].pos.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
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

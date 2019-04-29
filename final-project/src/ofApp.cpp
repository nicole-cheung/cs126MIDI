#include "ofApp.h"

const int kMaxNotes = 1000;

//for spacing purposes in app display. kMidiFormat is the size of a line.
const int kMidiFormat = 10;
const int kFormatTab = 4;

//MIDI logic and handling sourced from https://ask.audio/articles/create-your-own-midi-generated-realtime-visuals-with-openframeworks
void ofApp::setup() {
    ofSetVerticalSync(true);
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetFrameRate(60);
    
    background_color = 0;
    showing_instructions = true;
    
    //opens a port to listen for MIDI data (AKA USB input or a virtual bus)
    midi_in.openPort(0);
    midi_in.addListener(this);
    
    for (int i = 0; i < kMaxNotes; i++) {
        notes[i].time_counter = 0;
    }
}

void ofApp::draw() {
    ofBackgroundGradient(0, background_color);
    
    if (showing_instructions) {
        //display text as white
        ofSetColor(255);
        
        std::vector<string> midi_ports = midi_in.getInPortList();
        
        //for formatting consistency depending on size of list
        int last_line = 44;
        for (int i = 0; i < midi_ports.size(); i++) {
            last_line += (kMidiFormat * i);
        }
        
        ofDrawBitmapString("Currently connected to MIDI input:", kMidiFormat, last_line + kMidiFormat * kFormatTab);
        
        //if we are currently connected to a MIDI input, display its name on the screen
        if (midi_in.getPort() != -1) {
            ofDrawBitmapString(midi_in.getName(), kMidiFormat, last_line + kMidiFormat * kFormatTab + kMidiFormat);
        //if we're not currently connected to a MIDI input, display that we're not connected to anything
        } else {
            ofDrawBitmapString("NOT CONNECTED", kMidiFormat, last_line + kMidiFormat * kFormatTab + kMidiFormat);
        
        ofDrawBitmapString("Press the number of the port you'd wish to connect to.", kMidiFormat, last_line + kMidiFormat * kMidiFormat);
        }
        
        ofDrawBitmapString("Press lowercase 'i' on the keyboard to toggle the instructions on screen.", kMidiFormat, last_line + kMidiFormat * kMidiFormat + kMidiFormat);
    }
    
    //Displays note graphics
    for (int i = 0; i < kMaxNotes; i++) {
        if (notes[i].time_counter > 0) {
            
            //Sets the visual elements of the circle
            //newer notes will be more opaque to catch the eye
            int transparency = notes[i].time_counter;
            //TODO: fiddle with color value in case int converstion is ugly
            int color = notes[i].pitch * 2;
            ofSetColor(255 - color, color + kMidiFormat, color, transparency);
            
            //draws the circle at the randomly generated position
            //It is suggested to change this based on the "crowdedness" of the midi file
            //TODO: fiddle with value of velocity to get smooth images
            double smooth = .8;
            ofDrawCircle(notes[i].pos, notes[i].velocity * smooth);
            
            notes[i].time_counter--;
        }
    }
}

void ofApp::keyPressed(int key) {
    //toggle instructions
    if (key == 'i') {
        showing_instructions = !showing_instructions;
        
        //toggles port switch in the case of multiple inputs being sent in.
    } else if (key >= '0' && key <= '9') {
        //convert the value of the number key to the related number
        int port_num = key - 48;
        midi_in.closePort();
        midi_in.openPort(port_num);
    }
}

//Runs every time a new note is played
void ofApp::newMidiMessage(ofxMidiMessage& note) {
    //if we have received a note-on message
    if (note.status == MIDI_NOTE_ON && note.velocity != 0) {
        for (int i = 0; i < kMaxNotes; i++) {
            //if found a note that is currently 'off'
            if (notes[i].time_counter == 0) {
                notes[i].time_counter = 500;
                
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

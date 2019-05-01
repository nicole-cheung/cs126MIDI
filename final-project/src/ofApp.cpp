#include "ofApp.h"

const int kMaxNotes = 1000;

//for spacing purposes in app display. kMidiFormat is the size of a line.
const int kMidiFormat = 10;
const int kFormatTab = 4;

const int kWhite = 255;
const int kKeyConversion = 48;
const int kFps = 60;

//MIDI logic and handling sourced from https://ask.audio/articles/create-your-own-midi-generated-realtime-visuals-with-openframeworks
void ofApp::setup() {
    ofSetVerticalSync(true);
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetFrameRate(kFps);
    
    background_color = 0;
    showing_instructions = true;
    ofSetCircleResolution(50);
    
    //opens a port to listen for MIDI data (AKA USB input or a virtual bus)
    midi_in.openPort(0);
    midi_in.addListener(this);
    
    //TODO: if needed, this is where to initialize an output.
    for (int i = 0; i < kMaxNotes; i++) {
        notes[i].time_counter = 0;
    }
}

void ofApp::draw() {
    ofBackgroundGradient(0, background_color);
    if (showing_instructions) {
        //display text as white
        ofSetColor(kWhite);
        std::vector<string> midi_ports = midi_in.getInPortList();
        
        //for formatting consistency depending on size of list
        int last_line = kMidiFormat * kFormatTab + kFormatTab;
        for (int i = 0; i < midi_ports.size(); i++) {
            last_line += (kMidiFormat * i);
        }
        
        ofApp::displayInstructions(last_line);
    }
    
    //Displays note graphics
    for (int i = 0; i < kMaxNotes; i++) {
        if (notes[i].time_counter > 0) {
            //Sets the visual elements of the circle
            //newer notes will be more opaque to catch the eye
            int transparency = notes[i].time_counter;
            
            //TODO: fiddle with color value in case int converstion is ugly
            //right now the color scheme is mostly blue and purple
            int color = notes[i].pitch * 2;
            ofSetColor(kWhite - color, color + kMidiFormat * kMidiFormat,
                       color * kFormatTab, transparency);
        
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
        int port_num = key - kKeyConversion;
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
                notes[i].initializeNote(note);
                break;
            }
        }
    }
    //This means the MIDI message is not a note but a CC message (mod wheel)
    //Real life examples include footswitch, expression pedal, slider, or other controller that isn't a music note
    if (note.status == MIDI_CONTROL_CHANGE && note.control == 1) {
        background_color = note.value;
    }
    midi_out.sendNoteOn(1, note.pitch,  note.velocity);
}

void ofApp::displayInstructions(int line) {
    ofDrawBitmapString("Currently connected to MIDI input:", kMidiFormat, line + kMidiFormat * kFormatTab);
    
    //if we are currently connected to a MIDI input, display its name on the screen
    if (midi_in.getPort() != -1) {
        ofDrawBitmapString(midi_in.getName(), kMidiFormat, line + kMidiFormat * kFormatTab + kMidiFormat);
        //if we're not currently connected to a MIDI input, display that we're not connected to anything
    } else {
        ofDrawBitmapString("NOT CONNECTED", kMidiFormat, line + kMidiFormat * kFormatTab + kMidiFormat);
        
        ofDrawBitmapString("Press the number of the port you'd wish to connect to.", kMidiFormat, line + kMidiFormat * kMidiFormat);
    }
    
    ofDrawBitmapString("Press lowercase 'i' on the keyboard to toggle the instructions on screen.", kMidiFormat, line + kMidiFormat * kMidiFormat + kMidiFormat);
}

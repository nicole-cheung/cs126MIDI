# Development
### Week 0
* Generated oF project
* ofxMidi provides examples for testing - tested outputs and inputs
* Output explore - get an idea for what types of data are stored in each MIDI note
* Input explore - going to try to treat this like istream to load MIDI files

### Week 1
* Created note structure to store MIDI data 
* Started initial creation of data/methods needed to store graphics info
* Fiddled with setup() to get initial app going
* Wrote new message function to receive new note inputs - here, I decided to begin with a non-significant but still visually responsive circular display 
* ofGraphics has some useful methods to set color and transparency of the shapes
* Development is very slow at this point because it takes so much time to search through all the available libraries. Next week I will probably give extra time to going through the oF forum instead of just searching the libraries. I will also have to figure out how to toggle between the circular display and a future line display
* ofxMidi only takes in raw MIDI data - aka either the keyboard keys or piano. I will have to mess with Garageband and opening virtual ports in ofxMidiIn to feed in an existing MIDI file. (http://fox-gieg.com/tutorials/2007/inter-application-midi/) OR (https://forum.openframeworks.cc/t/importing-midi-file-to-be-used-as-visual-or-math-information/7381)

### Week 2
* Went hunting for a program that lets me pass MIDI data through two different applications. Found possible solution: MIDI patchbay http://notahat.com/midi_patchbay/
* Another solution is Audio MIDI Setup, but is only on Mac
* Creating a display for instructions is kind of nitpicky work with lots of pixel numbers that I'm not sure whether I can just keep as magic numbers or not. Very little consistency as I am still playing with design choices.
* ofDrawBitmapString creates easily readable instructions
* Set up key press function to toggle out of instructions
* Having trouble working with GarageBand as a MIDI output, but the program does currently recognize that an input from Audio Midi Setup exists
* Added ofxThreadedMidiPlayer to read in MIDI files 

### Week 3
* Garageband does NOT support MIDI output. Pocket MIDI is an option but currently I can't get it to work.
* Downloaded iPhone app that can manually send in MIDI messages. To read in files, a combo of Audio MIDI setup and MIDI Player X
* Messed with pitch and velocity number to see how it affects display
* Working on exporting video this week. Using Homebrew and FFmpeg to take many screencaptures and turn it into a video
* Found new library ofxSimpleScreenRecorder https://github.com/avseoul/ofxSimpleScreenRecorder/ 
* I considered adding audio output to the app. After consideration, I realized that most MIDI machines create their own audio and if the program did as well, it would be distracting/annoying to work with.
* The linear path graphic is pretty useless - it already exists in Garageband or most other MIDI players.
* Found problem with md files not committing WAY TOO LATE how do i fix this

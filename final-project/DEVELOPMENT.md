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

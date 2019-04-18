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
* ofxMidi only takes in raw MIDI data - aka either the keyboard keys or piano. I will have to mess with Garageband and opening virtual ports in ofxMidiIn to feed in an existing MIDI file.

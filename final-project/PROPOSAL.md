# Project Proposal
### Summary
MIDI files are typically used by music students to self-teach songs on the piano. Additionally, it is an easy way to visualize music in regards to pitch and note length for a multitude of different reasons both educationally, recreationally, and as assistive technology for those who are hard-of-hearing/deaf. I want to create an app that takes MIDI files and creates graphically interesting displays that respond to note changes in the music. This can either be musically significant or just visually interesting.

### openFrameworks
* ofxMidi found here: https://github.com/danomatika/ofxMidi || Purpose: analyze and import MIDI files - particularly, ofxMidiClock can analyze tempo and ofxMidiMessage analyzes pitch
* ofPath || If I decide to create graphics that react to pitch, ofPath can draw lines/shapes that react to higher pitches. This would be particularly usefull for music theory to study melodic lines.
* ofImage || I might want the user to be able to save a final picture of the graphic created, depending on whether I want to make it a cumulitive image or just a visual experience.

### Background
Most of my knowledge about music theory is at a basic level, but it is sufficient enough to see relationships between pitch from a mathematical standpoint. I've also done minimal work with MIDI files from a user standpoint and have attempted to write MIDI files before, so I'm very familiar with the format.

### Possible further functionality
It might be worthwile to see if I can create a video from the MIDI file and produced graphics to be able to rewatch if desired.

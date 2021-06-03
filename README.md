# ArWave 🔊

Play melodies on Arduino with a PC speaker.

# Requirements

1. VS Code with the PlatformIO extension installed.
2. Arduino board (tested on Arduino Leonardo).
3. PC speaker or any piezoelectric buzzer.

# Build instructions

1. Connect a PC speaker to GND and 12 pins of your Arduino.
2. Connect your Arduino to a PC with a USB cable.
3. Open the workspace in VS Code.
3. Compose your own melody (see below) and put it inside `src/melody.h` file.
4. Build and upload a firmware using the PlaformIO project tasks.

# How to compose your own melodies

Melody is loaded from the `src/melody.h` header file. It contains the following lines:

* `#define BPM       {bpm}` - defines BPM of your melody.
* `#define LENGTH    {length}` - defines amount of notes in your melody.
* `#define NOTES     {notes}` - defines notes that are used in your melody. See `src/pitches.h` for the reference.
* `#define DURATIONS {durations}` - defines durations of corresponding notes. Use `1` for a whole note, `2` for a half note, `4` for a quarter note and so forth.

You can use examples from the `examples` directory to test a program.

Composing a melody from scratch may be a bit confusing, so it's recommended to use the [ArWave Converter](https://github.com/torunar/arwave-converter) utility to convert single-track MIDI file to the melody header file.

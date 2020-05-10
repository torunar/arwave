#include <Arduino.h>
#include <avr/pgmspace.h>
#include "pitches.h"
#include "melody.h"
 
#define SPEAKER_PIN 12
#define TONE_DELAY 5

unsigned long getDuration(uint8_t bpm, uint8_t noteDuration) {
  return 60000.0 / (float) bpm / ((float) noteDuration / 4.0);
}

void play(uint16_t note, unsigned long duration) {
  if (note == N_REST) {
      delay(duration + TONE_DELAY);
      return;
  }
  
  tone(SPEAKER_PIN, note, duration);
  delay(duration + TONE_DELAY);
  noTone(SPEAKER_PIN);
}

const PROGMEM uint16_t notes[] = NOTES;
const PROGMEM byte durations[] = DURATIONS;

void setup() {
  pinMode(SPEAKER_PIN, OUTPUT);
  
  for (unsigned int i = 0; i < LENGTH; i++) {
    uint16_t note = pgm_read_word(&notes[i]);
    byte noteDuration = pgm_read_byte(&durations[i]);
    unsigned long duration = getDuration(BPM, noteDuration);
    play(note, duration);
  }
}

void loop() {
}
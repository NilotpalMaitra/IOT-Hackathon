#include <arduinoFFT.h>  // Ensure this is included at the top

#define NUM_TAPS 10 // Number of filter coefficients
#define BUFFER_SIZE 100 // Buffer to store input samples

float filterTaps[NUM_TAPS] = {0.1, 0.15, 0.2, 0.3, 0.2, 0.1, 0, -0.1, -0.15, -0.1};

float inputBuffer[BUFFER_SIZE] = {0};
int bufferIndex = 0;

void setup() {
  Serial.begin(115200);
}
void loop()
{
    float inputSignal  = analogRead(A0); // Read input signal from ADC

    inputBuffer[bufferIndex] = inputSignal; // Store input signal in buffer

    float filteredOutput = 0;

    for (int i = 0; i < NUM_TAPS; i++) {
    int index = (bufferIndex - i + BUFFER_SIZE) % BUFFER_SIZE;
    filteredOutput += inputBuffer[index] * filterTaps[i];
  }

  // Update buffer index
  bufferIndex = (bufferIndex + 1) % BUFFER_SIZE;

  // Output the filtered signal (replace with actual output)
  Serial.println(filteredOutput);

  delay(100); // Adjust as needed
}
// Compare this snippet from Embedded%20Development%20Hackathon/src/Bandpassfilter/FIR_filter.cpp:

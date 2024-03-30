volatile uint16_t overflows = 0;

void pressButton() {
    // if we press the button we should anticipate toggling the LED state
    // How to proceed here? 
    // 1. Toggle the LED state
    digitalWrite(13, !digitalRead(13));
    // 2. Clear all overflow counters
    overflows = 0;
    // 3. Clear Timer2 counter
    TCNT2 = 0;
    // 4. Release the button
}

// This function will be called every time TIMER2 overflows
// and it is binded to Timer2 Overflow Interrupt Service Routine
ISR(TIMER2_OVF_vect) {
    overflows ++;
    if (overflows == 306) {
        overflows = 0;
        // Toggle the LED state
        digitalWrite(13, !digitalRead(13));
    }
}

void setup() {
    // Set pin 13 as output
    pinMode(13, OUTPUT);
    // Set pin 2 as input
    pinMode(2, INPUT);

    // Attach interrupt to pin 2 through specifc function
    // attachInterrupt that can only be used with Arduino
    // pins that are interrupt capable (2 and 3 on the Uno)
    attachInterrupt(
        digitalPinToInterrupt(2), pressButton, RISING
    );

    // Set TIMER2 to normal mode
    // Arduino UNO has two controller registers for TIMER2: TCCR2A and TCCR2B
    TCCR2A = 0b00000000; // normal operation mode
    TCCR2B = 0b00000111; // enabling 1024 prescaler
    // Enable TIMER2 overflow interrupt. When we enable it it will be
    // binded to a ISR function that we need to implement in our code
    // As Timer2 can only count to 255 we need to count the times it overflows
    // So we will build it in our ISR function
    TIMSK2 = TIMSK2 | 0b00000001;

    // At the end we need to enable global interrupts
    sei();
    
}

void loop() {
    
}

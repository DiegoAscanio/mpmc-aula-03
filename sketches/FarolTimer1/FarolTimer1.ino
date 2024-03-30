
// 5. Registering a TIMER1_COMPA_vect ISR to toggle the LED
ISR(TIMER1_COMPA_vect) {
    // Toggle the LED
    digitalWrite(13, !digitalRead(13));
}

// 6.1 function to Toggle the LED and clear TCNT1
void toggleFarol() {
    // Toggle the Farol's state
    digitalWrite(13, !digitalRead(13));
    // Reset Timer1 counter
    TCNT1 = 0;
}

void setup() {
    // 1. Enabling CTC Mode
    TCCR1A = 0b00000000;
    TCCR1B = 0b00001000;

    // 2. Setting compare value OCR1A to 62500
    OCR1A = 62500;

    // 3. Selecting 1024 Prescaler
    TCCR1B = TCCR1B | 0b00000101;

    // 4. Enabling Output Compare A Match Interrupt
    TIMSK1 = TIMSK1 | 0b00000010;

    // 6.2
    // Set pin 13 as output
    pinMode(13, OUTPUT);
    // Set pin 2 as input
    pinMode(2, INPUT);
    // Attach the toggleFarol function to the interrupt
    attachInterrupt(
        digitalPinToInterrupt(2), toggleFarol, RISING
    );

    // 6.3
    // At the end we need to enable global interrupts
    sei();
    
}

void loop() {
    
}

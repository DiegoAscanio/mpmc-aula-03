
volatile bool isPressed = false;

void pressButton() {
    isPressed = true;
}

void releaseButton() {
    isPressed = false;
}

// This function will be called every time TIMER2 overflows
// and it is binded to Timer2 Overflow Interrupt Service Routine
ISR(TIMER2_OVF_vect) {
    // as Arduino integers are only 16 bits but we will need to
    // count the overflows until 312500 to get 5 seconds, so
    // we will use two variables for that and control them as
    // we need
    static uint16_t overflows_from_0_to_62500 = 0;
    static uint16_t overflows_from_0_to_62500_quantity = 0;
    overflows_from_0_to_62500_quantity ++;

    if (overflows_from_0_to_62500 >= 62500) { // 62500 overflows are 1 second
        overflows_from_0_to_62500 = 0;
        overflows_from_0_to_62500_quantity++;
    }
    else if (overflows_from_0_to_62500_quantity >= 5) { // 5 seconds
        overflows_from_0_to_62500 = 0;
        overflows_from_0_to_62500_quantity = 0;
        // toggle LED State
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
    TCCR2A = 0;
    // Enable TIMER2 overflow interrupt (not studied yet, but we need to enable
    // it in order to see `FOC0` bit behavior). When we enable it it will be
    // binded to a ISR function that we need to implement in our code
    // As Timer0 can only count to 255 we need to count the times it overflows
    // So we will build it in our ISR function
    TIMSK2 = TIMSK2 | 0b00000001;
    
}

void loop() {
    // we'll handle the button press outside the ISR in order to
    // avoid blocking the ISR
    if (isPressed) {
        // if we press the button we should anticipate toggling the LED state
        // How to proceed here? Setting FOC0 bit to 1 312500 times to get ahead
        // the 5 seconds in 19 ms.
        // Again, our integers are limited to 16 bits precision, therefore
        // we'll use to for loops to force the overflows:
        for (uint16_t j = 0; j < 5; j++) {
            for (uint16_t i = 0; i < 62500; i++) {
                // set FOC0 bit to 1
                TCCR2A = TCCR2A | 0b00000001;
            }
        }
    }
}

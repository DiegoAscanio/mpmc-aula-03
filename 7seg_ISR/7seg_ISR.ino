int matriz_7seg[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9 
};

volatile int count = 0;

void display(int num) {
    int i = 0, pin = 7; // we start at pin 7
    while (i < 7) {
        digitalWrite(pin, matriz_7seg[num][i]);
        i++;
        pin++;
    }
}

void increment() {
    count++;
    if (count > 9) {
        count = 0;
    }
}

void decrement() {
    count--;
    if (count < 0) {
        count = 9;
    }
}

void setup() {
    int i = 7; // we start at pin 7
    while (i < 14) {
        pinMode(i, OUTPUT);
        i++;
    }
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    attachInterrupt(
        digitalPinToInterrupt(2), increment, RISING
    );
    attachInterrupt(
        digitalPinToInterrupt(3), decrement, RISING
    );
}

void loop() {
    display(count);
}

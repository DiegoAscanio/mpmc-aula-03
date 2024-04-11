## Interrupções — Interrupções Externas

<style scoped>
#codigo-container {
  display: flex;
  justify-content: center;
  align-items: center;
  height: 80vh;
  text-align: left; /* Para garantir alinhamento do texto à esquerda */
}

#codigo-container pre,
#codigo-container code {
  width: 100%; /* Ocupa a largura total da `div` */
  max-width: 650px; /* Um valor máximo de largura pode ser útil */
  font-size: 16px; /* Ou qualquer tamanho que prefira */
  padding: 20px; /* Ajuste conforme necessário */
  box-sizing: border-box; /* Inclui o padding no cálculo da largura */
}
</style>

<div class="flex-container footnotesize">
<div class="column-container" markdown="1">

Como dito anteriormente, as interrupções externas do Arduino são associadas apenas aos pinos 2 e 3.

- Geradas por eventos externos ao microcontrolador, como pressionar um botão ou um sinal de um sensor.

O Arduino fornece uma função específica para configurar as interrupções externas, a `attachInterrupt()` cuja sintaxe é a seguinte:

`attachInterrupt(digitalPinToInterrupt(pin), ISR, mode);`

- `pin`: pino associado à interrupção.
- `digitalPinToInterrupt(pin)`: função que converte um número de pino digital específico em um número de interrupção correspondente.
- `ISR`: função que será executada quando a interrupção for acionada.
- `mode`: modo de acionamento da interrupção que pode ser:
    - `LOW`: acionada quando o pino está em nível baixo.
    - `CHANGE`: acionada quando o pino muda de nível.
    - `RISING`: acionada quando o pino muda de nível baixo (LOW) para alto (HIGH).
    - `FALLING`: acionada quando o pino muda de nível alto (HIGH) para baixo (LOW).

Ao lado temos um exemplo de código que utiliza a função `attachInterrupt()` para acionar uma interrupção externa.

</div>
<div class="column-container" markdown="1">
<div id="codigo-container" markdown="1">

```c

const int ledPin = 13;
const int interruptPin = 2; // only pin 2 and 3 can be used for interrupts

volatile int state = LOW;

void blink() { // ISR function
    state = !state; // toggle the state
}

void setup() {
    pinMode(ledPin, OUTPUT);
    attachInterrupt(
        digitalPinToInterrupt(interruptPin),
        blink,
        RISING
    );
}

void loop() {
    digitalWrite(ledPin, state);
}

```

</div>
</div>
</div>

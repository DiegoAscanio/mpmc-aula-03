<style scoped>
    ul, ol {
        font-size: 16px;
    }
    h2 {
        font-size: 28px;
    }
    h3 {
        font-size: 24px;
    }
    p {
        font-size: 18px;
    }
</style>

## *Timers* e Contadores no Arduino

Normalmente *timers* (contadores) são usados para gerar:

- Intervalos (atrasos) de tempo;
- Formas de onda;
- Contagem de eventos;
- Controle de pulsos de saída;
- Sinais de PWM (Pulse Width Modulation);
- Captura de eventos;
- Dentre outras aplicações.

Nos microcontroladores ATMega16 / ATMega32 (usados no Arduino UNO e Nano) existem três *timers*:

1. `Timer0`: Timer de 8 bits, capaz de contar de 0 a 255;
2. `Timer1`: Timer de 16 bits, capaz de contar de 0 a 65535;
3. `Timer2`: Timer de 8 bits, capaz de contar de 0 a 255.

Na aula de hoje vamos focar no uso de *timers* no Arduino para a contagem de tempo.

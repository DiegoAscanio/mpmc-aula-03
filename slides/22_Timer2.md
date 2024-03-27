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

## _Timers_ e Contadores no Arduino — Timer 2

Como não é possível usar o `Timer0` pelo Arduino IDE, o `Timer2` será utilizado para explicar o funcionamento dos timers de 8 bits.

O `Timer2` é um contador de 8 bits que suporta nativamente geração de PWM, bem como, operações assíncronas. Ele apresenta em sua composição:

<div class="flex-container" markdown="1">
<div class="column-container" markdown="1">

- Contador *single channel* de 8 bits;
- Limpeza automática do timer ao atingir o valor de comparação (*auto reload*);
- Modulador de largura de pulsos (PWM) livre de *glitches* e com fases estáveis;
- Gerador de Frequências;

</div>
<div class="column-container" markdown="1">

- *Prescaler* (divisor de frequeência de clock) de 10 bits — 1 a 1024;
- Fontes de interrupção de *overflow* e de comparação (`TOV2`, `OCF2A` e `OCF2B`);
- Capacidade de interligação a gerador de *clock* externo de 32kHZ (baseado em cristal de quartzo), que permite ao *timer* ficar independente do *clock* de E/S do microcontrolador.

</div>
</div>

Um diagrama simplificado do `Timer2` para fins didáticos é apresentado no próximo *slide* pela Figura 6.

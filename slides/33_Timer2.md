<style scoped>
    ul, ol {
        font-size: 12px;
    }
    h2 {
        font-size: 21px;
    }
    h3 {
        font-size: 18px;
    }
    h4 {
        font-size: 15px;
    }
    h5 {
        font-size: 13px;
    }
    p {
        font-size: 13px;
    }
    .codigo-container {
        display: flex;
        justify-content: center;
        text-align: left; /* Para garantir alinhamento do texto à esquerda */
    }
    .codigo-container pre,
    .codigo-container code {
        width: 100%; /* Ocupa a largura total da `div` */
        max-width: 650px; /* Um valor máximo de largura pode ser útil */
        font-size: 12px; /* Ou qualquer tamanho que prefira */
        padding: 20px; /* Ajuste conforme necessário */
        box-sizing: border-box; /* Inclui o padding no cálculo da largura */
    }

    
</style>

## _Timers_ e Contadores no Arduino — Timer 2

Na implementação que acabou de ser realizada existiu um problema para a contagem de _overflows_ necessários, pois, a quantidade de _overflows_ para comutar o estado do farol de 5 em 5 segundos — 312500 — excedeu a precisão de um `uint16_t`. Por isso, foram utilizadas duas variáveis `uint16_t` para armazenar a quantidade de _overflows_ necessários, o que deixou a lógica da rotina de interrupção de _overflow_ mais complexa.

É possível diminuir esta quantidade de _overflows_ para que ela caiba em um `uint16_t`? Se o _prescaler_ do `Timer2` for utilizado para diminuir a frequência de contagem (e consequentemente, a quantidade de _overflows_) assim é possível armazenar a quantidade de _overflows_ em um `uint16_t`.

Para fazer isso deve-se mudar a lógica da rotina associada ao ISR `TIMER2_OVF_vect` e o modo de operação do `Timer2` no registrador `TCCR2B`. No modo de operação do `Timer2` será escolhido um _prescaler_ para dividir o _clock_ de entrada por 1024 — `CS22 = 1`, `CS21 = 1`, `CS20 = 1` (Ver [Tabela 2](#Tabela-2)) — o que diminuirá a frequência de contagem do `Timer2` para 16MHz/1024 = 15625Hz. Com isso, a quantidade de _overflows_ necessários para comutar o estado do farol de 5 em 5 segundos será de 306, que cabe em um `uint16_t`!

<div class="flex-container">
<div class="column-container" markdown="1">

#### Mudança da Rotina do ISR

<div class="codigo-container" markdown="1">

```c

// Devemos deletar as variáveis globais voláteis
// anteriores e criar apenas uma para armazenar
// a quantidade de overflows necessários
volatile uint16_t overflows = 0;

// Depois, devemos mudar a lógica da rotina para contar
// até 306 overflows
ISR(TIMER2_OVF_vect) {
    overflows++;
    if (overflows == 306) {
        overflows = 0;
        // Inverte o estado do farol
        digitalWrite(13, !digitalRead(13));
    }
}

```

</div>
</div>
<div class="column-container" markdown="1">

#### Mudança no Modo de Operação do Timer2

##### Mudanças no Registrador TCCR2B na função `setup()`

<div class="codigo-container" markdown="1">

```c

    // ...
    TCCR2B = 0b00000111; // Prescaler 1024
    // ...

```

</div>

##### Mudanças na função `loop()`

<div class="codigo-container" markdown="1">

```c

    // ...
        // 2. Clear all overflow counters
        overflows = 0;
    // ...

```

</div>
</div>

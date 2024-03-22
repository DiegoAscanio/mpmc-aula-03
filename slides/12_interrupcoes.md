<style scoped>
    ul, ol {
        font-size: 18px;
    }
    h2 {
        font-size: 28px;
    }
    p {
        font-size: 20px;
    }
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
        font-size: 14px; /* Ou qualquer tamanho que prefira */
        padding: 20px; /* Ajuste conforme necessário */
        box-sizing: border-box; /* Inclui o padding no cálculo da largura */
    }
</style>

## Interrupções no Arduino — Interupções para (Inc/Dec)rementar um contador cujo resultado é mostrado em um display de 7 segmentos

<div class="flex-container">
<div class="column-container" markdown="1">

**Como fazer? (parte lógica de setup e loop)**

6. Defina os pinos 7 a 13 do Arduino (seg. A a G do display) como saída;
7. Defina os pinos 2 e 3 do Arduino como entradas;
8. Associe as ISR de incremento e decremento aos pinos 2 e 3, respectivamente;
9. No loop, exiba o valor do contador no display de 7 segmentos.

</div>
<div class="column-container" markdown="1">
<div id="codigo-container" markdown="1">

```c

void setup() {
    // 6. Definindo os pinos do arduino como saída
    // para o display de 7 segmentos
    int i = 7; // we start at pin 7
    while (i < 14) {
        pinMode(i, OUTPUT);
        i++;
    }
    // 7. Definindo os pinos 2 e 3 do arduino como entradas
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    // 8. Associando as ISR de incremento e decremento 
    // aos pinos 2 e 3
    attachInterrupt(
        digitalPinToInterrupt(2), increment, RISING
    );
    attachInterrupt(
        digitalPinToInterrupt(3), decrement, RISING
    );
}

void loop() {
    // 9. Exibindo o valor do contador no display de 7 segmentos
    display(count);
}

```

</div>
</div>
</div>

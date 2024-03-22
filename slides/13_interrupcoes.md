<style scoped>
    ul, ol {
        font-size: 16px;
    }
    figcaption {
        font-size: 12px;
        text-align: center;
    }
    h2 {
        font-size: 28px;
    }
    p {
        font-size: 18px;
    }
</style>

## Interrupções no Arduino — Interupções para (Inc/Dec)rementar um contador cujo resultado é mostrado em um display de 7 segmentos

<div class="flex-container">
<div class="column-container" markdown="1">

**Como fazer? (parte física)**

De acordo com a Figura 3:

1. Conecte a alimentação do circuito `VCC` ao pino `2.l` dos *push-buttons*;
2. Conecte o pino `1.l` dos *push-buttons* a um resistor de \\(10k\Omega\\) e, em seguida, ao `GND`;
3. Conecte o pino `1.r` do *push-button* da esquerda ao pino `3` do Arduino;
4. Conecte o pino `1.r` do *push-button* da direita ao pino `2` do Arduino;

</div>
<div class="column-container" markdown="1">
<figure markdown="1">

<!-- _class: transparent -->
![centered-img](./img/23incdec.png)

<figcaption markdown="1">Figura 3 — Conexões físicas dos <em>push-buttons</em> ao Arduino.</figcaption>   
</figure>
</div>
</div>

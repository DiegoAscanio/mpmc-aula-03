<style scoped>
    ul {
        font-size: 16px;
    }
    figcaption {
        font-size: 14px;
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

**Recapitulando:**

- Um display de 7 segmentos é um dispositivo que mostra — principalmente — números de 0 a 9. 
- Recebe este nome porque é composto por 7 LEDs (díodos emissores de luz A, B, C, D, E, F, G) que podem ser acesos ou apagados para formar os números.
- As sequências de leds do display que devem ser acesos para formar os números de zero a nove são mostradas na Figura 1.
- Um típico display de sete segmentos apresenta a seguinte sequência de pinos: A, B, C, D, E, F, G, DP (ponto decimal) e um pino comum (comum cátodo ou comum ânodo) em sua embalagem, como mostrado pela Figura 2.

<div class="flex-container">
<div class="column-container">
<figure markdown="1" id="figura-1">

<!-- _class: transparent -->
![centered-img](./img/7segdisplay-sequence.png)

<figcaption>Figura 1 — Sequências de LEDs acesos para formar os números de 0 a 9</figcaption>
</figure>
</div>
<div class="column-container">
<figure markdown="1">

<!-- _class: transparent -->
![centered-img](./img/7segdisplay.png)

<figcaption>Figura 2 — Pinagem de um típico display de 7-segmentos</figcaption>
</figure>
</div>
</div>

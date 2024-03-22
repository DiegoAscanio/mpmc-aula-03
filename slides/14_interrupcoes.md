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

De acordo com a Figura 4:
1. Para cada pino do arduino, começando do 7 e terminando no 13:
    - Conecte o pino a seu respectivo segmento no *display* 7-seg passando por um resistor protetivo de \\(390\Omega\\).
        - Ou seja: pino 7 do arduino passando por um resistor de \\(390\Omega\\) ao segmento 'a' do *display* 7-seg, pino 8 passando por outro resistor de \\(390\Omega\\) ao segmento 'b' e assim por diante.


</div>
<div class="column-container" markdown="1">
<figure markdown="1">

<!-- _class: transparent -->
![centered-img](./img/7segonduino.png)

<figcaption markdown="1">Figura 4 — Conexões físicas dos pinos do Arduino aos seus respectivos segmentos no <em>display</em> 7-seg</figcaption>   
</figure>
</div>
</div>

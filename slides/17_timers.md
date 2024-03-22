<style scoped>
    ul, ol {
        font-size: 14px;
    }
    figcaption {
        font-size: 12px;
        text-align: center;
    }
    h2 {
        font-size: 26px;
    }
    h3 {
        font-size: 22px;
    }
    p {
        font-size: 16px;
    }
</style>

## *Timers* e Contadores

<div class="flex-container" markdown="1">
<div class="column-container" markdown="1">

Até o momento foram vistas as funções `delay()` e `millis()`, que são úteis para controlar o tempo de execução de um programa no Arduino. No entanto, essas funções são limitadas, pois o `delay()` bloqueia a execução do programa e o `millis()` não é capaz de contar o tempo de forma precisa.

Imagine que você deve controlar a vazão dos vertedouros da barragem da usina de Itaipu Binacional, mostrada pela Figura 5. Este é um sistema de missão crítica, pois, qualquer erro pode colocar em risco vidas humanas e negócios. Se a vazão é definida pelas leituras periódicas dos sensores de nível de água, você não pode se dar ao luxo de perder uma leitura. 

O uso de `delay()` não é uma opção, pois o programa ficaria bloqueado por um tempo que não pode ser determinado com precisão. O uso de `millis()` também não é uma opção, pois sua contagem de forma imprecisa pode levar a perda de leituras.

Desta forma, é necessário descer o nível de abstração e trabalhar diretamente com os *timers* do *hardware* do microcontrolador, como disponbilizados pela fabricante.

</div>
<div class="column-container" markdown="1">
<div class="mid-aligned-container" markdown="1">
<figure markdown="1">

<!-- _class: transparent -->
![centered-img](./img/itaipu-binacional.png)

<figcaption markdown="1">

Figura 5 — Usina de Itaipu Binacional. Fonte: (BRASIL, 2023)

</figcaption>
</figure>
</div>
</div>
</div>

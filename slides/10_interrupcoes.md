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

**O que é desejado?**

Que o contador seja incrementado ou decrementado a partir de um botão, e que o valor do contador seja mostrado em um display de 7 segmentos.

**Como fazer? (parte lógica das funções de ISR)**

1. Criar uma variável global volátil para armazenar o valor do contador.
2. Criar uma função de *callback* ISR para incrementar o contador.
3. Criar uma função de *callback* ISR para decrementar o contador.

Ao lado temos o código que implementa a lógica descrita acima.

</div>
<div class="column-container" markdown="1">
<div id="codigo-container" markdown="1">

```c

volatile int count = 0; // 1. Variável global volátil

void increment() { // 2. ISR para incrementar o contador
    count++;
    if (count > 9) {
        count = 0;
    }
}

void decrement() { // 3. ISR para decrementar o contador
    count--;
    if (count < 0) {
        count = 9;
    }
}

```

</div>
</div>
</div>

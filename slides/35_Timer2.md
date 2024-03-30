<style scoped>
    figcaption {
        font-size: 14px;
        text-align: center;
    }
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

Ao usar o prescaler um efeito colateral muito bem vindo foi o ganho de desempenho no Arduino, como visto no wokwi, pois, ao dividir o clock por 1024, o Arduino executa menos vezes a interrupção de _overflow_ do timer e, consequentemente, tem uma carga menor de processamento.

Entretanto, um novo problema acometeu o código: A comutação do estado do LED feita pelo botão não funcionou como esperado. Isso ocorreu porque o pushbutton do wokwi simula um _bouncing_ (oscilação que ocorre quando um botão é pressionado que faz com que ele faça várias transições entre os estados de pressionado e não pressionado antes de se estabilizar) e, com isso, o código que foi feito para acionar o LED ao pressionar o botão não funcionou como esperado. Além disso, a comutação do estado do LED no loop faz com que o Loop possa entender que o botão está pressionado por mais tempo do que realmente está.

Para resolver este problema, será colocado um resistor de _pull-down_ no _pushbutton_ (como mostrado pela Figura 7) e a comutação do estado do LED e zeragem do contador será feita na própria interrupção do botão, deixando o loop vazio. Por fim, a variável de estado do botão pode ser excluída, assim como a função `releaseButton`, pois, não são mais necessárias.

<div class="flex-container">
<div class="column-container" markdown="1">

#### Modificação na Função de Interrupção

<div class="codigo-container" markdown="1">

```c

void pressButton() {
    // 1. Toggle the LED state
    digitalWrite(13, !digitalRead(13));
    // 2. Clear all overflow counters
    overflows = 0;
    // 3. Clear Timer2 counter
    TCNT2 = 0;    
}

```

</div>
</div>
<div class="column-container" markdown="1">

#### Modificação no Loop

<div class="codigo-container" markdown="1">

```c

void loop() {
    
}

```

</div>
</div>
<div class="column-container" markdown="1">

<!-- _class: transparent -->
![centered-img](./img/pulldown-push.png)

<figcaption markdown="1">

Figura 7 — Conexão de resistor _pull-down_ no _pushbutton_

</figcaption>
</figure>


</div>
</div>

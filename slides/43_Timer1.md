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
        text-align: justify;
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

    table {
        margin-left: auto;
        margin-right: auto;
        font-size: 10px;
    }
    table, td, th {
        border: 1px solid #dbdccf;
        border-collapse: separate;
        background-color: black;
        color: #dbdccf;
    }
    #t-caption {
        text-align: center;
        font-size: 8px;
        font-weight: bold;
    }

</style>

## _Timers_ e Contadores no Arduino — `Timer1` — Configuração e Funcionamento

### Passo 6: Associando interrupção externa ao acionamento do botão de controle do Farol e habilitando as interrupções globais

<div class="flex-container">
<div class="column-container" markdown="1">

Primeiramente criamos uma função para comutar o estado do farol e zerar o contador do Timer1:

<div class="codigo-container" markdown="1">

```c

void toggleFarol() {
    // Toggle the farol state
    digitalWrite(13, !digitalRead(13));
    // Reset the Timer1 counter
    TCNT1 = 0;
}

```

</div>

Depois definimos o pino 13 como saída, o pino 2 como entrada e associamos a rotina `toggleFarol` à ele na função `setup()`:

<div class="codigo-container" markdown="1">

```c
    
    // ...
    // Set pin 13 as output
    pinMode(13, OUTPUT);
    // Set pin 2 as input
    pinMode(2, INPUT);
    // Attach the toggleFarol function to the pin 2
    attachInterrupt(
        digitalPinToInterrupt(2), toggleFarol, RISING
    );
    // ...
}

```

</div>
</div>
<div class="column-container" markdown="1">

Por fim, colocamos a função `sei()` no final da função `setup()` para habilitar as interrupções globais:

<div class="codigo-container" markdown="1">

```c

    // ...
    // Enable global interrupts
    sei();
}
```

</div>

E assim conseguimos controlar o farol com o botão de controle e fazer com que ele comute o estado a cada 4 segundos pelo `Timer1`.

No próximo slide vemos a implementação e sua simulação no Wokwi.

</div>
</div>

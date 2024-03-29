<style scoped>
    ul, ol {
        font-size: 13px;
    }
    h2 {
        font-size: 24px;
    }
    h3 {
        font-size: 17px;
    }
    p {
        font-size: 15px;
    }
    #codigo-container {
        display: flex;
        justify-content: center;
        text-align: left; /* Para garantir alinhamento do texto à esquerda */
    }
    #codigo-container pre,
    #codigo-container code {
        width: 100%; /* Ocupa a largura total da `div` */
        max-width: 650px; /* Um valor máximo de largura pode ser útil */
        font-size: 12px; /* Ou qualquer tamanho que prefira */
        padding: 20px; /* Ajuste conforme necessário */
        box-sizing: border-box; /* Inclui o padding no cálculo da largura */
    }

</style>

## _Timers_ e Contadores no Arduino — Timer 2 — Funcionamento e Aplicações

Agora que já existem as funções necessárias é preciso definir as entradas e saídas para o Farol e seu botão de controle, além de configurar o Timer2 para o controle do tempo, pois, isto até o momento não foi feito.

### Configuração do Timer2

<div class="flex-container">
<div class="column-container">

Para finalizar a função `setup()` é necessário habilitar as interrupções globais:

<div id="codigo-container" markdown="1">

```cpp

    /* ... */
    // At the end we need to enable global interrupts
    sei();

}
```

</div>

Foi escolhido tratar o pressionamento do botão e a execução das tarefas associadas a ele fora do serviço de rotinas de interrupção **ISR** para evitar o bloqueio do serviço  e por consequência perdas de precisão na contagem de tempo. Por isso que tal tratamento é realizado na função `loop()` como visto ao lado:

</div>

<div class="column-container">
<div id="codigo-container" markdown="1">

```cpp

void loop() {
    // we'll handle the button press outside the ISR in order to
    // avoid blocking the ISR
    if (isPressed) {
        // if we press the button we should anticipate toggling the LED state
        // How to proceed here? 
        // 1. Toggle the LED state
        digitalWrite(13, !digitalRead(13));
        // 2. Clear all overflow counters
        overflows_from_0_to_62500 = 0;
        overflows_from_0_to_62500_from_0_to_5 = 0;
        // 3. Clear Timer2 counter
        TCNT2 = 0;
        // 4. Release the button
        releaseButton();
    }
}

```

</div>
</div>
</div>

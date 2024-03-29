<style scoped>
    ul, ol {
        font-size: 14px;
    }
    h2 {
        font-size: 24px;
    }
    h3 {
        font-size: 20px;
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

Para fazer a contagem de overflows é necessário criar uma rotina no ISR associada à interrupção de overflow do Timer2: `TIMER2_OVF_vect`. Neste código é necessário fazer sempre:

1. Incrementar `overflows_from_0_to_62500`;
2. Verificar se 62500 overflows já ocorreram. Se sim:
    1. Incrementar `overflows_from_0_to_62500_from_0_to_5`;
    2. Zerar `overflows_from_0_to_62500`.
3. Senão, verificar se 5 overflows já ocorreram. Se sim:
    1. Zerar `overflows_from_0_to_62500`;
    2. Zerar `overflows_from_0_to_62500_from_0_to_5`;
    3. Comutar o estado do Farol.

Lembrando que esta rotina é executada toda vez que ocorre um overflow do Timer2, ou seja, `TCNT2` passa de 255 para 0.

<div id="codigo-container" markdown="1">

```cpp

// This function will be called every time TIMER2 overflows
// and it is binded to Timer2 Overflow Interrupt Service Routine
ISR(TIMER2_OVF_vect) {
    overflows_from_0_to_62500 ++;

    if (overflows_from_0_to_62500 >= 62500) { // 62500 overflows are 1 second
        overflows_from_0_to_62500 = 0; 
        overflows_from_0_to_62500_from_0_to_5++;
    }
    else if (overflows_from_0_to_62500_from_0_to_5 >= 5) { // 5 seconds
        overflows_from_0_to_62500 = 0;
        overflows_from_0_to_62500_from_0_to_5 = 0;
        // toggle LED State
        digitalWrite(13, !digitalRead(13));
    }
}

```

</div>


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

## _Timers_ e Contadores no Arduino — Timer 2 — Funcionamento e Aplicações

Agora que já existem as funções necessárias é preciso definir as entradas e saídas para o Farol e seu botão de controle, além de configurar o Timer2 para o controle do tempo, pois, isto até o momento não foi feito.

### Configuração do Timer2

<div class="flex-container">
<div class="column-container">

Não adianta associar uma rotina ao overflow do Timer2 se a interrupção de overflow do Timer2 não estiver habilitada. Para fazer isto é necessário habilitá-la no registrador `TIMSK2` setando seu bit menos significativo para 1, pois, seu bit menos significativo corresponde ao bit `TOIE2` que habilita a interrupção de overflow do Timer2.

<div id="codigo-container" markdown="1">

```cpp

    /* ... */
    // Enable TIMER2 overflow interrupt. When we enable it it will be
    // binded to a ISR function that we need to implement in our code
    // As Timer2 can only count to 255 we need to count the times it overflows
    // So we will build it in our ISR function
    TIMSK2 = TIMSK2 | 0b00000001;
    /* ... */
```

</div>
</div>
<div class="column-container">

Convém também apresentar o `TIMSK2` e seus bits de controle para que se possa entender o que está sendo feito. O `TIMSK2` é o registrador da máscara de interrupção do Timer2. Aqui máscara significa que se o bit correspondente estiver setado, a interrupção correspondente será habilitada. Se o bit estiver zerado, a interrupção correspondente será desabilitada.

| Bit                   | 7   | 6   | 5   | 4   | 3   | 2      | 1      | 0     |
| --------------------- | --- | --- | --- | --- | --- | ------ | ------ | ----- |
| **(0x70)**            | —   | —   | —   | —   | —   | OCIE2B | OCEI2A | TOIE2 |
| **Leitura / Escrita** | R   | R   | R   | R   | R   | R/W    | R/W    | R/W   |
| **Valor Inicial**     | 0   | 0   | 0   | 0   | 0   | 0      | 0      | 0     |

<span id="Tabela-3"></span>

<div id="t-caption" markdown="1">

Tabela 3 — Bits do registrador de máscara de interrupções `TIMSK2` do `Timer2`

</div>

- `TOIE2` — Habilita a interrupção de overflow do Timer2.
- `OCIE2A` — Habilita a interrupção de _match_ do comparador A do Timer2.
- `OCIE2B` — Habilita a interrupção de _match_ do comparador B do Timer2.

</div>
</div>

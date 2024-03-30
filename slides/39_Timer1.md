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

### Passo 1: Configuração do Modo CTC (Clear Timer on Compare Match)

O modo CTC pela tradução literal de seu nome significa que o temporizador será zerado a cada vez que uma comparação bem sucedida com o valor armazenado no registrador de comparação `OCR1A` for realizada.

Para realizarmos a comparação precisamos conhecer quais bits de configuração devem ser setados em `TCCR1B` e `TCCR1A` para que o modo CTC seja ativado bem como, armazenar o valor a ser comparado no registrador `OCR1A`.

De acordo com o manual do fabricante o funcionamento no modo CTC é ativado quando o bit `WGM12` é setado em 1 e os demais bits WGM (13, 11, e 10) são zerados. Estes bits são configurados nos registradores `TCCR1B`, cujos bits de configuração são representados pela Tabela 4, e `TCCR1A` com bits representados pela Tabela 5.

<div class="flex-container">
<div class="column-container" markdown="1">

| Bit                   | 7     | 6     | 5   | 4     | 3     | 2    | 1    | 0    |
| --------------------- | ----- | ----- | --- | ----- | ----- | ---- | ---- | ---- |
| **(0x81)**            | ICNC1 | ICES1 | —   | WGM13 | WGM12 | CS12 | CS11 | CS10 |
| **Leitura / Escrita** | R/W   | R/W   | R   | R/W   | R/W   | R/W  | R/W  | R/W  |
| **Valor Inicial**     | 0     | 0     | 0   | 0     | 0     | 0    | 0    | 0    |

<span id="Tabela-4"></span>

<div id="t-caption" markdown="1">

Tabela 4 — Bits de controle registrador `TCCR1B` do `Timer1`

</div>

</div>
<div class="column-container" markdown="1">

| Bit                   | 7      | 6      | 5      | 4      | 3   | 2   | 1     | 0     |
| --------------------- | ------ | ------ | ------ | ------ | --- | --- | ----- | ----- |
| **(0x80)**            | COM1A1 | COM1A0 | COM1B1 | COM1B0 | —   | —   | WGM11 | WGM10 |
| **Leitura / Escrita** | R/W    | R/W    | R/W    | R/W    | R   | R   | R/W   | R/W   |
| **Valor Inicial**     | 0      | 0      | 0      | 0      | 0   | 0   | 0     | 0     |

<span id="Tabela-5"></span>

<div id="t-caption" markdown="1">

Tabela 5 — Bits de controle registrador `TCCR1A` do `Timer1`

</div>

</div>
</div>

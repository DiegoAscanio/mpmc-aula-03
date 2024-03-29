<style scoped>
    ul, ol {
        font-size: 14px;
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
    table {
        margin-left: auto;
        margin-right: auto;
        font-size: 14px;
    }
    table, td, th {
        border: 1px solid #dbdccf;
        border-collapse: separate;
        background-color: black;
        color: #dbdccf;
    }
    #t-caption {
        text-align: center;
        font-size: 10px;
        font-weight: bold;
    }

</style>

## *Timers* e Contadores no Arduino — Timer 2

O *prescaler* do `Timer2` é um componente que permite diminuir a frequência do *clock* do *timer* para que ele possa contar em um intervalo de tempo maior.

A configuração do *prescaler* do `Timer2` é feita através do registrador dos bits `CS22`, `CS21` e `CS20` do registrador `TCCR2B`, um dos registradores de controle do `Timer2` (o outro é o `TCCR2A`).

São apresentados nas Tabelas 1 e 2, respectivamente, os bits do registrador `TCCR2B` e os valores possíveis para o *prescaler* do `Timer2`.

<div class="flex-container" markdown="1">
<div class="column-container" markdown="1">

| Bit                   | 7     | 6     | 5   | 4   | 3     | 2    | 1    | 0    |
| --------------------- | ----- | ----- | --- | --- | ----- | ---- | ---- | ---- |
| **(0xB1)**            | FOC2A | FOC2B | —   | —   | WGM22 | CS22 | CS01 | CS00 |
| **Leitura / Escrita** | W     | W     | R   | R   | R     | R/W  | R/W  | R/W  |
| **Valor Inicial**     | 0     | 0     | 0   | 0   | 0     | 0    | 0    | 0    |

<span id="Tabela-1"></span>

<div id="t-caption" markdown="1">

Tabela 1 — Bits do registrador de controle `TCCR2B` do `Timer2`

</div>

Para os propósitos desta aula, apenas os bits de configuração `CS22`, `CS21` e `CS20` são relevantes. Os bits `WGM22`, `FOC2A` e `FOC2B` são utilizados para configuração de outros modos de operação do `Timer2`, como PWM, e não serão abordados ainda.

</div>
<div class="column-container" markdown="1">

| CS22 | CS21 | CS20 | Descrição                                                                    |
| ---- | ---- | ---- | ---------------------------------------------------------------------------- |
| 0    | 0    | 0    | Sem fonte de clock <br> (Temporizador parado).                               |
| 0    | 0    | 1    | \\({\text{clk}}\_{\text{T2S}}\\)  sem prescaler                              |
| 0    | 1    | 0    | \\(\frac{{\text{clk}}\_{\text{T2S}}}{8}\\) (com prescaler)                   |
| 0    | 1    | 1    | \\(\frac{{\text{clk}}\_{\text{T2S}}}{32}\\) (com prescaler)                  |
| 1    | 0    | 0    | \\(\frac{{\text{clk}}\_{\text{T2S}}}{64}\\) (com prescaler)                  |
| 1    | 0    | 1    | \\(\frac{{\text{clk}}\_{\text{T2S}}}{128}\\) (com prescaler)                 |
| 1    | 1    | 0    | \\(\frac{{\text{clk}}\_{\text{T2S}}}{256}\\) (com prescaler)                 |
| 1    | 1    | 1    | \\(\frac{{\text{clk}}\_{\text{T2S}}}{1024}\\) (com prescaler)                |

<span id="Tabela-2"></span>

<div id="t-caption" markdown="1">

Tabela 2 — Valores possíveis para o *prescaler* do `Timer2`

</div>

</div>
</div>

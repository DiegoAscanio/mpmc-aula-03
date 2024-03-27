<style scoped>
    ul, ol {
        font-size: 16px;
    }
    h2 {
        font-size: 28px;
    }
    h3 {
        font-size: 24px;
    }
    p {
        font-size: 18px;
    }
    table {
        margin-left: auto;
        margin-right: auto;
        font-size: 18px;
    }
    table, th, td {
        border: 1px solid #dbdccf;
        border-collapse: collapse;
        background-color: black;
        color: #dbdccf;
    }
    #t-caption {
        text-align: center;
        font-size: 14px;
        font-weight: bold;
    }
</style>

## _Timers_ e Contadores no Arduino — Funcionamento

### Timer0

O `Timer0` é um bom ponto de partida para entender o funcionamento dos timers no Arduino. Para isso é necessário entender os registradores básicos presentes nele:

1. **`TCNT0`: Registrador Contador / Temporizador número 0**
    - É um registrador de 8 bits que incrementa sua contagem a cada pulso de clock.
2. **`TCCR0`: Registrador de Controle do Timer0**
    - É um registrador de 8 bits que controla o modo de operação do Timer0, bem como a seleção da fonte de clock. Cada bit do registrador é apresentado na tabela abaixo:

| 7    | 6     | 5     | 4     | 3     | 2    | 1    | 0    |
| ---- | ----- | ----- | ----- | ----- | ---- | ---- | ---- |
| FOC0 | WGM00 | COM01 | COM00 | WGM01 | CS02 | CS01 | CS00 |

<span id="Tabela-1"></span>
<div id="t-caption" markdown="1">

Tabela 1 — Bits do registrador de controle `TCCR0` do `Timer0`

</div>

Nos próximos *slides* serão explicados os bits de controle — e seus respectivos funcionamentos — do registrador `TCCR0`.

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

Pela configuração do Fabricante, para se ativar o modo CTC, os bits `WGM13`, `WGM12`, `WGM11` e `WGM10` devem ser configurados respectivamente como `0`, `1`, `0` e `0`. Para isso, basta configurar o registrador `TCCR1A` como `0b00000000` e o registrador `TCCR1B` como `0b00001000` — Ver Tabelas [4](#Tabela-4) e [5](#Tabela-5) — na função `setup()`:

<div class="codigo-container" markdown="1">

```c

void setup() {
    // 1. Enabling CTC Mode
    TCCR1A = 0b00000000;
    TCCR1B = 0b00001000;
    // ...

```

</div>

### Passo 2: Definindo o valor de comparação

[É conhecido](#37) que para contar 4 segundos com _prescaler_ de 1024 são necessárias 62500 contagens do `Timer1`. O modo CTC do `Timer1` foi definido para que quando atingido este valor, o _timer_ seja zerado e o _flag_ `OCF1A` seja ativado. O que é necessário agora é armazenar o valor 62500 no registrador de comparação `OCR1A`, também na função `setup()`:


<div class="codigo-container" markdown="1">

```c

    // ...
    // 2. Setting `OCR1A` to 62500
    OCR1A = 62500;
    // ...

```

</div>

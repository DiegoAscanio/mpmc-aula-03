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

### Passo 3: Selecionando o _Prescaler_

No Timer2 para um _prescaler_ de 1024 ser utilizado os bits `CS22`, `CS21` e `CS20` devem ser configurados como 1, 1 e 1, respectivamente.

No Timer1 os bits são da forma `CS1X` onde \\(2 \geq X \leq 0\\) e devem ser configurados como 1, 0 e 1, respectivamente. 

Por fim, no Timer1 os bits `CS12`, `CS11` e `CS10` são os 3 bits menos significativos do registrador `TCCR1B`. Assim a configuração do prescaler de 1024, também no `setup()`, se dá como abaixo:

<div class="codigo-container" markdown="1">

```c

    // ...
    // 3. Setting 1024 Prescaler
    TCCR1B = TCRR1B | 0b00000101;
    // ...

```

</div>

### Passo 4: Habilitando a Interrupção de Comparação de Valor A do Timer1

Para habilitar a interrupção de comparação de valor A do Timer1, o bit `OCIE1A` do registrador `TIMSK1` deve ser configurado como 1. Este bit é o segundo da direita para a esquerda. Assim, a configuração da interrupção de comparação de valor A do Timer1, também no `setup()`, se dá como abaixo:

<div class="codigo-container" markdown="1">

```c

    // ...
    // 4. Enabling OCIE1A on TIMSK1
    TIMSK1 = TIMSK1 | 0b00000010;
    // ...

```

</div>


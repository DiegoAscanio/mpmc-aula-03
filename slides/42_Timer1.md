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

### Passo 5: Registrando uma interrupção de Comparação de Valor no ISR para comutar o LED

Deve ser criada uma rotina no ISR associada à interrupção de comparação de valor A do Timer1 `TIMER1_COMPA_vect` para comutar o LED:

<div class="codigo-container" markdown="1">

```c

ISR(TIMER1_COMPA_vect) {
    // Toggle the LED
    digitalWrite(13, !digitalRead(13));
}

```

</div>

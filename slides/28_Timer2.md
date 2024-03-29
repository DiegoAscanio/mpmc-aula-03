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

### Configuração da saída para acender / apagar o Farol e da entrada para o botão de controle

<div id="codigo-container" markdown="1">

```cpp

void setup() {
    // Set pin 13 as output
    pinMode(13, OUTPUT);
    // Set pin 2 as input
    pinMode(2, INPUT);

    // Attach interrupt to pin 2 through specifc function
    // attachInterrupt that can only be used with Arduino
    // pins that are interrupt capable (2 and 3 on the Uno)
    attachInterrupt(
        digitalPinToInterrupt(2), pressButton, RISING
    );
    /* ... */
```

</div>


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

O `Timer2` tem dois registradores de controle que precisam ser configurados: o `TCCR2A` e o `TCCR2B`. O `TCCR2A` não foi visto ainda porque não é necessário modificar o modo de operação do `Timer2` para o que é desejado fazer — o `TCCR2A` é associado a modos de operação distintos da contagem como PWM e geração de ondas quadradas.

Já o `TCCR2B` é o registrador responsável pela configuração do prescaler do `Timer2`, ou seja, da diminuição da frequência de contagem do temporizador pela divisão do clock de entrada. O que interessa para o propósito da aplicação de exemplo é a configuração dos bits responsáveis pelo prescaler, que são os bits `CS22`, `CS21` e `CS20` (ver [Tabela 1](#Tabela-1)). Como visto na [Tabela 2](#Tabela-2), é necessário configurar o contador para não ter prescaler, ou seja, para que o clock de entrada seja o mesmo do microcontrolador, assim, deve-se definir os bits `CS22`, `CS21` e `CS20` como 0, 0 e 1 respectivamente.

<div id="codigo-container" markdown="1">

```cpp

    /* ... */
    // Set TIMER2 to normal mode
    // Arduino UNO has two controller registers for TIMER2: TCCR2A and TCCR2B
    TCCR2A = 0b00000000; // normal operation mode
    TCCR2B = 0b00000001; // disabling any kind of prescaler
    /* ... */
```

</div>


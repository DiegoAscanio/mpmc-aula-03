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
    #codigo-container {
        display: flex;
        justify-content: center;
        text-align: left; /* Para garantir alinhamento do texto à esquerda */
    }
    #codigo-container pre,
    #codigo-container code {
        width: 100%; /* Ocupa a largura total da `div` */
        max-width: 650px; /* Um valor máximo de largura pode ser útil */
        font-size: 14px; /* Ou qualquer tamanho que prefira */
        padding: 20px; /* Ajuste conforme necessário */
        box-sizing: border-box; /* Inclui o padding no cálculo da largura */
    }

</style>

## _Timers_ e Contadores no Arduino — Timer 2 — Funcionamento e Aplicações

No controle do funcionamento do Farol de praia, é definido que a estratégia adotada será a de contagem de overflows. Então, para isso, são criadas duas variáveis globais inteiras (16bits) para armazenar a contagem de overflows de 0 a 62500 e depois para armazenar a quantidade de vezes que 62500 overflows ocorreram. Por fim, também é criada outra variável volátil para armazenar o estado do botão de controle do farol.

<div id="codigo-container" markdown="1">

```cpp

volatile static uint16_t overflows_from_0_to_62500 = 0;
volatile static uint16_t overflows_from_0_to_62500_from_0_to_5 = 0;
volatile bool isPressed = false;

```

</div>

É necessário também criar duas funções para o controle do botão, uma para o pressionamento e outra para a soltura:

<div id="codigo-container" markdown="1">

```cpp

void pressButton() {
    isPressed = true;
}

void releaseButton() {
    isPressed = false;
}

```

</div>

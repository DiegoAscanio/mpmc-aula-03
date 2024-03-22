<style scoped>
    ul, ol {
        font-size: 18px;
    }
    h2 {
        font-size: 28px;
    }
    p {
        font-size: 20px;
    }
    #codigo-container {
        display: flex;
        justify-content: center;
        align-items: center;
        height: 80vh;
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

## Interrupções no Arduino — Interupções para (Inc/Dec)rementar um contador cujo resultado é mostrado em um display de 7 segmentos

<div class="flex-container">
<div class="column-container" markdown="1">

**Como fazer? (parte lógica para exibir números no display de 7 segmentos)**

4. Criar uma matriz de \\(10 \times 7\\) para representar os números de 0 a 9 em um display de 7 segmentos onde cada coluna de cada linha representa respectivamente os segmentos a-g que precisam ficar acesos para representar o número correspondente à linha, como mostrado na [Figura 1](#figura-1) e no código ao lado.

5. Criar uma função `display` que receba como parâmetro o número decimal a ser exibido e acenda os sete segmentos correspondentes conforme a linha correspondente ao número decimal na `matriz_7seg`.

</div>
<div class="column-container" markdown="1">
<div id="codigo-container" markdown="1">

```c

// 4. Matriz de segmentos para os números de 0 a 9
int matriz_7seg[10][7] = { 
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9 
};

// 5. Função para exibir um número no display de 7 segmentos
void display(int num) {
    // we start at pin 7 (seg. A) and go up to pin 13 (seg. G)
    int pin = 7;
    int i = 0; 
    // for each segment i (A to G) in matriz_7seg[num]
    while (i < 7) { 
        digitalWrite(pin, matriz_7seg[num][i]);
        i++;
        pin++;
    }
}

```

</div>
</div>
</div>

<style scoped>
    figcaption {
        font-size: 14px;
        text-align: center;
    }
    ul, ol {
        font-size: 10px;
    }
    h2 {
        font-size: 21px;
    }
    h3 {
        font-size: 14px;
        text-align: justify;
    }
    h4 {
        font-size: 13px;
    }
    h5 {
        font-size: 11px;
    }
    p {
        font-size: 12px;
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

    
</style>

## _Timers_ e Contadores no Arduino — `Timer1` — Configuração e Funcionamento

### Passo 1: Configuração do Modo CTC (Clear Timer on Compare Match)

Para que o Timer1 reinicie ao atingir o valor especificado, você o configura no modo CTC. O Timer1 é um temporizador/contador de 16 bits, então pode lidar com o valor de 62500 diretamente.

### Passo 2: Definindo o Valor de Comparação

Você define o valor de comparação no registro `OCR1A` (Output Compare Register 1 A), que determina o valor para o qual o contador irá comparar e gerar uma interrupção de comparação de valor.

### Passo 3: Selecionando o _Prescaler_

O prescaler é selecionado para dividir o clock do CPU e determinar a taxa na qual o contador incrementa. Um prescaler de 1024 é selecionado através dos bits do registro `TCCR1B`.

### Passo 4: Habilitando a Interrupção de Comparação de Valor

Você precisa habilitar explicitamente a interrupção de comparação de valor para o Timer1, configurando o bit apropriado no registro `TIMSK1`.

### Passo 5: Registrando uma interrupção de Comparação de Valor no ISR para comutar o LED

Você define uma rotina ISR associada ao `TIMER1_COMPA_vect` para comutar o LED.

### Passo 6: Associando interrupção externa ao acionamento do botão de controle do Farol e habilitando as interrupções globais.

Por fim, você liga o botão em uma das entradas capazes de interrupção externa do Arduino, associa a esta entrada uma função de interrupção externa para comutar o estado do Farol e reiniciar a contagem do Timer1 e habilita as interrupções globais no `setup()`.

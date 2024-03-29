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
</style>

## _Timers_ e Contadores no Arduino — Timer 2 — Funcionamento e Aplicações

Suponha que seja necessário comutar os estados (aceso e apagado) da luz de um farol de praia a cada 5 segundos ou a cada aperto de um botão. Como realizar esta tarefa com temporização precisa?

- Se o clock do Arduino é de 16MHz, isso quer dizer que o processador executa 16 milhões de instruções por segundo. Logo, cada instrução leva \\(62.5 ns\\) para ser executada. Se eu fizer somas sucessivas das instruções executadas, logo, posso calcular o tempo que se leva para executar um determinado número de instruções.
    - O registrador de contagem do _Timer2_ `TCNT2` tem precisão de 8 bits. Logo, é impossível contar até 5 segundos com a precisão deste registrador.
        - Entretanto, a cada vez que o contador atinge o valor 255, ele é zerado e um _overflow_ é gerado. Este _overflow_ pode ser associado a uma ISR (função de interrupção) e podemos incrementar variáveis de _overflow_ para com isso contar o tempo!
    - Suponha que cada incremento no contador seja realizado em \\(62.5 ns\\). Como o `TCNT2` conta de 0 até 255 — 256 contagens — então, a cada \\(16\mu s\\) um overflow é gerado.
        - Pois, \\(256 \times 62.5 ns = 16 \mu s\\).
    - Assim, a cada 1 segundo ocorrem \\(1s/16\mu s = 62500\\) overflows.
        - Logo para contarmos 5 segundos, precisamos de \\(5s \times 62500 = 312500\\) overflows.
    - Entretanto, o arduino não armazena variáveis inteiras acima de 16 bits e o valor de 312500 excede esta precisão.
        - Mas nada nos impede de quebrar este valor em duas variáveis de overflow para controle. E é o que faremos!

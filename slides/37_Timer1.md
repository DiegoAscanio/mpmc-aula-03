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

## _Timers_ e Contadores no Arduino — `Timer1` — Funcionamento e Aplicações

Modificando um pouco do exemplo anterior, vamos agora utilizar o `Timer1` para contar intervalos de tempo de 4 segundos.

- Se o clock do Arduino é de 16MHz, isso quer dizer que o processador executa 16 milhões de instruções por segundo. Logo, cada instrução leva \\(62.5 ns\\) para ser executada. Se eu fizer somas sucessivas das instruções executadas, logo, posso calcular o tempo que se leva para executar um determinado número de instruções.
    - O registrador de contagem do `Timer1` `TCNT1` tem precisão de 16 bits. Logo, é impossível contar até 4 segundos com a precisão deste registrador considerando-se que 4 segundos são \\(4s/62.5ns = 64000000\\) instruções.
    - Porém, se o _clock_ do processador for diminuido por um fator de divisão, então o tempo de contagem do `Timer1` será aumentado por este mesmo fator.
        - Assim, se o _clock_ for dividido por 1024 — ficando em 15625 Hz — então, cada incremento no registrador `TCNT1` corresponderá a \\(1/15625 = 64 \mu s\\).
        - A cada segundo 15625 instruções serão executadas. Em 4 segundos, 62500 instruções serão executadas, um número que pode ser armazenado em um inteiro de 16 bits e que, portanto, pode ser contado pelo `Timer1` sem a necessidade de interrupções de _overflow_.

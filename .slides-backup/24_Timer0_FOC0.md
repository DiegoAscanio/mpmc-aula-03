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

## `Timer0` — Bit de controle `FOC0` (Force Output Compare on Timer0)

### Exemplo Didático do uso do Bit de Controle `FOC0` para adiantar um acendimento/apagamento de LED

- O Timer0 do Arduino tem 8 bits, portanto, pode contar de 0 até 255 apenas.
- Cada ciclo de clock do Arduino incrementa o contador do `Timer0` em 1.
- Considerando que o Arduino Uno tem um clock de 16MHz, o Timer0 incrementa a cada \\(62.5 ns\\).
- Considerando que o Timer0 tem overflow a cada 256 incrementos, o overflow ocorre a cada \\(16 \mu s\\).
- Como contar 5 segundos com o Timer0?
    - Contando a ocorrência de 312.500 *overflows* do Timer0.
- Assim quando a contagem de *overflows* chegar a este valor, o Arduino terá contado 5 segundos, o LED é aceso(apagado) e a contagem de overflows é zerada.
- Como adiantar essa comutação de estado do LED?
    - Associando uma interrupção externa ao pino 2 do Arduino;
    - Quando a interrupção ocorrer (botão pressionado):
        - Setamos o estado do botão para pressionado.
        - Na função principal:
            - O valor do contador de overflows é zerado.
            - Um loop é executado para causar 312.500 *overflows* no Timer0 setando o bit `FOC0` para 1.
                - (como a capacidade dos inteiros do arduino é de 16 bits, a contagem é feita em duas partes)
            - Como o clock do arduino é de 16MHz e o Timer0 incrementa a cada \\(62.5 ns\\), o tempo de espera é de \\(312.500 \times 62.5 ns = 19.53125 ms\\), o que é um delay imperceptível para o usuário e que adianta a comutação do estado do LED.
            

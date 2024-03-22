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

## *Timers* e Contadores no Arduino — Funcionamento

Para que os *Timers* do Arduino possam funcionar, é necessário definir suas configurações de operação. Isso é feito através de registradores e *flags* específicos dos contadores, que são apresentadas a seguir.

### Registradores e *flags* de controle comuns a todos os *Timers* do Arduino

- `TCNTn` : Registrador de contagem / tempo;
    - Todo *timer* do ATMega possui um registrador de contagem, que é responsável por armazenar o valor atual do contador. Quando em *reset*, o valor do registrador é zerado e é possível ler e escrever valores nesse registrador de acordo com a demanda da aplicação. Sua contagem é realizada a cada pulso de clock e o `n` ao final do nome do registrador indica o número do *timer*.
- `TOVn`: *Flag* de *overflow* (estouro do contador);
    - Cada temporizador do ATMega tem sua *flag* de *timer* *overflow*. Quando o temporizador estoura sua contagem, sua *flag* é definida automaticamente.
- `TCCRn`: Registrador de controle do *timer* (Timer/Counter Control Register);
    - O registrador de controle do *timer* é responsável por configurar o modo de operação do *timer*.
- `OCRn`: Registrador de comparação (Output Compare Register);
    - O registrador de comparação armazena um valor de referência para comparação com o valor do registrador de contagem/tempo (`TCNTn`). Quando o valor do registrador de contagem/tempo é igual ao valor do registrador de comparação, a *flag* de comparação `OCFn` é definida.
- `OCFn`: *Flag* de comparação;
    - A *flag* de comparação é definida quando o valor do registrador de contagem/tempo (`TCNTn`) é igual ao valor do registrador de comparação (`OCRn`).

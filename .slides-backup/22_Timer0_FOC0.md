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

O `FOC0` é um bit de controle do `Timer0` que permite ao desenvolvedor lançar manualmente eventos durante a operação do `Timer0`, especificamente no processo de geração de formas de onda do timer.

A geração de formas de onda em um microcontrolador (i.e. PWM, ondas quadradas) é feita através da comparação do valor do registrador de contagem do timer com o valor do registrador de comparação. Quando o valor do registrador de contagem é igual ao valor do registrador de comparação, o microcontrolador lança um evento, que pode ser usado para controlar a saída de um pino do microcontrolador, por exemplo.

O bit `FOC0` permite ao desenvolvedor lançar manualmente esse evento, sem esperar que o valor do registrador de contagem seja igual ao valor do registrador de comparação, ou seja, forçando a ocorrência de um evento independentemente da contagem registrada no temporizador.

Quando o bit `FOC0` é setado para `1`, o microcontrolador lança o evento de comparação, por ter sido forçado à realizá-la e o bit `FOC0` é automaticamente resetado para `0` pelo microcontrolador após a ocorrência do evento.

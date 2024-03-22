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

## *Timers* e Contadores

### *Timers*

Os *timers* (ou temporizadores) são componentes internos de microcontroladores que permitem a contagem do tempo — diferença entre instante de tempo final e instante de tempo inicial — em um sistema.

Funcionam a partir do incremento de um contador interno a cada ciclo (ou múltiplo de ciclo) de clock do microcontrolador.

Quando o contador de tempo do *timer* atinge um valor pré-determinado pelo programador, ele pode gerar uma interrupção, que pode ser usada para forçar o microcontrolador a executar uma rotina específica (ISR) que deva ser executada a cada intervalo de tempo.

### Contadores

Os contadores são os componentes que permitem a contagem de eventos que ocorrem em um sistema (exemplo: ciclos de clock, pulsos de um sensor, etc) sendo portanto, base para a implementação dos *timers*.


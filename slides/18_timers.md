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

## *Timers* e Contadores no Arduino

No Atmega328p, o microcontrolador do Arduino Uno, existem 3 *timers* que podem ser utilizados para contagem de tempo. Cada *timer* possui um *prescaler* que pode ser configurado para dividir a frequência do clock do microcontrolador. O *prescaler* é um divisor de frequência que pode ser configurado para dividir a frequência do clock do microcontrolador por 1, 8, 64, 256 ou 1024.

### *Prescaler*

O *prescaler* pode ser usado para reduzir a frequência do clock do microcontrolador e, consequentemente, a frequência de contagem do *timer*. Isso é útil para contagens de tempo mais longas, como segundos, minutos e horas.

Suponha que você precise de um timer que funcione a cada 1 segundo (1Hz). Se o clock do microcontrolador for de 16MHz, a frequência de contagem do timer será de 16MHz. Para obter uma frequência de contagem de 1Hz, você pode configurar o *prescaler* para dividir a frequência do clock por 16.000.000. Isso resultará em uma frequência de contagem de 1Hz.

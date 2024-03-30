## _Timers_ e Contadores no Arduino — Considerações Finais

O aluno também aprendeu a fazer contagens de virtualmente quaisquer valores com quaisquer tipos de _timers_ que forem disponíveis, de 8 bits, 16 bits, assim por diante, pela técnica de contagem de _overflows_.

Entretanto foi visto que a contagem de _overflows_ é uma técnica que pode ser bastante trabalhosa e que deve ser evitada por aumentar considerávelmente a carga de trabalho do microcontrolador.

As técnicas vistas para evitar ou diminuir a contagem de _overflows_ são:

- Uso de _prescalers_ de _clock_ para diminuir a frequência de contagem;
- Uso de _timers_ de 16 bits para aumentar o tamanho do contador;
- Uso do modo CTC com interrupção de comparação da saída;

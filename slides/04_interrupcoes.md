## Interrupções — Interrupções no Arduino

Quando algum evento ocorre no *hardware* do Arduino, uma função de *callback* associada a esse evento é executada, desviando o fluxo da execução do programa principal para o tratamento do evento.

Por isso recebe o nome de interrupção, pois interrompe a execução do programa principal para o tratamento de um evento até que tal tratamento seja finalizado.

São de fundamental importância para o Arduino por permitir que o microcontrolador realize tarefas de forma quasi-paralela.

## Interrupções — Interrupções no Arduino

<div class="regular" markdown="1">

No Arduino estas funções de *callback* também recebem o nome de ISRs (Interruption Service Routines) e possuem algumas limitações que devem ser observadas:

- Não recebem argumentos;
- Não retornam valores;
- Devem ser o mais curtas e rápidas possíveis;
- Apenas uma ISR pode ser executada por vez;
    - Se o programa usa múltiplas ISRs, outras interrupções serão executadas após a atual terminar, em uma ordem que depende de sua prioridade;
- Não podem ser interrompidas por outras interrupções;
- Para transitar dados entre a ISR e o programa principal, é necessário o uso de variáveis globais anotadas pelo modificador `volatile`.

</div>

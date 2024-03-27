## _Timers_ e Contadores no Arduino — Funcionamento

Apesar de existirem 3 *timers* no ATmega328P, apenas dois deles são acessíveis diretamente pelo usuário: `Timer1` e `Timer2`, pois, o `Timer0` é utilizado pelo Arduino para funções internas.

Assim, serão vistas algumas formas de contagem de tempo e associação de *triggers* — eventos — a serem executados quando o tempo atingir o valor desejado.

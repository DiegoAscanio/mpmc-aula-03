<style scoped>
    figcaption {
        font-size: 21px;
        text-align: center;
    }
    ul, ol {
        font-size: 18px;
    }
    h2 {
        font-size: 32px;
    }
    h3 {
        font-size: 27px;
    }
    h4 {
        font-size: 22px;
    }
    h5 {
        font-size: 18px;
    }
    p {
        font-size: 18px;
    }
    .codigo-container {
        display: flex;
        justify-content: center;
        text-align: left; /* Para garantir alinhamento do texto à esquerda */
    }
    .codigo-container pre,
    .codigo-container code {
        width: 100%; /* Ocupa a largura total da `div` */
        max-width: 650px; /* Um valor máximo de largura pode ser útil */
        font-size: 18px; /* Ou qualquer tamanho que prefira */
        padding: 20px; /* Ajuste conforme necessário */
        box-sizing: border-box; /* Inclui o padding no cálculo da largura */
    }

    
</style>

## _Timers_ e Contadores no Arduino — `Timer1`

Foi visto que com o `Timer2` que é possível realizar a contagem de tempo — virtualmente qualquer contagem de tempo — com um _timer_ de 8 bits. Entretanto, foram necessários muitos artifícios técnicos para alcançar tal objetivo e a própria contagem de _overflows_ é um artifício que evidencia a distorção de propósito dos temporizadores, pois, eles existem para contar para os programas evitando que os programas por si só tenham de fazer contagens.

Entretanto, ver que é possível é útil em contextos onde não existem contadores com maiores resoluções disponíveis. De qualquer forma o **ATMega328P** possui um _timer_ de 16 bits que é o `Timer1` e através dele é possível contar intervalos de tempo maiores com precisão correta sem a necessidade de contar _overflows_.

Será visto nos próximos _slides_ como configurar e utilizar o `Timer1` para contar intervalos de tempo aplicado ao exemplo em estudo do controle do farol de praia.

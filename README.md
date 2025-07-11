Sistema de Monitoramento de Vazamento de Gás com
Arduino

Este projeto implementa um sistema de detecção de vazamento de gás usando Arduino UNO,
sensor de gás (como o MQ-2), um display LCD 16x2, LEDs indicadores e um buzzer. O objetivo
é alertar sobre diferentes níveis de concentração do vapor de mercúrio no ambiente.

Componentes Utilizados

Componente Quantidade
Arduino UNO 1
Sensor de Gás (MQ-2) 1
Display LCD 16x2 1
LEDs (Verde, Amarelo, Vermelho) 1 de cada
Resistores (220Ω) 3
Buzzer 1
Protoboard e Jumpers diversos

Funcionalidades

 Leitura da concentração de gás via sensor analógico.
 Exibição do valor da concentração no LCD (em %).
 Alerta visual e sonoro:
o PERIGO (concentração > 90%): LED vermelho + som do buzzer.
o ATENÇÃO (concentração > 5%): LED amarelo.
o SEGURO (concentração ≤ 5%): LED verde.

Conexões do Hardware
LCD 16x2 (interface paralela)

Pino LCD Pino Arduino
RS 12
E 11
D4 10
D5 9
D6 8
D7 7

Outros Componentes

Componente Pino Arduino
Sensor MQ-2 A
LED Verde 2
LED Amarelo 3
LED Vermelho 4
Buzzer 13

Lógica de Funcionamento

    O valor analógico do sensor de gás é lido e mapeado para uma escala percentual de 0 a
    100%.
    Dependendo da concentração:
    o Acima de 90%: exibe “PERIGO” / “EVACUAR” e ativa o buzzer + LED
    vermelho.
    o Entre 6% e 90%: exibe “ATENÇÃO” e acende o LED amarelo.
    o 5% ou menos: exibe “SEGURO” e acende o LED verde.
    Os dados são enviados ao monitor serial para fins de depuração.


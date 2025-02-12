# Tarefa_U4C7
Atividade: Controle de servomotor por PWM.
Com o emprego do módulo PWM (do inglês, Pulse Width Modulation),
presente no microcontrolador RP2040, projete um sistema com a
ferramenta Pico SDK para simular o controle do ângulo de um
servomotor. Esta simulação contemplará o motor micro servo
padrão, presente no simulador de eletrônica online Wokwi. Para
condução desta prática, será necessário simular os componentes
listados abaixo. A configuração sugerida está presente na Figura 1.
1) Microcontrolador Raspberry Pi Pico W.
2) Servomotor – motor micro servo padrão – Wokwi.

Os requisitos para a realização desta atividade são:
1) Considerando a GPIO 22, defina a sua frequência de PWM para,
aproximadamente, 50Hz – período de 20ms. (20% da nota)
2) Defina o ciclo ativo do módulo PWM para 2.400µs
(microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,12%. isto
ajustará a flange (braço) do servomotor para a posição de,
aproximadamente, 180 graus. Aguarde 05 segundos nesta
posição. (10% da nota)
3) Defina o ciclo ativo do módulo PWM para 1.470µs
(microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,0735%.
Isto ajustará a flange do servomotor para a posição de,
aproximadamente, 90 graus. Aguarde 05 segundos nesta
posição. (10% da nota)
4) Defina o ciclo ativo do módulo PWM para 500µs
(microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,025%.
Isto ajustará a flange do servomotor para a posição de,
aproximadamente, 0 graus. Aguarde 05 segundos nesta
posição. (10% da nota)
5) Após a realização das proposições anteriores, crie uma rotina
para movimentação periódica do braço do servomotor entre os
ângulos de 0 e 180 graus. Obs.: a movimentação da flange deve
ser suave, recomenda-se o incremento de ciclo ativo de ±5µs,
com um atraso de ajuste de 10ms. (35% da nota)
6) Com o emprego da Ferramenta Educacional BitDogLab, faça
um experimento com o código deste exercício utilizando o LED
RGB – GPIO 12. O que o discente observou no comportamento
da iluminação do referido LED? (15% da nota)

# Video 
https://drive.google.com/file/d/1C8msOdUTqcpLkPuQM9dE-ula2lBtNZGp/view?usp=drive_link

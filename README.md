# Automação de Iluminação para Estacionamento

## Sobre o projeto

Este projeto foi desenvolvido com Arduino para automatizar a iluminação de um estacionamento utilizando sensores de movimento e fitas de LED NeoPixel.

A ideia é acender automaticamente as luzes quando houver movimento próximo ao estacionamento e desligá-las após um período sem novas detecções.

## Como funciona

O sistema utiliza 5 sensores de movimento. Quando qualquer um deles detecta movimento:

- As 3 fitas NeoPixel são ligadas.
- As luzes ficam na cor branca.
- O temporizador de 2 minutos é iniciado.
- Se houver uma nova detecção, o temporizador é reiniciado.
- Após 2 minutos sem novas detecções, todas as fitas são desligadas.

## Componentes utilizados

- Arduino
- 5 sensores de movimento
- 3 fitas NeoPixel
- Fios e componentes para conexão
- Biblioteca Adafruit NeoPixel

## Configuração dos pinos

| Componente | Pino | Quantidade |
|---|---:|---:|
| Fita NeoPixel 1 | 10 | 10 LEDs |
| Fita NeoPixel 2 | 8 | 12 LEDs |
| Fita NeoPixel 3 | 9 | 12 LEDs |
| Sensor 1 | 2 | - |
| Sensor 2 | 3 | - |
| Sensor 3 | 4 | - |
| Sensor 4 | 5 | - |
| Sensor 5 | 6 | - |

## Temporizador

O tempo padrão de iluminação é de **2 minutos (120 segundos)**.

Para testes, o código também permite utilizar:

- 10 segundos
- 30 segundos
- 1 minuto
- 2 minutos

## Biblioteca

O projeto utiliza a biblioteca **Adafruit NeoPixel** para controlar as fitas de LED.

## Objetivo

O objetivo é criar uma solução simples de automação que reduza o uso desnecessário de iluminação, ativando as luzes somente quando houver movimento próximo ao estacionamento.

## Autor

**Gabriel Vidal**

Projeto acadêmico desenvolvido para estudo de Arduino, automação e sistemas embarcados.

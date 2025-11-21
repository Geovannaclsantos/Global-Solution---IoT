# Global-Solution---IoT
FIAP – IoT + ESP32 + Wokwi + MQTT

# Sobre o Projeto
Este projeto apresenta uma **Sala de Capacitação Inteligente**, criada para melhorar ambientes de aprendizagem em comunidades rurais por meio de uma solução IoT acessível.

A proposta faz parte da iniciativa **Raiz Digital**, que busca fortalecer o futuro do trabalho no agronegócio por meio de tecnologias simples, sustentáveis e úteis.

Problema
Muitos espaços utilizados para capacitações rurais (salas comunitárias, galpões, associações de produtores) apresentam **iluminação inadequada**.

Isso prejudica:

- aprendizado  
- conforto  
- segurança  
- produtividade  

A falta de infraestrutura adequada afeta diretamente o desenvolvimento profissional no campo.

## Solução
Criamos um sistema com **ESP32 + sensor LDR + LED + MQTT** que:

- Detecta automaticamente o nível de luminosidade do ambiente  
- Acende a “lâmpada” quando o local está escuro  
- Apaga quando há luz natural suficiente  
- Envia os dados via **MQTT**, permitindo monitoramento remoto

Trata-se de uma solução simples, de baixo custo, e que melhora imediatamente as condições de ensino e trabalho.

## Lógica do Sistema

1. O sensor **LDR** mede a intensidade da luz no ambiente.  
2. O ESP32 interpreta o valor analógico (0–4095).  
3. Se o valor estiver abaixo de um limite → **LED liga** (ambiente escuro).  
4. Se estiver acima → **LED desliga** (ambiente claro).  
5. A cada 2 segundos, os dados são enviados via **MQTT** em formato JSON.

## Componentes utilizados

- ESP32 DevKit V1  
- Sensor de Luz LDR  
- Resistor 10kΩ (divisor de tensão)  
- LED  
- Resistor 220Ω  
- Broker MQTT público  
- Simulador Wokwi  

##  Comunicação MQTT

**Broker:** `test.mosquitto.org`  
**Porta:** `1883`  
**Tópico:**  


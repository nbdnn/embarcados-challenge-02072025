# 🚗 Bem-vindo(a) ao Desafio de Testes do Time de Embarcados - AgTech  

**AgTech** é sinônimo de inovação e excelência tecnológica. No time de embarcados, trabalhamos com sistemas críticos que demandam precisão, segurança e performance. Este repositório foi criado para avaliar suas habilidades técnicas em depuração e análise de código em sistemas embarcados.  

## 🎯 Objetivo do Desafio  

Seu desafio será analisar o código fornecido e identificar **7 erros**, que podem ser de **lógica** ou de **regra de negócio**, relacionados ao funcionamento de um motor de carro.  

### 🛠️ Cenário Simulado  

O motor de um carro segue as seguintes regras:  
1. **RPM não pode ser negativo**: O conceito de RPM (rotações por minuto) está associado ao movimento do virabrequim, impulsionado pela queima de combustível e pelo movimento do veículo. RPM negativo não é válido.  
2. **Sequência lógica de operação do motor**:  
   - O motor só pode ser **ligado** quando o veículo estiver **desligado**.  
   - O motor só pode ser **desligado** quando já estiver **ligado**.  
3. **Limite de RPM**: O RPM máximo permitido é de **10.000 RPM**. Valores acima disso podem causar danos severos ao motor.  
4. **Registro de mudanças de velocidade**: Após desligar o motor, o sistema deve listar todas as mudanças de velocidade que ocorreram enquanto o motor estava ligado.  

Seu papel será garantir que o código atenda a essas regras e funcione corretamente.  

## ✅ Critérios de Avaliação  

Os seguintes pontos serão avaliados:  
1. **Capacidade de análise**:  
   - Precisão na identificação de erros no código.  
   - Capacidade de compreender e corrigir problemas em lógica ou regras de negócio.  

2. **Clareza na explicação**:  
   - Documentação clara, objetiva e bem estruturada no arquivo `RESULTADOS.md`.  

3. **Sugestões de melhoria**:  
   - Correções consistentes e alinhadas às boas práticas de programação.  

4. **Atenção aos detalhes**:  
   - Identificação correta dos erros descritos no cenário.  
   - Respeito às regras de negócio apresentadas.  

5. **Engajamento extra** (opcional):  
   - Caso tenha sugestões adicionais de melhoria ou incrementos no código, esses serão bem-vindos!  

## 🌟 Boa sorte!  

Mostre todo o seu potencial técnico e atenção aos detalhes. Estamos ansiosos para ver sua solução e aprender com suas ideias! 🚀

## Reposta

Obrigado pelo desafio!

### Erro 1
Local do erro: ```Motor::aumentarRpm(int rpm_int)```

```else if (rpms_int > 10000)```

Erro no nome da variável

### Erro 2
Local do erro: ```Motor::diminuirRpm(int rpm_int)```

```if (rpm_int < -1000)```

RPM nao pode ser negativo e não que não pode ser menor que -1000

### Erro 3
Local do erro: ```Motor::diminuirRpm(int rpm_int)```

```while (1){};```

Esse loop infinito vai fazer a aplicação ficar presa aqui sem dar um erro para ser tratado

### Erro 4
Local do erro: ```Motor::diminuirRpm(int rpm_int)```

```else if (rpm_int > 100000)```

10000 é o valor de RPM máximo, esse erro é comum quando temos duplicação de código

### Erro 5
Local do erro: ```Carro::diminuirRpmCarro(int rpm_int)```

Faltou um return na verificação se o motor está ligado

### Erro 6
Erro de lógica

Em ```Carro::aumentarRpmCarro(int rpm_int)``` e em ```Carro::diminuitRpmCarro(int rpm_int)``` temos a linha
```rpmAtual_int -= rpm_int;```
que sem nenhuma verificação prévia já atualiza o valor da rpmAtual_int sem nem sabermos se é possível mudar para o valor de RPM em questão. Logo adicionei uma verificação prévia nas duas.

Essas verificações em lugares diferentes criam um problema quanto às boas práticas de programação, pois temos muito código duplicado. E se essas verificações mudarem, temos que alterar em vários lugares

### Erro 7
Local do erro: ```Carro::exibirRegistros()```

```if (i < 4)```

Deve listar todas as mudanças


### Observações

Criei um pequeno código com algumas alterações que acredito que se eu refatorasse esse código eu faria. Inclui traduzir para inglês e refatorar os métodos de mudança de rpm da classe do motor (Power) para um único método de alteração do valor de rpm e nesse método ele já retornaria se foi um sucesso ou não essa alteração. Utilizo isso nos métodos da classe do carro (Car) para atualizar o atributo que contém o valor de rpm atual do motor apenas se a mudança foi um sucesso.

Poderia escrever aqui que para projetos maiores a utilização de cmake para compilar e aplicar os testes unitários, a partir dos arquivos Makefile é importante, mas nesse caso em um projeto simples, isso não é interessante, já que comprometeria mais tempo de desenvolvimento do que teria de benefício.
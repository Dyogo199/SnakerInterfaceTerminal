
# 🐍 SnakeInterfaceTerminal 🎮

Bem-vindo ao **SnakeInterfaceTerminal**, uma versão emocionante do clássico jogo Snake, desenvolvida em **C** com a biblioteca **PDCurses**! Este projeto utiliza a biblioteca PDCurses para criar uma interface no terminal que funciona perfeitamente em sistemas Windows. Aqui você encontrará diversão, desafios e um ótimo aprendizado sobre desenvolvimento de interfaces no console!

---

## 📚 **Sobre o Projeto**

Este projeto é uma versão totalmente funcional do jogo Snake, com os seguintes recursos:
- **Interface no Terminal**: Totalmente interativa com suporte à biblioteca **PDCurses**.
- **Níveis de Dificuldade**: Escolha entre fácil, médio e difícil.
- **Obstáculos**: Torne o jogo mais desafiador com barreiras no mapa.
- **Placar Persistente**: O jogo registra a maior pontuação em um arquivo de histórico.

---

## 🛠️ **Tecnologias e Bibliotecas Utilizadas**

### **Linguagem de Programação**
- **C**: Utilizamos a linguagem C para sua simplicidade, velocidade e controle direto sobre o hardware.

### **Biblioteca PDCurses**
- **PDCurses** é uma alternativa ao **ncurses** que oferece suporte ao Windows, permitindo a criação de aplicativos baseados em texto com funcionalidades gráficas no terminal.
- Ele fornece recursos para:
  - Manipulação de janelas no console.
  - Controle de entrada do teclado.
  - Manipulação de cores e caracteres.

Você pode saber mais sobre a PDCurses em: [Site Oficial do PDCurses](https://pdcurses.org/).

---

## 🚀 **Como Executar o Projeto**

### **1. Pré-requisitos**
- Instale o compilador **MinGW** no Windows, se ainda não o tiver:
  - Baixe e instale o MinGW: [MinGW Download](https://sourceforge.net/projects/mingw/).
  - Certifique-se de que o **gcc** e o **mingw32-make** estão no seu `PATH`.

- Baixe e configure a **PDCurses**:
  1. Acesse: [PDCurses Download](https://pdcurses.org/).
  2. Extraia o conteúdo em um diretório (ex.: `C:\MinGW\PDCurses-3.8`).
  3. Compile a biblioteca (ou use uma versão pré-compilada):
     ```bash
     cd C:\MinGW\PDCurses-3.8\PDCurses-3.8\wincon
     mingw32-make -f Makefile
     ```
  4. Certifique-se de que o arquivo **`pdcurses.a`** ou **`pdcurses.dll`** está disponível em:
     ```
     C:\MinGW\PDCurses-3.8\PDCurses-3.8\wincon
     ```

---

### **2. Clonar o Repositório**
Clone este repositório no seu computador:
```bash
git clone https://github.com/Dyogo199/SnakeInterfaceTerminal.git
cd SnakeInterfaceTerminal
```

---

### **3. Compilar o Jogo**
Compile o jogo usando o comando:
```bash
gcc -o snake_game main.c -I"C:\MinGW\PDCurses-3.8\PDCurses-3.8" -L"C:\MinGW\PDCurses-3.8\PDCurses-3.8\wincon" -lpdcurses
```

---

### **4. Executar o Jogo**
Após a compilação, execute o programa:
```bash
./snake_game
```

---

## 🎮 **Controles**
- **Setas do Teclado**: Controlam a direção da cobra.
- **Q**: Encerra o jogo.

---

## 🏆 **Destaques do Projeto**
- **Desafios Progressivos**: Níveis de dificuldade ajustáveis para jogadores iniciantes e experientes.
- **Código Modular e Educativo**: Ideal para aprendizado de programação em C e manipulação de interfaces no console.
- **Experiência Multiplataforma**: Compatível com diferentes terminais no Windows.

---

## 🛠️ **Possíveis Melhorias**
- Adicionar suporte a cores para um visual mais atraente.
- Criar níveis pré-definidos com layouts exclusivos.
- Implementar uma tabela de pontuação visual diretamente no jogo.

---

## 📄 **Licença**
Este projeto é distribuído sob a licença MIT. Sinta-se à vontade para explorar, modificar e compartilhar.

---

💡 **Desenvolvido por Dyogo** | Aproveite o jogo e divirta-se explorando os fundamentos do terminal e da linguagem C! 🚀
```

---

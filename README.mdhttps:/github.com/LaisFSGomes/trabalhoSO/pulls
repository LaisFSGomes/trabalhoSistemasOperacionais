# Trabalho de Sistemas Operacionais 2020.2

Professor: Danilo Alves Oliveira

Alunos: Lais de  Fátima Sousa Gomes (matrícula 504405) e Danilo Paiva Alves (matrícula 418121)


Questão 1: (1 pt) Faça um programa que leia um número “n” informado pelo usuário e diga quantos números primos há entre 0 e “n”. Esse seu programa deve rodar em 2 threads, de forma que o esforço computacional seja uniformemente dividido entre os threads.

Questão 2: (1 pt) Podemos calcular o seno de um número segundo a série de Taylor-Maclaurin:
𝑠𝑒𝑛(𝑥)=𝑥−𝑥33!+𝑥55!−𝑥77!+𝑥99!−⋯
Faça um programa em C que lê um valor para xe cálculo o valor de Sen (x) utilizando duas linhas para dividir os cálculos, uma para os termos com soma e outra para os com subtração. O valor deve ser calculado até ser próximo do seno.

Questão 03: (2 pt) Implemente os processos em ambiente Linux:
a) Crie um programa em C que demonstre uma hierarquia de processos com o comando fork( ) -> Pai -> Filho ->Filho1.
b) Crie um programa que receba parâmetros na chamada do main e mostre na saída metade dos parâmetros pelo processo pai e a outra metade pelo processo filho.

Questão 4: (Especial COVID) (2 pt) Desenvolva um algoritmo que simule o contágio do coronavírus de uma forma simples. Suponha que cada pessoa infectada possa infectar somente 4 pessoas ao seu redor e que não necessariamente existem pessoas próximas, isso depende da taxa de isolamento que o grupo de pessoas está seguindo. Os dados que você deve solicitar ao usuário são: tamanho do espaço amostral, taxa de isolamento e número de infectados iniciais.
O tamanho do espaço amostral deve ser uma matriz N x M, criada dinamicamente. A taxa de isolamento deve ser usada para calcular a quantidade de valores vazios presentes no espaço amostral, o valor vazio indica uma distância entre as pessoas. Utilize valor 1 na matriz para indicar as pessoas, valor 0 para indicar espaço vazio devido o isolamento e 2 para indicar contaminados. Por exemplo, suponha que você tem uma matriz 4 x 4 com taxa de isolamento de 0.40, isso indica que 40% dos valores dessa matriz são de espaços vazios, aproximando teríamos 6 espaços vazios e 10 pessoas nesse espaço amostral. A distribuição das posições de pessoas e espaços vazios na matriz deve ser feito de forma aleatória, respeitando as quantidades obtidas pela taxa de isolamento e tamanho da matriz. A quantidade de infectados iniciais diz
respeito ao inicio da contaminação dentro desse espaço, para facilitar limite ao máximo 4 infectados iniciais, a posição desses infectados deve ser obtida aleatoriamente. A contaminação deve ser feita por interações, sempre atualizando os valores da matriz a cada iteração. Cada infectado pode contaminar apenas as 4 pessoas ao seu redor em uma interação, as pessoas que foram contaminadas na interação anterior passam a contaminar as 4 próximas que estão ao seu redor e isso se repete ao longo das interações até infectar todos os possíveis de acordo com o isolamento. Por exemplo, suponha a matriz 5 x 5 abaixo com taxa de isolamento de 0.4 e com somente um infectado inicial:
Observe que são apresentados nas matrizes os infectados (vermelho) e seus vizinhos que serão infectados na próxima interação (verde). Observe também que a presença dos espaços vazios 0 impedem a propagação da contaminação, evitando o contato entre as pessoas na matriz. Em cada iteração devem ser verificados os 4 vizinhos de cada infectado, buscando os próximos a serem contaminados na iteração seguinte e isso prossegue até atingir o máximo possível. Suponha um contaminado na posição (i, j), na próxima iteração os contaminados serão as posições (i+1, j), (i, j-1), (i-1, j) e (i, j+1) que tenham valores 1.
O programa finaliza quando não tiverem mais infectados em uma iteração e deve ser apresentado na saída o print das matrizes em cada iteração e quando finalizar o resumo da infecção: Espaço amostral simulado, taxa de isolamento, quantidade de infectados iniciais, porcentagem da população contaminada ao final, porcentagem da população saudável e quantidade de iterações que foram precisas.
Obs: O programa deve utilizar threads para resolução. Deixarei livre para utilizarem a criatividade de como aplicar threads nessa problemática

Questão 5: (2 pt) Crie um programa em C que apresente duas funções para threads (produtor e consumidor), nesse devem ser criadas a quantidade de threads definidas por uma variável global QTD e utilizar outra variável global chamada “valor”. O produtor só pode produzir um número se essa variável tiver sido consumida (valor=0), quando ele for produzir é atribuído um número aleatório a variável “valor”. O consumido só pode consumir um número, se ele já tiver sido produzido (valor≠0), quando ele consome é atribuído valor=0. O programa deve seguir as seguintes especificações:
- A função produtor e consumidor devem receber o id da thread como parâmetro no momento de sua criação.
- O produtor deve produzir um número aleatório menor que 100 e armazenar na variável “valor”. Após produzir esse número deve apresentar a mensagem "produtor
%d: produziu %d", onde o primeiro campo é o id da thread e o segundo é o valor aleatório que foi obtido.
- Essa mensagem e o processo de obtenção do valor devem estar dentro do loop do produtor, logo a verificação da variável "valor" deve ser dentro do loop. Utilize um valor alto para o número de iterações nesse laço de repetição.
- Ao sair do loop, seja do produtor ou consumido, finalize a thread.
- O consumidor deve apresentar a mensagem "consumidor %d: consumiu %d", onde o primeiro campo é o numero do processo e o segundo é o valor da variável compartilhada "valor", que foi produzido aleatoriamente pelo processo produtor.
- Essa mensagem deve está dentro do loop do consumidor, logo a verificação da variável "valor" deve ser dentro do loop.
- Caso a variável "valor" seja diferente de zero, então ele apresenta essa mensagem, e deve alterar o valor da variável "valor" para zero (valor=0).
- Crie 4 pares de threads com esses processos (4 threads para consumidores e 4 threads para produtores).
- Execute os threads algumas vezes, observe as saídas e responda as observações:
3.1-Por que alguns consumidores consumiram mais de uma vez em seguida o mesmo número?
3.2-Por que o consumidor consumiu um determinado número, mas o produtor só o produziu depois?
3.3-Tirando o fato de ser gerado números aleatórios, por que a execução sempre ocorre em ordem diferente?

Questão 6: (2 pt) Implemente uma simulação para os algoritmos de escalonamento SJF e Round Robin em C. Em sua implementação o usuário deve fornecer a quantidade de processos que estão na fila para serem executados, a ordem de chegada e o tempo de execução de cada processo. Durante a execução deve ser informado ao usuário qual o processo que está executando e esperado o tempo de cada processo por segundo. Por exemplo, se um processo A demora 5 segundos, deve ser informado que ele está sendo trabalhado e esperado o tempo de execução deste para poder iniciar o próximo, para isso utilize um temporizador em seu algoritmo.

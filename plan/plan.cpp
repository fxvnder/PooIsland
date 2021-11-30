/*

Utilizar Framework Qt (valoriza-se)

 -ILHA:
	-Geração:
	    retangular, feita por quadriculas(zonas)
		tamanho init definido pelo utilizador, minimo 3*3, max 8*16
		Pelo menos 1 zona de cada tipo
		distribuição de tipos de zona equilibrada
	-Zonas
		Máximo 1 edifício por zona
		Tipos:
			-> Deserto. São dunas de areia. Permite a construção de qualquer tipo de edifícios. No entanto, as minas sofrem uma redução de 50% de produção por causa dos aluimentos (areia solta). 
			-> Pastagem. Aceita qualquer tipo de edifício. Os funcionários que se encontrem aqui nunca pedem a demissão dado que a paz da paisagem reduz o stress. 
			-> Floresta. Tem um conjunto inicial de árvores, decidido aleatoriamente entre 20 e 40 árvores. A cada dois dias cresce uma nova árvore, até ao máximo de 100. A floresta produz 1 kg de madeira por cada lenhador que se encontra nessa zona. A madeira cortada fica armazenada ao ar livre sem limite de quantidade. Se forem construídos edifícios numa zona do tipo floresta, morrerá uma árvore por dia e não crescem novas árvores.
			-> Montanha. Aceita qualquer tipo de construção, no entanto o preço de construção é o dobro do normal. As minas aumentam a produção em 100%. As montanhas têm a caraterística interessante de produzirem espontaneamente ferro a 0.1 Kg por dia por cada funcionário que lá se encontre, independentemente do seu tipo. Este ferro extra fica armazenado na própria zona e não tem limite (fica ao ar livre). Dado que andam sempre vergados a apanhar pepitas de ferro, a probabilidade destes trabalhadores pedirem demissão aumenta em mais 5%, e até os lenhadores (se lá estiverem) são afetados. 
			-> Pântano. Aceita qualquer tipo de edifício, que têm o custo normal e produzem normalmente. No entanto, passados 10 dias, o edifício afunda-se e desaparece. Os funcionários que lá se encontrem pedem a demissão passados esses mesmos 10 dias (se não for antes pelas suas próprias razões, conforme o seu tipo). Um pântano é realmente pouco interessante, mas existe e é tão obrigatório como os outros.
			-> Zona-X. Tem as caraterísticas e comportamento que cada grupo entender. Zonas-X repetidas em grupos diferentes é o mesmo que pedir para ir ver o que se passa nesses grupos com uma lupa.
	Dias:
		Amanhecer:
			acontecem os efeitos dos vários tipos de zona.
		Meio Dia:
			Jogador expressa suas ordens, como:
				-ligar/desligar edificios
				-construir edificios
				-vender recursos
				-movimentar trabalhadores
		Anoitecer
			Faz-se a recolha dos recursos obtidos (minados, transformados, etc.), já considerando os trabalhadores nas zonas para onde tenham sido movidos nas ordens do meio-dia, assim como os edifícios que tenham sido construídos nessa altura

	-Trabalhadores:
		Todos ( to do? xD) os trabalhadores estarão inicialmente numa zona tipo pasto

		Identificação única:  Número.day
		Tipos:
			-> Operário: Bom para operar fundições e centrais elétricas. Custa 15 € para contratar. Tem 5% de probabilidade por dia de se cansar e ir embora, mas só a partir do 10o dia após ter sido contratado.
			-> Lenhador. Só serve para cortar árvores. Custa 20 €. Trabalha 4 dias e descansa 1 (e depois repete). Nos dias em que descansa, é como se não existisse (o que estiver dependente do seu trabalho não funciona / não produz / não tem efeito). Dado o descanso e o trabalho ao ar livre, em princípio não se despede.
			-> Mineiro. Seve para escavar a terra em minas. Custa 10 €. Dada a vida desgraçada que leva tem uma probabilidade de se ir embora de 10% em cada dia e logo a partir do segundo dia na ilha.

	-Recursos:
		Podem ser:
			armazenados
			transformados em outros recursos
			vendidos
			usados em construções
		Tipos:
			-> Ferro - Pode ser obtido do solo da ilha através de uma mina. Pode ser vendido por 1 € por kg.
			-> Barra de aço -  Pode ser obtido através da transformação de ferro e carvão. 1.5 kg de ferro e 0.5 kg de carvão dão origem a um 1 barra de aço. Pode ser vendido por 2 € por kg.
			-> Carvão. Pode ser obtido a partir da ilha através de uma mina. Também pode ser obtido pela transformação de madeira em carvão: 1 kg de madeira dá origem a 1 kg de carvão. Pode ser vendido por 1 € por Kg.
			-> Madeira. Extraída das florestas da ilha. Pode ser vendida por 1 € por kg de madeira
			-> Vigas de madeira. Pode ser obtida por transformação de madeira numa serração. 2 kg de madeira dão origem a 1 viga. Pode ser vendida por 2 € por viga.
			-> Eletricidade. Obtida por queima de carvão. Pode ser vendida por 1.5 € por KWh. 1 kg de carvão dá origem a 1 KWh de electriidade
	-Edifícios:
		Quando construidos estão desligados, pode ser ligados e desligados pelo jogador
		Tipos:
			-> Mina de ferro. Permite obter ferro. Pode ser construída gastando 10 vigas de madeira, em que cada viga pode ser substituída por 10 €. Produz 2 Kg de ferro por dia. Pode ser melhorada até ao nível 5 em que cada nível aumenta a produção em 1 kg de ferro por dia. Cada nível de melhoramento exige 15 € e 1 viga de madeira (não substituível por €). A mina apenas produz se existir um mineiro na zona em que a mina se encontra. Em cada dia a mina tem 15% de probabilidade de desabar. A mina de ferro armazena até 100 kg de ferro, mais 10 Kg por cada nível adicional. Depois disso, pára de produzir. 
			-> Mina de carvão. Permite obter carvão. Pode ser construída gastando 10 vigas de madeira, em que cada viga pode ser substituída por 10 €. Produz 2 Kg de carvão por dia. Pode ser melhorada até ao nível 5 em que cada nível aumenta a produção em 1 kg de carvão por dia. Cada nível de melhoramento exige 10 € e 1 viga de madeira (não substituível por €). A mina apenas produz se existir um mineiro na zona em que a mina se encontra. Em cada dia a mina tem 10% de probabilidade de desabar. A mina de carvão armazena até 100 kg de carvão, mais 10 Kg por cada nível adicional. Depois disso, pára de produzir.
			-> Central elétrica de biomassa: Queima madeira, produzindo carvão e eletricidade. A central elétrica transforma 1kg de madeira em 1 kg de carvão mais 1 KWh de eletricidade por dia, desde que se encontre um operário na zona em que se encontra. A central pode armazenar o carvão produzido até 100 kg de carvão. A eletricidade ficará armazenada numa bateria que se encontre numa zona adjacente, caso contrário perde-se. Para funcionar, a central elétrica tem que estar numa zona adjacente a uma zona do tipo floresta, sendo a madeira obtida a partir da madeira que tenha sido cortada e depositada nessa zona de floresta. Custa 15 €. 
			-> Bateria: é um edifício que consiste num enorme bloco de lítio que armazena eletricidade. Tem capacidade de 100 KWh. Custa 10 € e 10 vigas. Adquire automaticamente a energia produzida nas centrais elétricas que estejam colocadas em zonas adjacentes. Pode ser melhorado até ao nível 5 por mais 5 € cada nível 
			-> Fundição. Permite obter aço a partir de ferro e carvão. Para funcionar é necessário que a zona em que se encontre seja adjacente a uma zona que tenha uma mina de ferro e a uma mina de carvão ou a uma central elétrica (por causa do carvão). Precisa também de ter um operário na sua zona. Custa 10 €. 
			-> Edifício-X. Tem as caraterísticas e comportamento que cada grupo entender. Em princípio não há repetição de edifícios-X entre grupos diferentes, pois isso seria mesmo muito estranho. 


Jogo acaba quando
	O jogador quiser
	Jogador perdeu todos recursos/Trabalhadores

interface:
Representação Ilha:
	A ilha deve estar toda no ecrã
	É necessário indicar o conteúdo das várias zonas. Utilize as abreviaturas e códigos indicados:
		pnt –> Montanha
		dsr -> Deserto
		pas -> Pastagem
		flr -> Floresta
		pnt -> Pântano
		znZ -> ZonaX
		mnF -> Mina de ferro
		mnC -> Mina de carvão
		elec -> Central elétrica
		bat -> Bateria
		fun -> Fundição

		1a linha: tipo de zona.
		2a linha: edifício (se houver).
		3a linha: trabalhadores na zona (O = Operário, M =Mineiro, L = Lenhador). Nesta representação só cabem 4, mas podem estar mais nessa zona, tal como indicado na 4a linha.
		4a linha número total de trabalhadores na zona.
		
	Exemplo interface:  ┐┌├ ┬ ─│
	  1    2    3    4    5
	┌────┬────┬────┬────┬────┐
	│flr │pas │pan │flr │mnt │
   1│    │elec│    │    │mnF │
	│LO  │    │    │    │    │
	│2   │    │    │    │M   │
	├────┼────┼────┼────┼────┤
	│pas │dsr │mnt │flr │mnt │
   2│    │bat │    │    │    │
	│    │O   │    │L   │    │
	│    │1   │    │1   │    │
	├────┼────┼────┼────┼────┤
	│znX │mnt │pnt │dsr │mnt │
   3│    │mnC │    │    │    │
	│    │M   │    │    │M   │
	│    │1   │    │    │1   │
	├────┼────┼────┼────┼────┤
    │mnt │pas │znX │pas │flr │
   4│    │    │    │    │    │
	│    │    │    │OOOO│    │
	│    │    │    │5   │    │
	└────┴────┴────┴────┴────┘
Sumários:
	Sumário sempre presente sobre situação do jogo:
		Contém:
			-> Dia 
			-> Quantidade de Reursos
			-> Trabalhadores Existentes
			-> etc
	Sumário ao fim de cada dia:
		-> Dia de simulação e riqueza acumulada
		-> Quantidade de recursos e lista de quais existem
		-> Quantidade de trabalhadores e lista de quais existem

Ordens Utilizador:
	Dadas textualmente como comandos e argumentos,
	Pode escrever em minusculas ou maiusculas e funciona
	Ex:
		cons minaferro 3 5  (constroi edificio tipo mina de ferro na zona 3,5)
	Comandos:
		● exec <nomeFicheiro> Executa um conjunto de comandos existentes em nomeFicheiro. Esse ficheiro tem os comandos, um por cada linha, segundo a mesma sintaxe como quando são escritos diretamente no teclado.
		● cons <tipo> <linha> <coluna> Constrói um edifício de um dado tipo na zona posicionada na linha e coluna. Nesta zona não poderá haver outro edifício e as condições necessária para a construção do tipo de edifício deverão ser observadas na altura de execução do comando. Tipo = minaf | minac | central | bat | fund | edx (abreviaturas baseadas nos nomes dos recursos em minúsculas e sem letras acentuadas).
		● liga <linha> <coluna> Liga o edifício (caso exista) que está construído na zona posicionada na linha e coluna.
		● des <linha> <coluna> desliga o edifício (caso exista) que está construído na zona posicionada na linha e coluna.
		● move <id> <linha> <coluna> Move o trabalhador com o identificador id para a zona posicionada na linha e coluna.
		● vende <tipo> <quanto> Vende recursos de um dado tipo e de acordo com quanto se pretende vender (de acordo com a unidade de cada recurso). Tipo = ferro | aco | carvao | mad | viga | eletr (abreviaturas baseadas nos nomes dos recursos em minúsculas e sem letras acentuadas).
		● cont <tipo> Contrata um trabalhador de um dado tipo e este, tal como dito anteriormente, vai para a zona de pasto à espera de ordens do jogador. Tipo = oper | len | miner (abreviaturas baseadas nos nomes dos recursos em minúsculas e sem letras acentuadas).
		● list <linha> <coluna> Obtém a informação do jogo, globalmente se não for indicada nenhuma linha.coluna, ou detalhada acerca de uma zona caso a sua posição linha coluna seja indicada. 
		● vende <linha> <coluna> Vende o edifício existente na zona indicada na linha e coluna especificadas. Recupera os € gastos na sua construção mas não os recursos adicionalmente usados (exemplo, as vigas na mina). Os recursos armazenados no edifício em questão são automaticamente vendidos e os € resultantes passam para o jogador. 
		● next Termina a fase de recolha de comandos e desencadeia as ações necessárias ao seu processamento.
		● save <nome> Grava o estado do jogo em memória, associando-lhe um nome. Esta ação consiste em fazer uma espécie de savegame para memória, possibilitando ao jogador manter em memória diversos snapshots do jogo, correspondentes a diversos momentos, permitindo-lhe a qualquer momento recuperar um desses momentos. O jogo continua ativo, mas a cópia feita para memória já não será afetada pelos comandos entretanto escritos a partir deste momento.
		● load <nome> Recupera um dado estado do jogo em memória, identificado ao nome indicado, e carrega-o. O jogo recuperado passa a ser o que está em efeito: os comandos passam a agir sobre este. 
		● apaga <nome> Apaga um determinado savegame de memória.
		● config <ficheiro> Lê o ficheiro de texto e extrai dele os preços de contratação dos trabalhadores e de compra dos edifícios. São configurados apenas os valores base de € e não os números de recursos adicionais (ex.: número de vigas para a mina). Os valores lidos sobrepõe-se aos indicados no enunciado, que apenas são considerados enquanto não for lido um ficheiro de configuração 
			● O ficheiro tem o conteúdo em que cada linha tem duas palavras separadas por um espaço: nome da coisa (edifício ou trabalhador) e preço (apenas aparte dos €). Os nomes são os mesmos usados nos comandos de contratação e de construção. Exemplo:
				-> minaclen 12
				-> 15
		● debcash <valor> Adicina a quantidade de € especificada em valor. A quantidade pode ser positiva (adicionar) ou negativa (remove. Serve para debug e teste.
		● debed <tipo> <linha> <coluna> Adiciona um edifício a custo zero na zona linha, coluna, respeitando as restrições de não poder haver mais do que um edifício na zona. Serve para debug e teste.
		● debkill <id> Remove o trabalhador com a identificação id. Serve para debug e teste.

Implementação:
	-> A ilha deve representada de forma dinâmica, ou seja, não se vai construir um espaço (estrutura de dados) a contar com o tamanho máximo e depois usar apenas uma parte (aceita-se apenas na meta 1)
	-> A estrutura de dados da ilha (para guardar as zonas) não deve usar coleções da STL. 


Metas e entregas: 
Meta1 - Prazo: 23 de novembro
    ● Leitura do ficheiro de configuração.
	● Construção inicial da ilha. Deve ter em atenção que a representação da ilha irá ser melhorada com matéria dada posteriormente e agora só se pretende algo que possa ser representado no ecrã. 
		● Pode implementar a ilha (apenas na meta 1) através de uma estrutura de dados de tamanho fixo (por exemplo, considerando um tamanho máximo mesmo que depois a ilha seja mais pequena)
	● Considere uma representação simplificada para as zonas sabendo que vai modificar essa parte da implementação quando for dada mais matéria 
	● Representação visual da ilha e conteúdo incluído nesta meta (ver bullets seguintes).
	● Nesta meta não são considerados os recursos. 
	● Implementação da leitura e validação de todos os comandos, seja por teclado, ou seja por leitura do ficheiro de comandos. Os comandos não farão ainda nada, mas devem ser já interpretados e validados.
	● Construção de edifício do tipo minaferro através de comandos (cons), tanto pelo teclado como por ficheiro (comando exec)
	● Contratação de mineiros (comando cont), tanto pelo teclado como por ficheiro (comando exec) 
	● Visualização dos dados do jogo e de zonas (comando list ) 
	● O projeto já deverá estar devidamente organizado em .h e .cpp separados.

	● Relatório – Nesta meta o relatório é simplificado, mas deve incluir a descrição das opções tomadas e a descrição das estruturas usadas. Deve também dar uma indicação da estruturação do trabalho em termos de classes (quais, para que servem / o que representam e qual a relação entre elas)

Meta 2 – Prazo: 16 de janeiro
	Objetivos: o programa completo, com relatório.
	
			
*/


/*
 -funcao run
    -chama class da ilha
        - criar vetor de vetores de classes tile
    -days()
 -funcao days
    while (gameover != true){
        print_island()
        amanhecer()
        jogador_joga()
        anoitecer()
    }

    class tile{

    }
 */
    // chooseDimensions();
/*
int main(){
    Jogo j; // Dados
    UserInt ui(j); // user interface (comandos)
    ui.run();

    //professor diz que é imprescindivel separar a parte dos dados e da ui
}

 Como se usa e para quê que se usa o new
Deve-se fazer as funções de cont e cons nod objetos ou como funções normais que passas o mundo normalmente?
*/

// Testing new branch alright 👍
// Compiling on surface 👍

/*
Todo:
 1-Make vetors into arrays
 2-Read a text file too
 3-Change the structure of the program to:
    Jogo j; // Dados
    UserInt ui(j); // user interface (comandos)
    ui.run();
 5-typeid(a).name() ???
 6-make file?: g++ -Wall -Wextra -Error         Kylix: cFlags = -Wall -Werror -Wextra

 Dizer ao founder:
    Não use cin >> str
    use getline(cin,str)
    e getNumber se quiser um numero.
    Evita de poluir o buffer que isso já deu muito problema

 Perguntar ao durães:
 alguma diferença entre
    if
        cout << "hello"
ou
    if {
        cout << "hello"
    }


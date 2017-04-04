public class Poker {
	public static void main(String[] args) {
		int aposta;
		String s = new String();
		System.out.println("BEM-VINDO A VIDEO POKER SIMULATOR 2017: DELUXE VERSION\n\n")
		
		while(temFicha()==true){
			System.out.printf("Voce tem %d fichas\n", qtdFichas());
			System.out.println("Para iniciar uma nova rodada, digite sua aposta\n");
			aposta = EntradaTeclado.leInt();
			//Gera 5 cartas aleatorias
			//Imprime as cartas
			System.out.println("Selecione as cartas que deseja trocar\n");
			s = EntradaTeclado.leString();
			//Gera x cartas aleatorias
			//Imprime as cartas
			System.out.println("Selecione as cartas que deseja trocar\n");
			s = EntradaTeclado.leString();
			//Gera x cartas aleatorias
			//Imprime as cartas
			//comb = Checa combinacao
			//Imprime combinacao
			//Imprime qtd de fichas ganhas
			premio(aposta, comb);
		}
	}
}

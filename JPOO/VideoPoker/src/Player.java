public class Player {
	int fichas = 200;
	
	public int qtdFicha(){
		return fichas;
	}
	
	public void aposta(int n){
		while(n>fichas){
			System.out.printf("Voce nao tem fichas suficientes: Suas fichas %d", fichas);
			//n = EntradaTeclado.leInt();
		}
		fichas = fichas - n;
	}
	
	public void  premio(int n, int comb){
		switch(comb){
			//Dois pares
			case 1: fichas = fichas + n*1; 
					break;
			//Trinca
			case 2: fichas = fichas + n*2; 
					break;
			//Sequencia
			case 3: fichas = fichas + n*5; 
					break;
			//Flush
			case 4: fichas = fichas + n*10; 
					break;
			//Full house
			case 5: fichas = fichas + n*20; 
					break;
			//Quadra
			case 6: fichas = fichas + n*50; 
					break;
			//Straight Flush
			case 7: fichas = fichas + n*100; 
					break;
			//Royal Straight Flush
			case 8: fichas = fichas + n*200; 
					break;
		}
	}
	
	public Boolean temFicha(){
		Boolean b;
		if(fichas > 0){
			b = true;
		} else {
			b = false;
		}
		return b;
	}
}

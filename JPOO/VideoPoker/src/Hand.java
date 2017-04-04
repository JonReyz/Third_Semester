
public class Hand {
	int nCards;
	Carta [] cards;
	Carta [] changed;
	int nChange;
	
	
	public Hand(int n){
		nCards = n;
		cards = new Carta[n];
		
	}
	
	public void makeHand(){
		int value;
		int naipe;
		Random r = new Random();
		boolean isValid = false;
		while(!isValid){
			for(int i =0;i<nCards;i++){
				cards[i].value = r.getIntRand(13) + 1;
				cards[i].naipe = r.getIntRand(4)  + 1;
			}
			isValid = verificadorDeMao(cards);
		}
	}
	
	public void ChangeHand(){
		boolean isValid = false;
		Random r = new Random();
		while(!isValid){
			for(int i =0;i<nCards;i++){
				cards[i].value = r.getIntRand(13) + 1;
				cards[i].naipe = r.getIntRand(4)  + 1;
			}
			isValid = verificadorDeMao(cards);
		}
	}
	
	private void zeroying(int[] vet, int n){
		for(int i=0;i<n;i++){
			vet[i] = 0;
		}
	}
	
	private boolean verificadorDeMao(Carta[] cards){
		int[] nFreq = new int[4];
		int[] cFreq = new int[13];
		
		zeroying(nFreq,4);
		zeroying(cFreq,12);
		
		int i;
		
		for(i=0;i<nCards;i++){
			nFreq[cards[i].getNaipe() - 1]++;
			cFreq[cards[i].getValue() - 1]++;
		}
		
		for(i=0;i<4;i++){
			if(nFreq[i]>1) return false;
		}
		for(i=0;i<13;i++){
			if(cFreq[i]>4) return false;
		}
		
		return true;
	}
	
	
	
	
}

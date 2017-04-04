
public class Carta {
	int value;
	int naipe;
	
	
	public Carta(int n, int naip){
		this.value = n;
		this.naipe = naipe;
	}
	
	public Carta(){
		this.value = -1;
		this.naipe = 0;
	}
	
	public int getValue(){
		return value;
	}
	
	public int getNaipe(){
		return naipe;
	}
	
}

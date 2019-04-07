public class Ex4 {
	public static void main(String[] args) {
		System.out.println(" +--------+--------+\n");
		System.out.println(" |   °„C   |   °„F   |\n");
		System.out.println(" +--------+--------+\n");
	     for(double i=0.0;i<=36.0;i+=2.0){
	    	 double  num= 32+(9/5.0)*i;
	    	 String  F=String.format("%.1f", num);
	    	 String  C=String.format("%.1f", i);
	    	 if(i<=8){
	    	 System.out.println(" |   "+C+"  |  "+F+"  |");}
	    	 else{
	    		 System.out.println(" |  "+C+"  |  "+F+"  |"); 
	    	 }
	     }
		
	}

}
		

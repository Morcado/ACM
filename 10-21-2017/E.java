package e;
import java.util.Scanner;
import java.util.ArrayList;
public class E {
    public static Scanner teclado = new Scanner(System.in);
    public static ArrayList<String> cadenas = new ArrayList<String>();
    public static void main(String[] args) {
        while(true){
            String n = teclado.nextLine();
            if(n.equals("."))
                break;
            else
               cadenas.add(n);
        }
    }
    public static void ordenaCadena(String cad){
        
    }
}

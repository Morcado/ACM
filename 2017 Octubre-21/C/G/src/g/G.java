
import java.util.ArrayList;
import java.util.Scanner;
public class G {
    public static ArrayList<Integer> primos = new ArrayList<Integer>();
    public static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {    
        int a, b;
        ArrayList<ArrayList<Integer>> arreglos = new ArrayList<ArrayList<Integer>>(); 
        while(true){
            a = scan.nextInt();
            b = scan.nextInt();
            if(a == 0 && b == 0)
                break;
            if(b > a)
            arreglos.add(obtenPrimos(a, b));
        }
        for(int i = 0; i < arreglos.size(); i++){
            
            if(arreglos.get(i).size() == 1){
                if(esPrimo(arreglos.get(i).get(0)))
                    System.out.println("NULL");
                else
                    System.out.println("NULL");
            }
            else
                System.out.println(mayorGap(arreglos.get(i)));
        }
    }
    public static ArrayList<Integer> obtenPrimos(int a, int b){  
        boolean []arr; 
        arr = new boolean[b+1];
        ArrayList<Integer> primos = new ArrayList<Integer>();
        for(int i = 2; i < arr.length; i++){
            arr[i] = true;
        } 
        for(int i = 2; i < arr.length; i++){ //primeros b primos
            if(arr[i])
                for(int j = i; j < arr.length; j+=i){
                    if(j!=i)
                        arr[j] = false;
                }               
        }
        for(int i = a; i < arr.length; i ++){
            if(arr[i]){
                primos.add(i);
            }
        }
        return primos;
    }
    public static int mayorGap(ArrayList<Integer> a){
        int mayor = 0;
        int n;
        for(int i = 0; i < a.size()-1; i++){
            n = -(a.get(i) - a.get(i+1));
            if(n > mayor){
                mayor= n;
            }
        }
        return mayor;
    }

    private static boolean esPrimo(Integer get) {
        int cont = 0;
        int i;
        for(i = 1; i < get; i ++){
            if(i%get == 0){
                cont++;
            }
        }
        if(cont == 2){
            return true;
        }
        return false;
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}

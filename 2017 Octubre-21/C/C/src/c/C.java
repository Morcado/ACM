package c;
import java.util.Scanner;
import java.util.ArrayList;

public class C {
    public static Scanner a = new Scanner(System.in);
    private static int x;
    private static int n;
    public static void main(String[] args)
    {
        ArrayList<double[]> arreglos = new ArrayList<double[]>();
        x = a.nextInt();
        for(int i = 0; i < x; i++){
            n = a.nextInt();
            arreglos.add(obtenCoeficientes(n));
        }
        for(int i = 0; i < arreglos.size(); i++)
            imprimeBinomio(arreglos.get(i), arreglos.get(i).length-1);
    }   
    public static double fact(double factor)
    {
        if(factor == 0)
            return 1;
        return factor*fact(factor-1);
    }
    public static void imprimeBinomio(double []coef, int n){
        int x = n;
        int y = 0;
        String cad = "";
        if(coef.length == 1){
            System.out.println(1);
        }
        else{
            for(int i = 0; i < coef.length; i++){
                if(coef[i]!=1)
                    cad+=(int)coef[i];
                if(x > 0){
                    if(x != 1)
                        cad += imprimeX()+ "^" + x;
                    else
                        cad += imprimeX();
                    x--;
                }
                if(y > 0){
                    if(y != 1)
                        cad += imprimeY()+ "^" + y;
                    else
                        cad += imprimeY();
                }
                y++;
                if(n > 0){
                    cad+="+";
                    n--;
                }
            }
            System.out.println(cad);
        }
        
    }
    public static String imprimeX(){
        return "x";
    }
    public static String imprimeY(){
        return "y";
    }
    
    public static double[] obtenCoeficientes(int n){
        double arr[] = new double[n+1];
        for(int i = 0; i < n+1; i++){
            arr[i] = fact(n)/(fact(i)*(fact(n-i)));
        }
        return arr;
    }
}

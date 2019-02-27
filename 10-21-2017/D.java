import java.util.Scanner;
import java.util.ArrayList;
public class D {
    public static double num;
    public static Scanner teclado = new Scanner(System.in);
    public static void main(String[] args) {
        // TODO code application logic here
        ArrayList<String> array = new ArrayList<String>();
        do{
            String num = teclado.nextLine();
            if(generaEntero(num.toCharArray()) != 0)
            {
                array.add(num);
            }
            else
                break;
        }while(true);
        for(int i = 0; i < array.size(); i++){
            char temp[] = array.get(i).toCharArray();
            while(true){
                int num = generaEntero(temp);
                String cad = "" + num;
                if(cad.length() == 1){
                    System.out.println(num);
                    break;
                }
                else
                    temp = cad.toCharArray();
            }
        }
    }
    public static int generaEntero(char[] cadena){
        int num = 0; 
        for(int i = 0; i<cadena.length; i++){
            num += cadena[i]-48;
        }
        return num;
    }
}

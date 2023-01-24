import java.util.*;

class RomanToInt{
    public int romanToInt(String roman) {
        int length = roman.length();
        int num = 0;
        for(int i=0;i<length;i++){
            int temp = value(roman.substring(i,i+1)),temp2 = 0;
            if(i+1 < length)
                temp2 = value(roman.substring(i+1,i+2));
            if(temp < temp2){
                num+= value(roman.substring(i,i+2));
                i++;
            }
            else{
                num+=temp;
            }
        }
        return num;
    }
    public static int value(String code){
        switch(code){
            case "I": return 1;
            case "IV": return 4;
            case "V": return 5;
            case "VI": return 6;
            case "IX": return 9;
            case "X": return 10;
            case "XL": return 40;
            case "L": return 50;
            case "XC": return 90;
            case "C": return 100;
            case "CD": return 400;
            case "D": return 500;
            case "CM": return 900;
            case "M": return 1000;
            default : return 0;
        }
    }
    public static void main(String []value){
        System.out.println("Number of Roman (XXLLM) is : "+ new RomanToInt().romanToInt("XXLLM"));
    }
}
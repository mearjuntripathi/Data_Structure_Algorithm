import java.lang.String;

class LinearSearch {
    
    public static int search(int arr[],int k){
        for(int i=0;i<arr.length;i++)
            if(arr[i] == k)
                return i;
        return -1;
    }

    public static void main(String []arjun){
        int arr[] = { 2, 3, 4, 10, 40 };
        int x = 10;

        int result = search(arr,10);
        if(result == -1){
            System.out.println("10 is not avilable in this array");
        }else{
            System.out.println("10 is avilable in this array at position: "+result);
        }
    }
}
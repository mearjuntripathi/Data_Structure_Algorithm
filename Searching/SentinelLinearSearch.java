class SentinelLinearSearch{

    public static int search(int arr[],int k){
        int n = arr.length;

        int last = arr[n-1];
        arr[n-1] = k;

        int i=0;
        while(arr[i] != k)
            i++;

        arr[n-1] = last;

        if((i < n-1) || (arr[n-1] == k)){
            return i;
        }
        return -1;
    }

    public static void main(String arg[]){
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
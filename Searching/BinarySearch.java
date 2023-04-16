class BinarySearch{

    public static int BinarySearch(int arr[],int l,int r,int k){
        if(l<r){

            if(arr[l] == k)
                return l;
            
            if(arr[r] == k)
                return r;

            int m = l + (r-l)/2;
            
            if(arr[m] == k)
                return m;
            
            if(arr[m] > k)
                return BinarySearch(arr,l,m-1,k);
            
            else
                return BinarySearch(arr,m+1,r,k);
        }
        return -1;
    }

    public static void main(String []arg){
        int arr[] = { 2, 3, 4, 10, 40 };
        int x = 10;

        int result = BinarySearch(arr,0,4,3);
        if(result == -1){
            System.out.println("10 is not avilable in this array");
        }else{
            System.out.println("10 is avilable in this array at position: "+result);
        }
    }
}
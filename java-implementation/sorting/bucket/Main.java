package sorting.bucket;

import java.util.Random;

public class Main {
    public static void main(String[] args) {
        int arr[] = new int[100];

        //Generating 100 random numbers in the range of 0-100
        Random random = new Random();
        for(int i=0;i<100;i++) {
            arr[i] = random.nextInt(100)+100;
        }

        BucketSort bs = new BucketSort(arr);
        System.out.println("Array before Sorting: ");
        bs.printArray();
        bs.bucketSort();


        System.out.println("\n\nArray after Sorting: ");
        bs.printArray();
    }
}

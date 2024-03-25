import java.util.Arrays;

public class OrderStatistic {
    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }

    public static void quicksort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quicksort(arr, low, pi - 1);
            quicksort(arr, pi + 1, high);
        }
    }

    public static int ithOrderStatistic(int[] arr, int i) {
        if (i < 0 || i >= arr.length) {
            throw new IllegalArgumentException("i is out of range");
        }
        quicksort(arr, 0, arr.length - 1);
        return arr[i];
    }

    public static void main(String[] args) {
        int[] arr = {12, 4, 67, 1, 89, 43, 27, 6, 54, 19};
        int i = 7;
        int result = ithOrderStatistic(arr, i);
        System.out.println("The " + (i + 1) + "th order statistic in the array " + Arrays.toString(arr) + " is " + result);
    }
}
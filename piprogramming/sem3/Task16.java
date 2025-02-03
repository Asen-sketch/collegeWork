package sem3;

import java.util.Arrays;

public class Task16 {
    public static void main (String args[]) {
        int[] arr1 = {1,2,3,4,5};
        int[] arr2 = {4,5,6,7,8};
        int[] uni = findUnion(arr1, arr2);
        int[] inter = findIntersec(arr1, arr2);
        System.out.println("uni: " + Arrays.toString(uni));
        System.out.println("inter: " + Arrays.toString(inter));
    }

    public static int[] findUnion(int[] arr1, int[] arr2) {
        Arrays.sort(arr1);
        Arrays.sort(arr2);

        int[] tempuni = new int[arr1.length + arr2.length];
        int index = 0;

        int i = 0, j = 0;
        while (i < arr1.length && j < arr2.length) {
            if (arr1[i] < arr2[j]) {
                tempuni[index++] = arr1[i++];
            } else if (arr1[i] > arr2[j]) {
                tempuni[index++] = arr2[j++];
            } else {
                tempuni[index++] = arr1[i];
                i++;
                j++;
            }
        }

        while (i < arr1.length) {
            tempuni[index++] = arr1[i++];
        }

        while (j < arr2.length) {
            tempuni[index++] = arr2[j++];
        }
        return Arrays.copyOf(tempuni, index);
    }

    public static int[] findIntersec(int[] arr1, int[] arr2) {
        Arrays.sort(arr1);
        Arrays.sort(arr2);

        int[] tempint = new int[Math.min(arr1.length, arr2.length)];
        int index = 0;

        int i = 0, j = 0;
        while (i < arr1.length && j < arr2.length) {
            if (arr1[i] < arr2[j]) {
                i++;
            } else if (arr1[i] > arr2[j]) {
                j++;
            } else {
                tempint[index++] = arr1[i];
                i++;
                j++;
            }
        }
        return Arrays.copyOf(tempint, index);
    }
}

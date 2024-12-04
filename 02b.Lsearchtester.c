
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int linearSearch(int *a, int k, int n) {
 for (int i = 0; i < n; i++) {
 if (*(a + i) == k) {
 return i;
 }
 }
 return -1;
}
int binarySearch(int key, int *a, int high, int low) {
 if (low <= high) {
 int mid = low + (high - low) / 2; // To avoid potential overflow
 if (*(a + mid) == key)
 return mid;
 else if (*(a + mid) > key)
 return binarySearch(key, a, mid - 1, low);
 else
 return binarySearch(key, a, high, mid + 1);
 }
 return -1;
}
int main() {
 int arr[100];
 int n, key, r;
 for (;;) {
 printf("ENTER 1. TO LINEAR SEARCH\n2. TO BINARY SEARCH\n3. 
TO EXIT\n");
 int ch;
 scanf("%d", &ch);
 switch (ch) {
 case 1:
 printf("ENTER THE NUMBER OF ELEMENTS\n");
 scanf("%d", &n);
 printf("ENTER THE ELEMENTS OF THE ARRAY\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
 printf("ENTER THE KEY ELEMENT\n");
 scanf("%d", &key);
 r = linearSearch(arr, key, n);
 if (r != -1) {
 printf("The element is present at the index %d\n", r);
 } else {
 printf("Element not found\n");
 }
 break;
 case 2:
 printf("ENTER THE NUMBER OF ELEMENTS\n");
 scanf("%d", &n);
 printf("ENTER THE ELEMENTS OF THE ARRAY\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
 printf("ENTER THE KEY ELEMENT\n");
 scanf("%d", &key);
 r = binarySearch(key, arr, n - 1, 0);
 if (r != -1) {
 printf("The element is present at the index %d\n", r);
 } else {
 printf("Element not found\n");
 }
 break;
 default:
 exit(0);
 }
 }
 return 0;
}
